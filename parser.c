#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef enum{NUM,PLUS,MINUS,MUL,DIV,LPAREN,RPAREN,END} TokenType;
typedef struct{
    TokenType type;
    int value;
} Token;

const char *input;
Token currentToken;

Token getNextToken(TokenType type);
void eat(TokenType type);
int factor();
int term();
int expr();

Token getNextTokne(){
    while (*input != '\0'){
        if (isspace(*input)){
            input++;
        }
       Token token ;
       if(*input == '\0'){
        token.type = END;
       }
       else if(*input == '+'){
        token.type = PLUS;
        input++;
       }
       else if(*input == '-'){
        token.type = MINUS;
        input++;
       }
       else if(*input == '*'){
        token.type = MUL;
        input++;
       }
       else if(*input == '/'){
        token.type = DIV;
        input++;
       }
       else if(*input == '('){
        token.type = LPAREN;
        input++;
       }
       else if(*input == ')'){
        token.type = RPAREN;
        input++;
       }
       else if(isdigit(*input)){
        token.type = NUM;
        token.value = 0;
        token.value = token.value * 10 + (*input - '0');
        input++;
        }
        else{
            token.type = END;

        }
        return token;

    }
    

    int main(){
        const char *expression = "3 +5 *(10-4)";
        input = expression ;
        currentToken = getNextToken();
        int result = expr();
        printf("Result: %d\n", result);
        return 0;
        
    }

 void eat (TokenType type){
    if (currentToken.type == type){
        currentToken = getNextToken();
    }
    else{
        printf("Error: Unexpected token\n");
        exit(1);
    }

    int factor(){
        int result = 0;
        if(currentToken.type == NUM){
            result = currentToken.value;
            eat(NUM);
        }
        else if(currentToken.type == LPAREN){
            eat(LPAREN);
            result = expr();
            eat(RPAREN);
        }
        else{
            printf("Error: Unexpected token\n");
            exit(1);
        }
        return result;
    }

    int term(){
        int result = factor();
        while(currentToken.type == MUL || currentToken.type == DIV){
            if(currentToken.type == MUL){
                eat(MUL);
                result *= factor();
            }
            else if(currentToken.type == DIV){
                eat(DIV);
                result /= factor();
            }
        }
        return result;
    }

    int expr(){
        int result = term();
        while(currentToken.type == PLUS || currentToken.type == MINUS){
            if(currentToken.type == PLUS){
                eat(PLUS);
                result += term();
            }
            else if(currentToken.type == MINUS){
                eat(MINUS);
                result -= term();
            }
        }
        return result;
    }


