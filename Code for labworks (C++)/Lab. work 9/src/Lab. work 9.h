#pragma once

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

namespace labwork_9
{
	void find_elem_and_exchange(double**& matrix, const int ROW, const int COL, double x);
	void Exchange_min_mid(double**& matrix, const int ROWI, const int COLI, const double X, const int MID_I);
	void create_and_init_matrix(double**& matrix, const int ROW, const int COL);
	template<typename T>
	void print_arr(T** matrix, const int ROW, const int COL);
	template<typename T>
	void print_arr(T* sequence, const int SIZE);
	void del_matrix(double** matrix, const int ROW);
}