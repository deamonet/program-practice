#include <stdio.h>
#include <iostream>
#include <iomanip>

using namespace std;

int test(void)
{
    int a = 0;
    int b = 1;
    return a || b;
}

int main(void)
{
    int c = test();
    cout<<c;
}