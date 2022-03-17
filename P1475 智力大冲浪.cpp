/*
题目描述

小伟报名参加中央电视台的智力大冲浪节目。本次挑战赛吸引了众多参赛者，主持人为了表彰大家的勇气，先奖励每个参赛者 m 元。先不要太高兴！因为这些钱还不一定都是你的？！接下来主持人宣布了比赛规则：首先，比赛时间分为 n 个时段 (n≤500)，它又给出了很多小游戏，每个小游戏都必须在规定期限 ti 前完成 (1≤ti≤n)。如果一个游戏没能在规定期限前完成，则要从奖励费 m 元中扣去一部分钱 wi，wi 为自然数，不同的游戏扣去的钱是不一样的。当然，每个游戏本身都很简单，保证每个参赛者都能在一个时段内完成，而且都必须从整时段开始。主持人只是想考考每个参赛者如何安排组织自己做游戏的顺序。作为参赛者，小伟很想赢得冠军，当然更想赢取最多的钱！注意：比赛绝对不会让参赛者赔钱！

输入描述
多组输入，每组共 4 行，
第 1 行为 m，表示一开始奖励给每位参赛者的钱；
第 2 行为 n，表示有 n 个小游戏；
第 3 行有 n 个数，分别表示游戏 1 到 n 的规定完成期限；
第 4 行有 n 个数，分别表示游戏 1 到 n 不能在规定期限前完成的扣款数。

输出描述
对于每组输入，仅 1 行，表示小伟能赢取最多的钱

样例输入

10000
7
4 2 4 3 1 4 6
70 60 50 40 30 20 10

样例输出

9950
*/

#include <iostream>
#include <algorithm>

using namespace std;

struct game
{
    int ti, wi;
} arr[502];

int cmp(const game &a, const game &b)
{
    return a.wi > b.wi;
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {

        for (int i = 1; i <= n; i++)
            cin >> arr[i].ti;
        for (int i = 1; i <= n; i++)
            cin >> arr[i].wi;
        bool *schedule = new bool[502]();
        sort(arr + 1, arr + n + 1, cmp);
        int fine = 0;
        for (int i = 1; i <= n; i++)
        {
            bool flag = false;
            for (int j = arr[i].ti; j; j--)
            {
                if (!schedule[j])
                {
                    schedule[j] = true;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                for (int j = n; j; j--)
                {
                    if (!schedule[j])
                    {
                        schedule[j] = true;
                        break;
                    }
                }
                m -= arr[i].wi;
            }
        }
        cout << m << endl;
        delete[] schedule;
    }
    return 0;
}