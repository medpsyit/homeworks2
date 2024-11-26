#include <iostream>
#include <Windows.h>

class DynamicArray
{
private:
    int last{ -1 }, size{ 0 };
    int* data = new int[size] {0};
public:
    DynamicArray(int logical_size, int actual_size)
    {
        size = actual_size;
        data = new int[size];
        last = logical_size;
    }

    int get_size() { return size; }

    void print_dynamic_array()
    {
        for (int count = 0; count < last; count++)
        {
            std::cout << data[count] << " ";
        }
        for (int count = last; count < size; count++)
        {
            std::cout << "_ ";
        }
    }

    void write_to_array()
    {
        int num{};
        for (int count = 0; count < last; count++)
        {
            std::cout << "Введите arr[" << count << "]: ";
            std::cin >> num;
            data[count] = num;
        }
    }

    void remove()
    {
        --last;
        int data_size = _msize(data) / sizeof(*data);
        if (last <= data_size / 3)
        {
            int* new_data = new int[data_size / 3] {0};
            for (int count = 0; count < last; count++)
            {
                new_data[count] = data[count + 1];
            }
            data = new_data;
            size = data_size / 3;
        }
        else
        {
            for (int count = 0; count < last; count++)
            {
                data[count] = data[count + 1];
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int actual_size{}, logical_size{};
    std::string ans{};
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
    DynamicArray arr(logical_size, actual_size);
    arr.write_to_array();
    do
    {
        if (arr.get_size() <= 0) { std::cout << "Невозможно удалить первый элемент, так как массив пустой. До свидания!"; return 0; }
        std::cout << "Динамический массив: ";
        arr.print_dynamic_array();
        std::cout << "\nУдалить первый элемент? ";
        std::cin >> ans;
        if (ans == "нет" || ans == "-") { break; }
        arr.remove();
    } while (ans != "нет" && ans != "-");
    if (arr.get_size() > 0)
    {
        std::cout << "Спасибо! Ваш массив: ";
        arr.print_dynamic_array();
    }
    return 0;
}
