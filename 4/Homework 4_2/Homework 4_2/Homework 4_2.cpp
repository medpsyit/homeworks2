#include <iostream>

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

    void append(int addedNum)
    {
        int data_size = _msize(data) / sizeof(*data);
        if (last == data_size)
        {
            int* new_data = new int[2 * data_size] {0};
            for (int count = 0; count < last + 1; count++)
            {
                new_data[count] = data[count];
            }
            data = new_data;
            size = 2 * data_size;
        }
        data[last] = addedNum;
        last++;
    }
};

int main()
{
    setlocale(LC_CTYPE, "rus");
    int actual_size{}, logical_size{}, num{};
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
        std::cout << "Динамический массив: ";
        arr.print_dynamic_array();
        std::cout << "\nВведите элемент для добавления (для выхода введите \"0\"): ";
        std::cin >> num;
        if (num == 0) { break; }
        arr.append(num);
    } while (num != 0);
    std::cout << "Спасибо! Ваш массив: ";
    arr.print_dynamic_array();
    return 0;
}