#include <stdio.h>
#include <stdlib.h>

int **cria_sudoku()
{
    int **m = (int **)malloc(sizeof(int *) * 9);
    for (int i = 0; i < 9; i++)
    {
        m[i] = (int *)malloc(sizeof(int) * 9);
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }

    return m;
}

int verifica_linha(int **m)
{
    for (int l = 0; l < 9; l++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int p = i + 1; p < 9; p++)
            {
                if (m[l][i] == m[l][p])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int verifica_coluna(int **m)
{
    for (int c = 0; c < 9; c++)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = i + 1; j < 9; j++)
            {
                if (m[i][c] == m[j][c])
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

int verifica_sub(int **m)
{
    for (int l = 0; l < 9; l += 3)
    {
        for (int k = 0; k < 9; k += 3)
        {
            for (int i = l; i < l + 3; i++)
            {
                for (int c = k; c < k + 3; c++)
                {
                    for (int p = l; p < l + 3; p++)
                    {
                        for (int j = k; j < k + 3; j++)
                        {
                            if ((m[i][c] == m[p][j]) && (i != p || c != j))
                            {
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    return 1;
}

int main()
{
    int n;
    int **mat;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        mat = cria_sudoku();
        

        if (verifica_linha(mat) &&
            verifica_coluna(mat) &&
            verifica_sub(mat))
        {
            printf("\n");
            printf("Instancia %d\n", i + 1);
            printf("SIM\n\n");
        }
        else
        {
            printf("\n");
            printf("Instancia %d\n", i + 1);
            printf("NAO\n\n");
        }
    }

    for (int i = 0; i < 9; i++)
    {
        free(mat[i]);
    }
    free(mat);
    
    return 0;
}
