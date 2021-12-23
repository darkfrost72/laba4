#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "matrixfunct.c"

int main(){
    int na = 0, nb = 0, mb = 0;
    printf("Введите количество столбцов с строк в матрице A  \n");
    scanf("%d", &na);
    printf("Введите количество строк в матрице B  \n");
    scanf("%d", &nb);
    printf("Введите количество столбцов в матрице B  \n");
    scanf("%d", &mb);
    pick(na,nb,mb);

    return 0;
}
int pick(int na, int nb, int mb){
// Переменные
    int **matrix_a;
    int **matrix_b;
    unsigned int choice;
//Создание и вывод матриц
    matrix_a = malloc(na * sizeof(int *));
    for(int i=0;i < na;i++){
        matrix_a[i] =  malloc(na * sizeof(int));
    }
    matrix_b = malloc(mb * sizeof(int *));
    for (int i = 0; i < mb; i++){
        matrix_b[i] =  malloc(nb * sizeof(int));
    }
    for (int i = 0; i < na; i++){
        for (int j = 0; j < na; j++){
            matrix_a[i][j] = 10 + rand() % (30 - 10 + 1);
        }
    }
    printf("Матрица A:\n");
    for (int i = 0; i < na; i++){
        for (int j = 0; j < na; j++){
            printf("%d \t", matrix_a[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < mb; i++){
        for (int j = 0; j < nb; j++){
            matrix_b[i][j] = 10 + rand() % (20 - 10 + 5);
        }
    }
    printf("Матрица B:\n");
    for (int i = 0; i < mb; i++){
        for (int j = 0; j < nb; j++){
            printf("%d \t", matrix_b[i][j]);
        }
        printf("\n");
    }
    printf("Введите вариант  \n");
    printf("1 - Найти максимальный элемент матрицы А \n");
    printf("2 - Транспонировать матрицю В \n");
    printf("3 - Найти матричный добуток А х В\n");
    printf("4 - Сортировать за возрастанием элементы строок\n");
    printf("5 - Вывести суму элементов строк А та столбцов В\n");

    scanf("%u", &choice);
    switch (choice) {
        case 1:
            minmax_A(matrix_a,na);
            break;
        case 2:
            trans_B(matrix_b,nb,mb);
            break;
        case 3:
            if (nb != mb && nb != na) {
                printf("Количество столбцов и строк одной матрицы должны совпадать с количеством в другой");
                return 0;
            }
            else {
                mnoj_A_B(matrix_a,matrix_b,na,nb,mb);
            }
            return 0;
        case 4:
            sort_A(matrix_a,na);
            break;
        case 5:
            sum(matrix_a,matrix_b,na,nb,mb);
            break;
    }
    return 0;
}
