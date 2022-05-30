/* 您需要写一种数据结构，来维护一些数，其中需要提供以下操作：

插入 x 数
删除 x 数 (若有多个相同的数，因只删除一个)
查询 x 数的排名 (排名定义为比当前数小的数的个数 +1)
查询排名为 x 的数
求 x 的前驱 (前驱定义为小于 x，且最大的数)
求 x 的后继 (后继定义为大于 x，且最小的数)

输入描述

第一行为 n，表示操作的个数，下面 n 行每行有两个数 opt 和 x，opt 表示操作的序号 ( 1≤opt≤6)
1≤n≤10^5，∣x∣≤10^7


输出描述

对于操作 3,4,5,6 每行输出一个数，表示对应答案

样例输入

10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
样例输出

106465
84185
492737 */

#include <iostream>

using namespace std;

const int N = 100005;

struct Splay
{
    int rt, tot, fa[N], ch[N][2], val[N], cnt[N], sz[N];
    inline void init()
    {
        rt = tot = 0;
    }
    inline void maintain(int x)
    {
        sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
    }
    inline bool get(int x)
    {
        return x == ch[fa[x]][1];
    }
    inline void clear(int x)
    {
        ch[x][0] = ch[x][1] = fa[x] = val[x] = sz[x] = cnt[x] = 0;
    }
    inline void rotate(int x)
    {
        int y = fa[x], z = fa[y], chk = get(x);
        ch[y][chk] = ch[x][chk ^ 1];
        fa[ch[x][chk ^ 1]] = y;
        ch[x][chk ^ 1] = y;
        fa[y] = x;
        fa[x] = z;
        if (z)
            ch[z][y == ch[z][1]] = x;
        maintain(x);
        maintain(y);
    }
    void splay(int x)
    {
        for (int f = fa[x]; f = fa[x], f; rotate(x))
            if (fa[f])
                rotate(get(x) == get(f) ? f : x);
        rt = x;
    }
    void ins(int x)
    {
        if (!rt)
        {
            val[++tot] = x;
            cnt[tot]++;
            rt = tot;
            maintain(rt);
            return;
        }
        int now = rt, f = 0;
        while (1)
        {
            if (val[now] == x)
            {
                cnt[now]++;
                maintain(now);
                maintain(f);
                splay(now);
                break;
            }
            f = now;
            now = ch[now][val[now] < x];
            if (!now)
            {
                val[++tot] = x;
                cnt[tot]++;
                fa[tot] = f;
                ch[f][val[f] < x] = tot;
                maintain(tot);
                maintain(f);
                splay(tot);
                break;
            }
        }
    }
    int rk(int x)
    {
        int res = 0, now = rt;
        while (1)
        {
            if (x < val[now])
                now = ch[now][0];
            else
            {
                res += sz[ch[now][0]];
                if (x == val[now])
                {
                    splay(now);
                    return res + 1;
                }
                res += cnt[now];
                now = ch[now][1];
            }
        }
    }
    int kth(int k)
    {
        int now = rt;
        while (1)
        {
            if (ch[now][0] && k <= sz[ch[now][0]])
                now = ch[now][0];
            else
            {
                k -= cnt[now] + sz[ch[now][0]];
                if (k <= 0)
                {
                    splay(now);
                    return val[now];
                }
                now = ch[now][1];
            }
        }
    }
    int pre()
    {
        int now = ch[rt][0];
        while (ch[now][1])
            now = ch[now][1];
        splay(now);
        return now;
    }
    int nxt()
    {
        int now = ch[rt][1];
        while (ch[now][0])
            now = ch[now][0];
        splay(now);
        return now;
    }
    void del(int k)
    {
        rk(k);
        if (cnt[rt] > 1)
        {
            cnt[rt]--;
            maintain(rt);
            return;
        }
        if (!ch[rt][0] && !ch[rt][1])
        {
            clear(rt);
            rt = 0;
            return;
        }
        if (!ch[rt][0])
        {
            int now = rt;
            rt = ch[rt][1];
            fa[rt] = 0;
            clear(now);
            return;
        }
        if (!ch[rt][1])
        {
            int now = rt;
            rt = ch[rt][0];
            fa[rt] = 0;
            clear(now);
            return;
        }
        int now = rt;
        int x = pre();
        splay(x);
        fa[ch[now][1]] = x;
        ch[x][1] = ch[now][1];
        clear(now);
        maintain(rt);
    }
} tree;

int main()
{
    int n, opt, x;
    cin >> n;
    while (n--)
    {
        cin >> opt >> x;
        if (opt == 1)
            tree.ins(x);
        else if (opt == 2)
            tree.del(x);
        else if (opt == 3)
            cout << tree.rk(x) << endl;
        else if (opt == 4)
            cout << tree.kth(x) << endl;
        else if (opt == 5)
            tree.ins(x), cout << tree.val[tree.pre()] << endl, tree.del(x);
        else
            tree.ins(x), cout << tree.val[tree.nxt()] << endl, tree.del(x);
    }
    return 0;
}