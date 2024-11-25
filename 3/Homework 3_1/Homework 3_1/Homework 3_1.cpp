#include <iostream>

void merge_sort(int*& arr, int size);

int* merge(int*& arr1, int*& arr2, int size);

void print_array(int* arr, int size);

void print_interface(int* arr, int size);

int main()
{
	setlocale(LC_CTYPE, "rus");
	int* arr1 = new int[10]{ 3, 43, 38, 29, 18, 72, 57, 61, 2, 33 };
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

void merge_sort(int*& arr, int size)
{
	if (size <= 1) { return; }
	int len1{};
	if (size % 2 == 0)
	{
		len1 = size / 2;
	}
	else { len1 = (size / 2) + 1; }
	int len2 = size / 2;
	int* arr1 = new int[len1];
	int* arr2 = new int[len2];
	for (int count = 0; count < len1; count++)
	{
		arr1[count] = arr[count];
	}
	for (int count = 0; count < len2; count++)
	{
		arr2[count] = arr[len1 + count];
	}
	merge_sort(arr1, len1);
	merge_sort(arr2, len2);
	arr = merge(arr1, arr2, size);
	delete[] arr1;
	delete[] arr2;
}

int* merge(int*& arr1, int*& arr2, int size)
{
	int len1{};
	if (size % 2 == 0)
	{
		len1 = size / 2;
	}
	else { len1 = (size / 2) + 1; }
	int len2 = size / 2;
	int* arr3 = new int[len1 + len2];
	int count1{ 0 }, count2{ 0 }, count3{ 0 };
	while (count1 < len1 || count2 < len2)
	{
		if (count1 == len1)
		{
			arr3[count3] = arr2[count2];
			count2++;
		}
		else if (count2 == len2)
		{
			arr3[count3] = arr1[count1];
			count1++;
		}
		else
		{
			if (arr1[count1] <= arr2[count2])
			{
				arr3[count3] = arr1[count1];
				count1++;
			}
			else
			{
				arr3[count3] = arr2[count2];
				count2++;
			}
		}
		count3++;
	}
	return arr3;
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
	merge_sort(arr, size);
	std::cout << "\nОтсортированный массив: ";
	print_array(arr, size);
	std::cout << '\n' << std::endl;
}