#include <stdio.h>

int main()
{
    FILE* f = fopen("dados.txt","w");
    fprintf(f,"%s,%d,%f\n","Renato Mauro",49,1.84);
    fclose(f);
    return 0;
}