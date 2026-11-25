#include <stdio.h>
#include <string.h>

int main()
{
    char l[20], o[20], p[20], name[20];
    char mdt[10][3][20];
    int i, n = 0;

    FILE *f1, *f2, *f3;

    // Open files
    f1 = fopen("MACIN.txt", "r");
    f2 = fopen("MACOUT.txt", "w");
    f3 = fopen("MDT.txt", "w");

    if (f1 == NULL || f2 == NULL || f3 == NULL)
    {
        printf("File error");
        return 1;
    }

    fscanf(f1, "%s %s %s", l, o, p);

    while (strcmp(o, "END") != 0)
    {
        // Macro definition
        if (strcmp(o, "MACRO") == 0)
        {
            strcpy(name, l);
            fscanf(f1, "%s %s %s", l, o, p);

            // Store instructions in MDT
            while (strcmp(o, "MEND") != 0)
            {
                strcpy(mdt[n][0], l);
                strcpy(mdt[n][1], o);
                strcpy(mdt[n][2], p);

                fprintf(f3, "%s %s %s\n", l, o, p);

                n++;
                fscanf(f1, "%s %s %s", l, o, p);
            }
        }

        // Macro expansion
        else if (strcmp(o, name) == 0)
        {
            for (i = 0; i < n; i++)
                fprintf(f2, "%s %s %s\n",
                mdt[i][0], mdt[i][1], mdt[i][2]);
        }

        // Normal instruction
        else
            fprintf(f2, "%s %s %s\n", l, o, p);

        fscanf(f1, "%s %s %s", l, o, p);
    }

    fprintf(f2, "%s %s %s\n", l, o, p);

    fclose(f1);
    fclose(f2);
    fclose(f3);

    printf("Macro expansion completed");

    return 0;
}