#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 4)
	{
		return putchar('e'), 1;
	}
	else
	{
		//initialize board
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int iterations = atoi(argv[3]);
		
		char board[width][height];
		char next_board[width][height];

		//read input to initialize cells to 0
		for(int y = 0; y < height; y++)
		{
			for(int x = 0; x < width; x++)
			{
				board[x][y] = 0;
			}
		}
		
	}
	return 0;
}