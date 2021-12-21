#include "Lab. work 9.h"

int main()
{
	srand(time(NULL));
	double** matrix = nullptr, x{};
	int row{}, col{};
	std::cout << "Please, enter the count of rows: ";
	std::cin >> row;
	std::cout << "Please, enter the count of columns: ";
	std::cin >> col;
	labwork_9::create_and_init_matrix(matrix, row, col);	// Appearing of a matrix
	labwork_9::find_elem_and_exchange(matrix, row, col, x);	// Solving the task
	labwork_9::del_matrix(matrix, row);
	delete[] matrix;
}

