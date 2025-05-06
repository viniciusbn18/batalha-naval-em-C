#include <stdio.h>

int main()
{
  int navio1[3] = {3, 3, 3};
  int navio2[3] = {3, 3, 3};

  size_t tamanhoNavio1 = sizeof(navio1) / sizeof(navio1[0]);
  size_t tamanhoNavio2 = sizeof(navio2) / sizeof(navio2[0]);

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
  printf("Tabuleiro com navios: \n");
  for (int i = 0; i < 9; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      // Barco na horizontal

      for (int k = 0; k < tamanhoNavio1; k++)
      {
        tabuleiro[4][k] = 3;
      }

      // barco na vertical

      for (int n = 0; n < tamanhoNavio2; n++)
      {
        tabuleiro[n][2] = 3;
      }

      printf(" %d ", tabuleiro[i][j]);
    }
    printf("\n");
  }

  return 0;
}
