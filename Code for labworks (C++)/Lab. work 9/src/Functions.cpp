#include "Lab. work 9.h"

/*
	Задано матрицю дійсних чисел A[m,n]. У кожному рядку матриці знайти
	останній мінімальний елемент Х і його місцезнаходження. Обміняти знайдене
	значення Х з елементом середнього стовбця.
*/

namespace labwork_9
{
	// Searching of the minimal elements, their indexes and exchanging of them
	void find_elem_and_exchange(double **&matrix, const int ROW, const int COL, double x)
	{
		int colI{}, rowI{}, midI = COL / 2;
		for (int i = 0; i < ROW; i++)
		{
			rowI = i;
			x = matrix[i][0];
			for (int y = 0; y < COL; y++)
			{
				if (x >= matrix[i][y])
				{
					x = matrix[i][y];
					colI = y;
				}
			}

			std::cout << "Min. element of row " << rowI + 1 << " in position " << colI + 1 << ": " << x <<  std::endl << std::endl;
			if (((colI != ROW / 2 + 1) && ROW % 2 != 0) || (ROW % 2 == 0 && (colI != ROW / 2 + 1 && colI != ROW / 2)))
			{
				Exchange_min_mid(matrix, rowI, colI, x, midI);
				print_arr(matrix[rowI], COL);
			}
			else
				std::cout << "The element is already in the mid of the row" << std::endl << std::endl;
		}
		std::cout << "The final matrix is: " << std::endl;
		print_arr(matrix, ROW, COL);
	}
	
	// Exchanging two elements of the row
	void Exchange_min_mid(double **&matrix, const int ROWI, const int COLI, const double X, const int MID_I)
	{
		matrix[ROWI][COLI] = matrix[ROWI][MID_I];
		matrix[ROWI][MID_I] = X;
	}

	// Creating of the matrix and its initialization
	void create_and_init_matrix(double **&matrix, const int ROW, const int COL)
	{
		matrix = new double* [ROW];
		for (int i = 0; i < ROW; i++)
		{
			matrix[i] = new double[COL]{};
		}

		double temp{};
		for (int i = 0; i < ROW; i++)
		{
			for (int y = 0; y < COL; y++)
			{
				temp = rand() % 3;
				matrix[i][y] = (temp == 2) ? rand() % 1000 * 2 - 1000 : (temp == 1) ? (rand() % 1000 * 2 - 1000) / 12.4 : 0;
			}
		}
		print_arr(matrix, ROW, COL);
	}

	template<typename T>
	void print_arr(T**matrix, const int ROW, const int COL) 
	{
		std::cout << "Here is a matrix:" << std::endl;
		for (int i = 0; i < ROW; i++)
		{
			for (int y = 0; y < COL; y++)
			{
				std::cout << std::setw(10) << matrix[i][y];
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << std::endl;
	}

	template<typename T>
	void print_arr(T* sequence, const int SIZE)
	{
		std::cout << "Here is a sequence:" << std::endl;
		for (int i = 0; i < SIZE; i++)
		{
			std::cout << sequence[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	void del_matrix(double** matrix, const int ROW)
	{
		for (int i = 0; i < ROW; i++)
		{
			delete[] matrix[i];
		}
	}
}