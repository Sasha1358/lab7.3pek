#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
int Sum(int** a, int i, int j, const int n) {
	if (i >= n || j >= n) {
		return 0;
	}

	int sum = 0;

	if (i < j) {
		sum += abs(a[i][j]);
	}

	if (j == n - 1) {
		return sum + Sum(a, i + 1, 0, n);
	}

	return sum + Sum(a, i, j + 1, n);
}

int Sum(int** a, const int n) {
	return Sum(a, 0, 0, n);
}

int LocalMin(int** a, int i, int j, const int n) {
	if (i < 1 || i >= n - 1 || j < 1 || j >= n - 1) {
		return 0;  // Elements at the border cannot be local minimums
	}

	int currentValue = a[i][j];
	bool isLocalMinimum = true;

	if (currentValue >= a[i - 1][j] || currentValue >= a[i + 1][j] ||
		currentValue >= a[i][j - 1] || currentValue >= a[i][j + 1]) {
		isLocalMinimum = false;
	}

	int count = 0;
	if (isLocalMinimum) {
		count = 1;
	}

	if (j == n - 2) {
		return count + LocalMin(a, i + 1, 1, n);
	}

	return count + LocalMin(a, i, j + 1, n);
}

void localmin(int** a, const int n) {
	int count = LocalMin(a, 1, 1, n);  // Start from (1, 1) to avoid boundary elements
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int N;
	cout << "n = "; cin >> N;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = 1, High = 20;
	CreateRows(a, N, Low, High, 0);

	cout << "Масив" << endl;
	PrintRows(a, N, 0);

	int sum = Sum(a, 0, 0, N);
	cout << "Сума модулів елементів вище головної діагоналі = " << sum << endl;

	cout << "К-сть локальних мінімумів = ";
	localmin(a, N);
	cout << endl;

	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
