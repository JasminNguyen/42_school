// #ifndef EX_H
// #define EX_H

// #include <stdlib.h>
// #include <stdio.h>

// #define UNINITIALIZED -1
// typedef struct {
//     int map_y; //vertical map size (of original map)
//     int map_x; //horizontal map size 
//     char **arr;

//     char empty;
//     char obst;
//     char full;

//     int sol_side;
//     int sol_y;
//     int sol_x;

// } s_map;

// #endif


















#ifndef EX_H
#define EX_H

#include <stdio.h>
#include <stdlib.h>
#define UNINITIALIZED -1
typedef struct {
    int map_x;
    int map_y;
    char **arr;
    
    char full;
    char empty;
    char obst;

    int sol_size;
    int sol_x;
    int sol_y;
} s_map;

#endif