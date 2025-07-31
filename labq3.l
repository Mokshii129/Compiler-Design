#include <stdio.h>
#include <string.h>
#define SIZE 10

int main() {
    char non_terminal;
    char alpha[SIZE], beta[SIZE];
    int num;
    char production[10][SIZE];

    printf("Enter Number of Productions: ");
    scanf("%d", &num);
    printf("Enter the grammar (e.g., E->E-A or E->Ea|b):\n");

    for (int i = 0; i < num; i++) {
        scanf("%s", production[i]);
    }

    for (int i = 0; i < num; i++) {
        printf("\nGRAMMAR: %s", production[i]);
        non_terminal = production[i][0];

        if (production[i][3] == non_terminal) {
            // Left recursion detected
            int j = 4, k = 0;
            while (production[i][j] != '\0' && production[i][j] != '|') {
                alpha[k++] = production[i][j++];
            }
            alpha[k] = '\0';

            if (production[i][j] == '|') {
                j++; // skip '|'
                k = 0;
                while (production[i][j] != '\0') {
                    beta[k++] = production[i][j++];
                }
                beta[k] = '\0';

                printf("\nLeft recursion detected.");
                printf("\nGrammar without left recursion:\n");
                printf("%c -> %s%c'\n", non_terminal, beta, non_terminal);
                printf("%c' -> %s%c' | ε\n", non_terminal, alpha, non_terminal);
            } else {
                printf("\nOnly left recursive production found. Cannot be simplified without alternate (β).");
            }
        } else {
            printf("\nNo left recursion.");
        }
    }

    return 0;
}

