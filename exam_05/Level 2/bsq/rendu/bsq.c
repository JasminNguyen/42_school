			
#include "bsq.h"

void	free_bsq(t_bsq *bsq)
{
	if(bsq)
	{
		if(bsq->stream && bsq->stream != stdin)
			fclose(bsq->stream);
		if(bsq->map)
		{
			int i = -1;
			while(bsq->map[++i])
				free(bsq->map[i]);
			free(bsq->map);
		}
		free(bsq);
	}
}

int	ft_strlen(char *str)
{
	int i = 0;
	
	while(str && str[i])
		i++;
	return i;
}

int	parse_header(t_bsq *bsq)
{
	int n = fscanf(bsq->stream, "%i%c%c%c\n", &bsq->rows, &bsq->empty, &bsq->obst, &bsq->full);
	if(n != 4 || bsq->rows <= 0
		|| (bsq->empty == bsq->full || bsq->empty == bsq->obst || bsq->full == bsq->obst))
		return (printf("Invalid map\n"), 1);
	return (0);
}

int read_map(t_bsq *bsq)
{
	if(parse_header(bsq))
		return 1;
	ssize_t nread;
	size_t n = 0;
	char *line = NULL;
	int map_size = 1;
	while((nread = getline(&line, &n, bsq->stream)) != -1)
	{
		char **tmp = realloc(bsq->map, (map_size + 1) * sizeof(char *));
		if(!tmp)
		{
			free(line);
			return (printf("Error: allocation error\n"), 1);
		}
		bsq->map = tmp;
		bsq->map[map_size] = NULL;
		bsq->map[map_size - 1] = calloc(nread, sizeof(char));
		if(!bsq->map[map_size - 1])
		{
			free(line);
			return (printf("Error: Allocation failed\n"), 1);
		}
		if(line[nread - 1] != '\n')
		{
			free(line);
			return (printf("Error: Invalid map\n"), 1);
		}
		for(int i = 0; i < nread- 1; i++)
		{
			bsq->map[map_size - 1][i] = line[i];
		}
		map_size++;
		free(line);
		n = 0;
		line = NULL;
	}
	if(line)
		free(line);
	return (0);
}

int	validate_map(t_bsq *bsq)
{
	if(!bsq->map)
		return (printf("Error: Invalid map\n"), 1);
	bsq->cols = ft_strlen(bsq->map[0]);
	if(bsq->cols < 1)
		return (printf("Error: Invalid map\n"), 1);
	int i;
	for(i = 0; bsq->map[i] != NULL; i++)
	{
		if(ft_strlen(bsq->map[i]) != bsq->cols)
			return (printf("Error: Invalid map\n"), 1);
		for(int j = 0; j < bsq->cols; j++)
		{
			if((bsq->map[i][j] != bsq->empty && bsq->map[i][j] != bsq->obst)
				|| bsq->map[i][j] < 32 || bsq->map[i][j] > 126)
				return (printf("Error: Invalid map\n"), 1);
		}
	}
	if(i != bsq->rows)
		return (printf("Error: Invalid map\n"), 1);
	return (0);
}

int 	find_bsq(t_bsq *bsq)
{
	int max_y = 0, max_x = 0, max_len = 0;
	char dp[bsq->rows + 1][bsq->cols + 1];
	for(int y = 0; y < bsq->rows; y++)
	{
		for(int x = 0; x < bsq->cols; x++)
		{
			if(bsq->map[y][x] == bsq->obst)
				dp[y][x] = 0;
			else if(x == 0 || y == 0)
				dp[y][x] = 1;
			else
			{
				int min = dp[y - 1][x];
				min = min < dp[y][x - 1] ? min : dp[y][x -1];
				min = min < dp[y - 1][x - 1] ? min : dp[y - 1][x - 1];
				dp[y][x] = min + 1;
			}
			if(max_len < dp[y][x])
			{
				max_len = dp[y][x];
				max_y = y;
				max_x = x;
			}
		}
	}
	if(max_len == 0)
		return (printf("Error: this contains only obsticles\n"), 1);
	for(int y = (max_y - max_len) + 1; y <= max_y; y++)
	{
		for(int x = (max_x - max_len) + 1; x <= max_x; x++)
			bsq->map[y][x] = bsq->full;
	}
	return (0);
}	

int	main(int argc, char **argv)
{
	t_bsq *bsq = calloc(1, sizeof(t_bsq));
	if(!bsq)
	{
		free(bsq);
		return (printf("Error: allocation failed\n"), 1);
	}
	if(argc == 1)
		bsq->stream = stdin;
	else if(argc == 2)
	{
		bsq->stream = fopen(argv[1], "r");
		if(!bsq->stream)
		{
			free(bsq);
			return (printf("Error: could not open the file\n"), 1);
		}
	}
	else
	{
		free(bsq);
		return (printf("Error: too many arguments\n"), 1);
	}
	if(read_map(bsq) || validate_map(bsq) || find_bsq(bsq))
	{
		free_bsq(bsq);
		return 1;
	}
	for(int i = 0; i < bsq->rows; i++)
	{
		printf("%s\n", bsq->map[i]);
	}
	return (0);
}


	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		
		
		
		
		
		
		
	
