#include <iostream>

int fibonacci(int n)
{
    int* memo = new int[n] { 1, 1 };
    for (int count = 2; count < n; count++)
    {
        memo[count] = memo[count - 2] + memo[count - 1];
    }
    return memo[n - 1];
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::cout << fibonacci(5) << " " << fibonacci(10) << " " << fibonacci(15) << std::endl;
    return 0;
}