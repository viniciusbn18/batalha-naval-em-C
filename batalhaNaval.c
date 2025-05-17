#include <stdio.h>

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

  return 0;
}
