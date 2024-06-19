#include <stdio.h>
#include <stdlib.h>
#define maxNumber 10

int main() {
	int array[maxNumber];
	int i;
	for (i = 0; i < maxNumber; i++) {
		scanf("%d", &array[i]);
	}
	void selectionSort(int *array, int n);
	selectionSort(array, maxNumber);
	for (i = 0; i < maxNumber; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

void selectionSort(int *array, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		int j;
		for (j = i + 1; j < n; j++) {
			if (array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}

// TEST SAMPLE:
// Input: 0 15 8 4 13 6 10 17 19 1
