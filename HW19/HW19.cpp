#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

// Вывод массива
void showArr(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]\n";
}

// Задача 1
int NOD(int num1, int num2) {
	int min;
	if (num1 > num2)
		min = num2;
	else
		min = num1;
for (int i = min; i > 0; i--)
	if (num1 % i == 0 && num2 % i == 0)
		return i;
}

// Задача 2
int reverseNumber(int num1) {
	int n = 0;
	while (num1) {
		n = n * 10 + num1 % 10;
		num1 /= 10;
	}
	return n;
}

// Задача 3
int firstNum(int array[], int length, int num, int index = 0) {
	for (int i = index; i < length; i++)
		if (array[i] == num) {
			index = i;
			for (int i = length - 1; i > 0; i--)
				for (int j = index + 1; j < i; j++)
					if (array[j] > array[j + 1])
						swap(array[j], array[j + 1]);
			return index;
		}
	return -1;
}

// Задача 4
void fillArr(int array[], int length, int num1, int num2) {
	cout << "[";
	for (int i = 0; i < length; i++) {
		array[i] = rand() % (num2 + 1 - num1) + num1;
		cout << array[i] << ", ";
	}
	cout << "\b\b]\n";
}


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n, m, a, b, x, y;
	//Задача 1
	
	cout << "Задача 1\nВведите два числа: ";
	cin >> n >> m;
	cout << "Наибольший общий делитель: " << NOD(n, m) << endl;

	// Задача 2
	cout << "Задача 2\nВведите число: ";
	cin >> a;
	cout << reverseNumber(a) << endl;

	// Задача 3
	cout << "Задача 3\nИзначальный массив:\n";
	int z3[10] = { 12, 1, 2, 5, 34, 1, 8, 34, 19, 2 };
	showArr(z3, 10);
	cout << "Введите число из массива: ";
	cin >> b;
	cout << "Первая позиция числа " << b << " в массиве = " << firstNum(z3, 10, b) << endl;
	showArr(z3, 10);
	
	// Задача 4
	int z4[10];
	cout << "Задача 4\nВведите начало и конец диапазона: ";
	cin >> x >> y;
	fillArr(z4, 10, x, y);

	return 0;
}