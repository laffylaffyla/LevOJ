#include<iostream>
#include<math.h>
using namespace std;
int main() 
{
	int n;
	cin >> n;
	while (n--) 
	{
		int a, b, i;
		cin >> a >> b;
		for (i = min(a, b); i >= 2; i--)
			if (a % i == 0 && b % i == 0) break;
		cout << i << endl;
	}
	return 0;
}