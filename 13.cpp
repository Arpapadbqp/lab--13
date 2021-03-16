#include <iostream>
#include <stdlib.h>
#include <time.h>

int ** MakeMatr(int m, int n)
{
	int ** t;
	t = new int*[m];
	for (int i = 0; i < m; i++){
		t[i] = new int[n];
		for (int j = 0; j < n; j++)
			t[i][j] = rand() %10;
	}
	return t;
}
void PrintMatr(int m, int n, int ** matr)
{
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			std::cout.width(4);
			std::cout << matr[i][j];
		}
		std::cout << std::endl;
	}
}

int* MakeArray(int k, int m, int n, int** matr)
{
	int*arr = new int[m];
	for (int i = 0; i < m; i++){
		arr[i] = 0;
		for (int j = 0; j < n; j++)
			if (matr[i][j] % 2 == 0)
				arr[i]++;
	}
	return arr;
}

void main()
{
	system("color 0A");
	setlocale(0, "rus");
	int N, M, K=0;
	std::cout << "Введите размерности матрицы: ";
	std::cin >> M >> N;
	int **A;
	A = MakeMatr(M, N);
	PrintMatr(M, N, A);
	int * B = MakeArray(K, M, N, A);
	std::cout << "Результат: \n";
	for (int i = 0; i < M; i++) std::cout << B[i] << ' ';
	std::cout << std::endl;
	for (int i = 0; i < M; i++)
		delete[] A[i];
	delete[] A;
	delete[] B;
	system("pause");
}