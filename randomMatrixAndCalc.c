/*
-- Menu --
1. Random Square Matrix Generation
2. Transpose (T)
3. Rotation (90, 180, 270, 360 degree)
4. Inverse (^-1)
5. Calculation (+, -, *)
6. Exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define X 0
#define Y 1
#define MATRIX_EXIST(mat) if(mat == NULL) {puts("ERROR : matrix is not exist"); return;}

void printMenu();
void printMatrix(int** matrix);
int** generateBlankedMatrix(int square);
void fillMatrixWithRandom(int** matrix, int square);
int** generateRandomMatrix(int square);
int*** randomSquareMatrixGeneration();
int getMenuSelection();
int*** selectMenu(int menuSelection, int*** matrix);
void transpose(int*** matrix);
void rotation(int*** matrix);
int*** rotate90(int*** matrix);
void deleteMatrix(int** matrix);

int main(void)
{
	int menuSelection = 0;
	int*** matrix = NULL;
	while (menuSelection != 6) {
		printMenu();
		menuSelection = getMenuSelection();
		matrix = selectMenu(menuSelection, matrix);
	}

	if (matrix != NULL) {
		deleteMatrix(matrix[X]);
		deleteMatrix(matrix[Y]);
		free(matrix);
	}
	return 0;
}

void printMenu()
{
	puts("--Menu--");
	puts("1. Random Square Matrix Generation");
	puts("2. Transpose (T)");
	puts("3. Rotation (90, 180, 270, 360 degree)");
	puts("4. Inverse (^-1)");
	puts("5. Calculation (+, -, *)");
	puts("6. Exit");
}

int** generateBlankedMatrix(int square)
{
	int** matrix = (int**)malloc(sizeof(int*) * square);
	for (int i = 0; i < square; i++) {
		matrix[i] = (int*)malloc(sizeof(int) * square);
	}
	return matrix;
}

void fillMatrixWithRandom(int** matrix, int square)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			matrix[i][j] = rand() % 100;
		}
	}
}

int** generateRandomMatrix(int square)
{
	int** matrix = generateBlankedMatrix(square);
	fillMatrixWithRandom(matrix, square);

	return matrix;
}

int*** randomSquareMatrixGeneration()
{
	int square = 0;
	printf("Input the number of rows (2 or 3): ");
	scanf_s("%d", &square);
	int*** matrix = malloc(sizeof(int**) * 2);
	matrix[X] = generateRandomMatrix(square);
	matrix[Y] = generateRandomMatrix(square);

	printf("X = ");
	printMatrix(matrix[X]);

	printf("Y = ");
	printMatrix(matrix[Y]);

	return matrix;
}

int getMenuSelection()
{
	printf("Choose the item you want: ");
	int selection = 0;
	scanf_s("%d", &selection);

	return selection;
}

int*** selectMenu(int menuSelection, int*** matrix)
{
	switch (menuSelection) {
	case 1:
		matrix = randomSquareMatrixGeneration();
		return matrix;
		break;
	case 2:
		MATRIX_EXIST(matrix)
		transpose(matrix);
		break;
	case 3:
		MATRIX_EXIST(matrix)

		break;
	case 4:
		MATRIX_EXIST(matrix)

		break;
	case 5:
		MATRIX_EXIST(matrix)
		break;
	case 6:
		return;
	default:
		puts("Menu Selection Error!");
	}
}

void transpose(int*** matrix)
{
	int square = _msize(matrix[0]) / sizeof(matrix[0][0]);
	int** transposedMatrix[2];

	transposedMatrix[X] = generateBlankedMatrix(square);
	transposedMatrix[Y] = generateBlankedMatrix(square);

	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			transposedMatrix[X][i][j] = matrix[X][j][i];
			transposedMatrix[Y][i][j] = matrix[Y][j][i];
		}
	}

	printf("X^T = ");
	printMatrix(transposedMatrix[X]);

	printf("Y^T = ");
	printMatrix(transposedMatrix[Y]);

	deleteMatrix(transposedMatrix[X]);
	deleteMatrix(transposedMatrix[Y]);
}

void rotation(int*** matrix)
{
	int degree = 0;
	while (!(degree == 90 || degree == 180 || degree == 270 || degree == 360)) {
		printf("Input the degree to rotate: ");
		scanf_s("%d", &degree);
		if (!(degree == 90 || degree == 180 || degree == 270 || degree == 360)) {
			puts("Input appropriate degree");
		}
	}

	int rotationNumber = degree % 90;
}

int*** rotate90(int*** matrix)
{
	int square = _msize(matrix[0]) / sizeof(matrix[0][0]);
	int*** rotatedMatrix = malloc(sizeof(int**) * 2);
	rotatedMatrix[X] = generateBlankedMatrix(square);
	rotatedMatrix[Y] = generateBlankedMatrix(square);

	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			rotatedMatrix[X][j][square - i - 1] = matrix[X][i][j];
			rotatedMatrix[Y][j][square - i - 1] = matrix[Y][i][j];
		}
	}

	return rotatedMatrix;
}

void deleteMatrix(int** matrix)
{
	int square = _msize(matrix) / sizeof(matrix[0]);
	for (int i = 0; i < square; i++) {
		free(matrix[i]);
	}
	free(matrix);
}

void printMatrix(int** matrix)
{
	int square = _msize(matrix) / sizeof(matrix[0]);
	for (int i = 0; i < square; i++) {
		for (int j = 0; j < square; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");

		if (i != square - 1)
			printf("    ");
	}
}