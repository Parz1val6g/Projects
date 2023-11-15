#include "../filemode.h"

void ex1()
{
    FILE *f = fopen("C:\\tmp\\ola.txt", "r");
}
int main()
{
    setlocale(LC_ALL, "pt_PT.utf8");
    ex1();
    return 0;
}
