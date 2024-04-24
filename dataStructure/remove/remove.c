#include "../artist.h"
#include "remove.h"

void removeArtist(Artist artists[], int *num_artists)
{
  char artistName[MAX_NAME_LENGTH];
  printf("Digite o nome do artista a ser removido: ");
  scanf(" %[^\n]", artistName);

  int i, found = 0;
  for (i = 0; i < *num_artists; i++)
  {
    if (strcmp(artists[i].name, artistName) == 0)
    {
      found = 1;
      break;
    }
  }

  if (found)
  {
    for (int j = i; j < *num_artists - 1; j++)
    {
      artists[j] = artists[j + 1];
    }
    (*num_artists)--;
    printf("Artista removido com sucesso!\n");
  }
  else
  {
    printf("Artista não encontrado.\n");
  }
}
