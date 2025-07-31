%{
#include <stdio.h>
#include <stdlib.h>
int posint = 0, negint = 0, posfraction = 0, negfraction = 0;
%}

%%
[-][0-9]+\.[0-9]+      { negfraction++; }
[-][0-9]+              { negint++; }
[+]?[0-9]+\.[0-9]+     { posfraction++; }
[+]?[0-9]+             { posint++; }
%%

int yywrap() {
    return 1;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <inputfile>\n", argv[0]);
        exit(0);
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    yyin = file;
    yylex();
    fclose(file);

    printf("No of +ve integers = %d\n", posint);
    printf("No of -ve integers = %d\n", negint);
    printf("No of +ve fractions = %d\n", posfraction);
    printf("No of -ve fractions = %d\n", negfraction);
    return 0;
}

