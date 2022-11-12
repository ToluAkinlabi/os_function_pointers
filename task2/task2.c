#include <stdio.h>
#include <stdlib.h>

typedef int (*Operate) (const void *a, const void *b);

// For addition
int add(const void *a, const void *b)
{
    // cast arguments to true type
    int x = *(int *)a;
    int y = *(int *)b;
    
    return x + y;
}

// For subtraction
int sub(const void *a, const void *b)
{
    // cast arguments to true type
    int x = *(int *)a;
    int y = *(int *)b;
    
    return x - y;
}

// For multiplication
int mul(const void *a, const void *b)
{
    // cast arguments to true type
    int x = *(int *)a;
    int y = *(int *)b;
    
    return x * y;
}

// For division
int divs(const void *a, const void *b)
{
    // cast arguments to true type
    int x = *(int *)a;
    int y = *(int *)b;
    // have checking for denominator being 0
    return (y != 0 ? (x / y) : 0);
}

// For exit
int exit_prog(const void *a, const void *b)
{
    exit(1);
}

// Create an array of function pointers
Operate ops[] = {&add, &sub, &mul, &divs, &exit_prog};

int main()
{
    int a, b;
    char c;
    // in loop
    while (1)
    {
        // take input for two integers to operate
        printf("Enter two integers: ");
        scanf("%d %d", &a, &b);
        // show menu
        printf("0: Add\n1: Subtraction\n2: Multiplication\n3: Division\n4: Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &c);
        // cast to int from 0 to 4
        c -= '0';
        // call corresponding function
        printf("Result = %d\n", ops[c](&a, &b));
    }
    return 0;
}
