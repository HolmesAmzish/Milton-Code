#include<stdio.h>
#include<stdlib.h>

int main() {
	int n;
	int array[64];
	int i, j; 
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	for(i = 0; i < n - 1; i++) {
		for(j = i + 1; j < n; j++) {
			if(array[i] > array[j]) {
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
	for(i =0; i < n; i++) {
		printf("%d ", array[i]);
	}
	system("pause");
	return 0;
}
