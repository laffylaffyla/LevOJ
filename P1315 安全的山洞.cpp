/*
题目描述
围绕着山顶有 m (m <= 1000) 个山洞，兔子和狐狸各住在其中的一个山洞中。狐狸总想吃掉兔子。某一天兔子就对狐狸说：“你想吃我有一个条件，你把山洞用 1 到 m 进行编号，我躲在其中的一个山洞中，你每次间隔 n (n < 1000) 个山洞找我，而且每个山洞只能找一次，直到还剩最后一个山洞。只要不是在剩最后一个山洞找到我，我就让你吃掉！”

问：兔子躲在哪个山洞能保证不被吃掉？

输入描述
一行输入两个正整数，两个数之间用一个空格分开，分别表示山洞数和间隔数。

输出描述
一个整数，占一行，表示安全的山洞编号。

样例输入
9 5

样例输出
8
*/

#include<iostream>
#include<cstdlib>

using namespace std;

struct node
{
    int data;
    struct node* next;
};

int main()
{
    struct node* head, * p, * q;
    int n, m;
    while (cin >> n >> m)
    {
        head = p = (struct node*)malloc(sizeof(struct node));
        p->data = 1;
        for (int i = 2; i <= n; i++)
        {
            q = (struct node*)malloc(sizeof(struct node));
            q->data = i;
            p->next = q;
            p = q;
        }
        p->next = head;
        q = head;
        while (q->next != q)
        {
            if (m % 2 != 0)
            {
                for (int i = 0; i < m / 2; i++)
                {
                    p = q->next;
                    q = p->next;
                }
                p->next = q->next;
                //cout << q->data << " ";
                free(q);
                q = p->next;
            }
            else if (m % 2 == 0)
            {
                for (int i = 0; i < m / 2 - 1; i++)
                {
                    p = q->next;
                    q = p->next;
                }
                p = q->next;
                q->next = p->next;
                //cout << p->data << " ";
                free(p);
                q = q->next;
            }
        }
        cout << q->data << endl;
    }
    return 0;
}