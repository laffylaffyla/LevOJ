/*
题目描述
上周末，M.A. Ya 教授对古老的玛雅有了一个重大发现。从一个古老的节绳（玛雅人用于记事的工具）中，教授发现玛雅人使用了一个一年有 365 天的叫做 Haab 的历法。这个 Haab 历法拥有 19 个月，在开始的 18 个月，一个月有 20 天，月份的名字分别是 pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu。这些月份中的日期用 0 到 19 表示。Haab 历的最后一个月叫做 uayet，它只有 5 天，用 0 到 4 表示。玛雅人认为这个日期最少的月份是不吉利的，在这个月法庭不开庭，人们不从事交易，甚至没有人打扫屋中的地板。

因为宗教的原因，玛雅人还使用了另一个历法，在这个历法中年被称为 Tzolkin (holly 年)，一年被分成 13 个不同的时期，每个时期有 20 天，每一天用一个数字和一个单词相组合的形式来表示。使用的数字是 1-13，使用的单词共有 20 个，它们分别是：imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau。

注意：年中的每一天都有着明确唯一的描述，比如，在一年的开始，日期如下描述： 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, ，8 imix, 9 ik, 10 akbal …… 也就是说数字和单词各自独立循环使用。

Haab 历和 Tzolkin 历中的年都用数字 0，1，…… 表示，数字 0 表示世界的开始。所以第一天被表示成：

Haab: 0 pop 0

Tzolkin: 1 imix 0

请帮助 M.A. Ya 教授写一个程序可以把 Haab 历转化成 Tzolkin 历。

输入描述
第一行表示要转化的 Haab 历的数据量。下面的每一行表示一个日期。

Haab 历中的数据由如下的方式表示：日期 月份 年数。其中年数小于 5000。

输出描述
每一行表示一个对应的 Tzolkin 历日期。Tzolkin 历中的数据由如下的方式表示： 天数字 天名称 年数。

样例输入
3
10 zac 0
0 pop 0
10 zac 1995

样例输出
3 chuen 0
1 imix 0
9 cimi 2801
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int haabDate, haabYear;
		string haabMonth;
		int data;
		cin >> haabDate >> haabMonth >> haabYear;
		if (haabMonth == "pop")
			data = 0 * 20;
		else if (haabMonth == "no")
			data = 1 * 20;
		else if (haabMonth == "zip")
			data = 2 * 20;
		else if (haabMonth == "zotz")
			data = 3 * 20;
		else if (haabMonth == "tzec")
			data = 4 * 20;
		else if (haabMonth == "xul")
			data = 5 * 20;
		else if (haabMonth == "yoxkin")
			data = 6 * 20;
		else if (haabMonth == "mol")
			data = 7 * 20;
		else if (haabMonth == "chen")
			data = 8 * 20;
		else if (haabMonth == "yax")
			data = 9 * 20;
		else if (haabMonth == "zac")
			data = 10 * 20;
		else if (haabMonth == "ceh")
			data = 11 * 20;
		else if (haabMonth == "mac")
			data = 12 * 20;
		else if (haabMonth == "kankin")
			data = 13 * 20;
		else if (haabMonth == "muan")
			data = 14 * 20;
		else if (haabMonth == "pax")
			data = 15 * 20;
		else if (haabMonth == "koyab")
			data = 16 * 20;
		else if (haabMonth == "cumhu")
			data = 17 * 20;
		else
		{
			cout << "Error";
			system("pause");
			return 0;
		}
		data += haabYear * 365 + haabDate;
		cout << data % 13 + 1 << " ";
		int t = data % 20;
		switch (t)
		{
		case 0:		cout << "imix"; break;
		case 1:		cout << "ik"; break;
		case 2:		cout << "akbal"; break;
		case 3:		cout << "kan"; break;
		case 4:		cout << "chicchan"; break;
		case 5:		cout << "cimi"; break;
		case 6:		cout << "manik"; break;
		case 7:		cout << "lamat"; break;
		case 8:		cout << "muluk"; break;
		case 9:		cout << "ok"; break;
		case 10:	cout << "chuen"; break;
		case 11:	cout << "eb"; break;
		case 12:	cout << "ben"; break;
		case 13:	cout << "ix"; break;
		case 14:	cout << "mem"; break;
		case 15:	cout << "cib"; break;
		case 16:	cout << "caban"; break;
		case 17:	cout << "eznab"; break;
		case 18:	cout << "canac"; break;
		case 19:	cout << "ahau"; break;
		}
		cout << " " << data / 260 << endl;
	}
}