#include <malloc.h>
#include "bsq.h"

int is_valid_header(FILE *stream, t_map *map)
{
	if (fscanf(stream, "%d%c%c%c\n", &(map->map_y), &(map->empty), &(map->obst), &(map->full)) != 4) //check header for 4 successfully returned elements
	{
		return 0;
	}
		
	if (map->empty == map->obst || map->empty == map->full || map->obst == map->full || map->map_y < 1)
	{
		return 0;
	}
	// is good header, init the rest
	map->map_x = UNINITIALIZED;
	map->sol_side = UNINITIALIZED;
	map->sol_y = UNINITIALIZED;
	map->sol_x = UNINITIALIZED;
	map->arr2d = malloc(sizeof(char*) * map->map_y); //allocate memory for the height of the number of lines in the map (height)
	if (!(map->arr2d))
	{
		fprintf(stdout, "Error: malloc fail");
		return 0;
	}
	return 1;
}

int square_fits(t_map *map, int pos_y, int pos_x, int side_size)
{
	if (pos_y + side_size > map->map_y || pos_x + side_size > map->map_x) //pos + potential side bigger than square? then noo
		return 0;

	for (int y = pos_y; y < pos_y + side_size; y++) // is there an obstacle in the potential square?? then nooo
	{
		for (int x = pos_x; x < pos_x + side_size; x++)
		{
			if (map->arr2d[y][x] == map->obst)
				return 0;
		}
	}
	return 1;
}

void try_squares_for_coords(t_map *map, int pos_y, int pos_x)
{
	int side_size = 1;

	while (square_fits(map, pos_y, pos_x, side_size))
	{
		if (side_size > map->sol_side)
		{
			map->sol_side = side_size;
			map->sol_y = pos_y;
			map->sol_x = pos_x;
		}
		side_size++;
	}
}

void find_bsq(t_map *map)
{
	for (int pos_y = 0; pos_y < map->map_y; pos_y++)
	{
		for (int pos_x = 0; pos_x < map->map_x; pos_x++)
		{
			try_squares_for_coords(map, pos_y, pos_x);
		}
	}
}

int is_within_square(t_map *map, int y , int x)
{
	return (y < map->sol_y + map->sol_side && x < map->sol_x + map->sol_side && y >= map->sol_y && x >= map->sol_x);
}

void print_map(t_map *map)
{
	for (int y = 0; y < map->map_y; y++)
	{
		for (int x = 0; x < map->map_x; x++)
		{
			if (is_within_square(map, y, x))
				fprintf(stdout, "%c", map->full); //print full
			else
				fprintf(stdout, "%c", map->arr2d[y][x]); //print original character of map
		}
		fprintf(stdout, "\n");
	}
}

void parse_map(FILE *stream, t_map *map)
{
	char *line = NULL; //line buffer (constent read)
	size_t size = 0; // contains the buffer size

	// extract and validate map body
	for (int y = 0; y < map->map_y; y++) //loop through height
	{
		int nread = getline(&line, &size, stream);
		if (map->map_x == UNINITIALIZED) // find width of the map (x)
			map->map_x = nread - 1;  // (nread -1) bc '\n' retained
		else if (nread == -1 || (nread - 1) != m->map_x || line[nread - 1] != '\n')
		{
			fprintf(stdout, "Error: invalid map\n");
			return;
		}
		map->arr2d[y] = malloc(sizeof(char) * map->map_x); // allocate memory for width of the map (x)
		if (!(m->arr2d[y]))
		{
			fprintf(stdout, "Error: malloc fail\n");
			return;
		}
		for (int x = 0; x < map->map_x; x++) //loop through width 
		{
			if (!(line[x] == map->empty || line[x] == map->obst )) // check for characters that are not part of the specified ones (we can only have empty or obstacles!)
			{
				fprintf(stdout, "Error: invalid map\n");
				return;
			}
			map->arr2d[y][x] = line[x]; //populate one line and put it into map
		}
		free(line); //free line
		line = NULL; // set it to NULL so getline does not assume that we want to reuse the line (which is a buffer)
		size = 0; // set size to 0
	}
	if (getline(&line, &size, stream) != -1)
	{
		fprintf(stdout, "Error: invalid map\n");
		return;
	}


	find_bsq(map);
	print_map(map);
}

void check_file(FILE* stream)
{
	t_map map;

	if (is_valid_header(stream, &map)) //check for valid header
		parse_map(stream, &map); // parse map
	else
		fprintf(stdout, "Error: invalid map\n");
}


int main(int argc, char **argv)
{
	FILE *stream = NULL;

	if (argc > 2) //check for too many arguments
	{
		fprintf(stdout, "Error: too many arguments\n");
		return 1;
	}
	else if (argc == 2) // if two arguments -> open file in read mode
		stream = fopen(argv[1], "r");
	else
		stream = stdin; // if one argument -> read from stdin
	
	if (!stream)
		fprintf(stdout, "Error: fopen fail\n"); //stream fail
	else
		check_file(stream); // if everything correct -> parse file
}