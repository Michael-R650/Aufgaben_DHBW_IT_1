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
int init_playlist(Playlist *pl);
int count_songs(Playlist *pl);
int add_song(Playlist *pl, const char *title, const char *artist);
int delete_firstSong(Playlist *pl);
int print_playlist(Playlist *pl);
int delete_playlist(Playlist *pl);
#endif