#include <assert.h>
#include "stdio.h"
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>
#include <time.h>
#include <conio.h>


const int row = 5; // can change the dimension by changing this const. N x N matrix.



void Table(int **num)
{
	int count = 0;
	for (int r = 0; r < row; r++) 
	{
		for (int c = 0; c < row; c++)
		{
			std::cout << "-------";
		}
		std::cout << std::endl;
		for (int c = 0; c < row; c++)
		{
			std::cout << "  |  ";
			std::cout << ((num[r][c] == 0) ? " ": std::to_string(num[r][c]));
		}
		std::cout << "  |  ";
		std::cout << std::endl;
		count++;
		if (count == row) 
		{
			for (int r = 0; r < row; r++)
			{
				std::cout << "-------";
			}
		}
	}
}

void Value(int **num)
{
	int tm = (int)time(NULL);
	srand(tm);
	int i = 0;
	
	while (i < 2) 
	{
		int x = rand() % row;
		int y = rand() % row;
		if (num[x][y] == 0) 
		{
			num[x][y] = 2;
			i++;
		}
	}
}

void Add(int **num) 
{
	int tm = (int)time(NULL);
	srand(tm);
	int i = 0;

	while (i < 1)
	{
		int x = rand() % row;
		int y = rand() % row;
		if (num[x][y] == 0)
		{
			num[x][y] = 2;
			i++;
		}
	}
}

void Initial(int **num,int row) 
{
	for (int i = 0; i < row; i++)
	{
		num[i] = new int[row];
		for (int j = 0; j < row; j++)
		{
			num[i][j] = 0;
		}
	}
}

int GetDirection()
{
	int ret;
	do
	{
		int ch = _getch();

		ch = _getch();
		switch (ch)
		{
		case 72:
			ret = 1; // UP
			break;
		case 80:
			ret = 2; // DOWN
			break;
		case 75:
			ret = 3; // LEFT
			break;
		case 77:
			ret = 4; // RIGHT
			break;
		}
	} while (ret == 0);

	return ret;
}

enum keyboard 
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

void ChangeType(int **num) 
{

}

void MoveUP_Condition(int **num, int row) 
{
	int set;
	for (int c = 0; c < row; c++) 
	{
		set = 0;
		for (int r = 0; r < row; r++) 
		{
			if (num[r][c] != 0) 
			{
				num[set][c] = num[r][c];
				if (set != r) 
				{
					num[r][c] = 0;
				}
				set++;
			}
			else;
		}
	}
	
}

void MoveUP(int **num, int row)
{
	MoveUP_Condition(num, row);
	int i;
	for (int c = 0; c < row; c++) 
	{
		i = 1;
		for (int r = 0; r + 1 < row; r++)
		{
			if (num[r][c] == num[r+1][c])
			{
				num[r][c] = num[r][c] + num[r+1][c];
				
				while (r + i + 1 < row)
				{
					num[r + i][c] = num[r + i + 1][c];
					num[r + i + 1][c] = 0;
					i++;
				}
				break;
			}
			else;
		}
	}	
}

void MoveDOWN_Condition(int **num, int row)
{
	int set;
	for (int c = 0; c < row; c++)
	{
		set = row - 1;
		for (int r = row - 1; r >= 0; r--)
		{
			if (num[r][c] != 0)
			{
				num[set][c] = num[r][c];
				if (set != r)
				{
					num[r][c] = 0;
				}
				set--;
			}
			else;
		}
	}
}

void MoveDOWN(int **num, int row)
{
	MoveDOWN_Condition(num, row);
	int i;
	for (int c = 0; c < row; c++)
	{
		i = 1;
		for (int r = row - 1; r >= 1; r--)
		{
			if (num[r][c] == num[r - 1][c])
			{
				num[r][c] = num[r][c] + num[r - 1][c];

				while (r - i - 1 >= 0)
				{
					num[r - i][c] = num[r - i - 1][c];
					num[r - i - 1][c] = 0;
					i++;
				}
				break;
			}
			else;
		}
	}
}

void MoveLEFT_Condition(int **num, int row)
{
	int set;
	for (int r = 0; r < row; r++)
	{
		set = 0;
		for (int c = 0; c < row; c++)
		{
			if (num[r][c] != 0)
			{
				num[r][set] = num[r][c];
				if (set != c)
				{
					num[r][c] = 0;
				}
				set++;
			}
			else;
		}
	}

}

void MoveLEFT(int **num, int row)
{
	MoveLEFT_Condition(num, row);
	int i;
	for (int r = 0; r < row; r++)
	{
		i = 1;
		for (int c = 0; c + 1 < row; c++)
		{
			if (num[r][c] == num[r][c + 1])
			{
				num[r][c] = num[r][c] + num[r][c + 1];

				while (c + i + 1 < row)
				{
					num[r][c + i] = num[r][c + i + 1];
					num[r][c + i + 1] = 0;
					i++;
				}
				break;
			}
			else;
		}
	}
}

void MoveRIGHT_Condition(int **num, int row)
{
	int set;
	for (int r = 0; r < row; r++)
	{
		set = row - 1;
		for (int c = row - 1; c >= 0; c--)
		{
			if (num[r][c] != 0)
			{
				num[r][set] = num[r][c];
				if (set != c)
				{
					num[r][c] = 0;
				}
				set--;
			}
			else;
		}
	}
}

void MoveRIGHT(int **num, int row)
{
	MoveRIGHT_Condition(num, row);
	int i;
	for (int r = 0; r < row; r++)
	{
		i = 1;
		for (int c = row - 1; c >= 1; c--)
		{
			if (num[r][c] == num[r][c - 1])
			{
				num[r][c] = num[r][c] + num[r][c - 1];

				while (c - i - 1 >= 0)
				{
					num[r][c - i] = num[r][c - i - 1];
					num[r][c - i - 1] = 0;
					i++;
				}
				break;
			}
			else;
		}
	}
}

void Logic(int ret, int **num, int row)
{
	switch (ret)
	{
	case 1:
		MoveUP(num, row);	// UP
		break;
	case 2:
		MoveDOWN(num, row);  // DOWN
		break;
	case 3:
		MoveLEFT(num, row);	// LEFT
		break;
	case 4:
		MoveRIGHT(num, row); // RIGHT
		break;
	}
}

int victory(int **num) 
{	
	int result;
	for (int i = 0; i < 3; i++) 
	{
		for (int j = 0; j < 3; j++)
		{
			if (num[i][j] == 2048)
			{
				return result = 1;
			}
			else
				return result = 0;
		}
	}
}

int Defeat(int **num)
{
	int check = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < row; j++)
		{
			if (num[j][i] == 0) 
			{
				check++;
			}
		}
	}
	if (check == 0) 
	{
		return 1;
	}
	else return 0;
}

int main() 
{
	
	int **num = new int*[row];

	Initial(num, row);
	
	Value(num);
	
	while (victory(num) == 0 && Defeat(num) == 0)
	{
		system("cls");

		Table(num);

		std::cout << std::endl;

		std::cout << "Enter direction" << std::endl;
		char ret = GetDirection();

		Logic(ret, num, row);
		
		Add(num);
		
	}
	system("cls");

	Table(num);

	if (victory(num) == 1) 
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Victory" << std::endl;
			/*exit(1);*/	
	}
	else if (Defeat(num) == 1) 
	{
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << "Defeat" << std::endl;
			/*exit(1);*/
	}
}