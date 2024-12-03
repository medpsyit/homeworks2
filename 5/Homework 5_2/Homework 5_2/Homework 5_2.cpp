#include <iostream>

void print_pyramid(int* mass, int size)
{
    std::cout << "Пирамида:" << std::endl;
    int lvl{ 0 }, child{ 0 }, children{ 2 };
    std::cout << lvl << " root " << mass[0] << std::endl;
    lvl++;
    for (int count = 0; count < size; count++)
    {
        if (child == children)
        {
            lvl++;
            child = 0;
            children = children * 2;
        }
        if (2 * count + 2 < size)
        {
            std::cout << lvl << " left(" << mass[count] << ") " << mass[2 * count + 1] << std::endl;
            std::cout << lvl << " right(" << mass[count] << ") " << mass[2 * count + 2] << std::endl;
            child = child + 2;
        }
        else if (2 * count + 1 < size)
        {
            std::cout << lvl << " left(" << mass[count] << ") " << mass[2 * count + 1] << std::endl;
            child++;
        }
    }
}

void print_mass(int* mass, int size)
{
    std::cout << "Исходный массив: ";
    for (int count = 0; count < size; count++)
    {
        std::cout << mass[count] << " ";
    }
    std::cout << std::endl;
}

int up(int* mass, int size, int child_index)
{
    if (child_index == 0) { std::cout << "Ошибка! Отсутствует родитель!" << std::endl; return child_index; }
    std::cout << "OK" << std::endl;
    return (child_index - 1) / 2;
}

int left(int* mass, int size, int parent_index)
{
    if (2 * parent_index + 1 >= size) { std::cout << "Ошибка! Отсутствует левый потомок!" << std::endl; return parent_index; }
    std::cout << "OK" << std::endl;
    return 2 * parent_index + 1;
}

int right(int* mass, int size, int parent_index)
{
    if (2 * parent_index + 2 >= size) { std::cout << "Ошибка! Отсутствует правый потомок!" << std::endl; return parent_index; }
    std::cout << "OK" << std::endl;
    return 2 * parent_index + 2;
}

void print_curr(int* mass, int size, int curr_index)
{
    int lvl{ 0 }, index{ 1 }, parent_index{}, child = curr_index;
    if (curr_index == 0) { std::cout << lvl << " root " << mass[curr_index] << std::endl; return; }
    parent_index = (curr_index - 1) / 2;
    while (index != 0)
    {
        index = (child - 1) / 2;
        child = index;
        lvl++;
    }
    if (curr_index % 2 != 0) { std::cout << lvl << " left(" << mass[parent_index] << ") " << mass[curr_index] << std::endl; return; }
    std::cout << lvl << " right(" << mass[parent_index] << ") " << mass[curr_index] << std::endl;
}

void movement(int* mass, int size)
{
    std::string answer{};
    int curr_index{ 0 };
    do
    {
        std::cout << "Вы находитесь здесь: ";
        print_curr(mass, size, curr_index);
        do
        {
            std::cout << "Введите команду: ";
            std::cin >> answer;
            if (answer != "up" && answer != "left" && answer != "right" && answer != "exit")
            {
                std::cout << "Ошибка! Такой команды нет! Попробуйте снова." << std::endl;
            }
        } while (answer != "up" && answer != "left" && answer != "right" && answer != "exit");
        if (answer == "up")
        {
            curr_index = up(mass, size, curr_index);
        }
        else if (answer == "left")
        {
            curr_index = left(mass, size, curr_index);
        }
        else if (answer == "right")
        {
            curr_index = right(mass, size, curr_index);
        }
    } while (answer != "exit");
    std::cout << "Спасибо! Работа окончена." << std::endl;
}


int main()
{
    setlocale(LC_CTYPE, "rus");
    int mass1[]{ 1, 3, 6, 5, 9, 8 };
    int mass2[]{ 94, 67, 18, 44, 55, 12, 6, 42 };
    int mass3[]{ 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    int size1 = sizeof(mass1) / sizeof(mass1[0]);
    int size2 = sizeof(mass2) / sizeof(mass2[0]);
    int size3 = sizeof(mass3) / sizeof(mass3[0]);
    print_mass(mass1, size1);
    print_pyramid(mass1, size1);
    movement(mass1, size1);
    std::cout << std::endl;
    print_mass(mass2, size2);
    print_pyramid(mass2, size2);
    movement(mass2, size2);
    std::cout << std::endl;
    print_mass(mass3, size3);
    print_pyramid(mass3, size3);
    movement(mass3, size3);
    std::cout << std::endl;
    return 0;
}
