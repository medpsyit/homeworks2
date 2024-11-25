#include <iostream>

void count_sort(int* arr, int size);

void print_array(int* arr, int size);

void print_interface(int* arr, int size);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int arr1[]{ 19, 14, 22, 22, 17, 22, 13, 21, 20, 24, 18, 10, 17, 16, 17, 20, 22, 11, 20, 16, 14, 13, 10, 22, 18, 14, 16, 24, 19, 17 };
    int arr2[]{ 16, 17, 14, 20, 22, 20, 17, 22, 16, 19, 23, 24, 20, 22, 21, 18, 14, 16, 17, 21, 10, 11, 19, 23, 11, 11, 17, 17, 11, 21, 17, 11, 17, 16, 12, 11, 16, 22, 23, 16 };
    int arr3[]{ 21, 15, 19, 18, 23, 12, 18, 18, 19, 23, 12, 20, 15, 22, 21, 18, 19, 20, 12, 16, 20, 14, 17, 13, 10, 23, 19, 14, 10, 22, 19, 12, 24, 23, 22, 15, 13, 22, 18, 18, 11, 23, 24, 17, 10 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    print_interface(arr1, size1);
    print_interface(arr2, size2);
    print_interface(arr3, size3);
    return 0;
}

void count_sort(int* arr, int size)
{
    int* counts = new int[(24 - 10) + 1]{0};
    for (int count = 0; count < size; count++)
    {
        counts[arr[count] - 10] += 1;
    }
    int c{ 0 };
    for (int count = 0; count < size; count++)
    {
        while (counts[c] == 0)
        {
            c++;
        }
        arr[count] = c + 10;
        counts[c]--;
    }
    delete[] counts;
}

void print_array(int* arr, int size)
{
    for (int count = 0; count < size; count++)
    {
        std::cout << arr[count] << " ";
    }
}

void print_interface(int* arr, int size)
{
    std::cout << "Исходный массив: ";
    print_array(arr, size);
    count_sort(arr, size);
    std::cout << "\nОтсортированный массив: ";
    print_array(arr, size);
    std::cout << '\n' << std::endl;
}