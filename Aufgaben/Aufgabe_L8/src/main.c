#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../include/playlist.h"

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