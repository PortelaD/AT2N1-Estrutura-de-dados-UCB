#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// imports de arqs
#include "dataStructure/artist.h"
#include "dataStructure/insert/insert.c"
#include "dataStructure/remove/remove.c"
#include "dataStructure/edit/edit.c"
#include "dataStructure/binary_search/binary_search.c"
#include "dataStructure/sequential_search/sequential_search.c"

int readArtistsFromFile(Artist artists[], char *filename) {

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", filename);
        exit(1);
    }

    int num_artists = 0;
    char buffer[100];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strcmp(buffer, "==========\n") == 0) {
            // Separador encontrado, passar para o próximo artista
            num_artists++;
            continue;
        }

        strcpy(artists[num_artists].name, buffer);
        strtok(artists[num_artists].name, "\n"); // Remove o \n
        fgets(artists[num_artists].genre, sizeof(artists[num_artists].genre), file);
        strtok(artists[num_artists].genre, "\n");
        fgets(artists[num_artists].location, sizeof(artists[num_artists].location), file);
        strtok(artists[num_artists].location, "\n");
        
        artists[num_artists].num_albums = 0;
        while (fgets(buffer, sizeof(buffer), file) != NULL && strcmp(buffer, "==========\n") != 0) {
            strtok(buffer, "\n");
            if (artists[num_artists].num_albums < MAX_ALBUMS) {
                strcpy(artists[num_artists].albums[artists[num_artists].num_albums], buffer);
                artists[num_artists].num_albums++;
            } else {
                printf("Número máximo de álbuns atingido!\n");
            }

            artists[num_artists].num_albums++;
        }
    }

    fclose(file);
    return num_artists;
}
