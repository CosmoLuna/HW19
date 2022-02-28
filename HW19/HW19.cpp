#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;

// ����� �������
void showArr(int array[], int length) {
	cout << "[";
	for (int i = 0; i < length; i++)
		cout << array[i] << ", ";
	cout << "\b\b]\n";
}

// ������ 1
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

// ������ 2
int reverseNumber(int num1) {
	int n = 0;
	while (num1) {
		n = n * 10 + num1 % 10;
		num1 /= 10;
	}
	return n;
}

// ������ 3
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

// ������ 4
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
	//������ 1
	
	cout << "������ 1\n������� ��� �����: ";
	cin >> n >> m;
	cout << "���������� ����� ��������: " << NOD(n, m) << endl;

	// ������ 2
	cout << "������ 2\n������� �����: ";
	cin >> a;
	cout << reverseNumber(a) << endl;

	// ������ 3
	cout << "������ 3\n����������� ������:\n";
	int z3[10] = { 12, 1, 2, 5, 34, 1, 8, 34, 19, 2 };
	showArr(z3, 10);
	cout << "������� ����� �� �������: ";
	cin >> b;
	cout << "������ ������� ����� " << b << " � ������� = " << firstNum(z3, 10, b) << endl;
	showArr(z3, 10);
	
	// ������ 4
	int z4[10];
	cout << "������ 4\n������� ������ � ����� ���������: ";
	cin >> x >> y;
	fillArr(z4, 10, x, y);

	return 0;
}