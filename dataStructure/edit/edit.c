#include "../artist.h"
#include "edit.h"

void editArtist(Artist artists[], int num_artists)
{
  char artistName[MAX_NAME_LENGTH];
  printf("Digite o nome do artista a ser editado: ");
  scanf(" %[^\n]", artistName);

  int i, found = 0;
  for (i = 0; i < num_artists; i++)
  {
    if (strcmp(artists[i].name, artistName) == 0)
    {
      found = 1;
      break;
    }
  }

  if (found)
  {
    printf("Digite o novo nome do artista: ");
    scanf(" %[^\n]", artists[i].name);
    printf("Digite o novo gênero musical: ");
    scanf(" %[^\n]", artists[i].genre);
    printf("Digite o novo local de origem: ");
    scanf(" %[^\n]", artists[i].location);
    printf("Digite o novo número de álbuns: ");
    scanf("%d", &artists[i].num_albums);
    printf("Digite os novos nomes dos álbuns:\n");
    for (int j = 0; j < artists[i].num_albums; j++)
    {
      scanf(" %[^\n]", artists[i].albums[j]);
    }
    printf("Artista editado com sucesso!\n");
  }
  else
  {
    printf("Artista não encontrado.\n");
  }
}
