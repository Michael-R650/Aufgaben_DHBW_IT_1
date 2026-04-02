#include <assert.h>
#include <string.h>
#include <stdio.h>
#include "../include/playlist.h"

int main(void)
{
    Playlist p;
    assert(init_playlist(&p) == 0);
    assert(count_songs(&p) == 0);
    assert(add_song(&p, "Song1", "Band1") == 0);
    assert(delete_firstSong(&p) == 0);
    assert(delete_firstSong(&p) == 1);
    add_song(&p, "Song1", "Band1");
    add_song(&p, "Song2", "Band2");
    assert(print_playlist(&p) == 0);
    assert(delete_playlist(&p) == 0);
    assert(print_playlist(&p) == 1);

    printf("Alle Playlist-Tests erfolgreich bestanden.\n");
    return 0;
}