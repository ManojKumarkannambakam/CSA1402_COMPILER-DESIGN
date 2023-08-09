#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_TERMINALS 50
#define MAX_PRODUCTIONS 50

char terminals[MAX_TERMINALS];
char productions[MAX_PRODUCTIONS][50];
int numTerminals = 0;
int numProductions = 0;

void addToFirst(char variable, char terminal) {
    int varIndex = variable - 'A';
    int termIndex = terminal - 'a';
    terminals[varIndex] |= (1 << termIndex);
}

void calculateFirst(char variable) {
    int varIndex = variable - 'A';
    if (terminals[varIndex] != 0)
        return;

    for (int i = 0; i < numProductions; ++i) {
        if (productions[i][0] == variable) {
            char nextSymbol = productions[i][2];
            if (nextSymbol >= 'a' && nextSymbol <= 'z') {
                addToFirst(variable, nextSymbol);
            } else if (nextSymbol >= 'A' && nextSymbol <= 'Z') {
                calculateFirst(nextSymbol);
                for (int j = 0; j < numTerminals; ++j) {
                    if (terminals[nextSymbol - 'A'] & (1 << (terminals[j] - 'a'))) {
                        addToFirst(variable, terminals[j]);
                    }
                }
            }
        }
    }
}

int main() {
    printf("Enter the number of terminals: ");
    scanf("%d", &numTerminals);
    printf("Enter the terminal symbols (a-z): ");
    scanf("%s", terminals);

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    printf("Enter the productions in the format A -> x: \n");
    for (int i = 0; i < numProductions; ++i) {
        scanf("%s", productions[i]);
    }

    char variable;
    printf("Enter the variable to calculate FIRST for: ");
    scanf(" %c", &variable);

    calculateFirst(variable);

    printf("FIRST(%c) = { ", variable);
    for (int i = 0; i < numTerminals; ++i) {
        if (terminals[variable - 'A'] & (1 << (terminals[i] - 'a'))) {
            printf("%c ", terminals[i]);
        }
    }
    printf("}\n");

    return 0;
}
