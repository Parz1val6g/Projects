#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

void changeValues(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ex1()
{
    int a, b;

    printf("Insert value to a:");
    scanf("%d", &a);
    printf("Insert value to b:");
    scanf("%d", &b);

    changeValues(&a, &b);

    printf("a:%d; b:%d", a, b);
}

void ex2()
{
    char *word;
    printf("Write one word:");
    scanf("%s", word);

    printf("%s", word);
}

void arrayConcatenation(char *str1, char *str2)
{
    int i = 0, j = 0;
    char *str3;
    while (str1[i] != '\0')
        i++;
    for (int j = 0; str2[j] != '\0'; j++)
    {
        str1[i++] = str2[j];
    }
    str1[i] = '\0';
}
void ex3()
{

    char *str1, *str2;
    printf("Write one word:");
    scanf("%s", str1);
    printf("Write another word:");
    scanf("%s", str2);
    arrayConcatenation(str1, str2);
    printf("\n%s", str1);
}

void aa(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Insert a value to an vector:\n(PRESS «0» TO EXIT)\n");
        scanf("%d", ptr++);
    }
}
void bb(int *ptr, int n)
{
    for (int i = 0; i < n; i++)
        printf("vet[%d]=%d;\n", i, *ptr++);
}
void cc(int *ptr, int n)
{
    printf("Vector in reverse order:");
    for (int i = (n - 1); i >= 0; i--)
        printf("\nvet[%d]=%d;", i, *(ptr--));
}
void dd(int *ptr, int n)
{
    int b, s, bN = 0, sN = 0;
    b = 0;
    s = 99;
    for (int j = 0; j < n; j++)
    {
        if (*ptr > b)
        {
            b = *ptr;
            bN = j;
        }
        if (*ptr < s)
        {
            s = *ptr;
            sN = j;
        }
        ptr++;
    }
    printf("\nVator MAIOR: vet[%d]=%d\nVator mais pequeno: vet[%d]=%d", bN, b, sN, s);
}
void ee(int *ptr, int n)
{
    int s, sN = 0;
    s = 99;
    for (int j = 0; j < n; j++)
    {
        if (*ptr < s)
        {
            s = *ptr;
            sN = j;
        }
        ptr++;
    }
}
void ff(int *ptr, int n, int *s)
{
    for (int i = 0; i < n; i++)
    {
        *s += *ptr;
        ptr++;
    }
    printf("\nSomatório(vet)=%d", *s);
}
void gg(int n, int s, float *avg)
{
    *avg = (float)s / n;
    printf("\nAverage:%.2f", *avg);
}
void hh(int *ptr, int vet[], int n, float avg)
{
    int ss = 0, ii = 0;

    for (int j = 0; j < n; j++)
    {
        *ptr > avg ? ss++ : ii++;
        ptr++;
    }
    printf("\nNumber of elements larger than average( %.2f ): %d;\nNumber of elements smaller than average( %.2f ): %d;", avg, ss, avg, ii);
}
void ii(int *ptr1, int *ptr2, int n)
{
    for (int i = 0; i < n; i++)
    {
        *ptr2 = *ptr1 * 2;
        ptr1++;
        ptr2++;
    }
}
void jj(int *ptr1, int *ptr2, int *ptr3, int n)
{
    for (int i = 0; i < n; i++)
    {
        *ptr3 = *ptr1;
        ptr1++;
        ptr3++;
        *ptr3 = *ptr2;
        ptr2--;
        ptr3++;
    }
    ptr3 -= n * 2;
    printf("ptr1+ptr2=ptr3");
    for (int i = 0; i < n * 2; i++)
    {
        printf("\nptr3[%d]=%d;", i, *ptr3);
        ptr3++;
    }
}
void ex4()
{
    int n;
    printf("n:");
    scanf("%d", &n);
    int vet[n], *ptr1 = vet, s = 0, vet2[n], *ptr2 = vet2, vet3[2 * n], *ptr3 = vet3;
    float avg = 0;
    aa(ptr1, n);
    bb(ptr1, n);
    cc((ptr1 + n - 1), n);
    dd(ptr1, n);
    ee(ptr1, n);
    ff(ptr1, n, &s);
    gg(n, s, &avg);
    hh(ptr1, vet, n, avg);
    ii(ptr1, ptr2, n);
    jj(ptr1, (ptr2 + n - 1), ptr3, n);
}

int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex4();
    return 0;
}