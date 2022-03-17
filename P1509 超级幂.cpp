/*
��Ŀ����
���������� a, b������ b ���󡣼��� a �� b �η��� 1337 ȡģ�Ľ�������ݱ�֤ a �� int ��Χ�ڣ�b С�� 100 λ��

��������
ÿ�������������зֱ��ʾ a �� b��

�������
ÿ���������һ�б�ʾ��a �� b �η��� 1337 ȡģ�Ľ����

��������
2
3

�������
8
*/

#include<iostream>
#include<string>
#include<cstring>
#define BASE 1337

using namespace std;

int mypow(int, int);
int superPow(int, string);

//ԭ��:Diffie-Hellman Key Exchange

int main()
{
	int a;
	string b;
	while (cin >> a >> b)
	{
        cout << superPow(a, b) << endl;
	}
    return 0;
}

// ���� a �� k �η�Ȼ���� base ��ģ�Ľ��
int mypow(int a, int k)
{
    // ��������ģ
    a %= BASE;
    int res = 1;
    for (int i = 0; i < k; i++)
    {
        // �����г˷�����Ǳ�ڵ������
        res *= a;

        // �Գ˷������ģ
        res %= BASE;
    }
    return res;
}

int superPow(int a, string b)
{
    if (b.empty())
        return 1;
    //�ַ����д���ASCII��
    int last = b.back() - 48;
    b.pop_back();

    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);

    // ÿ�γ˷���Ҫ��ģ
    return (part1 * part2) % BASE;
}

/*
��Ȩ����������ΪCSDN������wolf������ԭ�����£���ѭCC 4.0 BY - SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/wolfGuiDao/article/details/105865221
*/