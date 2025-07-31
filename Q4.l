%{
#include <stdio.h>
#include <stdlib.h>

int comment_lines = 0;
FILE *outfile;
%}

/* Rules */
%%

"//".*              {
                      comment_lines++;
                      /* ignore single-line comment */
                    }

"/*"([^*]|\*+[^*/])*"*"+"/"    {
                      // multi-line comment
                      for (int i = 0; yytext[i]; i++) {
                        if (yytext[i] == '\n')
                          comment_lines++;
                      }
                    }

.|\n                {
                      fputc(yytext[0], outfile); // write other content to file
                    }

%%

int yywrap() {
    return 1;
}

int main() {
    char filename[50];

    printf("Enter output file name (e.g., cleaned.c): ");
    scanf("%s", filename);

    // Clear stdin buffer before taking input
    getchar();

    outfile = fopen(filename, "w");
    if (!outfile) {
        perror("Failed to open output file");
        exit(1);
    }

    printf("Paste your C code below. Press Ctrl+D (or Ctrl+Z on Windows) to end input:\n");

    yylex();

    fclose(outfile);
    printf("\nTotal comment lines removed: %d\n", comment_lines);
    printf("Cleaned code saved in: %s\n", filename);

    return 0;
}

