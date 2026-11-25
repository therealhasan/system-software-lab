#include <stdio.h>

int main()
{
    int load, i;
    
    // Read memory address
    printf("Enter load address in Hex: ");
    scanf("%x", &load);

    // Two object modules
    int A[] = {0x1000, 0x2000, 0x9999, 0xF000};
    int B[] = {0x3000, 0x4000, 0xF000};

    // Linked array
    int C[7];

    // Copy Module A
    for(i = 0; i < 4; i++)
        C[i] = A[i];

    // Resolve external symbol FOO
    C[2] = 0x1004;

    // Copy Module B
    for(i = 0; i < 3; i++)
        C[i+4] = B[i];

    // Display memory map
    printf("\nMemory Address\tData\n");

    for(i = 0; i < 7; i++)
        printf("0x%04X\t\t0x%04X\n", load+i, C[i]);

    return 0;
}