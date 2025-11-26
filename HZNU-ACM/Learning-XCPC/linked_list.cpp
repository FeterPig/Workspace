// 练习 手搓双向循环链表

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *last;
};

int main()
{
    // --- 步骤 A: 创建节点 (数据预制) ---
    // 我们直接预制 3 个节点，不需要用户输入
    Node *head = (Node *)malloc(sizeof(Node));
    Node *mid = (Node *)malloc(sizeof(Node));
    Node *end = (Node *)malloc(sizeof(Node));

    // --- 步骤 B: 填充数据 ---
    head->data = 10;
    mid->data = 20;
    end->data = 30;

    // --- 步骤 C: 链接节点 (核心步骤) ---
    head->next = mid; // 头节点指向第二个
    head->last = end;
    mid->next = end; // 第二个指向第三个
    mid->last = head;
    end->next = head; // 循环链表
    end->last = mid;

    // --- 步骤 D: 验证链表 (简单的遍历打印) ---
    printf("链表内容: ");
    Node *current = head;
    while (current != NULL)
    {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

    // --- 步骤 E: 释放内存 (好习惯) ---
    free(head);
    free(mid);
    free(end);

    return 0;
}