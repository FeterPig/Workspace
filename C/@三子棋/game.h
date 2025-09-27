// 包含头文件
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

/**
 * @brief 自定义棋盘大小
 * @todo 非3×3棋盘时斜线判定
 */
// 定义常量宏
#define ROW 3 // 行数
#define COL 3 // 列数

// 初始化棋盘
void init_board(char board[ROW][COL], int row, int col);

// 打印棋盘
void display_board(char board[ROW][COL], int row, int col);

// 玩家下棋
void player_move(char board[ROW][COL], int row, int col);

// 电脑下棋
void computer_move(char board[ROW][COL], int row, int col);

/**
 * 1:  玩家获胜
 * -1: 电脑获胜
 * 2: 平局
 * 0: 继续
 */
// 判断输赢
int is_win(char board[ROW][COL], int row, int col);
