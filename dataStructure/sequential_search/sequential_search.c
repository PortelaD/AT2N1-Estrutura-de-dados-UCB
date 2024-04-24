#include "sequential_search.h"
#include "../artist.h"

void sequentialSearchAlbum(Artist artists[], int num_artists) {
    char albumName[MAX_NAME_LENGTH];
    printf("Digite o nome do álbum a ser buscado: ");
    scanf(" %[^\n]", albumName);

    int found = 0;
    for (int i = 0; i < num_artists; i++) {
        for (int j = 0; j < artists[i].num_albums; j++) {
            if (strcmp(artists[i].albums[j], albumName) == 0) {
                found = 1;
                printf("Álbum encontrado no artista %s.\n", artists[i].name);
                break;
            }
        }
    }

    if (!found) {
        printf("Álbum não encontrado em nenhum artista.\n");
    }
}
