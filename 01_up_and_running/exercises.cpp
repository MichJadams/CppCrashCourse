#include <cstdio>

int absolute_value(int num)
{
    if(num < 0)
    {
        return -num;
    }
    return num;
}

int main()
{
    int result1 = absolute_value(0);

    printf("%d", result1);
}