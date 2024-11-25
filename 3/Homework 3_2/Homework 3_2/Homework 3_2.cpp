#include <iostream>


void quick_sort(int* arr, int size);

int pivoting(int* arr, int size, int pi);

void print_array(int* arr, int size);

void print_interface(int* arr, int size);

int main()
{
    setlocale(LC_CTYPE, "rus");
    int* arr1 = new int[10] { 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
    int* arr2 = new int[15] { 88, 91, 87, 59, 53, 49, 29, 16, 4, 27, 28, 89, 2, 25, 74 };
    int* arr3 = new int[18] { 24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62 };
    print_interface(arr1, 10);
    print_interface(arr2, 15);
    print_interface(arr3, 18);
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
    return 0;
}

void quick_sort(int* arr, int size)
{
    if (size == 1) { return; }
    int pi{ size / 2 };
    int border = pivoting(arr, size, pi);
    quick_sort(arr, border);
    quick_sort(&arr[border], size - border);
}

int pivoting(int* arr, int size, int pi)
{
    int left{ 0 }, right{ size - 1 }, pivot{ arr[pi] };
    while (true)
    {
        while (arr[left] < pivot) { left += 1; }
        while (arr[right] > pivot) { right -= 1; }
        if (left >= right) { return left; }
        int temp{ arr[left] };
        arr[left] = arr[right];
        arr[right] = temp;
        left += 1;
        right -= 1;
    }
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
    quick_sort(arr, size);
    std::cout << "\nОтсортированный массив: ";
    print_array(arr, size);
    std::cout << '\n' << std::endl;
}