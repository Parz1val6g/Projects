#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
JOEL MAMA MUITO typedef int bool;
#define true 1
#define false 0

void readMatrix(unsigned int r, unsigned int c, int **matrix)
{
    for (int rr = 0; rr < r; rr++)
        for (int cc = 0; cc < c; cc++)
            printf("\nmatrix[%d][%d] = %d;", rr, cc, *(*(matrix + cc) + rr));
}
void writeMatrix(unsigned int r, unsigned int c, int **matrix)
{
    for (int rr = 0; rr < r; rr++)
        for (int cc = 0; cc < c; cc++)
        {
            printf("\nmatrix[%d][%d] =", rr, cc);
            scanf("%d", (*(matrix + cc) + rr));
        }
}
void dashCalculation(unsigned int r, unsigned int c, int **matrix)
{
    int dash = 0;
    for (int rr = 0; rr < r; rr++)
        for (int cc = 0; cc < c; cc++)
            if (rr == cc)
                dash += *(*(matrix + rr) + cc);
    printf("Dash=%d", dash);
}
char *isSymmetrical(unsigned int r, unsigned int c, int **matrix)
{
    bool var = true;
    for (int rr = 0; rr < r; rr++)
        for (int cc = 0; cc < c; cc++)
            if (*(*(matrix + rr) + cc) != *(*(matrix + cc) + rr))
                var = false;
    return (var ? "Matrix is symmetrical!" : "Matrix isn't symmetrical!");
}
void matrixProduct()
{
    unsigned int r1, c1, r2, c2;

    printf("Matrix 1 row number: ");
    scanf("%u", &r1);
    printf("Matrix 1 column number: ");
    scanf("%u", &c1);

    printf("Matrix 2 row number: ");
    scanf("%u", &r2);
    printf("Matrix 2 column number: ");
    scanf("%u", &c2);

    if (c1 != r2)
    {
        printf("Matrix multiplication not possible due to dimensions.\n");
        return;
    }

    int **matrix1, **matrix2, **matrixProd;

    matrix1 = (int **)malloc(r1 * sizeof(int *));
    for (int j = 0; j < r1; j++)
        matrix1[j] = (int *)malloc(c1 * sizeof(int));

    matrix2 = (int **)malloc(r2 * sizeof(int *));
    for (int j = 0; j < r2; j++)
        matrix2[j] = (int *)malloc(c2 * sizeof(int));

    matrixProd = (int **)malloc(r1 * sizeof(int *));
    for (int j = 0; j < r1; j++)
        matrixProd[j] = (int *)malloc(c2 * sizeof(int));

    writeMatrix(r1, c1, matrix1);
    writeMatrix(r2, c2, matrix2);

    for (int rr = 0; rr < r1; rr++)
        for (int i = 0; i < c2; i++)
        {
            int sum = 0;
            for (int cc = 0; cc < c1; cc++)
            {
                sum += *(*(matrix1 + rr) + cc) * *(*(matrix2 + cc) + i);
            }
            *(*(matrixProd + rr) + i) = sum;
        }

    readMatrix(r1, c2, matrixProd);

    for (int i = 0; i < r1; i++)
    {
        free(matrix1[i]);
        free(matrixProd[i]);
    }
    for (int i = 0; i < r2; i++)
        free(matrix2[i]);
    free(matrix1);
    free(matrix2);
    free(matrixProd);
}
void ex1And2()
{
    unsigned int r, c;
    char opt;

    do
    {
        printf("row number:");
        scanf("%u", &r);
        printf("column number:");
        scanf("%u", &c);
        if (r != c)
            printf("The matrix has to be square!!\n");
    } while (r != c);

    printf("\nr: %u - c: %u", r, c);

    int **matrix = (int **)malloc(r * sizeof(int *));
    for (int i = 0; i < r; i++)
        matrix[i] = (int *)malloc(c * sizeof(int));

    do
    {
        printf("\nWhat do you want to do?\n\t(a)write matrix\n\t(b)read matrix\n\t(c)calculate the dash\n\t(d)check the simmetry\n\t(e)calculate the product of two matrices\n");
        scanf(" %c", &opt);

        switch (opt)
        {
        case 'a':
            writeMatrix(r, c, matrix);
            break;
        case 'b':
            readMatrix(r, c, matrix);
            break;
        case 'c':
            dashCalculation(r, c, matrix);
            break;
        case 'd':
            printf(isSymmetrical(r, c, matrix));
            break;
        case 'e':
            matrixProduct(r, c, matrix);
            break;
        default:
            break;
        }
    } while (opt == 'a' || opt == 'b' || opt == 'c' || opt == 'd');

    void resetArray(int **arr, int rowN)
    {
        for (int i = 0; i < rowN; i++)
            free(arr[i]);
    }
}

typedef struct Party
{
    int id;
    unsigned int votesN;
    int end_seat_result[];
} party;

void getVotes(party *parties, unsigned int lN)
{
    for (int i = 0; i < lN; i++)
    {
        (parties + i)->id = i;
        printf("Number of votes from party %d: ", (parties + i)->id);
        scanf("%u", &(parties + i)->votesN);
    }
}
void setEachListSeats(party *parties, unsigned int availableSeats, unsigned int lN)
{
    int maxId = 0;
    int var12[availableSeats];
    for (int i = 0; i < availableSeats; i++)
    {
        var12[i] = 0;
    }

    for (int i = 0; i < availableSeats; i++)
    {
        for (int j = 0; j < lN; j++)
            if (((parties + j)->votesN / (var12[j] + 1)) > ((parties + maxId)->votesN / (var12[maxId] + 1)))
                maxId = j;
        (parties + maxId)->end_seat_result[i] = ;
    }
}
void showPartiesSeats(party *parties, unsigned int lN)
{
    for (int i = 0; i < lN; i++)
        if ((parties + i)->end_seat_result)
            printf("Party %d, keep the seat %u", (parties + i)->id, (parties + i)->end_seat_result);
}
void ex3()
{
    printf("Welcome to the IPV's 2023 votting system!\n\n");

    unsigned int lN, pN, seatsN;
    printf("How many parties will participate this year?\n");
    scanf("%u", &lN);
    printf("How many seats are available to all parties?");
    scanf("%u", &seatsN);

    party *parties = (party *)malloc(lN * sizeof(party));
    for (int i = 0; i < lN; i++)
        for (int j = 0; j < seatsN; j++)
            (parties + i)->end_seat_result[j] = NULL;

    getVotes(parties, lN);

    setEachListSeats(parties, seatsN, lN);

    showPartiesSeats(parties, lN);

    free(parties);
}

int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex3();
    return 0;
}