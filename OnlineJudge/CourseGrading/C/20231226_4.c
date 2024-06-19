#include <stdio.h>
#include <stdlib.h>

int main() {
	int daysOfMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int year, month, day;
	scanf("%d,%d,%d", &year, &month, &day);

	if (year % 4 == 0 && year % 100 != 0) {
		daysOfMonth[2] = 29;
	}

	int sum = 0;
	int i;
	for (i = 0; i < month; i++) {
		sum += daysOfMonth[i];
	}
	sum += day;
	printf("It is the %dth day in %d", sum, year);
	system("pause");
	return 0;
}

/*TEST SAMPLE
Input:
2008,8,8
2020,4,16
*/
