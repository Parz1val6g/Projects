#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define MAX_STR 25
#define MAX_STUDENTS 50
#define BOOK_MAX_STR 30

void ex1()
{
    struct vertex
    {
        int x, y;
    };
    struct vertex v1, v2;
    printf("\nvertex 1:\n\tx:");
    scanf("%d", &v1.x);
    printf("\ty:");
    scanf("%d", &v1.y);
    printf("\nvertex 2:\n\tx:");
    scanf("%d", &v2.x);
    printf("\ty:");
    scanf("%d", &v2.y);
    int l1 = sqrt(pow(v1.x - v2.x, 2)), l2 = sqrt(pow(v1.y - v2.y, 2));

    /*int vertex[2][2], l1, l2;
    printf("\nvertex 1:\n\tx:");
    scanf("%d", &vertex[0][0]);
    printf("\ty:");
    scanf("%d", &vertex[0][1]);
    printf("\nvertex 2:\n\tx:");
    scanf("%d", &vertex[1][0]);
    printf("\ty:");
    scanf("%d", &vertex[1][1]);

    l1 = sqrt(pow(vertex[0][0] - vertex[1][0], 2));
    l2 = sqrt(pow(vertex[0][1] - vertex[1][1], 2));*/

    printf("Length:%d / Width:%d;", l1 > l2 ? l1 : l2, l1 < l2 ? l1 : l2);
    printf("\nArea: %d; \nDiagonal: %.2f; ", l1 * l2, sqrt(pow(l1, 2) + pow(l2, 2)));
}
typedef struct Fraction
{
    int numerator;
    int denominator;
} fraction;
typedef struct Student
{
    int number;
    char name[MAX_STR];
    int grade;
} student;
typedef struct Book
{
    char title[30];
    char author[30];
    char type[20];
    int year;
} book;

void additionAndSubtraction(fraction f1, fraction f2, int add_sub)
{
    if (f1.denominator != f2.denominator)
    {
        int newDenominator = f1.denominator * f2.denominator;

        f1.numerator *= f2.denominator;
        f2.numerator *= f1.denominator;

        f1.denominator = f2.denominator = newDenominator;
    }
    printf("\n(%d/%d) %c (%d/%d) = (%d/%d);", f1.numerator, f1.denominator, (add_sub ? '-' : '+'), f2.numerator, f2.denominator, add_sub ? f1.numerator - f2.numerator : f1.numerator + f2.numerator, f1.denominator);
}
void multiplication(fraction f1, fraction f2)
{
    printf("\n(%d/%d) x (%d/%d) = (%d/%d);", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f1.numerator * f2.numerator, f1.denominator * f2.denominator);
}
void division(fraction f1, fraction f2)
{
    printf("\n(%d/%d) / (%d/%d) = (%d/%d);", f1.numerator, f1.denominator, f2.numerator, f2.denominator, f1.numerator * f2.denominator, f1.denominator * f2.numerator);
}
void getFraction(fraction *fs)
{
    do
    {
        printf("Insert value for this fraction:\n\tnumerador:");
        scanf("%d", &fs->numerator);
        printf("\tdenominator:");
        scanf("%d", &fs->denominator);
    } while (fs->denominator <= 0);
}
void ex2()
{
    fraction f1, f2;
    getFraction(&f1);
    getFraction(&f2);
    printf("\nAddition:");
    additionAndSubtraction(f1, f2, 0);
    printf("\n\nSubtraction:");
    additionAndSubtraction(f1, f2, 1);
    printf("\n\nMultiplication:");
    multiplication(f1, f2);
    printf("\n\nDivision:");
    division(f1, f2);
}

void ex3a()
{
    char bool;
    int i, stnum;
    student students[MAX_STUDENTS];
    for (i = 1; i <= MAX_STUDENTS; i++)
    {
        printf("Assign new student:\n\t(Y)yes\t(N)no\n");
        scanf(" %c", &bool);
        if (bool == 'Y' || bool == 'y')
        {
            students[i].number = i;
            printf("Enter student number %d info:\n\tName: ", i);
            getchar();
            fgets(students[i].name, MAX_STR, stdin);
            printf("\tGrade:");
            scanf("%d", &students[i].grade);
        }
        else
            break;
    }
    printf("\nSTUDENTS LIST:\n");
    for (int j = 1; j < i; j++)
    {
        printf("\n\tStudent nº%d:\n\t\tName: %s\t\tGrade: %d", students[j].number, students[j].name, students[j].grade);
    }
    bool = 'y';
    while (bool == 'y' || bool == 'Y')
    {
        printf("\n\nWitch student you want to check individualy?\nstudent nº:");
        scanf("%d", &stnum);
        if (stnum < i && stnum > 0)
        {
            printf("\n\tStudent nº%d:\n\t\tName: %s\t\tGrade: %d", students[stnum].number, students[stnum].name, students[stnum].grade);
            printf("\nCheck other student?\n\t(Y)yes\t(N)no\n");
            scanf(" %c", &bool);
        }
        else
        {
            printf("\nWRONG NUMBER!");
        }
    };
}

void newStudent(student *students, int *count, char bool)
{
    do
    {
        if (*count < MAX_STUDENTS)
        {
            printf("Assign new student:\n\t(Y)yes\t(N)no\n");
            scanf(" %c", &bool);
            if (bool != 'y' && bool != 'Y')
                break;
            (*count)++;
            students[*count - 1].number = *count;
            printf("Enter student number %d info:\n\tName: ", *count);
            getchar();
            fgets(students[*count - 1].name, MAX_STR, stdin);
            printf("\tGrade: ");
            scanf("%d", &students[*count - 1].grade);
        }
        else
        {
            printf("Student limit has been reached!!");
            break;
        }
    } while (bool == 'y' || bool == 'Y');
}
void getStudentInfo(student *students, int count)
{
    if (count > 0)
    {
        printf("\n%d\n", count);
        printf("\nSTUDENTS LIST:\n");
        for (int j = 1; j <= count; j++)
        {
            printf("\n\tStudent nº%d:\n\t\tName: %s\t\tGrade: %d", students->number, students->name, students->grade);
            students++;
        }
    }
}
void obtainIndividualStudentInformation(student *students, int count, char bool)
{
    int stnum;
    do
    {
        printf("\n\nWitch student you want to check individualy?\nstudent nº:");
        scanf("%d", &stnum);
        if (stnum < count && stnum > 0)
        {
            students += stnum - 1;
            printf("\n\tStudent nº%d:\n\t\tName: %s\t\tGrade: %d", students->number, students->name, students->grade);
            printf("\nCheck other student?\n\t(Y)yes\t(N)no\n");
            scanf(" %c", &bool);
            if (bool != 'y' && bool != 'Y')
                break;
        }
        else
            printf("\nWRONG NUMBER!");
    } while (bool == 'y' || bool == 'Y');
}
void ex3b()
{
    char bool;
    int count = 0;
    student *students;
    newStudent(students, &count, bool);
    getStudentInfo(students, count);
    obtainIndividualStudentInformation(students, count, bool);
}

void newBook(book *books, int *count)
{
    (*count)++;
    printf("BOOK Nº%d:\n\tTITLE:", *count);
    getchar();
    fgets(books->title, BOOK_MAX_STR, stdin);

    printf("\tAUTHOR:");
    getchar();
    fgets(books->author, BOOK_MAX_STR, stdin);

    printf("\tTYPE:");
    getchar();
    fgets(books->type, BOOK_MAX_STR - 10, stdin);

    printf("\tYEAR:");
    scanf("%d", books->year);
}
void listBooks(book *books, int count)
{
    for (int i = 1; i < count; i++)
        printf("BOOK Nº%d:\n\tTITLE: %s;\n\tAUTHOR: %s;\n\tTYPE: %s;\n\tYEAR: %d;\n", i, books->title, books->author, books->type, books->year);
}
void removeBook(book *books, int *count)
{
    int n;
    do
    {
        printf("What book do you want to remove from the list?");
        scanf("%d", &n);
    } while (n > *count || n <= 0);
    for (int i = 1; i < *count; i++)
        books[n + (i - 1)] = books[n + i];
    *count--;
}
/*void askOperation(book *books, int count)
{
    char opt;
    printf("\nWhat do you want to do?\n(a)register new book\t(b)show books\t(c)remove book\n");
    scanf(" %c", &opt);
    switch (opt)
    {
    case 'a':
        newBook(books, &count);
        break;
    case 'b':
        listBooks(books, count);
        break;
    case 'c':
        removeBook(books, &count);
        break;
    default:
        break;
    }
}*/

void ex4()
{
    book *books;
    int count = 0;
    char opt;

    printf("WELCOME TO THE IPV's LIBRARY!!\n");

    do
    {
        printf("\nWhat do you want to do?\n(a)register new book\t(b)show books\t(c)remove book\n");
        scanf(" %c", &opt);

        switch (opt)
        {
        case 'a':
            newBook(books, &count);
            break;
        case 'b':
            listBooks(books, count);
            break;
        case 'c':
            removeBook(books, &count);
            break;
        default:
            break;
        }
    } while (opt == 'a' || opt == 'b' || opt == 'c');
}

int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex4();
    return 0;
}