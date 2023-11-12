#include <iostream>
#define N 50
using namespace std;
int main() {
	float A[N][N], C[N], temp, K, L; int x, elementNumber = 1, n = 0;
	do {
		cout << "\nEnter dimensions:"; cin >> x; // the user enters the dimension of the matrix A
	} while (x > N || x < 2); // checks if the user input is valid
	for (int i = 0; i < x; i++) { // the user enters numbers in array A
		for (int j = 0; j < x; j++) {
			do {
				printf("Enter element %d) ", elementNumber);
				cin >> A[i][j];
			} while (A[i][j] > 1000 || A[i][j] < -1000); // checks if the number is in the interval [-1000; 1000]
			elementNumber++;
		}
	}
	printf("\nA:\n");
	for (int i = 0; i < x; i++) { // displays all of the numbers in array A
		for (int j = 0; j < x; j++) {
			cout << A[i][j] << " ";
		}
		printf("\n");
	}
	do {
		do {
			printf("Enter lower limit:");
			cin >> K;
		} while (K < -1000 || K > 1000); // validates the lower limit
		do {
			printf("Enter upper limit:");
			cin >> L;
		} while (L < -1000 || L >1000); // validates the upper limit
		if (K > L) { // checks if the lower limit is greater than the upper limit
			cout << "The lower limit is greater than the upper limit!!!\n";
		}
	} while (K > L);
	for (int i = 0; i < x; i++) { // filters all of the elements from array A falling in the interval [K, L] and puts them in array C
		for (int j = 0; j < x; j++) {
			if (A[i][j] >= K && A[i][j] <= L) {
				C[n] = A[i][j];
				n++;
			}
		}
	}
	cout << "C:" << endl;
	for (int i = 0; i < n; i++) { // displays array C
		cout << C[i] << endl;
	}
	for (int i = 0; i < n; i++) { // bubble sorts array C
		for (int j = i + 1; j < n; j++) {
			if (C[j] > C[i]) {
				temp = C[i];
				C[i] = C[j];
				C[j] = temp;
			}
		}
	}
	cout << "C sorted:" << endl; // displays the sorted array C
	for (int i = 0; i < n; i++) {
		cout << C[i] << endl;
	}
	return 0;
}