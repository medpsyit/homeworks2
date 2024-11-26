#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    std::cout << "Динамический массив: ";
    for (int count = 0; count < logical_size; count++)
    {
        std::cout << arr[count] << " ";
    }
    for (int count = logical_size; count < actual_size; count++)
    {
        std::cout << "_ ";
    }
}

void write_to_array(int* arr, int logical_size)
{
    int num{};
    for (int count = 0; count < logical_size; count++)
    {
        std::cout << "Введите arr[" << count << "]: ";
        std::cin >> num;
        arr[count] = num;
    }
}

int main()
{
    setlocale(LC_CTYPE, "rus");
    int actual_size{}, logical_size{};
    std::cout << "Введите фактический размер массива: ";
    std::cin >> actual_size;
    do
    {
        std::cout << "Введите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size)
        {
            std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        }
    } while (logical_size > actual_size);
    int* arr = new int[actual_size];
    write_to_array(arr, logical_size);
    print_dynamic_array(arr, logical_size, actual_size);
    delete[] arr;
    return 0;
}
