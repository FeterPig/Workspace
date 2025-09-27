#include "game.h"

// 初始化棋盘
void init_board(char board[ROW][COL], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

// 打印棋盘
void display_board(char board[ROW][COL], int row, int col)
{
    /**
     * @bug 无法适应不同棋盘大小
     * 
        printf("\n|---|---|---|\n");
        for (int i = 0; i < row; i++)
        {
            printf("| %c | %c | %c |\n", board[i][0], board[i][1], board[i][2]);
            printf("|---|---|---|\n");
        }
        printf("\n");
    */

    // 用变量控制行数和列数，实现自适应

    // 打印第一行分割线
    printf("\n|");
    for (int i = 0; i < col; i++)
    {
        printf("---|");
    }
    printf("\n");

    // 循环打印棋盘格子和分割线
    for (int i = 0; i < row; i++)
    {
        // 打印一行棋盘格子
        printf("|");
        for (int j = 0; j < col; j++)
        {
            printf(" %c |", board[i][j]);
        }
        printf("\n");

        // 打印一行分割线
        printf("|");
        for (int k = 0; k < col; k++)
        {
            printf("---|");
        }
        printf("\n");
    }
    printf("\n");
}

// 玩家下棋
void player_move(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;

re_move:
    printf("玩家下棋, 请输入坐标 -> ");
    int ret = scanf("%d %d", &x, &y);

    // 非数字?
    if (ret != 2)
    {
        printf("\n输入格式错误, 请输入数字坐标!\n\n");
        Sleep(1200);
        // 清空输入缓存区
        while (getchar() != '\n')
            ; // 空语句
        goto re_move;
    }
    if (x >= 1 && x <= row && y >= 1 && y <= col)
    {
        if (board[x - 1][y - 1] == ' ')
        {
            board[x - 1][y - 1] = '*';
        }
        else
        {
            printf("\n坐标被占用, 不能下棋!\n\n");
            Sleep(1200);
            goto re_move;
        }
    }
    else
    {
        printf("\n坐标不合法, 请重新输入!\n\n");
        Sleep(1200);
        goto re_move;
    }
}

// 电脑下棋
void computer_move(char board[ROW][COL], int row, int col)
{
    printf("电脑下棋 -> \n");

    while (1)
    {
        int x = rand() % row; // 生成 0 ~ row-1 的随机数
        int y = rand() % col; // 生成 0 ~ col-1 的随机数

        if (board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

/**
 * @version 2.0
 * @author 豆包AI
 * @brief 智能电脑落子（增加难度）
 * 
    void computer_move(char board[ROW][COL], int row, int col)
    {
        printf("电脑落子 ->\n");

        // 步骤1：检查电脑是否能一步获胜（优先自己赢）
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == ' ') // 找到空位
                {
                    board[i][j] = '#';   // 假设电脑落子
                    if (is_win(board, row, col) == -1) // 检查是否获胜
                    {
                        return; // 确认能赢，直接落子
                    }
                    board[i][j] = ' '; // 恢复棋盘（未赢则撤销假设）
                }
            }
        }

        // 步骤2：检查玩家是否即将获胜（优先阻止玩家）
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (board[i][j] == ' ') // 找到空位
                {
                    board[i][j] = '*';   // 假设玩家落子
                    if (is_win(board, row, col) == 1) // 检查玩家是否会赢
                    {
                        board[i][j] = '#'; // 电脑抢占该位置阻止
                        return;
                    }
                    board[i][j] = ' '; // 恢复棋盘
                }
            }
        }

        // 步骤3：优先占据中心（3x3棋盘的中心是最优位置）
        if (board[1][1] == ' ') // 中心坐标 (1,1)（数组下标从0开始）
        {
            board[1][1] = '#';
            return;
        }

        // 步骤4：其次占据角落（角落比边缘更易形成获胜路线）
        int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}}; // 四个角落坐标
        for (int i = 0; i < 4; i++)
        {
            int x = corners[i][0];
            int y = corners[i][1];
            if (board[x][y] == ' ')
            {
                board[x][y] = '#';
                return;
            }
        }

        // 步骤5：最后选择边缘位置（剩余空位只能是边缘）
        int edges[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}}; // 四个边缘坐标
        for (int i = 0; i < 4; i++)
        {
            int x = edges[i][0];
            int y = edges[i][1];
            if (board[x][y] == ' ')
            {
                board[x][y] = '#';
                return;
            }
        }
    }
*/

// 下面这里写死了, 只能用于三子棋, 待后续优化

// 判断输赢
int is_win(char board[ROW][COL], int row, int col)
{
    // 一行上的三个棋子相同
    for (int i = 0; i < row; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
        {
            if (board[i][1] == '*')
            {
                return 1;
            }
            else if (board[i][1] == '#')
            {
                return -1;
            }
        }
    }

    // 一列上的三个棋子相同
    for (int j = 0; j < col; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
        {
            if (board[1][j] == '*')
            {
                return 1;
            }
            else if (board[1][j] == '#')
            {
                return -1;
            }
        }
    }

    // 对角线上的三个棋子相同
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
    {
        if (board[1][1] == '*')
        {
            return 1;
        }
        else if (board[1][1] == '#')
        {
            return -1;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
    {
        if (board[1][1] == '*')
        {
            return 1;
        }
        else if (board[1][1] == '#')
        {
            return -1;
        }
    }

    // 检查平局（所有格子填满）
    int is_full = 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (board[i][j] == ' ')
            {
                is_full = 0;
                break;
            }
        }
        if (is_full == 0)
        {
            break;
        }
    }
    if (is_full == 1)
    {
        // 平局
        return 2;
    }
    else
    {
        // 继续
        return 0;
    }
}