#include <stdio.h>
#include <stdlib.h>

int add (int a, int b);
int sub (int a, int b);
int mult (int a, int b);
int divide (int a, int b);
int exit_prog ( int a , int b);


// Create an array of function pointers
//int (ops[])(int a, int b) = {&add, &sub, &mult, &divide, &exit_prog};

typedef int (*OP) (int a, int b);


int main()
{
    int a, b;
    int c;

    OP operators[5] = {&add, &sub, &mult, &divide, &exit_prog};
    // in loop
    while (1)
    {
        // take input for two integers to operate
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        // show menu
        printf("0: Add\n1: Subtraction\n2: Multiplication\n3: Division\n4: Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &c);

        // call corresponding function
        printf("Result = %d\n", (*operators[c])(a, b));
    }
    return 0;
}

int add (int a, int b) { printf ("Adding a and b \n"); return (a + b); }
int sub (int a, int b) { printf ("Subtracting a and b\n"); return (a - b); }
int mult (int a, int b) { printf ("Multiplying a and b\n"); return (a * b); }
int divide (int a, int b) { printf ("Dividing a and b\n"); return (a / b); }
int exit_prog(int a, int b) { exit(1); }
