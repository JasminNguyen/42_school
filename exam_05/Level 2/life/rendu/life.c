#include <stdio.h>
#include <stdbool.h>


bool within_board(int pos_x, int pos_y, int width, int height)
{
	if(pos_x < width && pos_y < height && pos_x >= 0 && pos_y >= 0)
	{
		return true;
	}
	return false;
}
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

		//initialize cells in board to 0
		//x is a column, y is a row
		for(int y = 0; y < height; y++)
		{
			for(int x = 0; x < width; x++)
			{
				board[x][y] = 0;
				next_board[x][y] = 0;
			}
		}
		//set alive cells to 1 in board
		char cmd;
		
		int pos_x = 0;
		int pos_y = 0;
		bool pen_down = false;

		while (read(0, &cmd, 1) > 0)
		{
			if(cmd == 'w') //up
			{
				pos_y--;
				if(pen_down && within_board(pos_x, pos_y, width, height))
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'a') //left
			{
				pos_x--;
				if(pen_down && within_board(pos_x, pos_y, width, height))
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 's') //down
			{
				pos_y++;
				if(pen_down && within_board(pos_x, pos_y, width, height))
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'd') //right
			{
				pos_x++;
				if(pen_down && within_board(pos_x, pos_y, width, height))
				{
					board[pos_x][pos_y] = 1;
				}
			}
			else if(cmd == 'x') //toggle pen
			{
				if(!pen_down)
				{
					pen_down = true;
					if(within_board(pos_x, pos_y, width, height))
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

		
	}
	return 0;
}