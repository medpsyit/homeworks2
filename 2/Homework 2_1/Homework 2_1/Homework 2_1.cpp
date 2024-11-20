#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    std::cout << fibonacci(5) << " " << fibonacci(10) << " " << fibonacci(15) << std::endl;
    return 0;
}
