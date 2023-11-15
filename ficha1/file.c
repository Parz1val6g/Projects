#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <float.h>

void ex1()
{
	float base, altura;
	printf("Insira os valores da Base e Altura do Triangulo\n");
	printf("Base:");
	scanf("%f", &base);
	printf("Altura:");
	scanf("%f", &altura);
	printf("A area do triangulo e de %.2fm quadrados.", base * altura / 2);
}
void ex2()
{
	float product, cash;
	printf("Valor do produto:");
	scanf("%f", &product);
	printf("Dinheiro Disponivel:");
	scanf("%f", &cash);
	int unidades = cash / product;
	printf("E possivel comprar %d produtos com %.2f euros.", unidades, cash);
}
void ex3()
{
	int num1, num2, num3;
	printf("Insira os valores de tres numeros:");
	scanf("%d %d %d", &num1, &num2, &num3);
	if (num1 > num2 && num1 > num3)
	{
		printf("%d e o maior", num1);
	}
	else
	{
		if (num2 > num1 && num2 > num3)
		{
			printf("%d e o maior", num2);
		}
		else
		{
			if (num3 > num1 && num3 > num2)
			{
				printf("%d e o maior", num3);
			}
		}
	}
}
void ex4()
{
	int num;
	printf("Insira um numero inteiro:");
	scanf("%d", &num);
	printf("\n");
	if (num > 0)
	{
		printf("o numero %d e positivo.", num);
	}
	else
	{
		if (num == 0)
		{

			printf("o numero %d e nulo.", num);
		}
		else
		{
			printf("o numero %d e negativo.", num);
		}
	}
}
void ex5()
{
	int num;
	printf("Insira um numero inteiro:");
	scanf("%d", &num);
	printf("\n");
	num % 2 == 0 ? printf("Numero par.") : printf("numero impar");
}
void ex6()
{
	float side1, side2;
	printf("Insere valores para os dois lados dos triangulos:\n");
	printf("lado 1:");
	scanf("%f", &side1);
	printf("lado 2:");
	scanf("%f", &side2);
	printf("Terceiro Lado:%.2f", sqrt(pow(side1, 2) + pow(side2, 2)));
}
void ex7()
{
	int num1, num2;
	printf("Insira dois numeros inteiros:\n");
	scanf("%d", &num1);
	scanf("%d", &num2);
	printf("\n");
	num1 / num2 == 0 ? printf("e multiplo") : printf("nao e multiplo");
}
void ex8()
{
	char opt;
	float side1, side2, side3, radius;
	const float pi = 3.141593;
	printf("Escolha uma forma geometrica:\n(a)quadrado\t(b)retangulo\t(c)circulo\n");
	scanf("%c", &opt);
	switch (opt)
	{
	case 'a':
		printf("Insira os valor de um lado:\n");
		scanf("%f", &side1);
		printf("Area do Quadrado: %.1f;\nPerimetro do Quadrado: %.1f", pow(side1, 2), side1 * 4);
		break;
	case 'b':
		printf("Insira os valor dos lados:\n\tLado 1:");
		scanf("%f", &side1);
		printf("\tLado 2:");
		scanf("%f", &side2);
		printf("Area do Retangulo: %.1f;\nPerimetro do Retangulo: %.1f", side1 * side2, (side1 * 2) + (side2 * 2));
		break;
	case 'c':
		printf("Insira o valor do raio:\n\tRaio:");
		scanf("%f", &radius);
		printf("Area do Circulo: %.1f;\nPerimetro do Circulo: %.1f", pi * pow(radius, 2), 2 * pi * radius);
		break;
	default:
		break;
	}
}
void ex9()
{
	float num1, num2;
	printf("Insere dois numeros para efetuar operações.\nnumero 1:");
	scanf("%f", &num1);
	printf("numero2:");
	scanf("%f", &num2);
	int aux = num1 / num2;
	printf("Soma:\n\t%.2f+%.2f=%.2f", num1, num2, num1 + num2);
	printf("\nDivisao:\n\t%.2f/%.2f=%.2f", num1, num2, num1 / num2);
	printf("\nResto:\n\t%.2f", num1 - (num2 * aux));
	printf("\nProduto:\n\t%.2fx%.2f=%.2f", num1, num2, num1 * num2);
}
void ex10()
{
	int ano;
	printf("Insere um ano:");
	scanf("%d", &ano);
	(ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) ? printf("Ano Bisexto") : printf("Ano Comum");
}
void ex11()
{
	int dia, mes, ano;
	printf("Insere uma data:\n");
	scanf("%d %d %d", &dia, &mes, &ano);
	switch (mes)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		printf("Faltam %d dias!", 30 - dia);
		break;
	case 2:
		printf("Faltam %d dias!", (ano % 4 == 0 && ano % 100 != 0 || ano % 400 == 0) ? 29 - dia : 28 - dia);
		break;
	default:
		printf("Faltam %d dias!", 31 - dia);
	}
}
void ex12()
{
	int i, v, x, r, m, n, y, maior;
	i++;
	v = (x == 8 || x == 80);
	r = x % 2;
	m = (x % n == 0);
	maior = (x > y);
	int temp;
	do
	{
		printf("minutos decorridos desde a meia noite:");
		scanf("%d", &temp);
	} while (0 > temp || temp >= 1440);
	printf("%02d:%02d", temp / 60, temp % 60);
}
void ex13_ex14()
{
	int temp;
	do
	{
		printf("minutos decorridos desde a meia noite:");
		scanf("%d", &temp);
	} while (0 > temp || temp >= 1440);
	if (temp <= 779)
		printf("%02d:%02d a.m.", temp / 60, temp % 60);
	else
		printf("%02d:%02d p.m.", (temp / 60) - 12, temp % 60);
}
void ex15()
{
	float a, b, c;
	printf("insere o valor de:\n");
	do
	{
		printf("\ta->");
		scanf("%f", &a);
	} while (a == 0);
	printf("\tb->");
	scanf("%f", &b);
	printf("\tc->");
	scanf("%f", &c);
	float delta = (b * b) - (4 * a * c);
	if (!(delta < 0))
		printf("x = %.2f U x = %.2f", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
	else
		printf("Não existe raizes reais!");
}
void ex16()
{
	int a;
	printf("Numero Inteiro:");
	scanf("%d", &a);
	printf("%8.d\n", a);
	printf("%-8d", a);
}
void ex17()
{
	float a;
	printf("Numero Real:");
	scanf("%f", &a);
	printf("%.3f", a);
}
void ex18()
{
	int opt, val;
	printf("Converter:\n(a)cm<=>pol\t(b)kg<=>lbs\t(c)l<=>gal\t(d)Cº<=>Fº\n");
	char type = getchar();
	switch (type)
	{
	case 'a':
		printf("[1]cm->pol\t[2]pol->cm\n");
		scanf("%d", &opt);
		printf(opt == 1 ? "cm:" : "pol:");
		scanf("%d", &val);
		printf("%.2f", opt == 1 ? val * 2.54 : val / 2.54);
		break;
	case 'b':
		printf("[1]kg->lbs\t[2]lbs->kg\n");
		scanf("%d", &opt);
		printf(opt == 1 ? "kg:" : "lbs:");
		scanf("%d", &val);
		printf("%.4f", opt == 1 ? val * 0.4536 : val / 0.4536);
		break;
	case 'c':
		printf("[1]l->gal\t[2]gal->l\n");
		scanf("%d", &opt);
		printf(opt == 1 ? "l:" : "gal:");
		scanf("%d", &val);
		printf("%.3f", opt == 1 ? val * 3.785 : val / 3.785);
		break;
	case 'd':
		printf("[1]Cº->Fº\t[2]Fº->Cº\n");
		scanf("%d", &opt);
		printf(opt == 1 ? "Cº:" : "Fº:");
		scanf("%d", &val);
		printf("%.2f", opt == 1 ? 1.8 * val + 32 : (val - 32) / 1.8);
		break;
	}
}
void ex19()
{
	printf("Insere valores:");
	char val = getchar();
	if (val >= 'a' && val <= 'z')
		printf("letra minuscula");
	else if (val >= 'A' && val <= 'Z')
		printf("letra Maiuscula");
	else if (val >= '0' && val <= '9')
		printf("digito");
	else if ((val >= 33 && val <= 47) || (val >= 58 && val <= 64) || (val >= 91 && val <= 96) || (val >= 123 && val <= 126))
		printf("sinal de pontuação");
	else
		printf("outro caractere");
}
void ex20()
{
	float num1, num2;
	char op;
	printf("operação:");
	scanf("%f%c%f", &num1, &op, &num2);
	switch (op)
	{
	case '/':
		if (num2 != 0)
			printf("%.2f / %.2f = %.2f", num1, num2, num1 / num2);
		else
			printf("ERR");
		break;
	case '*':
		printf("%.2f x %.2f = %.2f", num1, num2, num1 * num2);
		break;
	case '-':
		printf("%.2f - %.2f = %.2f", num1, num2, num1 - num2);
		break;
	case '+':
		printf("%.2f + %.2f = %.2f", num1, num2, num1 + num2);
		break;
	}
}
void ex21()
{
	printf("Tipo char:\nTamanho em bytes: %zu\nValor minimo: %d\nValor maximo: %d\n\n", sizeof(char), CHAR_MIN, CHAR_MAX);

	printf("Tipo short:\nTamanho em bytes: %zu\nValor minimo: %d\nValor maximo: %d\n\n", sizeof(short), SHRT_MIN, SHRT_MAX);

	printf("Tipo int:\nTamanho em bytes: %zu\nValor minimo: %d\nValor maximo: %d\n\n", sizeof(long int), INT_MIN, INT_MAX);

	printf("Tipo long:\nTamanho em bytes: %zu\nValor minimo: %ld\nValor maximo: %ld\n\n", sizeof(long), LONG_MIN, LONG_MAX);

	printf("Tipo float:\nTamanho em bytes: %zu\nValor minimo: %e\nValor maximo: %e\n\n", sizeof(float), FLT_MIN, FLT_MAX);

	printf("Tipo double:\nTamanho em bytes: %zu\nValor minimo: %e\nValor maximo: %e\n\n", sizeof(double), DBL_MIN, DBL_MAX);
}
void main()
{
	setlocale(LC_ALL, "pt_PT.utf8");
	//  exX();
}