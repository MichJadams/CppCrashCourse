#include <cstdio>

int absolute_value(int num)
{
    if(num < 0)
    {
        return -num;
    }
    return num;
}

int sum(int num1, int num2)
{
    return num1 + num2;
}

int main()
{
    int result1 = sum(-10, 1);

    printf("%d", result1);

    return 0;
}