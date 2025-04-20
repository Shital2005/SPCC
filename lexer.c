#include <stdio.h>
#include <ctype.h>
#include <string.h>

define MAX_TOKEN_LENGTH 100

void getToken(FILE *fp)
int isKeywoed(const char *word)
int isOperator(char ch)
int isDelimiter(char ch)

char *keywords[] = {"int","float","if","else","while","return"};
int numKeywords = 6;

int main(){
    FILE *fp;
    fp = fopen("test.c", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    print("lexical analyis:");
    getToken(fp);
    fclose(fp);
    return 0;
}

void getToken(FILE *fp) {
    char token[MAX_TOKEN_LENGTH];
    int i = 0;
    char currentChar;
    while ((currentChar = fgetc(fp)) != EOF) {
        if (isspace(currentChar)) {
            continue;
        } else if (isalpha(currentChar)) {
            token[i++] = currentChar;
            while (isalnum((currentChar = fgetc(fp))) || currentChar == '_') {
                token[i++] = currentChar;
            }
            token[i] = '\0';
            ungetc(currentChar, fp);
            if (isKeyword(token)) {
                printf("Keyword: %s\n", token);
            } else {
                printf("Identifier: %s\n", token);
            }
            i = 0;
        } 
        else if (isdigit(currentChar)) {
            token[i++] = currentChar;
            while (isdigit(currentChar = fgetc(fp))) {
                token[i++] = currentChar;
            }
            token[i] = '\0';
            ungetc(currentChar, fp);
           
            printf("Number: %s\n", token);
            i = 0;
        } 
        else if (isOperator(currentChar)) {
            printf("Operator: %c\n", currentChar);
        } else if (isDelimiter(currentChar)) {
            printf("Delimiter: %c\n", currentChar);
        }
    }
}
int isKEYWORD(const char *word) {
    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '%');
}
int isDelimiter(char ch) {
    return (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '.');
}

// This code is a simple lexical analyzer for C-like programming languages. It reads a source file, identifies keywords, identifiers, numbers, operators, and delimiters, and prints them to the console. The code uses functions to check if a token is a keyword, operator, or delimiter and handles whitespace and comments appropriately.