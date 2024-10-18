#include <stdio.h>
#include <string.h>

#define swap(t, x, y) { \
  t swapped = x; \
  x = y; \
  y = swapped; \
}

int main() {
  char type[9];
  // obtain the type of the inputs that will be swapped
  printf("Enter the type [integer, char, float]: ");
  scanf("%8s", type); // limit user input to not go past the scope of my string
  printf("You entered: %s\n", type);
  /* 
    I had to use the strcmp() function to compare the value of the type variable the user
    provided with the different types for our defined swap. Depending on the users input, 
    different values are provided for the print statements and the t value of swap
  */
  // testing for integer
  if(strcmp(type, "integer") == 0){
    int input1, input2;
    printf("Enter the first integer: ");
    scanf("%d", &input1);
    printf("Enter the second integer: ");
    scanf("%d", &input2);
    printf("Before swapping: input1 = %d, input2 = %d\n", input1, input2);
    swap(int, input1, input2);
    printf("After swapping: input1 = %d, input2 = %d\n", input1, input2);
  }
  // testing for char 
  else if(strcmp(type, "char") == 0){
    /*
      I ran into an issue where after inputting my first char for input1, the newline character
      created from hitting enter in the terminal would carry over and immediatley be used for the 
      input for my input2 variable. getchar() solved my issue by clearing the buffered newline characters
      or any remaining characters passed in by the user (since I only really want to swap a single character), 
      allowing the user input to be correctly read into my variables
    */
    char input1, input2;
    while(getchar() != '\n');
    printf("Enter the first char: ");
    scanf("%1c", &input1);
    while(getchar() != '\n');
    printf("Enter the second char: ");
    scanf("%1c", &input2);
    printf("Before swapping: input1 = %c, input2 = %c\n", input1, input2);
    swap(char, input1, input2);
    printf("After swapping: input1 = %c, input2 = %c\n", input1, input2);
  }
  // testing for float 
  else if(strcmp(type, "float") == 0){
    float input1, input2;
    printf("Enter the first float number: ");
    scanf("%f", &input1);
    printf("Enter the second float number: ");
    scanf("%f", &input2);
    printf("Before swapping: input1 = %.3f, input2 = %.3f\n", input1, input2);
    swap(float, input1, input2);
    printf("After swapping: input1 = %.3f, input2 = %.3f\n", input1, input2);
  } 
  // base case to catch whether or not the user inputs a value we do not want for the type
  else {
    printf("Incompatible input entered.\n");
  };

  return 0;
}