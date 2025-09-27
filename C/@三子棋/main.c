#include "game.h"

void first_menu()
{
	printf("************************************\n");
	printf("************** 三子棋 **************\n");
	printf("************************************\n\n");
	Sleep(500);
	printf("************************************\n");
	printf("******* 输入坐标以空格间隔 *********\n");
	printf("************************************\n\n");
	Sleep(500);
	printf("************************************\n");
	printf("**** 例如 1 2 表示 第1行 第2列 *****\n");
	printf("************************************\n\n");
	Sleep(500);
	printf("************************************\n");
	printf("************* 1. play **************\n");
	printf("************************************\n");
	printf("************* 2. exit **************\n");
	printf("************************************\n\n");
}

void menu()
{
	printf("************************************\n");
	printf("************** 三子棋 **************\n");
	printf("************************************\n\n");
	Sleep(500);
	printf("************************************\n");
	printf("************* 1. play **************\n");
	printf("************************************\n");
	printf("************* 2. exit **************\n");
	printf("************************************\n\n");
}

void game()
{
	int status = 0;
	char board[ROW][COL] = {0};

	// 初始化棋盘
	init_board(board, ROW, COL);

	// 打印棋盘
	display_board(board, ROW, COL);

	Sleep(600);

	printf("------------------------------------\n\n");

	// 下棋
	while (1)
	{
		Sleep(600);

		// 玩家回合
		player_move(board, ROW, COL);
		status = is_win(board, ROW, COL);
		if (status != 0)
		{
			// 跳出下棋循环
			break;
		}
		display_board(board, ROW, COL);

		Sleep(600);

		printf("------------------------------------\n\n");

		Sleep(600);

		// 电脑回合
		computer_move(board, ROW, COL);
		status = is_win(board, ROW, COL);
		if (status != 0)
		{
			// 跳出下棋循环
			break;
		}
		display_board(board, ROW, COL);

		Sleep(600);

		printf("------------------------------------\n\n");
	}

	switch (status)
	{
	case 1:
		display_board(board, ROW, COL);
		printf("玩家获胜!\n\n");
		break;
	case -1:
		display_board(board, ROW, COL);
		printf("电脑获胜!\n\n");
		break;
	case 2:
		display_board(board, ROW, COL);
		printf("平局!\n\n");
		break;
	}
}

int main()
{
	// 初始化随机数
	srand((unsigned int)time(NULL));

	int input = 0;
	do
	{
		if (input == 0)
		{
			first_menu();
		}
		else
		{
			menu();
		}

		printf("请选择:-> ");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();
			Sleep(1200);
			break;
		case 2:
			printf("\n退出游戏!\n");
			Sleep(1200);
			break;
		default:
			printf("\n选择错误!\n\n");
			Sleep(1200);
			break;
		}
	} while (input == 1);

	return 0;
}