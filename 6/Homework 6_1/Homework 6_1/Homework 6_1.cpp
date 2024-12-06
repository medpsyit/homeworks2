#include <iostream>
#include <string>
#include <Windows.h>

int simple_string_hash(std::string str)
{
    int sum{ 0 };
    for (int count = 0; count < str.length(); count++)
    {
        int ch = str[count];
        sum = sum + ch;
    }
    return sum;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string str{};
    do
    {
        std::cout << "Введите строку (для выхода введите \"exit\"): ";
        std::cin >> str;
        std::cout << "Наивный хэш строки \"" << str << "\": " << simple_string_hash(str) << std::endl;
    } while (str != "exit");
    return 0;
}
