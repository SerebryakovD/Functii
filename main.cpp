#include<iostream>
using namespace std;

// Ручная инициализация массива.
void initializeArray (double array[], int size, bool isRandom = false) {
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = ";
		if (isRandom) {
			array[i] = rand()%10 - 4;
			cout << array[i] << endl;
		}
		else {
			cin >> array[i];
		}
	}
}

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "arr[" << i << "] = " << array[i] << endl;
	}
}

void sort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1; j++) {
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

//В одномерном массиве, состоящем из N вещественных
//чисел вычислить :
//■ Сумму отрицательных элементов.
//■ Произведение элементов, находящихся между min и max
//элементами.
//■ Произведение элементов с четными номерами (четными индексами).
//■ Сумму элементов, находящихся между первым и последним отрицательными элементами.

bool checkEven(int a) {
	if (a % 2 == 0) {
		return true;
	}

	return false;
}

double multiply(double a, double b) {
	if (a == 0) {
		return b;
	}

	return a * b;
}

int setMax(double arr[], int index, int max) {
	if (arr[index] > arr[max]) {
		return index;
	}

	return max;
}

int setMin(double arr[], int index, int min) {
	if (arr[index] < arr[min]) {
		return index;
	}

	return min;
}

int main() {
	double arr[10];
	initializeArray(arr, 10, true);
	double sum = 0.0;
	double mult = 0;
	double evenMult = 0;
	double minMaxRangeSum = 0.0;
	int minIndex = 0;
	int maxIndex = 0;
	int negativeMinIndex = -1;
	int negativeMaxIndex = -1;

	for (int i = 0; i < 10; i++) {
		maxIndex = setMax(arr, i, maxIndex);
		minIndex = setMin(arr, i, minIndex);

		//  За сумму отрицательных и за индексы 1 и последнего отрицательного
		if (arr[i] < 0) {
			sum += arr[i];

			if (negativeMinIndex == -1) {
				negativeMinIndex = i;
				negativeMaxIndex = i;
			} else {
				negativeMaxIndex = i;
			}
		}

		if (i % 2 == 0) {
			evenMult = multiply(evenMult, arr[i]);
		}
	}

	for (int i = minIndex; i <= maxIndex; i++) {
		mult = multiply(mult, arr[i]);
	}

	cout << endl << "sum = " << sum << endl;
	if (mult != 0) cout << "mult = " << mult << endl;
	if (evenMult != 0) cout << "evenMult = " << evenMult << endl;

	if (negativeMinIndex != -1) {
		for (int i = negativeMinIndex; i <= negativeMaxIndex; i++) {
			minMaxRangeSum += arr[i];
		}
		cout << "minMaxRangeSum = " << minMaxRangeSum << endl;
	}



	return 0;
}
