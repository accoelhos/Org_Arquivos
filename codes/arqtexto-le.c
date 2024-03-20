#include <stdio.h>

int main()
{
    FILE* f = fopen("dados.txt","r");
    char nome[40];
    int idade;
    float altura;
    fscanf(f,"%s%d%f",nome,&idade,&altura);
    printf("%s %d %f\n",nome,idade,altura);
    fclose(f);
    return 0;
}