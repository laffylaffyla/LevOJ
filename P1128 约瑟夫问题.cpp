/*
题目描述
已知 n 个人（编号分别为 1、2、3，……、n）围坐在一张圆桌周围，从编号为 1 的人开始报数，数到 m 的那个人出列；他的下一个人又从 1 开始报数，数到 m 的那个人又出列，依次规律重复下去，直到圆桌周围的人全部出列

输入描述
一行：人数 n 和间隔数 m

输出描述
出列顺序，每个编号之间用一个空格分开

样例输入
9 5

样例输出
5 1 7 4 3 6 9 2 8
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
                cout << q->data << " ";
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
                cout<<p->data<<" ";
                free(p);
                q = q->next;
            }
        }
        cout << q->data << endl;
    }
    return 0;
}