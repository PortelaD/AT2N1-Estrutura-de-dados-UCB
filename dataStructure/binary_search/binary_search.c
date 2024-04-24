#include "../artist.h"
#include "binary_search.h"

void binarySearchArtist(Artist artists[], int num_artists)
{
  char artistName[MAX_NAME_LENGTH];
  printf("Digite o nome do artista a ser buscado: ");
  scanf(" %[^\n]", artistName);

  int left = 0, right = num_artists - 1, found = 0, mid;
  while (left <= right)
  {
    mid = (left + right) / 2;
    if (strcmp(artists[mid].name, artistName) == 0)
    {
      found = 1;
      break;
    }
    else if (strcmp(artists[mid].name, artistName) < 0)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }

  if (found)
  {
    printf("Artista encontrado:\n");
    printf("Nome: %s\n", artists[mid].name);
    printf("Gênero musical: %s\n", artists[mid].genre);
    printf("Local de origem: %s\n", artists[mid].location);
    printf("Álbuns:\n");
    for (int i = 0; i < artists[mid].num_albums; i++)
    {
      printf("- %s\n", artists[mid].albums[i]);
    }
  }
  else
  {
    printf("Artista não encontrado.\n");
  }
}
