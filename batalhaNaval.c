#include <stdio.h>
#include <stdlib.h>

int main()
{
  int navio1[3] = {3, 3, 3};
  int navio2[3] = {3, 3, 3};
  int navio3[3] = {3, 3, 3};
  int navio4[3] = {3, 3, 3};

  size_t tamanhoNavio1 = sizeof(navio1) / sizeof(navio1[0]);
  size_t tamanhoNavio2 = sizeof(navio2) / sizeof(navio2[0]);

  size_t tamanhoNavio3 = sizeof(navio3) / sizeof(navio3[0]);
  size_t tamanhoNavio4 = sizeof(navio4) / sizeof(navio4[0]);
  int tabuleiro[10][10] = {
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0},
      {0, 0, 0, 0, 0, 0, 0, 0, 0}

  };

  // Printando na tela o tabuleiro vazio

  printf("Tabuleiro vazio:\n");
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      printf(" %d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  printf("\n\n");

  // adicionando os navios ao tabuleiro
  printf("Tabuleiro com navios: \n");
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      // Barco na horizontal

      for (int k = 0; k < tamanhoNavio1; k++)
      {
        tabuleiro[7][k] = 3;
      }

      // barco na vertical

      for (int n = 0; n < tamanhoNavio2; n++)
      {
        tabuleiro[n][7] = 3;
      }

      printf(" %d ", tabuleiro[i][j]);
    }
    printf("\n");
  }
  printf("\n");

  printf("Adicionando os barcos na diagonal: ");
  printf("\n");
  // Barcos nas diagonais

  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      // Primeiro navio na diagonal
      for (int k = 0; k < tamanhoNavio3; k++)
      {
        tabuleiro[k + 4][k + 2] = 3;
      }
      // Segundo navio na diagonal
      for (int n = 0; n < tamanhoNavio4; n++)
      {
        tabuleiro[n + 2][n + 3] = 3;
      }

      printf(" %d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  // Matrizes de Habilidades
  int cone[5][5] = {0};
  for (int i = 0; i < 5; i++)
  {
    for (int j = 5 / 2 - i; j <= 5 / 2 + i; j++)
    {
      if (j >= 0 && j < 5)
        cone[i][j] = 1;
    }
  }

  int cruz[5][5] = {0};
  for (int i = 0; i < 5; i++)
  {
    cruz[5 / 2][i] = 1; // Linha central
    cruz[i][5 / 2] = 1; // Coluna central
  }

  int octaedro[5][5] = {0};
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (abs(i - 5 / 2) + abs(j - 5 / 2) <= 5 / 2)
      {
        octaedro[i][j] = 1;
      }
    }
  }

  // Aplicação das Habilidades no Tabuleiro
  int origemLinha, origemColuna;
  // Cone no caso, (2,2)
  origemLinha = 2;
  origemColuna = 2;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (cone[i][j] == 1)
      {
        int linhaTabuleiro = origemLinha + i - 5 / 2;
        int colunaTabuleiro = origemColuna + j - 5 / 2;
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10)
        {
          if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0)
          {
            tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
          }
        }
      }
    }
  }

  // cruz, no caso (5,5)

  origemLinha = 5;
  origemColuna = 5;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (cruz[i][j] == 1)
      {
        int linhaTabuleiro = origemLinha + i - 5 / 2;
        int colunaTabuleiro = origemColuna + j - 5 / 2;
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10)
        {
          if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0)
          {
            tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
          }
        }
      }
    }
  }

  // octaedro, no caso (7,7)
  origemLinha = 7;
  origemColuna = 7;
  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      if (octaedro[i][j] == 1)
      {
        int linhaTabuleiro = origemLinha + i - 5 / 2;
        int colunaTabuleiro = origemColuna + j - 5 / 2;
        if (linhaTabuleiro >= 0 && linhaTabuleiro < 10 && colunaTabuleiro >= 0 && colunaTabuleiro < 10)
        {
          if (tabuleiro[linhaTabuleiro][colunaTabuleiro] == 0)
          {
            tabuleiro[linhaTabuleiro][colunaTabuleiro] = 5;
          }
        }
      }
    }
  }

  return 0;
}
