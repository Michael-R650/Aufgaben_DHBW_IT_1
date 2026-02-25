#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
//Stuct für Song
typedef struct Song {
    char *title;
    char *artist;
    struct Song *next;
} Song;
//Struct für playlist
typedef struct Playlist {
    Song *head;
} Playlist;
// Init Playlist
void init_playlist(Playlist *pl) {
    pl->head = NULL;
}

//Song hinten hinzufügen
void add_song(Playlist *pl, const char *title, const char *artist) {
    Song *newSong = malloc(sizeof(Song));
    if (newSong == NULL) return;

    // Speicher für Strings reservieren und kopieren
    newSong->title = strdup(title);  
    newSong->artist = strdup(artist);
    newSong->next = NULL;

    if (pl->head == NULL) {
        pl->head = newSong;
    } else {
        Song *temp = pl->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newSong;
    }
}
//Erster Song löschen
void delete_firstSong(Playlist *pl) {
    if (pl->head == NULL) return;

    Song *temp = pl->head;
    pl->head = pl->head->next;

    // WICHTIG: Erst die Strings im Song löschen, dann den Song selbst!
    free(temp->title);
    free(temp->artist);
    free(temp);
}
//Ausgeben der ganzen Playlist
void print_playlist(Playlist *pl) {
    Song *temp = pl->head;
    if (temp == NULL) {
        printf("Die Playlist ist leer.\n");
        return;
    }
    while (temp != NULL) {
        printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
    printf("\n");
}
//Löschen der ganzen Plalist
void delete_playlist(Playlist *pl) {
    while (pl->head != NULL) {
        delete_firstSong(pl);
    }
}


int main()
{
   Playlist myPlaylist;
   init_playlist(&myPlaylist);

   add_song(&myPlaylist,"The World Is Yours","Tim McMorris");
   add_song(&myPlaylist,"Zelten auf Kies","Tream, treamiboii");
   add_song(&myPlaylist,"Der Kanalreiniger","SSIO");

   print_playlist(&myPlaylist);
   delete_firstSong(&myPlaylist);
   print_playlist(&myPlaylist);
   delete_playlist(&myPlaylist);

    printf("ENDE\n");
    return 0;
}