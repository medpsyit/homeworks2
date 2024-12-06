#include <iostream>
#include <string>
#include <Windows.h>

int real_string_hash(std::string str, int p, int n)
{
    long long sum{ 0 };
    int ans{ 0 };
    int mult{ 1 };
    for (int count = 0; count < str.length(); count++)
    {
        int ch = str[count];
        sum = sum + mult * ch;
        mult = mult * p;
    }
    ans = sum % n;
    return ans;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str{};
    int p{}, n{};
    std::cout << "Введите значение \"p\" (простое число): ";
    std::cin >> p;
    std::cout << "Введите значение \"n\" (модуль): ";
    std::cin >> n;
    do
    {
        std::cout << "Введите строку (для выхода введите \"exit\"): ";
        std::cin >> str;
        std::cout << "Хэш строки \"" << str << "\" = " << real_string_hash(str, p, n) << std::endl;
    } while (str != "exit");
    return 0;
}