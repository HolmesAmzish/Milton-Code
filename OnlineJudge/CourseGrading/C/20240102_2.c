#include <stdio.h>
#include <stdlib.h>

struct student {
    int id;
    char name[32];
    float course[3];
};

struct student stu[3];

void input(int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d%s", &stu[i].id, stu[i].name);
        for (int j = 0; j < 3; j++) {
            scanf("%f", &stu[i].course[j]);
        }
    }
}

float cal(struct student stu[], int n) {
    float average = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            average += stu[i].course[j];
        }
    }
    average /= n * 3;
    return average;
}

void max(struct student stu[], struct student *maxStu, int n, float *maxScore) {
    float sum[3];
    *maxScore = 0;
    for (int i = 0; i < n; i++) {
        sum[i] = 0;
        for (int j = 0; j < 3; j++) {
            sum[i] += stu[i].course[j];
        }
        if (i == 0 || *maxScore < sum[i]) {
            *maxStu = stu[i];
            *maxScore = sum[i];
        }
    }
}

void output(struct student stu[], int n) {
    printf("No.\tname\tscore1\tscore2\tscore3\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t", stu[i].id, stu[i].name);
        for (int j = 0; j < 3; j++) {
            printf("%.2f\t", stu[i].course[j]);
        }
        printf("\n");
    }
}

int main() {
    input(3);

    output(stu, 3);

    float average = cal(stu, 3);
    printf("The average score of these students is: %.2f\n", average);

    struct student maxStu;
    float maxScore;
    max(stu, &maxStu, 3, &maxScore);
    printf("The highest total score is: %.2f. No.%d, %s", maxScore, maxStu.id, maxStu.name);

    system("pause");
    return 0;
}


