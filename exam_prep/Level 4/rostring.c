#include<unistd.h>

int main(int argc, char *argv[])
{
        if(argc > 1)
        {
                int i = 0;
                int start = 0;
                int end = 0;
                int flag = 0;
                while(argv[1][i] == ' ' || argv[1][i] == '\t')
                {
                        i++;
                }
                start = i;
                while(argv[1][i] != '\0' && argv[1][i] != ' ' && argv[1][i] != '\t')
                {
                        i++;
                }
                end = i;
                while(argv[1][i] == ' ' || argv[1][i] == '\t')
                {
                        i++;
                }
                while(argv[1][i] != '\0')
                {
                        while((argv[1][i] == ' ' && argv[1][i + 1] == ' ') || (argv[1][i] == '\t' && argv[1][i + 1] == '\t'))
                        {
                                i++;
                        }
                        if(argv[1][i] == ' ' || argv[1][i] == '\t')
                        {
                                flag = 1;
                        }
                        write(1, &argv[1][i], 1);
                        i++;
                }
                if(flag && argv[1][i - 1] != ' ')
                {
                        write(1, " ", 1);
                }
                while(start < end)
                {
                        write(1, &argv[1][start], 1);
                        start++;
                }

        }
        write(1, "\n", 1);
}

