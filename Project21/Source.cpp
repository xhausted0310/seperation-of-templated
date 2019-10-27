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
T  Sum(T Arr[], const int n);	//�������� �-��� - Function declaration
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
	cout << "����� ��������� ������: " << Sum(Arr, n) << endl;
	cout << "������� ��������������: " << Avg(Arr, n) << endl;
	cout << "����������� �������� � ������: " << minValueIn(Arr, n) << endl;
	cout << "������������ �������� � ������: " << maxValueIn(Arr, n) << endl;

	//////////////////////////////////////////////////////////////

	const int m = 10;
	double Brr[m];
	FillRand(Brr, m);
	Print(Brr, m);
	Sort(Brr, m);
	Print(Brr, m);
	cout << "����� : " << Sum(Brr, m) << endl;
	cout << "������� : " << Avg(Brr, m) << endl;
	cout << "����������� : " << minValueIn(Brr, m) << endl;
	cout << "������������ : " << maxValueIn(Brr, m) << endl;

	///////////////////////////////////////////////////////////////

	const int SIZE = 8;
	char Crr[SIZE];
	FillRand(Crr, SIZE);
	Print(Crr, SIZE);
	Sort(Crr, SIZE);
	Print(Crr, SIZE);

	////////////////////////////////////////////////////////////////

	cout << "��������� �������: " << endl;

	int Drr[ROWS][COLS] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	FillRand(Drr, ROWS, COLS);
	Print(Drr, ROWS, COLS);
	cout << endl;
	/*cout << "���� ���������: " << Sum(Drr, ROWS, COLS) << endl;
	cout << "�� : " << Avg(Drr, ROWS, COLS) << endl;
	cout << "���: " << minValueIn(Drr, ROWS, COLS) << endl;
	cout << "����: " << maxValueIn(Drr, ROWS, COLS) << endl;*/
	Sort(Drr, ROWS, COLS);
	Print(Drr, ROWS, COLS);
}
template <typename T>
void FillRand(T Arr[], const int n)
{
	//���������� ������  ���� �������:
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
	//����� ������ �� �����:
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
	//����������:
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
				//if (k == i)l = j + 1; else l = 0;//���������� � 237
				//condition? expression1(true): expression2(false) ����� ������������ ������ if
				(k == i) ? l = j + 1/*true*/ : l = 0/*false*/;
				//��� l=(k == i) ?  j + 1/*true*/:  0/*false*/;
				for (; l < COLS; l++)
				{
					//���� ������������ ������� ������, ��� ���������,
					//�� ����� �������� �������
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
	cout << "������ ������������ �� " << iterations << " ��������." << endl;
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

