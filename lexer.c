#include <stdio.h>
#include <ctype.h>
#include <string.h>

define MAX_TOKEN_LENGTH 100

void getToken(FILE *fp)
int isKeyword(const char *word)
int isOperator(char ch)
int isDelimiter(char ch)

char *keywords[] = {"if", "else", "while", "return", "int", "float"};
int numKeywords = 6;

int main(){
    FILE *fp = fopen("source_code.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    getToken(fp);
    fclose(fp);
    return 0;
}

void getToken(FILE *fp) {
    char token[MAX_TOKEN_LENGTH];
    int i= 0;
    char currentChar;

    while ((currentChar = fgetc(fp)) != EOF) {
        if (isspace(currentChar)) {
            continue; // Skip whitespace
        } else if (isalpha(currentChar)) {
            token[index++] = currentChar;
            while (isalnum((currentChar = fgetc(fp)) ) || currentChar == '_') {
                token[i++]= currentChar;
            }
            token[index] = '\0';
            ungetc(currentChar, fp); // Put back the last character
           
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            i = 0;
        } else if (isdigit(currentChar)) {
            token[i++] = currentChar;
            while (isdigit((currentChar = fgetc(fp)) )){
                token[i++] = currentChar;
            }
            token[i] = '\0';
            ungetc(currentChar, fp); // Put back the last character
            printf("Number: %s\n", token);
            i = 0;
        } else if (isOperator(currentChar)) {
            printf("Operator: %c\n", currentChar);
        } else if (isDelimiter(currentChar)) {
            printf("Delimiter: %c\n", currentChar);
        } else {
            printf("Unknown character: %c\n", currentChar);
        }
    }
}

int isKeyword(const char *word) {
    const char *keywords[] = {"if", "else", "while", "return", "int", "float"};
    for (int i = 0; keywords[i] != NULL; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1; // It's a keyword
        }
    }
    return 0; // Not a keyword
}

int isOperator (char ch) {
   return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '>' || ch == '<' || ch == '&' || ch == '|');
}

int isDelimiter(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '.');
}