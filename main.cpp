#include<iostream>
using namespace std;

//void FillRand(int** arr)
#define tab "\t"

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

void push_row_back(int**& arr, int& m, int n);
void push_row_front(int**& arr, int& m, int n);
void insert_row(int**& arr, int& m, int n);
void pop_row_back(int**& arr, int& m, int n);
void pop_row_front(int**& arr, int& m, int n);
void erase_row(int**& arr, int& m, int n);

void main()
{
	setlocale(LC_ALL, "Rus");
	int m = 5; //Количество строк
	int n = 5; //Количество столбцов
	/*cout << " Введите количество строк: "; cin >> m;
	cout << "\n Введите количество элементов строки: "; cin >> n;*/

	int** arr = new int* [m] {};    //1) Создаём массив указателей:

	for (int i = 0; i < m; i++)     //2) Выделяем память под строки двумерного массива:
	{
		arr[i] = new int[n] {};
	}

	FillRand(arr, m, n);
	cout << " Начальный массив \n"; Print(arr, m, n);
	push_row_back(arr, m, n);
	cout << "*push_row_back* \n"; Print(arr, m, n);
	push_row_front(arr, m, n);
	cout << "*push_row_front* \n"; Print(arr, m, n);
	insert_row(arr, m, n);
	cout << "*    insert    * \n"; Print(arr, m, n);
	pop_row_back(arr, m, n);
	cout << "* pop_row_back * \n"; Print(arr, m, n);
	pop_row_front(arr, m, n);
	cout << "* pop_row_front * \n"; Print(arr, m, n);
	erase_row(arr, m, n);
	cout << "*   erase_row   * \n"; Print(arr, m, n);
	//1)Удаляем строки массива:
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	//2)Удаляем массив указателей:
	delete[] arr;
}

void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, const int m, const int n)
{
	cout << "+++++++++++++++++++++++++++++++++++\n\n";
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
	cout << "+++++++++++++++++++++++++++++++++++\n";
}
void push_row_back(int**& arr, int& m, int n)
{
	int** buffer = new int* [++m] {};    //1) Создаём буферный массив указателей:
	for (int i = 0; i < m; i++)            //2) Выделяем память под строки двумерного массива:
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m - 1; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < n; i++)
	{
		arr[m - 1][i] = rand() % 100;
	}
	
}
void push_row_front(int**& arr, int& m, int n)
{
	int** buffer = new int* [++m]{};    //1) Создаём буферный массив указателей:
	for (int i = 0; i < m; i++)            //2) Выделяем память под строки двумерного массива:
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i + 1][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m - 1; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = 0; i < n; i++)
	{
		arr[0][i] = rand() % 100;
	}

}
void insert_row(int**& arr, int& m, int n)
{
	int** buffer = new int* [++m]{};    //1) Создаём буферный массив указателей:
	for (int i = 0; i < m; i++)            //2) Выделяем память под строки двумерного массива:
	{
		buffer[i] = new int[n] {};
	}

	int value;
	cout << " Выберите номер новой строки от 0 до " << m - 1 << tab; cin >> value;

	for (int i = 0; i < m - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= value)
			buffer[i + 1][j] = arr[i][j];
			else
			buffer[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m - 1; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	//Не заполняем, чтобы лучше видеть вставленную строку (00000000)
	/*for (int i = 0; i < n; i++)       
	{
		arr[value][i] = rand() % 100;
	}
	*/
}
void pop_row_back(int**& arr, int& m, int n)
{
	int** buffer = new int* [--m] {};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	arr = buffer;
}
void pop_row_front(int**& arr, int& m, int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i + 1][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
	
}
void erase_row(int**& arr, int& m, int n)
{
	int** buffer = new int* [--m]{};
	for (int i = 0; i < m; i++)
	{
		buffer[i] = new int[n] {};
	}
	int value;
	cout << " Выберите номер удаляемой строки от 0 до " << m << tab; cin >> value;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i >= value)
			{
			buffer[i][j] = arr[i +1][j];
			}
			else
			{
			buffer[i][j] = arr[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	arr = buffer;
}