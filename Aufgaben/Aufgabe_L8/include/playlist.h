#ifndef PLAYLIST
#define PlAYLIST
#define MAX_SONGS 3
//Stuct für Song
typedef struct Song {
    char *title;
    char *artist;
    struct Song *next;
} Song;
typedef struct Playlist {
    Song *head;
} Playlist;
//functions
int count_songs(Playlist *pl);
void init_playlist(Playlist *pl);
void add_song(Playlist *pl, const char *title, const char *artist);
void delete_firstSong(Playlist *pl);
void print_playlist(Playlist *pl);
void delete_playlist(Playlist *pl);
#endif