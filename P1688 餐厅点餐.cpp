/*
题目描述
因疫情原因，同学们只能在学校食堂就餐，学校为了保证同学们的就餐，准备了各种食品供大家选择。在学校餐厅，有 a 种汤，b 种饭，c 种面条，d 种荤菜，e 种素菜。为了保证膳食搭配，小王每顿饭都会点 1~2 样荤菜，1~2 样素菜（不重复）。同时，在小王心情好的时候，会点一样饭，再配上一种汤。在心情不好的时候，就只吃一种面条。因为经济有限，小王每次点餐的总价在 min~max 之间。小王想知道，总共有多少种不同的点餐方案。

输入描述
输入数据第一行包含一个整数 T，表示测试数据的组数，对于每组测试数据： 第一行为整数 a,b,c,d,e (0<a,b,c,d,e<=10) 第二行为 a 个大于零的整数，表示 a 种汤的价格 第三行为 b 个大于零的整数，表示 b 种饭的价格 第四行为 c 个大于零的整数，表示 c 种面条的价格 第五行为 d 个大于零的整数，表示 d 种荤菜的价格 第六行为 e 个大于零的整数，表示 e 种素菜的价格 第七行为两个整数 min max, 表示每次点餐的价格范围

输出描述
对于每组测试数据，输出一行，包含一个整数，表示点餐方案数。

样例输入
1
2 2 2 2 2
2 3
3 1
5 2
1 4
3 6
5 8

样例输出
3
*/

#include<iostream>

using namespace std;

int main()
{
	int t;
	int a, b, c, d, e;
	int max, min;
    int count = 0;
    int s1, s2, s3, s4, s5;  //From 0 to the end,traverse.
    int sum;
    int sum1, sum2, sum3, sum4; //Sum at each stage
	cin >> t;
    while (t--)
	{
		cin >> a >> b >> c >> d >> e;
		int* aMenu = new int[a]();
		for (int i = 0; i < a; i++)
			cin >> aMenu[i];

		int* bMenu = new int[b]();
		for (int i = 0; i < b; i++)
			cin >> bMenu[i];

		int* cMenu = new int[c]();
		for (int i = 0; i < c; i++)
			cin >> cMenu[i];

		int* dMenu = new int[d]();
		for (int i = 0; i < d; i++)
			cin >> dMenu[i];

		int* eMenu = new int[e]();
		for (int i = 0; i < e; i++)
			cin >> eMenu[i];
		cin >> min >> max;
        for (s4 = 0; s4 < d; s4++)
        {
            for (int i = s4; i < d; i++)
            {
                if (i == s4)
                    sum1 = dMenu[s4];
                else
                    sum1 = dMenu[s4] + dMenu[i];
                for (s5 = 0; s5 < e; s5++)
                {
                    for (int j = s5; j < e; j++)
                    {
                        if (j == s5)
                            sum2 = eMenu[s5];
                        else
                            sum2 = eMenu[s5] + eMenu[j];
                        for (s2 = 0; s2 < b; s2++)//Good mood
                            for (s1 = 0; s1 < a; s1++)
                            {
                                sum3 = bMenu[s2] + aMenu[s1];
                                sum = sum1 + sum2 + sum3;
                                if (sum >= min && sum <= max)
                                    count++;
                            }
                        for (s3 = 0; s3 < c; s3++)//Bad mood
                        {
                            sum4 = cMenu[s3];
                            int sum = sum1 + sum2 + sum4;
                            if (sum >= min && sum <= max)
                                count++;
                        }
                    }
                }
            }
        }
        cout << count << endl;
        count = 0;
        delete[] aMenu;
        delete[] bMenu;
        delete[] cMenu;
        delete[] dMenu;
        delete[] eMenu;
	}
	return 0;
}