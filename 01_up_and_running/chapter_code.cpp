#include <cstdio>

int step_function(int x)
{
    int result = 0;

    if (x < 0)
    {
        result = -1;
    }
    else if (x > 0)
    {
        result = 1;
    }
    return result;
}

int main()
{
    int num1 = 43;
    int result1 = step_function(num1);

    int num2 = 1; 
    int result2 = step_function(num2);
    
    int num3 = -32454;
    int result3 = step_function(num3);

    printf("num1: %d, step %d", num1, result1);
    printf("num1: %d, step %d", num2, result2);
    printf("num1: %d, step %d", num3, result3);

}