#include <stdio.h>
#include <stdint.h>

int main()
{
    char *code[] = {
        "LOAD R1, 10",
        "LOAD R2, 20",
        "ADD R3, R1, R2",
        "SUB R1, R3, R1",
        "STORE R3, 255",
        "HALT"
    };

    int r1, r2, r3, v;
    unsigned short mc;

    for (int i = 0; i < 6; i++)
    {
        if (sscanf(code[i], "LOAD R%d, %d", &r1, &v) == 2)
            mc = 0x1000 | (r1 << 8) | v;

        else if (sscanf(code[i], "STORE R%d, %d", &r1, &v) == 2)
            mc = 0x2000 | (r1 << 8) | v;

        else if (sscanf(code[i], "ADD R%d, R%d, R%d", &r1, &r2, &r3) == 3)
            mc = 0x3000 | (r1 << 8) | (r2 << 4) | r3;

        else if (sscanf(code[i], "SUB R%d, R%d, R%d", &r1, &r2, &r3) == 3)
            mc = 0x4000 | (r1 << 8) | (r2 << 4) | r3;

        else if (code[i][0] == 'H')
            mc = 0xF000;

        else
        {
            printf("Syntax Error\n");
            continue;
        }

        printf("0x%04X: %04X\n", i, mc);
    }

    return 0;
}