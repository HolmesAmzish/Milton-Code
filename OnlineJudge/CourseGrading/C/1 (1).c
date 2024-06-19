#include<stdio.h>

int main() {
	int matrix[5][5];
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	int* Max = &matrix[0][0];
	for(int i = 0; i < 5; i++) {
		for(int j =0; j < 5; j++) {
			if(*Max < matrix[i][j]) {
				*Max = matrix[i][j];
			}
		}
	}

	void swap(int* ptrMax, int* ptrMid);
	int* Mid = &matrix[2][2];
	swap(Max, Mid);
	
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void swap(int* ptrMax, int* ptrMid) {
	int temp = *ptrMax;
	*ptrMax = *ptrMid;
	*ptrMid = temp;
}
