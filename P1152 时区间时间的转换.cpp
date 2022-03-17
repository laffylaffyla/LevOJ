/*
题目描述
直到 19 世纪，时间校准是一个纯粹的地方现象。每一个村庄当太阳升到最高点的时候把他们的时钟调到中午 12 点。一个钟表制造商人家或者村里主表的时间被认为是官方时间，市民们把自家的钟表和这个时间对齐。每周一些热心的市民会带着时间标准的表，游走大街小巷为其他市民对表。在城市之间旅游的话，在到达新地方的时候需要把怀表校准。但是，当铁路投入使用之后，越来越多的人频繁地长距离地往来，时间变得越来越重要。在铁路的早期，时刻表非常让人迷惑，每一个所谓的停靠时间都是基于停靠地点的当地时间。时间的标准化对于铁路的高效运营变得非常重要。

在 1878 年，加拿大人 Sir Sanford Fleming 提议使用一个全球的时区（这个建议被采纳，并衍生了今天我们所使用的全球时区的概念）。他建议把世界分成 24 个时区，每一个跨越 15 度经线（因为地球的经度 360 度，划分成 24 块后，一块为 15 度）。Sir Sanford Fleming 的方法解决了一个全球性的时间混乱的问题。美国铁路公司于 1883 年 11 月 18 日使用了 Fleming 提议的时间方式。1884 年一个国际子午线会议在华盛顿召开，会议的目的是选择一个合适的本初子午线。大会最终选定了格林尼治为标准的 0 度。尽管时区被确定了下来，但是各个国家并没有立刻更改他们的时间规范。在美国，尽管到 1895 年已经有很多州开始使用标准时区时间，而国会直到 1918 年才强制使用会议制定的时间规范。今天，各个国家使用的是一个 Fleming 时区规范的一个变种。中国一共跨越了 5 个时区，但是使用了一个统一的时间规范，比 Coordinated Universal Time（UTC，格林尼治时间）早 8 个小时；俄罗斯也拥护这个时区规范，尽管整个国家使用的时间和标准时区提前了 1 个小时；澳大利亚使用 3 个时区，其中主时区提前于 Fleming 规范的时区半小时。很多中东国家也使用了半时时区（即不是按照 Fleming 的 24 个整数时区）。因为时区是对经度进行划分，在南极或者北极工作的科学家直接使用了 UTC 时间，否则南极大陆将被分解成 24 个时区。

时区间的转化表如下：

UTC (Coordinated Universal Time), 定义为 UTC
GMT(Greenwich Mean Time), 定义为 UTC
BST (British Summer Time), 定义为 UTC+1 hour
IST (Irish Summer Time), 定义为 UTC+1 hour
WET (Western Europe Time), 定义为 UTC
WEST (Western Europe Summer Time), 定义为 UTC+1 hour
CET (Central Europe Time), 定义为 UTC+1 hour
CEST (Central Europe Summer Time), 定义为 UTC+2 hours
EET (Eastern Europe Time), 定义为 UTC+2 hours
EEST (Eastern Europe Summer Time), 定义为 UTC+3 hours
MSK (Moscow Time), 定义为 UTC+3 hours
MSD (Moscow Summer Time), 定义为 UTC+4 hours
AST (Atlantic Standard Time), 定义为 UTC-4 hours
ADT (Atlantic Daylight Time), 定义为 UTC-3 hours
NST (Newfoundland Standard Time), 定义为 UTC-3.5 hours
NDT (Newfoundland Daylight Time), 定义为 UTC-2.5 hours
EST (Eastern Standard Time), 定义为 UTC-5 hours
EDT (Eastern Daylight Saving Time), 定义为 UTC-4 hours
CST (Central Standard Time), 定义为 UTC-6 hours
CDT (Central Daylight Saving Time), 定义为 UTC-5 hours
MST (Mountain Standard Time), 定义为 UTC-7 hours
MDT (Mountain Daylight Saving Time), 定义为 UTC-6 hours
PST (Pacific Standard Time), 定义为 UTC-8 hours
PDT (Pacific Daylight Saving Time), 定义为 UTC-7 hours
HST (Hawaiian Standard Time), 定义为 UTC-10 hours
AKST (Alaska Standard Time), 定义为 UTC-9 hours
AKDT (Alaska Standard Daylight Saving Time), 定义为 UTC-8 hours
AEST (Australian Eastern Standard Time), 定义为 UTC+10 hours
AEDT (Australian Eastern Daylight Time), 定义为 UTC+11 hours
ACST (Australian Central Standard Time), 定义为 UTC+9.5 hours
ACDT (Australian Central Daylight Time), 定义为 UTC+10.5 hours
AWST (Australian Western Standard Time), 定义为 UTC+8 hours
下面给出了一些时间，请在不同时区之间进行转化。

输入描述
输入的第一行包含了一个整数 N，表示有 N 组测试数据。

接下来 N 行，每一行包括一个时间和两个时区的缩写，它们之间用空格隔开。时间由标准的 a.m./p.m 给出。midnight 表示晚上 12 点（12:00 a.m.），noon 表示中午 12 点（12:00 p.m.）。

输出描述
假设输入行给出的时间是在第一个时区中的标准时间，要求输出这个时间在第二个时区中的标准时间。

样例输入
4
noon HST CEST
11:29 a.m. EST GMT
6:01 p.m. CST UTC
12:40 p.m. ADT MSK

样例输出
midnight
4:29 p.m.
12:1 a.m.
6:40 p.m.
*/

#include<iostream>
#include<string>

using namespace std;

double timeZoneTable(string);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string currentTime, timeZoneBeforeConversion, timeZoneAfterConversion, amOrPm;
		int t;
		cin >> currentTime;
		if (currentTime[0] == 'n')
			t = 12 * 60;
		else if (currentTime[0] == 'm')
			t = 24 * 60;
		else
		{
			if (currentTime[1] == ':')
				t = (currentTime[0] - '0') * 60 + (currentTime[2] - '0') * 10 + (currentTime[3] - '0');
			else
				t = ((currentTime[0] - '0') * 10 + (currentTime[1] - '0')) * 60 + (currentTime[3] - '0') * 10 + (currentTime[4] - '0');
			if (t / 60 == 12)
				t -= 12 * 60;
			cin >> amOrPm;
			if (amOrPm[0] == 'p')
				t += 12 * 60;
		}
		cin >> timeZoneBeforeConversion >> timeZoneAfterConversion;
		t += (int)((timeZoneTable(timeZoneAfterConversion) - timeZoneTable(timeZoneBeforeConversion)) * 60);
		if (t <= 0)
			t += 24 * 60;
		if (t > 24 * 60)
			t -= 24 * 60;
		if (t == 12 * 60)
			cout << "noon" << endl;
		else if (t == 24 * 60)
			cout << "midnight" << endl;
		else
		{
			amOrPm = "a.m.";
			if (t >= 12 * 60)
			{
				t -= 12 * 60;
				amOrPm[0] = 'p';
			}
			if (t < 60)
				t += 12 * 60;
			cout << t / 60 << ":" << t % 60 << " " << amOrPm << endl;
		}
	}
	return 0;
}

double timeZoneTable(string s)
{
	if (s == "UTC")	return 0.0;
	if (s == "GMT")	return 0.0;
	if (s == "BST")	return 1.0;
	if (s == "IST")	return 1.0;
	if (s == "WET")	return 0.0;
	if (s == "WEST") return 1.0;
	if (s == "CET")	return 1.0;
	if (s == "CEST") return 2.0;
	if (s == "EET")	return 2.0;
	if (s == "EEST") return 3.0;
	if (s == "MSK")	return 3.0;
	if (s == "MSD")	return 4.0;
	if (s == "AST")	return -4.0;
	if (s == "ADT")	return -3.0;
	if (s == "NST")	return -3.5;
	if (s == "NDT")	return -2.5;
	if (s == "EST")	return -5.0;
	if (s == "EDT")	return -4.0;
	if (s == "CST")	return -6.0;
	if (s == "CDT")	return -5.0;
	if (s == "MST")	return -7.0;
	if (s == "MDT")	return -6.0;
	if (s == "PST")	return -8.0;
	if (s == "PDT")	return -7.0;
	if (s == "HST")	return -10.0;
	if (s == "AKST") return -9.0;
	if (s == "AKDT") return -8.0;
	if (s == "AEST") return 10.0;
	if (s == "AEDT") return 11.0;
	if (s == "ACST") return 9.5;
	if (s == "ACDT") return 10.5;
	if (s == "AWST") return 8.0;
}