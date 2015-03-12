#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>
#include <time.h>

using namespace std;

// Using two-dimensional array

void multiply1(int** matrixA, int** matrixB, int** matrixC, size_t size)
{
	int sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			for (size_t k = 0; k < size; k++)
			{
				sum += matrixA[i][k] * matrixB[k][j];
			}

			matrixC[i][j] = sum;
			sum = 0;
		}
	}
}


void print1(int** matrix, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << setw(8) << matrix[i][j];
		}
		cout << endl;
	}
}

// Using one-dimensional array with linear addresing

void multiply2(int *srcA, int *srcB, int *dest, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			*(dest + (size * i + j)) = 0; // Initialize the output matrix to zero
			for (size_t k = 0; k < size; k++)
			{
				*(dest + (size * i + j)) += *(srcA + (size * i + k)) * *(srcB + (size * k + j));
			}
		}
	}
}

void print2(int *matrix, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			cout << setw(8) << *(matrix + (size * i + j));
		}
		cout << endl;
	}
}


void elapsedTime(const clock_t &start)
{
	cout << "Finished in " << (float)(clock() - start) / CLOCKS_PER_SEC << " s." << endl;
}

void main()
{
	struct Ticket {
		int seatNumber;
		const char *Name;
		float price;
	};


	Ticket tickets[48];


	srand(time(NULL));
	clock_t start;

	size_t size = 0;
	cout << "Enter matrix size: ";
	cin >> size;

	
	/* Two dimensional array */
	cout << "TWO DIMENSIONAL ARRAY" << endl;
	
	cout << "Allocating..." << endl;
	start = clock();
	int **matrixA = new int*[size];
	int **matrixB = new int*[size];
	int **matrixC = new int*[size];
	for (size_t i = 0; i < size; i++)
	{
		matrixA[i] = new int[size];
		matrixB[i] = new int[size];
		matrixC[i] = new int[size];
	}
	elapsedTime(start);

	cout << "Filling..." << endl;
	start = clock();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			matrixA[i][j] = rand() % 10;
			matrixB[i][j] = rand() % 10;
		}
	}

	start = clock();
	cout << "Computing... " << endl;
	multiply1(matrixA, matrixB, matrixC, size);
	elapsedTime(start);
	//print1(matrixA, size);

	cout << endl;

	/* One dimensional array with linear addresing */
	cout << "ONE DIMENSIONAL ARRAY" << endl;
	
	start = clock();
	cout << "Allocating..." << endl;
	int *srcMatrixA = new int[size*size];
	int *srcMatrixB = new int[size*size];
	int *destMatrix = new int[size*size];
	elapsedTime(start);

	cout << "Filling..." << endl;
	start = clock();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			int pos = size * i + j;
			*(srcMatrixA + pos) = rand() % 10;
			*(srcMatrixB + pos) = rand() % 10;
		}
	}
	elapsedTime(start);
	
	start = clock();
	cout << "Computing... " << endl;
	multiply2(srcMatrixA, srcMatrixB, destMatrix, size);
	elapsedTime(start);

	//print2(destMatrix, size);

	cin.ignore();
	cin.get();
}