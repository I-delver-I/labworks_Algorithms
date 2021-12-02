#include <iostream>

// TASK 25
/*
 Розробити алгоритм та написати програму, яка складається з наступних дій:
1. Опису трьох змінних індексованого типу з 10 символьних значень.
2. Ініціювання двох змінних виразами згідно з варіантом (табл. 1).
3. Ініціювання третьої змінної рівними значеннями двох попередніх змінних.
4. Обробки третьої змінної згідно з варіантом
 arr1 - 100 + i
 arr2 - 100 - i * i
 Добуток кодів елементів більших за 100
*/

void output_arr(const char* arr, const int SIZE, int &num);
void mult_elements(char* arr3, const int SIZE);
void init_arrs(char* arr1, char* arr2, char *arr3, const int SIZE, int &num);

int main()
{
	const int SIZE = 10;
	int num = 1;
	char arr1[SIZE]{}, arr2[SIZE]{}, arr3[SIZE]{};
	init_arrs(arr1, arr2, arr3, SIZE, num);
	mult_elements(arr3, SIZE);
}

// Initialization of arrays
void init_arrs(char *arr1, char* arr2, char *arr3, const int SIZE, int &num)
{
	int temp = 0;
	for (int i = 0; i < SIZE; i++)	// Initialization of the second and the first array
	{
		arr1[i] = 100 + i;
		arr2[i] = 110 - i * i;
	}
	output_arr(arr1, SIZE, num);
	output_arr(arr2, SIZE, num);

	for (int i = 0; i < SIZE; i++)	// Initialization of the third array
	{
		for (int z = 0; z < SIZE; z++)
		{
			if (arr1[i] == arr2[z])
			{
				arr3[temp] = arr1[i];
				temp++;
			}
		}
	}
	output_arr(arr3, SIZE, num);
	std::cout << std::endl;
}

// Calculating of the multiplication of the elements of the third array
void mult_elements(char* arr3, const int SIZE)
{
	int multiplication = 1;
	for (int i = 0; i < SIZE; i++)
	{
		if (arr3[i] > 100)
		{
			multiplication *= arr3[i];
			std::cout << "The element is: " << arr3[i] << " = " << (int)arr3[i] << std::endl << "The multiplication is: " << multiplication << std::endl;
		}
	}
	(multiplication == 1) ? multiplication = 0 : multiplication;	// Checking for nothing to be multiplied
	std::cout << "The multiplication of elements whose code is bigger than 100 is: " << multiplication << std::endl;
}

// The output of an array
void output_arr(const char* arr, const int SIZE, int &num)
{
	std::cout << "Here is the " << num << " array: " << std::endl;
	num++;
	for (int i = 0; i < SIZE; i++)
	{	
		std::cout << arr[i] << "(" << (int)arr[i] << ")" << " ";
	}
	std::cout << std::endl;
}