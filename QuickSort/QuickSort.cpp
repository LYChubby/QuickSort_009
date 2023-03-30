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

void q_sort(int low, int high) {

	int pivot, i, j;
	if (low > high) {											// Langkah 1
		return;

		// Partition The List Into Two Parts :
		// One Containing Elements Greather Than Pivot
		// Outher Conntainning Element Greather Than Pivot

		pivot = arr[low];										// Langkah 2

		i = low + 1;											// Langkah 3
		j = high;												// Langkah 4


		while (i <= j) {										// Langkah 10

			// Search For an Element Greater Than Pivot
			while ((arr[i] <= pivot) && (i <= high)) {			// Langkah 5

				i++;											// Langkah 6
				cmp_count++;
			}
			cmp_count++;
			// Search For an Element Less Than or Equal to Pivot
			while ((arr[j] > pivot) && (j >= low)) {			// Langkah 7

				j--;											// Langkah 8
				cmp_count++;
			}
			cmp_count++;

																// Langkah 9
			if (i < j) { // If The Greater Element Is On The Left of The Element

				// Swap The Element at Index i With The Element at Index j
				swap(i, j);
				move_count++;
			}
		}
		// j Now Containt The Index of The Last Element In The Sorted List
		if (low < j) {											// Langkah 11

			// Move The Pivot To Its Correct Posisition In The List
			swap(low, j);
			move_count++;
		}
		// Sort The List On The Left of Pivot Using Quick Sort
		q_sort(low, j - 1);										// Langkah 12
	}

	// Sort The List On The Right of Pivot Using QUick Sort
	q_sort(j + 1, high);										// Langkah 13

}

void display() {
	cout << "\n-------------" << endl;
	cout << "-Sorted Array-" << endl;
	cout << "--------------" << endl;

	for (int i = 0; i < n; i++) {

		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of Comparison : " << cmp_count << endl;
	cout << "Number of Data Movements : " << move_count << endl;
}