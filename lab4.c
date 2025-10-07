#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int x = 0, n, i = 0, j = 0;
    void *mypointer, *T4Tutorials_address[15];
    char ch, c;
    char T4Tutorials_Array2[15], T4Tutorials_Array3[15];

    printf("Input the expression ending with $ sign: ");
    while ((c = getchar()) != '$' && i < 15) {
        T4Tutorials_Array2[i] = c;
        i++;
    }
    n = i - 1;

    printf("Given Expression: ");
    i = 0;
    while (i <= n) {
        printf("%c", T4Tutorials_Array2[i]);
        i++;  // <-- semicolon added here
    }

    printf("\n\nSymbol Table display\n");
    printf("Symbol \t addr \t type\n");

    j = 0;
    while (j <= n) {
        c = T4Tutorials_Array2[j];
        if (isalpha((unsigned char)c)) {
            mypointer = malloc(1);
            T4Tutorials_address[x] = mypointer;
            T4Tutorials_Array3[x] = c;
            printf("%c \t %p \t identifier\n", c, mypointer);  // use %p for pointers
            x++;
            j++;  // <-- semicolon added here
        } else {
            ch = c;
            if (ch == '+' || ch == '-' || ch == '*' || ch == '=') {
                mypointer = malloc(1);
                T4Tutorials_address[x] = mypointer;
                T4Tutorials_Array3[x] = ch;
                printf("%c \t %p \t operator\n", ch, mypointer);  // use %p here too
                x++;
                j++;  // <-- semicolon added here
            } else {
                j++;  // <-- semicolon added here
            }
        }
    }

    // Free allocated memory
    for (i = 0; i < x; i++) {
        free(T4Tutorials_address[i]);
    }

    return 0;
}

