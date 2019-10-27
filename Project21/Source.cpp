#include<iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 5;
template <typename T>
void FillRand(T Arr[], const int n);
template <typename T>
void FillRand(T Arr[ROWS][COLS], const int ROWS, const int COLS);
template <typename T>
void Print(T Arr[], const int n);
template <typename T>
void Print(T Arr[ROWS][COLS], const int ROWS, const int COLS);
template <typename T>
void Sort(T Arr[], const int n);
template <typename T>
void Sort(T Arr[ROWS][COLS], const int  ROWS, const int COLS);

template <typename T>
T  Sum(T Arr[], const int n);	//прототип ф-ции - Function declaration
template <typename T>
double Avg(T Arr[], const int n);

template <typename T>
T  minValueIn(T Arr[], const int n);

template <typename T>
T  maxValueIn(T Arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int Arr[n];

	FillRand(Arr, n);
	Print(Arr, n);
	Sort(Arr, n);
	Print(Arr, n);
	cout << "Сумма элементов масива: " << Sum(Arr, n) << endl;
	cout << "Среднее арифметическое: " << Avg(Arr, n) << endl;
	cout << "Минимальное значение в масиве: " << minValueIn(Arr, n) << endl;
	cout << "Максимальное значение в масиве: " << maxValueIn(Arr, n) << endl;

	//////////////////////////////////////////////////////////////

	const int m = 10;
	double Brr[m];
	FillRand(Brr, m);
	Print(Brr, m);
	Sort(Brr, m);
	Print(Brr, m);
	cout << "Сумма : " << Sum(Brr, m) << endl;
	cout << "Среднее : " << Avg(Brr, m) << endl;
	cout << "Минимальное : " << minValueIn(Brr, m) << endl;
	cout << "Максимальное : " << maxValueIn(Brr, m) << endl;

	///////////////////////////////////////////////////////////////

	const int SIZE = 8;
	char Crr[SIZE];
	FillRand(Crr, SIZE);
	Print(Crr, SIZE);
	Sort(Crr, SIZE);
	Print(Crr, SIZE);

	////////////////////////////////////////////////////////////////

	cout << "Двумерные массивы: " << endl;

	int Drr[ROWS][COLS] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	FillRand(Drr, ROWS, COLS);
	Print(Drr, ROWS, COLS);
	cout << endl;
	/*cout << "сума элементов: " << Sum(Drr, ROWS, COLS) << endl;
	cout << "ср : " << Avg(Drr, ROWS, COLS) << endl;
	cout << "мин: " << minValueIn(Drr, ROWS, COLS) << endl;
	cout << "макс: " << maxValueIn(Drr, ROWS, COLS) << endl;*/
	Sort(Drr, ROWS, COLS);
	Print(Drr, ROWS, COLS);
}
template <typename T>
void FillRand(T Arr[], const int n)
{
	//заполнение масива  случ числами:
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

template <typename T>
void FillRand(T Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}
}
template <typename T>
void Print(T Arr[], const int n)

{
	//вымод масива на экран:
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << "\t";
	}
	cout << endl;
}

template <typename T>
void Print(T Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << "\t";
		}
		cout << endl;
	}
}
template <typename T>
void Sort(T Arr[], const int n)
{
	//сортировка:
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[i])
			{
				int buffer = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = buffer;
			}
		}
	}
}

template <typename T>
void Sort(T Arr[ROWS][COLS], const int ROWS, const int COLS)
{
	int iterations = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				int l;
				//if (k == i)l = j + 1; else l = 0;//одинаковое с 237
				//condition? expression1(true): expression2(false) можно использовать вместо if
				(k == i) ? l = j + 1/*true*/ : l = 0/*false*/;
				//или l=(k == i) ?  j + 1/*true*/:  0/*false*/;
				for (; l < COLS; l++)
				{
					//если перебираемый элемент меньше, чем выбранный,
					//их нужно поменять местами
					if (Arr[k][l] > Arr[i][j])
					{
						int buffer = Arr[i][j];
						Arr[i][j] = Arr[k][l];
						Arr[k][l] = buffer;
					}
					iterations++;
				}

			}
		}
	}
	cout << "Массив отсортирован за " << iterations << " итераций." << endl;
}
template <typename T>
T  Sum(T Arr[], const int n)
{
	int Sum = 0;
	for (int i = 0; i < n; i++)
	{
		Sum += Arr[i];
	}
	return Sum;
}


template <typename T>
double Avg(T Arr[], const int n)
{
	return (double)Sum(Arr, n) / n;
}


template <typename T>
T minValueIn(T Arr[], const int n)
{
	int min = Arr[0];
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] < min)min = Arr[i];
	}
	return min;
}

template <typename T>
T maxValueIn(T Arr[], const int n)
{
	int max = Arr[0];
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] > max)max = Arr[i];
	}
	return max;
}

