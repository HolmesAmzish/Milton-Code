// File: 20231226_2.c
// Date: 20231226

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxNumber 5

struct students {
	int id;
	float course[3];
	float average;
} stu[maxNumber];

int main() {
	int i;;
	for (i = 0; i < maxNumber; i++) {
		stu[i].id = i + 1;
		int j;
		stu[i].average = 0;
		for (j = 0; j < 3; j++) {
			scanf("%f", &stu[i].course[j]);
			stu[i].average += stu[i].course[j];
		}
		stu[i].average /= 3;
	}
	// Input the table of students

	float averageOfCourse[3] = {0};
	for (i = 0; i < 3; i++) {
		int j;
		for (j = 0; j < maxNumber; j++) {
			averageOfCourse[i] += stu[j].course[i];
		}
		averageOfCourse[i] /= maxNumber;
	}
	// Calculate the average of every course
	
	float max = stu[0].course[0];
	int id = stu[0].id, courseId = 1;
	for (i = 0; i < maxNumber; i++) {
		int j;
		for (j = 0; j < 3; j++) {
			if (max < stu[i].course[j]) {
				max = stu[i].course[j];
				id = stu[i].id;
				courseId = j + 1;
			}
		}
	}
	// Find out the max score of these courses

	float variance;
	float sum1 = 0;
	for (i = 0; i < maxNumber; i++) {
		sum1 += pow(stu[i].average, 2);
	}
	sum1 /= 5;
	float sum2 = 0;
	for (i = 0; i < maxNumber; i++) {
		sum2 += stu[i].average / 5;
	}
	variance = sum1 - pow(sum2, 2);
	// Calculate the variance

	printf("No.  course1 course2 course3 average\n");
	for (i = 0; i < maxNumber; i++) {
		printf(" %d    ", stu[i].id);
		int j;
		for (j = 0; j < 3; j++) {
			printf("%.2f   ", stu[i].course[j]);
		}
		printf("%.2f\n", stu[i].average);
	}

	printf("ave   ");
	for (i = 0; i < 3; i++) {
		printf("%.2f   ", averageOfCourse[i]);
	}
	printf("\n");
	
	printf("The highest score is: %.2f. Student No. %d. Course No. %d.\n", max, id, courseId);

	printf("The variance is: %.2f.", variance); 

	system("pause");
	return 0;
}

/*TEST SAMPLE
Input:
84 80 96
79 85 68
71 85 76
84 86 82
76 84 90
*/


