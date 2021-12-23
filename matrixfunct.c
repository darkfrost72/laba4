//
// Created by Влад on 30.11.2021.
//

#include "matrixfunct.h"

void minmax_A(int **matrix_a,int na){
    int max = 1;
    int min = 0;
    for(int i = 0; i < na; i++ ){
        for (int j = na - 1; j > i;j--){
            if(matrix_a[i][j]>max)
                max=matrix_a[i][j];
            else max;
            if(matrix_a[i][j]<min)
                min=matrix_a[i][j];
            else min;
        }
    }
    printf("\nМаксимальное значение:%d",max);
    printf("\nMинимальное значение:%d",min);
}
void trans_B(int **matrix_b,int nb,int mb){
    int **Bt;
    Bt = malloc(nb * sizeof(int *));
    for (int i = 0; i < nb; i++){
        Bt[i] =  malloc(mb * sizeof(int));
    }
    for(int i = 0;i < nb;i++){
        for(int j = 0;j < mb;j++){
            Bt[i][j] = matrix_b[j][i];
        }
    }
    printf("\n Транспонированная матрица B:\n");
    for(int i = 0;i < nb;i++){
        for(int j = 0;j < mb;j++){
            printf("%d\t",Bt[i][j]);
        }
        printf("\n");
    }
}
void mnoj_A_B(int **matrix_a,int **matrix_b,int na,int nb,int mb){
    int **matrix_c;
    matrix_c = malloc(nb * sizeof(int *));

    if(na != nb ){
        printf("Ошибка!!! Количество строк и столбцов должно быть одинаково со второй матрицей");
        return;
    }
    for(int i = 0; i < nb;i++){
        for (int j = 0;j < mb;j++){
            matrix_c[i][j] = matrix_a[i][j] * matrix_b[j][i];
        }
    }
    printf("\nРезультат умножения матриц A и B:\n");
    for(int i = 0;i < nb;i++){
        for(int j = 0;j < mb;j++){
            printf("%d\t",matrix_c[i][j]);
        }
        printf("\n");
    }
}
void sort_A(int **matrix_a,int na){
    int row;
    int arr[na];
    printf("Выбрать строку: \t");
    scanf("%d",&row);
    row--;
    for(int i = 0 ; i < na+1; i++){
        for(int j = 0 ; j < na-i ; j++){
            if(matrix_a[row][j] > matrix_a[row][j+1]){
                int sort = matrix_a[row][j];
                matrix_a[row][j] = matrix_a[row][j+1];
                matrix_a[row][j+1] = sort;
            }
        }
    }
    printf("\n");
    for (int i = 0;i < na+1;i++){
        printf("%d\t",matrix_a[row][i]);
    }
}
void sum(int **matrix_a, int **matrix_b,int na,int nb,int mb){
    int suma = 0;
    printf("Сумма элементов A\n");
    for (int i = 0;i < na;i++){
        for(int j = 0;j < na;j++){
            suma+=matrix_a[i][j];
        }
        printf("%d\t",suma);
        suma = 0;
    }
    suma = 0;
    printf("\nСума элементов матрицы B\n");
    for (int i = 0;i < nb;i++){
        for(int j = 0;j < mb;j++){
            suma+=matrix_b[j][i];
        }
        printf("%d\t",suma);
        suma = 0;
    }
}