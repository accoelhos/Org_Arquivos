#include <stdio.h>

int main(int argc, char** argv)
{
    FILE* f = fopen(argv[1],"r");
    char linha[1024];
    while(fgets(linha,1024,f)) {
        fputs(linha,stdout);
    }
    fclose(f);
    return 0;
}