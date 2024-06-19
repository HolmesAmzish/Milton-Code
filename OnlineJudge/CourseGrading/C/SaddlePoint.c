#include<stdio.h>

int main()
{
    //int matrix[4][5]={1,2,3,4,5,2,4,6,8,10,3,6,9,12,15,4,8,12,16,20};
    int matrix[4][5];
    int i, j, pi;
    for(i=0; i<4; i++)
        for(j=0; j<5; j++)
            scanf("%d", &matrix[i][j]);
    int isSaddlePoint = 0 ;
    int rowMax, columnMin, row = 0, column = 0;
    for(i=0; i<4; i++)
    {
        for(rowMax=matrix[i][0],j=0; j<5; j++)
        {
            if(rowMax < matrix[i][j])
            {
                rowMax = matrix[i][j];
                column = j;
            }
        }
        for(columnMin=matrix[0][column],pi=0; pi<4; pi++)
        {
            if(columnMin > matrix[pi][column])
            {
                columnMin = matrix[pi][column];
                row = pi;
            }
        }
            if(columnMin == rowMax)
            {
                isSaddlePoint = 1;
                break;
            }
    }
    if(isSaddlePoint)printf("a[%d][%d]=%d", row, column, rowMax);
    else printf("It is not exist.");
    return 0;
}
