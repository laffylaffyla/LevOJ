#include <iostream>
#include <stdlib.h> 
#include <string.h>
using namespace std;
char* addChar(char* add1, char* add2, char* sum, int* carry);
int main()
{
	char num[40] = {};

	char num2[40] = {};

	char sum[40] = {};

	cin >> num;
	cin >> num2;


	//数字进行对齐
	if (strlen(num) == strlen(num2))
	{
		int carry = 0;
		addChar(num, num2, num, &carry);
		cout << num;
		return 0;
	}

	if (strlen(num) > strlen(num2))
	{
		//num大 
		int sub = strlen(num) - strlen(num2);
		int carry = 0;
		char* p = num + sub;
		addChar(num2, p, p, &carry);
		cout << num << endl;

	}
	else
	{
		int sub = strlen(num2) - strlen(num);
		int carry = 0;
		char* p = num2 + sub;
		addChar(num, p, p, &carry);
		cout << num2 << endl;
	}
}
//相加 
char* addChar(char* add1, char* add2, char* sum, int* carry)
{
	if (strlen(add1) == strlen(add2))
	{
		for (int i = strlen(add1) - 1; i >= 0; i--)
		{
			//48-57
			sum[i] = add1[i] + add2[i] - 48 + *carry;
			if (sum[i] > 57)
			{
				sum[i] -= 10;
				*carry = 1;
			}
			else
			{
				*carry = 0;
			}

		}
		return sum;
	}
	else
	{
		cout << "erro ,无法相加" << endl;
		return NULL;
	}

}