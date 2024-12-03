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
    std::cout << std::endl;
    print_mass(mass2, size2);
    print_pyramid(mass2, size2);
    std::cout << std::endl;
    print_mass(mass3, size3);
    print_pyramid(mass3, size3);
    std::cout << std::endl;
    return 0;
}
