#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Prototypes.h"

/*
	Із добутку додатних значень елементів стовпців двовимірного масиву. 
	Відсортувати методом бульбашки за зростанням
*/

int main()
{
	// Basic input
	srand(time(NULL));
	const int ROW = 5, COL = 8;
	int** arr = new int* [ROW], * newArr = new int[COL] {1, 1, 1, 1, 1, 1, 1, 1};
	create_d_arr(arr, ROW, COL);
	fill_arr(arr, ROW, COL);
	print_arr(arr, ROW, COL);

	// Calculations
	mult_cols(arr, newArr, ROW, COL);
	std::cout << "The created sequnce: " << std::endl;
	print_arr(newArr, COL);
	sort(newArr, COL);
	std::cout << "\nThe sorted sequence: " << std::endl;
	print_arr(newArr, COL);
}

// Creation of a double array
template<typename T>
void create_d_arr(T** arr, const int ROW, const int COL)
{
	for (int i = 0; i < ROW; i++)
	{
		arr[i] = new int[COL];
	}
}

// Multiplication of positive numbers in cols
void mult_cols(int **dArr, int *newArr, const int ROW, const int COL)
{
	int pos = 0;
	for (int i = 0; i < COL; i++)
	{
		for (int u = 0; u < ROW; u++)
		{
			if (dArr[u][i] > 0)
			{
				newArr[pos] *= dArr[u][i];
			}
		}
		if (newArr[pos] == 1)
		{
			newArr[pos] = 0;
		}
		pos++;
	}
}

// Print of an array
template<typename T>
void print_arr(T* arr, const int SIZE)
{
	std::cout << "Here is a sequence:\n";
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void print_arr(T** arr, const int ROW, const int COL)
{
	std::cout << "Here is a scope of sequences:\n";
	for (int u = 0; u < ROW; u++)
	{
		for (int i = 0; i < COL; i++)
		{
			std::cout << std::setw(7) << arr[u][i];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

// Initialization of an array by random numbers
void fill_arr(int** arr, const int ROW, const int COL)
{
	for (int u = 0; u < ROW; u++)
	{
		for (int i = 0; i < COL; i++)
		{
			arr[u][i] = rand() % 500 - 250;
		}
	}
}

// Sorting of an array by the "Bubble" method
void sort(int *arr, const int SIZE)
{
	int temp;
	for (int u = 0; u < SIZE; u++)
	{
		for (int i = 0; i < SIZE - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}