#include <stdio.h>
#include <string.h>

int main() {
    char gram[50], part1[25], part2[25];
    char modifiedGram[25], newGram[25];
    int i, j = 0, k = 0, pos = 0;

    printf("Enter Production (A->): ");
    fgets(gram, sizeof(gram), stdin);  // safe input

    // Remove newline if present
    gram[strcspn(gram, "\n")] = '\0';

    // Split into part1 and part2 at '|'
    for (i = 0; gram[i] != '|'; i++, j++)
        part1[j] = gram[i];
    part1[j] = '\0';

    for (j = ++i, i = 0; gram[j] != '\0'; j++, i++)
        part2[i] = gram[j];
    part2[i] = '\0';

    // Find common prefix
    for (i = 0; part1[i] != '\0' && part2[i] != '\0'; i++) {
        if (part1[i] == part2[i]) {
            modifiedGram[k++] = part1[i];
            pos = i + 1;
        } else {
            break;
        }
    }

    // Extract differing parts into newGram
    j = 0;
    for (i = pos; part1[i] != '\0'; i++)
        newGram[j++] = part1[i];
    newGram[j++] = '|';
    for (i = pos; part2[i] != '\0'; i++)
        newGram[j++] = part2[i];
    newGram[j] = '\0';

    // Finish modified grammar
    modifiedGram[k++] = 'X';
    modifiedGram[k] = '\0';

    // Final output
    printf("\nA->%s", modifiedGram);
    printf("\nX->%s\n", newGram);

    return 0;
}

