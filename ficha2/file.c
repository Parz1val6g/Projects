#include <stdio.h>
#include <locale.h>
#include <math.h>
int potencia(int b, int e)
{
    int s = b;
    for (int i = 1; i < e; i++)
    {
        s *= b;
    }
    return s;
}
int fatorial(int x)
{
    return x == 0 || x == 1 ? 1 : x * fatorial(x - 1);
}
void ex1()
{
    int num, x;
    printf("Numero a calcular:");
    scanf("%d", &num);
    printf("multiplos de %d:", num);
    for (int i = num; i < 100; i += num)
    {
        printf("\n\t%d", i);
    }
}
void ex2()
{
    int ni, nf;
    do
    {
        printf("Insira dois numeros inteiros(1ºn > 2ºn):");
        scanf("%d %d", &nf, &ni);
    } while (ni > nf);
    printf("\nNumeros pares entre %d e %d:", ni, nf);
    do
    {
        printf("\n\t%d", (ni > 0 && ni % 2 == 0) ? ni : ni++);
        ni += 2;
    } while (ni < nf);
}
void ex3()
{
    int n, p = 0;
    printf("Insira um numero com as seguintes caracteristicas:\n\t-inteiro\n\t-positivo\n\tR.:");
    scanf("%d", &n);
    // while (p < n - 1) // with while
    // p += (p == n ? 1 : 2);

    // for (int i = 0; i < n; i += 2) // with for
    // p = i;
    printf("numero par máximo: %d", p);
}
void ex4()
{
    int n;
    do
    {
        printf("Insira um valor de 0-9: ");
        scanf("%d", &n);
    } while (9 < n || n < 0);
}
void ex5()
{
    int i, even = 0, odd = 0;
    while (i >= 0)
    {
        printf("Insira um numero inteiro positivo(nº negativo para terminar):");
        scanf("%d", &i);
        if (i >= 0)
            i % 2 == 0 ? even++ : odd++;
    };
    printf("Há %d numeros pares e %d numeros impares.", even, odd);
}
void ex6()
{
    int n, m;
    printf("numero inteiro: ");
    scanf("%d", &n);
    printf("numero de multiplos: ");
    scanf("%d", &m);

    printf("os %d primeiros multiplos de %d:\n\t", m, n);
    for (int i = 1; i <= m; i++)
        printf("%d x %d = %d\n\t", n, i, n * i);
}
void ex7()
{
    int n, s = 0;
    printf("ultimo numero inteiro positivo:");
    scanf("%d", &n);
    printf("soma dos %d primeiros números inteiros positivos:");
    for (int i = 1; i <= n; i++)
        printf("\n     ->%d", s += i);
}
void ex8()
{
    int n;
    printf("tabuada a realizar:");
    scanf("%d", &n);
    printf("TABUADA DE %d:", n);
    for (int i = 1; i <= 10; i++)
        printf("\n   %d x %d = %d", n, i, n * i);
}
void ex9()
{
    for (int i = 2; i <= 10; i++)
    {
        printf("TABUADA DO %d:", i);
        for (int j = 1; j <= 10; j++)
            printf("\n   %d x %d = %d", i, j, i * j);
        printf("\n=========fim=========\n");
    }
}
void ex10()
{
    int n, s = 0;
    do
    {
        printf("Insere um numero:");
        scanf("%d", &n);
    } while (n < 0);

    for (int i = 1; i <= n; i++)
        s += fatorial(i);
    printf("\n%d", s);
}
void ex11()
{
    int n;
    float s = 0;
    do
    {
        printf("Insere um numero:");
        scanf("%d", &n);
    } while (n < 0);

    for (int i = 1; i <= n; i++)
        s += pow(2, i) / fatorial(i);
    printf("\n%.2f", s);
}
void ex12()
{
    int n;
    printf("Numero Inteiro Positivo:");
    scanf("%d", &n);
    for (int i = n; i > 0; i--)
    {
        if (n % i == 0)
            printf("%d\n", i);
    }
}
void ex13()
{
    int n;
    float soma = 1.0;
    printf("Insere um numero:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            soma += 1.0 / (i * 2);
        else
            soma -= 1.0 / (i * 2);
    }
    printf("%.2f", soma);
}
void ex14()
{
    int n;
    float soma = 1.0, den = 2.0;
    printf("Insere um numero:");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 0)
            soma += i / den;
        else
            soma -= i / den;
        den *= 2.0;
    }
    printf("%.2f", soma); // 0.72 para 5
}
void ex15()
{
    int n;
    printf("Insere um numero:");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
void ex16()
{
    int n;
    do
    {
        printf("Insere um numero:");
        scanf("%d", &n);
    } while (n > 9);

    for (int l = 1; l <= n; l++)
    {
        for (int c = 0; c < n - l; c++)
        {
            printf(" ");
        }
        for (int c = 1; c <= l - 1; c++)
        {
            printf("%d", c);
        }
        for (int c = l; c > 0; c--)
        {
            printf("%d", c);
        }
        printf("\n");
    }
}
void ex17()
{
    int a, b;
    printf("Insere a base:");
    scanf("%d", &a);
    printf("Insere a potência:");
    scanf("%d", &b);
    printf("%d ^ %d = %d", a, b, potencia(a, b));
}
void ex18a()
{
    int n, v, s = 0, i = 0;
    printf("Nº de parcelas:");
    scanf("%d", &n);
    do
    {
        printf("Insere um valor:");
        scanf("%d", &v);
        s += v;
        i++;
    } while (i < n);
    printf(" -Valor total:%d;\n -Parcelas:%d;\n -Média:%d;", s, n, s / n);
}
void ex18b()
{
    int v, s = 0, i = 0;
    while (v > 0)
    {
        printf("Insere um valor:");
        scanf("%d", &v);
        if (v > 0)
        {
            s += v;
            i++;
        }
    };
    printf(" -Valor total:%d;\n -Parcelas:%d;\n -Média:%d;", s, i, s / i);
}
void ex19()
{
    int n, r, t = 0;
    do
    {
        printf("Insere um numero de 0 a 100:");
        scanf("%d", &n);
    } while (n > 100 || n < 0);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    do
    {
        printf("\nAdivinha o numero:");
        scanf("%d", &r);
        if (r > n)
            printf("\t%d é mais maior que o numero.", r);
        if (r < n)
            printf("\t%d é mais pequeno que o numero.", r);
        t++;
    } while (r != n);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    printf("Adivinhaste o numero %d em %d tentativas. MESTREEE!", n, t);
}
void ex20()
{
    int ano, mes, dia, a, b, c, d, e;
    char opcao;
    do
    {
        do
        {
            printf("Indique um ano, entre 1900 e 2099 \n");
            scanf("%d", &ano);
        } while (ano < 1900 || ano > 2099);
        a = ano % 19;
        b = ano % 4;
        c = ano % 7;
        d = (19 * a + 24) % 30;
        e = (2 * b + 4 * c + 6 * d + 5) % 7;
        if (d + e > 9)
        {
            mes = 4;
            dia = d + e - 9;
        }
        else
        {
            mes = 3;
            dia = 22 + d + e;
        }
        printf("\n\nA Pascoa de %d ocorre em %d/%d \n\n", ano, dia, mes);
        printf("Pretende continuar (s/n)? ");
        scanf(" %c", &opcao); // "truque": ESPAÇO antes de %
    } while ((opcao == 's') || (opcao == 'S'));
}
void main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex20();
}
