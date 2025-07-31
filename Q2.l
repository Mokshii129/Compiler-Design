%{
#include <stdio.h>

int lines = 0, words = 0, chars = 0;
%}

%%

[ \t]+              { chars += yyleng; }              // spaces, tabs
\n                  { lines++; chars++; }             // newline
[A-Za-z0-9]+        { words++; chars += yyleng; }     // words
.                   { chars++; }                      // any other character

%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", chars);
    return 0;
}

