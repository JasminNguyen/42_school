
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>



bool within_board(int pos_x, int pos_y, int width, int height)
{
	if(pos_x < width && pos_y < height && pos_x >= 0 && pos_y >= 0)
	{
		return true;
	}
	return false;
}



int main(int argc, char*argv[])
{
	if(argc != 4)
	{
		return putchar('e'), 1;
	}
	else
	{
		//get mesurements of board
		int width = atoi(argv[1]);
		int height = atoi(argv[2]);
		int iterations = atoi(argv[3]);
		
		char board[width][height];
		char next_board[width][height];

		//initialization to 0
		for(int h = 0; h < height; h++)
		{
			for(int w = 0; w < width; w++)
			{
				board[w][h] = 0;
				next_board[w][h] = 0;
			}
		}

		//get configuration for board
		char cmd;
		int pos_x = 0;
		int pos_y = 0;
		bool pen_down = false;
		
		while(read(0, &cmd, 1) > 0)
		{
			if(cmd == 'w')
			{
				pos_y--;
				if(pen_down && within_board(pos_x, pos_y, width, height) == true)
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 's')
			{
				pos_y++;
				if(pen_down && within_board(pos_x, pos_y, width, height) == true)
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'a')
			{
				pos_x--;
				if(pen_down && within_board(pos_x, pos_y, width, height) == true)
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'd')
			{
				pos_x++;
				if(pen_down && within_board(pos_x, pos_y, width, height) == true)
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'x')
			{
				if(!pen_down)
				{
					pen_down = true;
					if(pen_down && within_board(pos_x, pos_y, width, height) == true)
					{
						board[pos_x][pos_y] = 1;
					}
				}
				else
				{
					pen_down = false;
				}
				
			}
		}

		//run simulation and swap board after each
		for(int iter = 0; iter < iterations; iter++)
		{
			for(int h = 0; h < height; h++)
			{
				for(int w = 0; w < width; w++)
				{
					//count alive neighbours for each cell					
					int alive_neighbours = 0;

					for(int pos_x = -1; pos_x <= 1; pos_x++)
					{
						for(int pos_y = -1; pos_y <= 1; pos_y++)
						{
							int neighbour_x = w + pos_x;
							int neighbour_y = h + pos_y;
							if(pos_x == 0 && pos_y == 0)
							{
								continue;
							}
							if(within_board(neighbour_x, neighbour_y, width, height) == true)
							{
								if(board[neighbour_x][neighbour_y] == 1)
								{
									alive_neighbours++;
								}
								
							}
						}
					}

					//apply rules to next board
					char alive = board[w][h];

					if(alive)
					{
						if(alive_neighbours == 2 || alive_neighbours == 3)
						{
							next_board[w][h] = 1;
						}
						else
						{
							next_board[w][h] = 0;
						}
					}
					else
					{
						if(alive_neighbours == 3)
						{
							next_board[w][h] = 1;
						}
						else 
						{
							next_board[w][h] = 0;
						}
					}
				}
			}
			//swap board to next_board
			for(int w = 0; w < width; w++)
			{
				for(int h = 0; h < height; h++)
				{
					board[w][h] = next_board[w][h];
				}
			}
		}

		//print final board --> probably needs a change
			for(int h = 0; h < height; h++)
			{
				for(int w = 0; w < width; w++)
				{
					if(board[w][h] == 1)
					{
						putchar('0');
					}
					else
					{
						putchar(' ');
					}
				}
				putchar('\n');
			}



	}
	return 0;
}
