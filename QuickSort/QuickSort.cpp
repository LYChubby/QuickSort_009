#include <iostream>
using namespace std;

// Array of Integres to Hold Values
int arr[20];
int cmp_count = 0;			// Number of Comparision
int move_count = 0;			// Number of Data Movements
int n;

void input() {
	while (true) {

		cout << "Masukkan Panjang Element Array : ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMaksimum Panjang Array Adalah 20" << endl;
	}

	cout << "\n-------------------" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n-------------------" << endl;

	for (int i = 0; i < n; i++) {

		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}

// Swap The Element at Index x With The Element at Index y
void swap(int x, int y) {

	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}

