#include "../include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void init_playlist(Playlist *pl) {
    pl->head = NULL;
}
//Zählen der Songs
int count_songs(Playlist *pl){
    int count = 0;
    Song *temp = pl->head;
    while(temp != NULL){
        count++;
        temp = temp->next;
    }
    return count;
}
//Song hinten hinzufügen
void add_song(Playlist *pl, const char *title, const char *artist) {
    if((count_songs(pl))>=(MAX_SONGS)){
        printf("Maximal Anzahl der Songs erreicht\n");
        return;
    }else{
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