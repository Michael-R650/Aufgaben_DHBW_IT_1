#include "../include/playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int init_playlist(Playlist *pl)
{
    pl->head = NULL;
    return 0;
}
// Zählen der Songs
int count_songs(Playlist *pl)
{
    int count = 0;
    Song *temp = pl->head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int count_songs_recursive(const Song *current)
{
    if (current == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count_songs_recursive(current->next);
    }
}
// Song hinten hinzufügen
int add_song(Playlist *pl, const char *title, const char *artist)
{
    if ((count_songs(pl)) >= (MAX_SONGS))
    {
        printf("Maximal Anzahl der Songs erreicht\n");
        return 1;
    }
    else
    {
        Song *newSong = malloc(sizeof(Song));
        if (newSong == NULL)
            return 1;

        // Speicher für Strings reservieren und kopieren
        newSong->title = strdup(title);
        newSong->artist = strdup(artist);
        newSong->next = NULL;

        if (pl->head == NULL)
        {
            pl->head = newSong;
        }
        else
        {
            Song *temp = pl->head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newSong;
        }
    }
    return 0;
}
//Sortieren der Liste
void sort_playlist_by_titel(Playlist *pl) {
    if (pl == NULL || pl->head == NULL || pl->head->next == NULL) {
        return;
    }

    int swapped;
    Song **current;
    do {
        swapped = 0;
        current = &(pl->head);
        while ((*current)->next != NULL) {
            Song *buffer_storage = *current;
            Song *next_node = buffer_storage->next;

            if (strcmp(buffer_storage->title, next_node->title) > 0) {
                buffer_storage->next = next_node->next; 
                next_node->next = buffer_storage;
                *current = next_node;            
                    swapped = 1;
            }
            
            current = &((*current)->next);
        }
    } while (swapped);
}

// Erster Song löschen
int delete_firstSong(Playlist *pl)
{
    if (pl->head == NULL)
        return 1;

    Song *temp = pl->head;
    pl->head = pl->head->next;

    // WICHTIG: Erst die Strings im Song löschen, dann den Song selbst!
    free(temp->title);
    free(temp->artist);
    free(temp);
    return 0;
}
Song *find_song_by_titel(Playlist *pl, const char *titel)
{
    Song *temp = pl->head;
    if (temp == NULL)
    {
        printf("No Song in Playlist\n");
        return NULL;
    }
    else
    {
        while (temp != NULL)
        {

            if (strcmp(temp->title, titel) == 0)
            {
                return temp;
            }
            else
            {
                temp = temp->next;
            }
        }
    }
    printf("Song not found\n");
    return NULL;
}
// Ausgeben der ganzen Playlist
int print_playlist(Playlist *pl)
{
    Song *temp = pl->head;
    if (temp == NULL)
    {
        printf("Die Playlist ist leer.\n");
        return 1;
    }
    while (temp != NULL)
    {
        printf("Title: %s, Artist: %s\n", temp->title, temp->artist);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}
// Löschen der ganzen Plalist
int delete_playlist(Playlist *pl)
{
    while (pl->head != NULL)
    {
        delete_firstSong(pl);
    }
    return 0;
}