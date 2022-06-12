#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a;
    while (true)
    {
        cin >> a;
        if (!a)
            break;
        printf("%o\n", a);
    }
    return 0;
}