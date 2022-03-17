/*
题目描述
莫尔斯电码表示方式为：

    a/A .-
    b/B -...
    c/C -.-.
    d/D -..
    e/E .
    f/F ..-.
    g/G --.
    h/H ....
    i/I ..
    j/J .---
    k/K -.-
    l/L .-..
    m/M --
    n/N -.
    o/O ---
    p/P .--.
    q/Q --.-
    r/R .-.
    s/S ...
    t/T -
    u/U ..-
    v/V ...-
    w/W .--
    x/X -..-
    y/Y -.--
    z/Z --..
    0 .----
    1 ..---
    2 ...--
    3 ....-
    4 .....
    5 -....
    6 --...
    7 ---..
    8 ----.
    9 -----
其中字母部分不区分大小写。任务要求是将输入的字符串 (测试数据中所有的字母字符均为大写字母，无须再做判断，且长度小于等于 100) 转换成莫尔斯电码，每个电码间用 "===" 分割开来

输入描述
每行输入大写字母和数字构成的符号串，长度小于等于 100，没有分隔符

输出描述
对应的莫尔斯电码，每个莫尔斯码都用 "===" 隔开

样例输入
ABCD123456EFG

样例输出
.-===-...===-.-.===-..===..---===...--===....-===.....===-....===--...===.===..-.===--.
*/

#include<iostream>
#include<string>

using namespace std;

int main()
{
	string input, output;
	while (cin >> input)
	{
		for (int i = 0; i < input.size(); i++)
		{
			switch (input[i])
			{
			case 'A':
				output += ".-";
				output += "===";
				break;
			case 'B':
				output += "-...";
				output += "===";
				break;
			case 'C':
				output += "-.-.";
				output += "===";
				break;
			case 'D':
				output += "-..";
				output += "===";
				break;
			case 'E':
				output += ".";
				output += "===";
				break;
			case 'F':
				output += "..-.";
				output += "===";
				break;
			case 'G':
				output += "--.";
				output += "===";
				break;
			case 'H':
				output += "....";
				output += "===";
				break;
			case 'I':
				output += "..";
				output += "===";
				break;
			case 'J':
				output += ".---";
				output += "===";
				break;
			case 'K':
				output += "-.-";
				output += "===";
				break;
			case 'L':
				output += ".-..";
				output += "===";
				break;
			case 'M':
				output += "--";
				output += "===";
				break;
			case 'N':
				output += "-.";
				output += "===";
				break;
			case 'O':
				output += "---";
				output += "===";
				break;
			case 'P':
				output += ".--.";
				output += "===";
				break;
			case 'Q':
				output += "--.-";
				output += "===";
				break;
			case 'R':
				output += ".-.";
				output += "===";
				break;
			case 'S':
				output += "...";
				output += "===";
				break;
			case 'T':
				output += "-";
				output += "===";
				break;
			case 'U':
				output += "..-";
				output += "===";
				break;
			case 'V':
				output += "...-";
				output += "===";
				break;
			case 'W':
				output += ".--";
				output += "===";
				break;
			case 'X':
				output += "-..-";
				output += "===";
				break;
			case 'Y':
				output += "-.--";
				output += "===";
				break;
			case 'Z':
				output += "--..";
				output += "===";
				break;
			case '0':
				output += ".----";
				output += "===";
				break;
			case '1':
				output += "..---";
				output += "===";
				break;
			case '2':
				output += "...--";
				output += "===";
				break;
			case '3':
				output += "....-";
				output += "===";
				break;
			case '4':
				output += ".....";
				output += "===";
				break;
			case '5':
				output += "-....";
				output += "===";
				break;
			case '6':
				output += "--...";
				output += "===";
				break;
			case '7':
				output += "---..";
				output += "===";
				break;
			case '8':
				output += "----.";
				output += "===";
				break;
			case '9':
				output += "-----";
				output += "===";
				break;
			default:
				break;
			}
		}
		output.pop_back(); 
		output.pop_back(); 
		output.pop_back();
		cout << output << endl;
		output.clear();
	}
	return 0;
}