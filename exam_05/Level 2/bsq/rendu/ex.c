#include "ex.h"


int square_fits(int side_size, s_map *map, int pos_y, int pos_x)
{
    if(pos_y + side_size > map->map_y || pos_x + side_size > map->map_x) //current pos + current side_size is bigger than square? then noo
    {
        return 0;
    }
    for(int y = pos_y; y < pos_y + side_size; y++) //are there obstacles in the potential square? then nooo
    {
        for(int x = pos_x; x < pos_x + side_size; x++)
        {
            if(map->arr[y][x] == map->obst)
            {
                return 0;
            }
        }
    }
    return 1;
}
void try_squares_for_coordinates(s_map *map, int pos_y, int pos_x)
{
    int side_size = 1;
    while(square_fits(side_size, map, pos_y, pos_x))
    {
        if(side_size > map->sol_side)
        {
            map->sol_side = side_size;
            map->sol_x = pos_x;
            map->sol_y = pos_y;
        }
        side_size++;
    }
}
void find_bsq(s_map *map)
{
    //loop through all positions of the map
    for(int pos_y = 0; pos_y < map->map_y; pos_y++)
    {
        for(int pos_x = 0; pos_x < map->map_x; pos_x++)
        {
            try_squares_for_coordinates(map, pos_y, pos_x);
        }
    }
}

int is_within_square(s_map *map, int y, int x)
{
    return (y < map->sol_y + map->sol_side && x < map->sol_x + map->sol_side && y >= map->sol_y && x >= map->sol_x);
}
void print_map(s_map *map)
{
    for(int y = 0; y < map->map_y; y++)
    {
        for(int x = 0; x < map->map_x; x++)
        {
            if(is_within_square(map, y, x))
            {
                fprintf(stdout, "%c", map->full);
            }
            else
            {
                fprintf(stdout, "%c", map->arr[y][x]);
            }
        }
        fprintf(stdout, "\n");
    }
}
void parse_map(FILE *stream, s_map *map)
{
    char *line = NULL;
    size_t size = 0;

    //loop through height of the map
    for(int y = 0; y < map->map_y; y++)
    {
        int nread = getline(&line, &size, stream);
        if(map->map_x == UNINITIALIZED) //find x of the map
        {
            map->map_x = nread -1;
        }
        else if(nread == -1 || nread -1 != map->map_x || line[nread - 1] != '\n') //nread not working, nread -1 not map_x, line[nread -1] not \n 
        {
            fprintf(stdout, "Error: invalid map 1\n");
            return;
        }
        map->arr[y] = malloc(sizeof(char) * map->map_x); //allocate memory for the width of each line 
        if(!map->arr[y])
        {
            fprintf(stdout, "Error: malloc fail\n");
        }
        //loop through width of the map
       
        for(int x = 0; x < map->map_x; x++)
        {
            if(!(line[x] == map->empty || line[x] == map->obst)) //check line for other characters than empty and obstacle
            {
                fprintf(stdout, "Error: invalid map 2\n");
                return;
            }
            map->arr[y][x] = line[x]; //set line
        }
        free(line); //reset everything
        line = NULL;
        size = 0;
    }
    if(getline(&line, &size, stream) != -1) //getline fail
    {
        fprintf(stdout, "Error: invalid map 3\n");
        return;
    }

    find_bsq(map);
    print_map(map);
}
int has_valid_header(FILE *stream, s_map *map)
{
    if(fscanf(stream, "%d%c%c%c\n", &(map->map_y), &(map->empty), &(map->obst), &(map->full)) != 4)
    {
        return 0;
    }
    if(map->empty == map->obst || map->empty == map->full || map->full == map->obst || map->map_y < 1) //check for doubles or map_y (height) less than 1
    {
        return 0;
    }
    //if all good then initialize (except for map_y and the characters obviously)
    map->map_x = UNINITIALIZED;
    map->sol_x = UNINITIALIZED;
    map->sol_y = UNINITIALIZED;
    map->sol_side = UNINITIALIZED;
    map->arr = malloc(sizeof(char*) *map->map_y); //allocate memory for char strings of the height of the map
    if(!map->arr)
    {
        fprintf(stdout, "Error: malloc fail\n");
    }
    return 1;
}
void check_file(FILE *stream)
{
    s_map map;
    if(has_valid_header(stream, &map))
    {
        parse_map(stream, &map);
    }
    else 
    {
        fprintf(stdout, "Error: invalid map 4\n");
    }
}
int main(int argc, char *argv[])
{
    FILE *stream = NULL;

    if(argc > 2)
    {
        fprintf(stdout, "Error: too many arguments\n");
        return 1;
    }
    else if (argc == 2)
    {
        stream = fopen(argv[1], "r");
    }
    else
    {
        stream = stdin;
    }

    if(!stream)
    {
        fprintf(stdout, "Error: fopen fail\n");
    }
    else 
    {
        check_file(stream);
    }

    return 0;
}
















