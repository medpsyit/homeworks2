#include <iostream>

int scan(int* arr, int size, int point)
{
    int left = 0;
    int right = size - 1;
    int count = 0;
    while (left <= right)
    {
        int middle = (left + right) / 2;
        if (arr[middle] > point)
        {
            count =+ size - middle;
            right = middle - 1;
        }
        else if (arr[middle] <= point)
        {
            left = middle + 1;
        }
    }
    return count;
}


int main()
{
    setlocale(LC_CTYPE, "rus");
    int arr[]{ 14, 16, 19, 32, 32, 32, 56, 69, 72 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int point{ 0 };
    std::cout << "Введите точку отсчёта: ";
    std::cin >> point;
    std::cout << "Количество элементов в массиве больших, чем " << point << ": " << scan(arr, size, point) << std::endl;
    return 0;
}
