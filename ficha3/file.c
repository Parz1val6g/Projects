#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int isDigit(char c)
{
    return c >= 48 && c <= 57;
}
int isAlpha(char c)
{
    return c >= 97 && c <= 122 || c >= 65 && c <= 90;
}
int isAlNum(char c)
{
    return isDigit(c) || isAlpha(c);
}
char toLower(char c)
{
    if (isAlpha(c))
        return c + 32;
}
char toUpper(char c)
{
    if (isAlpha(c))
        return c - 32;
}
void ex1()
{
    char c = 0;
    printf("Insere um valor:");
    scanf("%c", &c);
    printf(isDigit(c) == 0 ? "não é um digito" : "é um digito");
    printf("\n");
    printf(isAlpha(c) == 0 ? "não é uma letra" : "é uma letra");
    printf("\n");
    printf(isAlNum(c) == 0 ? "não é um caracter alfanumérico" : "é um caracter alfanumérico");
    printf("\n");
    printf("%c", toLower(c));
    printf("\n");
    printf("%c", toUpper(c));
}

int resto(int a, int b)
{
    return a % b;
}
int impar(int x)
{
    return x % 2 != 0;
}
int perfeito(int n)
{
    int s = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            s += i;
    }
    return s == n;
}
int primo(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return 0;
    }
    return 1;
}
void ex2()
{
    char o;
    int a = 0, b = 0;
    while (o != 'x')
    {
        printf("\n\nEscolha uma opção:\n(a)resto\t(b)impar\t(c)perfeito\t(d)primo\t(x)sair\n");
        scanf(" %c", &o);
        switch (o)
        {
        case 'a':
            printf("Insere dois valores:");
            scanf("%d %d", &a, &b);
            printf("resto de %d, com %d é igual a %d", a, b, resto(a, b));
            break;
        case 'b':
            printf("Insere um valor:");
            scanf("%d", &a);
            printf(impar(a) ? "o numero %d é impar\n" : "o numero %d é par\n", a);
            break;
        case 'c':
            printf("Insere um valor:");
            scanf("%d", &a);
            printf(perfeito(a) == 1 ? "é perfeito" : "não é perfeito");
            break;
        case 'd':
            printf("Insere um valor:");
            scanf("%d", &a);
            printf(primo(a) ? "é primo" : "não é primo");
            break;
        default:
            break;
        }
    };
}

int somaDivisores(int n)
{
    int s = 0;

    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            s += i;
    }
    return s;
}
void classNum(int a, int b)
{
    int r = 0, ab = 0, p = 0;
    for (int n = a; n < b; n++)
    {
        int s = somaDivisores(n);
        printf("%d é %s\n", n,
               s < n ? "reduzido" : (s > n ? "abundante" : "perfeito"),
               s < n ? r++ : (s > n ? ab++ : p++));
    }
    printf("Números Reduzidos: %d\n", r);
    printf("Números Abundantes: %d\n", ab);
    printf("Números Perfeitos: %d\n", p);
}
void ex3()
{
    int a, b;
    do
    {
        scanf("%d %d", &a, &b);
    } while (a >= b || a <= 0 || b <= 0);
    classNum(a, b);
}
int pow3(int n)
{
    return n * n * n;
}
void ex4()
{
    int n;
    scanf("%d", &n);
    printf("%d", pow3(n));
}
void ex5()
{
    int s1, s2;
    scanf("%d %d", &s1, &s2);
    printf("%d %s %d", s1, (s1 > s2 ? ">" : "<"), s2);
}

int getArrSz()
{
    int szArr;
    printf("Quantos valores pretende inserir?");
    scanf("%d", &szArr);
    return szArr;
}
void getElement(int arr[], int arrSz)
{
    int i = 0;
    while (i < arrSz)
    {
        printf("Insere um valor:");
        scanf("%d", &arr[i]);
        i++;
    };
}
void showArr(int arr[], int szArr)
{
    for (int i = 0; i < szArr; i++)
    {
        printf("\n-arr[%d]: %d", i, arr[i]);
    }
}
void highestPos(int arr[], int szArr)
{
    int max = arr[0], pos;
    for (int i = 1; i < szArr; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            pos = i;
        }
    }
    printf("\nO valor maior é %d e encontra-se na posição %d.", max, pos);
}
void ex6()
{
    int szArr = getArrSz();
    int arr[szArr];
    getElement(arr, szArr);
    showArr(arr, szArr);
    highestPos(arr, szArr);
}

void ex7()
{
    int s = 0, n = 0;
    printf("tamanho dos vetores:");
    scanf("%d", &n);
    int vetores[2][n];
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Insere um valor para vetor[%d][%d]: ", i, j);
            scanf("%d", &vetores[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        s += vetores[0][i] * vetores[1][i];
    }
    printf("\nsoma dos vetores: %d", s);
}

void ex8()
{
    int n, p, q, temp = 0;
    printf("Nº de elementos do vetor x:");
    scanf("%d", &n);
    int x[n];
    for (int i = 0; i < n; i++)
    {
        printf("%c[%d]:", 'x', i);
        scanf("%d", &x[i]);
    }
    printf("Trocar valor da posição:");
    scanf("%d", &p);
    printf("Com a posição:");
    scanf("%d", &q);
    temp = x[q];
    x[q] = x[p];
    x[p] = temp;
    for (int i = 0; i < n; i++)
    {
        printf("\nx[%d]: %d", i, x[i]);
    }
}

void setMatrix(int l, int c, int matriz[l][c])
{
    for (int ll = 0; ll < l; ll++)
    {
        for (int cc = 0; cc < c; cc++)
        {
            printf("matriz[%d][%d]: ", ll, cc);
            scanf("%d", &matriz[ll][cc]);
        }
    }
}
void showMatriz(int l, int c, int matriz[l][c])
{
    for (int ll = 0; ll < l; ll++)
    {
        for (int cc = 0; cc < c; cc++)
        {
            printf("\nmatriz[%d][%d] = %d;", ll, cc, matriz[ll][cc]);
        }
    }
}
void minValue(int l, int c, int matriz[l][c])
{
    int min = matriz[0][0], posc = 0, posl = 0;
    for (int ll = 0; ll < l; ll++)
    {
        for (int cc = 0; cc < c; cc++)
        {
            if (min > matriz[ll][cc])
            {
                min = matriz[ll][cc];
                posl = ll;
                posc = cc;
            }
        }
    }
    printf("\nVALOR MENOR: matriz[%d][%d] = %d;", posl, posc, min);
}
int isSymmetrical(int l, int c, int matriz[l][c])
{
    int bool = 1;
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
            if (matriz[x][y] != matriz[y][x])
                bool = 0;
        }
    }
    return bool;
}
int transposedMatrix(int l, int c, int matriz[l][c])
{
    for (int i = 0; i < l; i++)
    {
        for (int j = i + 1; j < c; j++)
        {
            int x = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = x;
            x = 0;
        }
    }
}
int addMatrices(int l, int c, int matriz1[l][c], int matriz2[l][c])
{
    int finalMatrix[l][c];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            finalMatrix[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    showMatriz(l, c, finalMatrix);
}
void ex9()
{
    int c, l;
    do
    {
        printf("Linhas da matriz:");
        scanf("%d", &l);
        printf("Colunas da matriz:");
        scanf("%d", &c);
    } while (c != l);
    int matriz[l][c];
    setMatrix(l, c, matriz);

    showMatriz(l, c, matriz);
    minValue(l, c, matriz);
    printf(isSymmetrical(l, c, matriz) ? "\nMatriz é simétrica" : "\nMatriz não é simétrica");
    transposedMatrix(l, c, matriz);
    showMatriz(l, c, matriz);
    printf("\n\nCALCULAR SOMA DE DUAS MATRIZES:\n");
    do
    {
        printf("Linhas das matrizes:");
        scanf("%d", &l);
        printf("Colunas das matrizes:");
        scanf("%d", &c);
    } while (c != l);
    int matriz1[l][c];
    int matriz2[l][c];
    setMatrix(l, c, matriz1);
    setMatrix(l, c, matriz2);
    addMatrices(l, c, matriz1, matriz2);
}

int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex9();
    return 0;
}