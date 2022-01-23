#include <stdio.h>

#define COL 8
#define ROW 8
#define Scol 3 // starting col 
#define Srow 3 // starting row

char maze[ROW][COL] = { {'x','x','x','0','0','0','x','x'},
					{'x','0','0','0','x','0','0','0'},
					{'0','0','x','x','x','x','x','x'},
					{'0','x','x','0','x','x','x','x'},
					{'0','0','x','0','x','0','0','0'},
					{'x','0','x','0','0','0','x','0'},
					{'x','0','0','x','x','x','x','0'},
					{'x','x','0','0','0','0','0','0'} };

int find_way(int direct[4][2]);
void print_maze();

int main()
{
	int x = Scol;
	int y = Srow;
	int mov;
	int direct[4][2];

	printf("<< 미로 탈출 프로그램 >>\n\n");
	printf(" 출발좌표(3,3)\n");

	while (1) {
		maze[x][y] = '1';
		print_maze(); 

		direct[0][0] = x - 1;
		direct[0][1] = y;
		direct[1][0] = x;
		direct[1][1] = y + 1;
		direct[2][0] = x + 1;
		direct[2][1] = y;
		direct[3][0] = x;
		direct[3][1] = y - 1;

		mov = find_way(direct);

		if (mov == -1)
		{
			printf("미로를 탈출했습니다!\n");
			break;
		}

		x = direct[mov][0];
		y = direct[mov][1];
		printf(" ( %d , %d )\n", x, y);
	}
	return 0;
}


int find_way(int direct[4][2]) // 길을 찾는 함수
{
	for (int i = 0; i < 4; i++)
	{
		if (maze[direct[i][0]][direct[i][1]] == '0')
			return i;
	}
	return  -1;
}


void print_maze()
{
	for (int i = 0; i < 8; i++) {
		printf("------------------------\n");
		printf(" %c  %c  %c  %c  %c  %c  %c  %c \n", maze[i][0], maze[i][1], maze[i][2], maze[i][3], maze[i][4], maze[i][5], maze[i][6], maze[i][7]);
	}
	printf("------------------------\n\n");
}
