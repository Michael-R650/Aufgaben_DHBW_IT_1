#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/playlist.h"

int main()
{
    Playlist myPlaylist;
    init_playlist(&myPlaylist);

    add_song(&myPlaylist, "DThe World Is Yours", "Tim McMorris");
    add_song(&myPlaylist, "AThe World Is Yours", "Tim McMorris");
    add_song(&myPlaylist, "BThe World Is Yours", "Tim McMorris");
    add_song(&myPlaylist, "CThe World Is Yours", "Tim McMorris");
    add_song(&myPlaylist, "GThe World Is Yours", "Tim McMorris");
    add_song(&myPlaylist, "FThe World Is Yours", "Tim McMorris");
    sort_playlist_by_titel(&myPlaylist);
    printf("Total Songs: %d\n",count_songs_recursive(myPlaylist.head));
    print_playlist(&myPlaylist);
    printf("%p\n", find_song_by_titel(&myPlaylist, "The World Is Yours"));
    delete_playlist(&myPlaylist);

    printf("ENDE\n");
    return 0;
}