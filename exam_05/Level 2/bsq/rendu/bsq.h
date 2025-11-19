#ifndef BSQ_H
# define BSQ_H

# define UNINITIALIZED -1

typedef struct {
	int map_y;	// vertical (y) map size
	int map_x;	// horizontal (x) map size
	char **arr2d;  // map data from file, w/o header, treated as const, solution bsq not written in it

	char empty;
	char obst;
	char full;

	int sol_side;	// square size (side a) of the solution square
	int sol_y;  // y coordinate, top-left corner as starting point of the solution square
	int sol_x;  // x coordinate, top-left corner as starting point of the solution square
} t_map;

#endif