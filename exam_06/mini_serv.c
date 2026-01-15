#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/ip.h>


//globals
int count = 0; //for keeping track of number of clients
int max_fd = 0; //for keeping track of max number of socket fds
int ids[65536]; //array indexed by fd, storing the client id (count) assigned to that socket fd
char *msg[65536]; // pointer to a buffer that holds collected bytes

fd_set rfds, wfds, afds; //sets of readable, writeable and all active fds 
char buf_read[1001], buf_write[42]; //temporary array for read and written bytes (buf_read = for recv(), buf_write = for formatted outgoing strings)


//COPY FROM GIVEN MAIN 

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

//COPY FROM GIVEN MAIN 

void notify_other(int author_fd, char *str)
{
    for(int fd = 0; fd <= max_fd; fd++)
    {
        if(FD_ISSET(fd, &wfds) && fd != author_fd) //is the fd writable and is it not the own fd?
        {
            send(fd, str, strlen(str), 0);
        }
    }
}
void send_msg(int fd)
{
    char *message;
    while(extract_message(&msg[fd], &message))
    {
        sprintf(buf_write, "client %d: ", ids[fd]);
        notify_other(fd, buf_write);
        notify_other(fd, message);
        free(message);
    }

}
void remove_client(int client_fd)
{
    sprintf(buf_write, "server: client %d just left\n", ids[client_fd]);
    notify_other(client_fd, buf_write);
    free(msg[client_fd]);
    FD_CLR(client_fd, &afds);
    close(client_fd);
}

void fatal_error()
{
    write(2, "Fatal error\n", 12);
    exit(1);
}

int create_socket()
{
    max_fd = socket(AF_INET, SOCK_STREAM, 0); // AF_INET -> IPv4, SOCK_STREAM -> TCP
    if(max_fd < 0)
    {
        fatal_error();
    }
    FD_SET(max_fd, &afds); //adds listening socket into active set
    return max_fd; //returns fd
}


void register_client(int client_fd)
{
    if(client_fd > max_fd) //update max_fd if necessary
    {
        max_fd = client_fd;
    }
   ids[client_fd] = count++; //assign client an id with count and increment the count
   msg[client_fd] = NULL; //initialize this clients buffer
   FD_SET(client_fd, &afds); //add this client socket fd to active set
   sprintf(buf_write, "server: client %d just arrived\n", ids[client_fd]);
   notify_other(client_fd, buf_write);
}

int main(int argc, char *argv[])
{
    //check argument number
    if(argc != 2)
    {
        write(2, "Wrong number of arguments\n", 26);
        exit(1);
    }
    //clear the afds set to start off clean
    FD_ZERO(&afds);
    //create socket fd
    int socket_fd = create_socket();

    //COPY FROM GIVEN MAIN
    struct sockaddr_in servaddr; //declares a variable that can hold an IPv4 address
    bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1])); //REPLACE PORT WITH ARGV[1]

	// Binding newly created socket to given IP and verification 
	if ((bind(socket_fd, (const struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) { //REMOVE PRINTFS HERE AND REPLACE WITH FATAL_ERROR()
		fatal_error();
	} 
	if (listen(socket_fd, 10) != 0) {
		fatal_error();
	}
    //COPY FROM GIVEN MAIN

    //main loop begins
    while(1)
    {
        rfds = wfds = afds; //put all active fds in readable and writable fd set everytime cause select will modify the sets 
        if(select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0) //check if select fails
        {
            fatal_error();
        }
        for(int fd = 0; fd <= max_fd; fd++) //go through every fd
        {
            if(!FD_ISSET(fd, &rfds)) //is the fd readable, if not continue
            {
                continue;
            }
            if(fd == socket_fd) //case A: the readable fd is a socket_fd
            {
                socklen_t addr_len = sizeof(servaddr);
                int client_fd = accept(socket_fd, (struct sockaddr *)&servaddr, &addr_len); //accept connection and create new client socket fd ! ->  accept(int socket, struct sockaddr *restrict address -> casting necessary, socklen_t *restrict address_len);
                if(client_fd >= 0) //register the client if fd is >= 0
                {
                    register_client(client_fd);
                    break;
                }

            }
            else //case B: the readable fd is a client_fd
            {
                int bytes_read = recv(fd, buf_read, 1000, 0);
                if(bytes_read <= 0)
                {
                    remove_client(fd);
                    break;
                }
                buf_read[bytes_read] = '\0';
                msg[fd] = str_join(msg[fd], buf_read);
                send_msg(fd);
            }
        } 
    }
    return 0;
}

