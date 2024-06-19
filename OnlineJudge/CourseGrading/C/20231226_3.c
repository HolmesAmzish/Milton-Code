#include <stdio.h>
#include <stdlib.h>

struct students {
	int num;
	float score;
}stu[2];

int main(void) {
	int i = 0;
	float average = 0;
	for (i = 0; i < 2; i++) {
		scanf("%d%f", &stu[i].num, &stu[i].score);
		average += stu[i].score;
	}
	average /= 2;
	printf("num     score\n");
	for (i = 0; i < 2; i++) {
		printf("%02d       %.2f\n", stu[i].num, stu[i].score);
	}
	printf("average %.2f\n", average);
	system("pause");
	return 0;
}

/*TEST SAMPLE
Input:
1
95.5
2
84.0
*/
	



