#ifndef ARTIST_H
#define ARTIST_H

#define MAX_NAME_LENGTH 50
#define MAX_GENRE_LENGTH 50
#define MAX_LOCATION_LENGTH 50
#define MAX_ALBUMS 10
#define MAX_ARTISTS 100

typedef struct
{
  char name[MAX_NAME_LENGTH];
  char genre[MAX_GENRE_LENGTH];
  char location[MAX_LOCATION_LENGTH];
  char albums[MAX_ALBUMS][MAX_NAME_LENGTH];
  int num_albums;
} Artist;

#endif
