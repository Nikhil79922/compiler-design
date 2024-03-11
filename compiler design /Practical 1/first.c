#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


enum TokenType {

NUMBER,
ADD,
SUBTRACT,

MULTIPLY,
DIVIDE,
LPAREN,
RPAREN,
END_OF_INPUT
};

// Token structure
struct Token {
enum TokenType type;
int value; // Only used for NUMBER tokens
};

// Function to get the next token from the input
struct Token getNextToken() {
static int currentChar = ' ';
while (isspace(currentChar)) {
currentChar = getchar();
}
struct Token token;
if (isdigit(currentChar)) {
// Token is a NUMBER
token.type = NUMBER;
token.value = 0;
while (isdigit(currentChar)) {
token.value = token.value * 10 + (currentChar - '0');

currentChar = getchar();
}
} else if (currentChar == '+') {
token.type = ADD;
currentChar = getchar();
} else if (currentChar == '-') {
token.type = SUBTRACT;
currentChar = getchar();
} else if (currentChar == '*') {
token.type = MULTIPLY;
currentChar = getchar();
} else if (currentChar == '/') {
token.type = DIVIDE;
currentChar = getchar();
} else if (currentChar == '(') {
token.type = LPAREN;
currentChar = getchar();
} else if (currentChar == ')') {
token.type = RPAREN;
currentChar = getchar();
} else if (currentChar == EOF) {
token.type = END_OF_INPUT;
} else {
// Invalid character
printf("Error: Invalid character '%c'\n", currentChar);
exit(EXIT_FAILURE);

}
return token;
}
int main() {
printf("Enter an arithmetic expression: ");
struct Token token;
do {
token = getNextToken();
switch (token.type) {
case NUMBER:
printf("Number: %d\n", token.value);
break;
case ADD:
printf("Addition (+)\n");
break;
case SUBTRACT:
printf("Subtraction (-)\n");
break;
case MULTIPLY:
printf("Multiplication (*)\n");
break;
case DIVIDE:
printf("Division (/)\n");
break;
case LPAREN:
printf("Left Parenthesis\n");

break;
case RPAREN:
printf("Right Parenthesis\n");
break;
case END_OF_INPUT:
printf("End of Input\n");
break;
}
} while (token.type != END_OF_INPUT);

return 0;
}