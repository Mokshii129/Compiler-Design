#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char s[20], stack[20];

int main() {
    char m[5][6][4] = {
        {"tb",   "",    "",   "tb",  "",    ""},
        {"" , "+tb", "",   "",   "n",  "n"},
        {"fc",  "",   "",   "fc",  "",    ""},
        {"" ,  "",  "*fc", "",   "n",  "n"},
        {"i",   "",   "",  "(e)", "",   ""}
    };

    int size[5][6] = {
        {2,0,0,2,0,0},
        {0,3,0,0,1,1},
        {2,0,0,2,0,0},
        {0,0,3,0,1,1},
        {1,0,0,3,0,0}
    };

    int i, j, k, n, str1 = 0, str2 = 0;
    printf("\nEnter the input string: ");
    scanf("%s", s);
    strcat(s, "$");
    n = strlen(s);
    stack[0] = '$';
    stack[1] = 'e';
    i = 1;
    j = 0;

    printf("\nStack\tInput\n");
    printf("______________\n");

    while ((stack[i] != '$') && (s[j] != '$')) {
        if (stack[i] == s[j]) {
            i--;
            j++;
        } else {
            switch (stack[i]) {
                case 'e': str1 = 0; break;
                case 'b': str1 = 1; break;
                case 't': str1 = 2; break;
                case 'c': str1 = 3; break;
                case 'f': str1 = 4; break;
            }

            switch (s[j]) {
                case 'i': str2 = 0; break;
                case '+': str2 = 1; break;
                case '*': str2 = 2; break;
                case '(': str2 = 3; break;
                case ')': str2 = 4; break;
                case '$': str2 = 5; break;
            }

            if (strcmp(m[str1][str2], "") == 0) {
                printf("\nERROR\n");
                exit(1);
            } else if (strcmp(m[str1][str2], "n") == 0) {
                i--;
            } else {
                i--;
                for (k = size[str1][str2] - 1; k >= 0; k--) {
                    i++;
                    stack[i] = m[str1][str2][k];
                }
            }
        }

        // Print stack
        for (k = 0; k <= i; k++)
            printf("%c", stack[k]);
        printf("\t");

        // Print input
        for (k = j; k <= n; k++)
            printf("%c", s[k]);
        printf("\n");
    }

    printf("\nSUCCESS\n");
    return 0;
}

