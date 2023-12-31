#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>

#define MAX_STR 25
#define MAX_STUDENTS 50
#define BOOK_MAX_STR 30
#define MAX_NAME 50

typedef int bool;
#define true 1
#define false 0

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
    int id;
    char title[30];
    char author[30];
    char type[20];
    int year;
} book;

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
    int l1 = fabs(v1.x - v2.x), l2 = fabs(v1.y - v2.y);

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
    books += *count;
    printf("BOOK Nº%d:\n\tTITLE:", *count);
    fseek(stdin, 0, 2);
    fgets(books->title, BOOK_MAX_STR, stdin);
    fseek(stdin, 0, 2);

    printf("\tAUTHOR: ");
    fseek(stdin, 0, 2);
    fgets(books->author, BOOK_MAX_STR, stdin);
    fseek(stdin, 0, 2);

    printf("\tTYPE: ");
    fseek(stdin, 0, 2);
    fgets(books->type, BOOK_MAX_STR - 10, stdin);
    fseek(stdin, 0, 2);

    printf("\tYEAR: ");
    scanf("%d", &books->year);
    books->id = *count;
    (*count)++;
}
void listBooks(book *books, int *count)
{
    for (int i = 0; i < *count; i++)
    {
        printf("BOOK %s:\n\tWriten by  %s. \n\tTYPE: %s;\n\tWriten in %d.\n", books->title, books->author, books->type, books->year);
        books++;
    }
}
int bookExist(book *books, char book[], int count)
{
    int id;
    for (int i = 0; i < count; i++)
    {
        printf("book:%s\nbook->title:%s", book, books->title);
        if (!strcmp(book, books->title))
        {
            printf("bookexists");
            id = books->id;
        }
        books++;
    }
    return id;
}
void removeBook(book *books, int *count)
{
    char bookTitle[BOOK_MAX_STR];
    printf("What book do you want to remove from the list?");
    fseek(stdin, 0, 2);
    fgets(bookTitle, BOOK_MAX_STR, stdin);
    int id = bookExist(books, bookTitle, *count);
    printf("\nid:%d", id);
    if (id == 0)
    {
        printf("Book not found in the list.\n");
        return;
    }

    for (int i = id; i < *count; i++)
        books[i] = books[i + 1];

    (*count)--;
}
void ex4()
{

    book books[50];
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
            listBooks(books, &count);
            break;
        case 'c':
            removeBook(books, &count);
            break;
        default:
            break;
        }
    } while (opt == 'a' || opt == 'b' || opt == 'c');
}

/*typedef struct Theater
{
    int row;
    seat seat;
} room;*/
typedef struct Seat
{
    char name[50];
    bool paid;
} Seat;
void askInputs(int *rown, int *seatn)
{
    while (true)
    {
        printf("\nHow many rows a single room can have?");
        if (scanf("%d", rown) == 1)
            break;
        printf("Invalid input!!");
        while (getchar() != '\n')
            ;
    }
    while (true)
    {
        printf("\nHow many seats can fit heach row?");
        if (scanf("%d", seatn) == 1)
            break;
        printf("Invalid input!!");
        while (getchar() != '\n')
            ;
    }
}
void createReservation(int rowN, int seatN, Seat *seats)
{
    printf("\nNEW RESERVATION:\n");
    int row, seat;
    do
    {
        row = 0;
        printf("\t-row n:");
        if (scanf("%d", &row) != 1 && (row > rowN || row <= 0))
        {
            printf("Invalid row number!\n");
            while (getchar() != '\n')
                ;
        }
    } while (row > rowN || row <= 0);

    do
    {
        seat = 0;
        printf("\t-seat n:");
        if (scanf("%d", &seat) != 1 && (seat > seatN || seat <= 0))
        {
            printf("Invalid seat number!\n");
            while (getchar() != '\n')
                ;
        }
    } while (seat > seatN || seat <= 0);

    seat--;
    row--;

    Seat *currentPos = seats += (row * seatN + seat);

    printf("Person name:");
    fseek(stdin, 0, 2);
    fgets(currentPos->name, MAX_NAME, stdin);
    fseek(stdin, 0, 2);
    currentPos->name[strcspn(currentPos->name, "\n")] = '\0';

    printf("Pay now or later?\n\t(1)now\t(0)later\n");
    scanf("%d", &currentPos->paid);

    printf(strlen(currentPos->name) ? "Reservation created successfully!!" : "Reservation not created!!");
    seats -= (row * rowN + seat);
}
void removeReservation(int rowN, int seatN, Seat *seats)
{
    printf("CANCEL RESERVATION:\n");
    int row, seat;
    do
    {
        printf("\t-row n:");
        scanf("%d", &row);
    } while (row > rowN || row <= 0);

    do
    {
        printf("\t-seat n:");
        scanf("%d", &seat);
    } while (seat > seatN || seat <= 0);

    char name2[MAX_NAME];
    Seat *currentPos = seats += (row * rowN + seat);
    if (*currentPos->name != '\0')
    {
        printf("To cancel the reservation enter your name:");
        fseek(stdin, 0, 2);
        fgets(name2, MAX_NAME, stdin);
        fseek(stdin, 0, 2);
        if (strcmp(name2, currentPos->name))
        {
            strcpy(currentPos->name, "");
            currentPos->paid = false;
            if (strcmp(currentPos->name, "") && !(currentPos->paid))
                printf("Reservation Cancelled!");
        }
        else
        {
            printf("Wrong name!");
        }
    }
    else
    {
        printf("The seat isn't yet reserv'd.\nOperation Cancelled!!");
    }
}
void showOccupationMap(int rowN, int seatN, Seat *seats)
{
    printf("Occupation Map:\n");
    int count = 0;
    for (int r = 1; r <= rowN; r++)
    {
        for (int s = 1; s <= seatN; s++)
        {
            char status = ' ';
            status = (strlen(seats->name) && seats->paid)
                         ? 'X'
                         : (strlen(seats->name) && !(seats->paid)
                                ? '-'
                                : ' ');
            printf("  [%c]  ", status);
            *seats++;
        }
        printf("\n");
    }
    printf("\n[X]-reserved_&_paid\t[-]-reserved_&_unpaid\t[ ]-not_reserved");
}
void listReservations(int rowN, int seatN, Seat *seats)
{
    printf("Reservation List: ");
    bool count = false;
    for (int r = 1; r <= rowN; r++)
    {
        for (int s = 1; s <= seatN; s++)
        {
            if (strlen(seats->name))
            {
                printf("\n\nSeat(%d-%d):\n\tname:%s\n\tpaid:%d", seatN, rowN, seats->name, seats->paid);
                count = true;
            }
            seats++;
        }
    }
    if (!count)
        printf("EMPTY LIST!!");
}

void ex5()
{
    int rown, seatn;
    printf("Welcome to the IPV Show!\n");
    askInputs(&rown, &seatn);
    Seat seats[rown][seatn];
    for (int i = 0; i < rown * seatn; i++)
    {
        memset(seats[i / seatn][i % seatn].name, 0, MAX_NAME);
        seats[i / seatn][i % seatn].paid = 0;
    }
    char opt;
    do
    {
        printf("\nWhat do you want to do?\n\t(a)create new reservation\n\t(b)cancel reservation\n\t(c)ocupation map\n\t(d)reservation list\n");
        scanf(" %c", &opt);

        switch (opt)
        {
        case 'a':
            createReservation(rown, seatn, (Seat *)seats);
            break;
        case 'b':
            removeReservation(rown, seatn, (Seat *)seats);
            break;
        case 'c':
            showOccupationMap(rown, seatn, (Seat *)seats);
            break;
        case 'd':
            listReservations(rown, seatn, (Seat *)seats);
            break;
        default:
            break;
        }
    } while (opt == 'a' || opt == 'b' || opt == 'c' || opt == 'd');
}

int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex5();
    return 0;
}