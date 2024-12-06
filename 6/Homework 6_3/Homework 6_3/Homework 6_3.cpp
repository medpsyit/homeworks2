#include <iostream>
#include <string>
#include <Windows.h>

int find_substring_light_rabin_karp(std::string base_str, std::string sub_str);

int simple_string_hash(std::string str);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string base_str{}, sub_str{};
    std::cout << "Введите строку, в которой будет осуществляться поиск: ";
    std::cin >> base_str;
    do
    {
        std::cout << "Введите подстроку, которую нужно найти: ";
        std::cin >> sub_str;
        std::cout << "Подстрока \"" << sub_str << "\" ";
        if (find_substring_light_rabin_karp(base_str, sub_str) == -1)
        {
            std::cout << "не найдена." << std::endl;
        }
        else
        {
            std::cout << "найдена по индексу \"" << find_substring_light_rabin_karp(base_str, sub_str) << "\"." << std::endl;
        }
    } while (sub_str != "exit");
    return 0;
}

int find_substring_light_rabin_karp(std::string base_str, std::string sub_str)
{
    int base_hash{ 0 };
    int sub_hash = simple_string_hash(sub_str);
    for (int count = 0; count < base_str.length() - sub_str.length() + 1; count++)
    {
        if (count == 0)
        {
            for (int count2 = 0; count2 < sub_str.length(); count2++)
            {
                int ch = base_str[count2];
                base_hash = base_hash + ch;
            }
        }
        else
        {
            base_hash = base_hash - base_str[count - 1] + base_str[count + sub_str.length() - 1];
        }
        if (base_hash == sub_hash)
        {
            for (int count3 = 0; count3 < sub_str.length(); count3++)
            {
                if (base_str[count + count3] == sub_str[count3])
                {
                    return count;
                }
            }
        }
    }
    return -1;
}

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