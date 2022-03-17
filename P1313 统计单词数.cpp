/*
题目描述
修罗王和邪狼潜入银行盗走了大量的珠宝，警察经过仔细查找和推理，终于找到了装有这批珠宝的保险柜，但无法打开保险柜。经过观察发现保险柜背面有一行字符，且发现只要统计出这行字符串中有多少个单词就是打开保险柜的密码。单词之间由一个或多个空格分开，且字符串不以空格开头。

输入描述
输入一行包含若干空格的字符串，且字符串的长度不超过 1000 个字符。

输出描述
占一行，输出单词数目。

样例输入
How are you?

样例输出
3
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    vector<string> str;
    string temp;

    while (cin >> temp)
    {
        str.push_back(temp);
        if (cin.get() == '\n')
            break;
    }

    cout << str.size() << endl;

    return 0;
}