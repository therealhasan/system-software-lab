#include <stdio.h>

int RAM[3] = {0};
int R[3] = {0};

// CISC Addition
void cisc_add()
{
    RAM[2] = RAM[0] + RAM[1];
    printf("CISC Result: %d\n", RAM[2]);
}

// RISC Operations
void risc_add()
{
    R[0] = RAM[0];  // LOAD
    R[1] = RAM[1];  // LOAD
    R[2] = R[0] + R[1];  // ADD
    RAM[2] = R[2];  // STORE

    printf("RISC Result: %d\n", RAM[2]);
}

int main()
{
    printf("Enter A: ");
    scanf("%d", &RAM[0]);

    printf("Enter B: ");
    scanf("%d", &RAM[1]);

    cisc_add();

    RAM[2] = 0;

    risc_add();

    return 0;
}