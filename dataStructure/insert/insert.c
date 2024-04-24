#include "insert.h"
#include "../artist.h"

void insertArtist(Artist artists[], int *num_artists) {
    if (*num_artists == MAX_ARTISTS) {
        printf("Não é possível inserir mais artistas. O limite foi atingido.\n");
        return;
    }

    Artist newArtist;
    printf("Digite o nome do novo artista: ");
    scanf(" %[^\n]", newArtist.name);
    printf("Digite o gênero musical: ");
    scanf(" %[^\n]", newArtist.genre);
    printf("Digite o local de origem: ");
    scanf(" %[^\n]", newArtist.location);
    printf("Quantos álbuns %s lançou? ", newArtist.name);
    scanf("%d", &newArtist.num_albums);
    printf("Liste os nomes dos álbuns de %s:\n", newArtist.name);
    for (int i = 0; i < newArtist.num_albums; i++) {
        printf("Nome do álbum %d: ", i + 1);
        scanf(" %[^\n]", newArtist.albums[i]);
    }

    int i = *num_artists - 1;
    while (i >= 0 && strcmp(artists[i].name, newArtist.name) > 0) {
        artists[i + 1] = artists[i];
        i--;
    }
    artists[i + 1] = newArtist;

    (*num_artists)++;
    printf("O artista %s foi adicionado com sucesso!\n", newArtist.name);
}
