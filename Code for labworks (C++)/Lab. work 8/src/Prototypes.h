#pragma once

template<typename T>
void create_d_arr(T** arr, const int ROW, const int COL);
void mult_cols(int** dArr, int* newArr, const int ROW, const int COL);
template<typename T>
void print_arr(T* arr, const int SIZE);
template<typename T>
void print_arr(T** arr, const int ROW, const int COL);
void fill_arr(int** arr, const int ROW, const int COL);
void sort(int* arr, const int SIZE);