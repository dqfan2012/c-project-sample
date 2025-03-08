#include <stdio.h>
#include <stdlib.h>
#include "calculator.h"

int main(void) {
  int num1, num2;
  char op;

  printf("Simple Calculator\n");
  printf("Supported operations: add, subtract, multiply, and divide (for integers only).\n");
  printf("Enter calculation (e.g., 3 + 4): ");

  if (scanf("%d %c %d", &num1, &op, &num2) != 3) {
    printf("Invalid input. Please enter in the format: number operator number\n");
    return EXIT_FAILURE;
  }

  switch (op) {
    case '+':
      printf("%d + %d = %d\n", num1, num2, add(num1, num2));
      break;
    case '-':
      printf("%d - %d = %d\n", num1, num2, subtract(num1, num2));
      break;
    case '*':
      printf("%d * %d = %d\n", num1, num2, multiply(num1, num2));
      break;
    case '/':
      if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
      } else {
        printf("%d / %d = %.2f\n", num1, num2, divide(num1, num2));
      }
      break;
    default:
      printf("Error: Unsupported operator '%c'.\n", op);
      break;
  }

  return EXIT_SUCCESS;
}
