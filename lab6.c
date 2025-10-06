#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0, j = 0, no = 0, tmpch = 90; // tmpch = 'Z'
char str[100], left[15], right[15];

struct exp {
    int pos;
    char op;
} k[15];

void findopr();
void explore();
void fleft(int);
void fright(int);

int main() {
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression: ");
    scanf("%s", str);

    printf("The intermediate code:\n");
    findopr();
    explore();

    return 0;
}

void findopr() {
    j = 0;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':' || str[i] == '/' || str[i] == '*' || str[i] == '+' || str[i] == '-' || str[i] == '=') {
            k[j].pos = i;
            k[j].op = str[i];
            j++;
        }
    }
    k[j].op = '\0'; // Mark end of operators
}

void explore() {
    i = 0;
    while (k[i].op != '\0') {
        fleft(k[i].pos);
        fright(k[i].pos);

        str[k[i].pos] = tmpch--;  // Replace operator with temporary variable (Z, Y, X...)

        printf("\t%c := %s %c %s\n", str[k[i].pos], left, k[i].op, right);

        i++;
    }

    // After processing all operators, print final assignment if any
    if (tmpch < 90) {
        printf("\t%s := %c\n", left, str[k[i - 1].pos]);
    } else {
        // If no operators, just print original expression
        printf("\t%s := %s\n", str, str);
    }
}

// Extract left operand (to the left of operator at position x)
void fleft(int x) {
    int w = 0;
    int flag = 0;
    x--;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '=' &&
           str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':' && str[x] != '$') {
        if (str[x] != '$' && flag == 0) {
            left[w++] = str[x];
            left[w] = '\0';
            str[x] = '$'; // mark visited
            flag = 1;
        }
        x--;
    }
    // Reverse the left operand because we collected it backward
    int len = strlen(left);
    for (int a = 0; a < len / 2; a++) {
        char temp = left[a];
        left[a] = left[len - a - 1];
        left[len - a - 1] = temp;
    }
}

// Extract right operand (to the right of operator at position x)
void fright(int x) {
    int w = 0;
    int flag = 0;
    x++;
    while (x != -1 && str[x] != '+' && str[x] != '*' && str[x] != '\0' &&
           str[x] != '=' && str[x] != ':' && str[x] != '-' && str[x] != '/') {
        if (str[x] != '$' && flag == 0) {
            right[w++] = str[x];
            right[w] = '\0';
            str[x] = '$'; // mark visited
            flag = 1;
        }
        x++;
    }
}

