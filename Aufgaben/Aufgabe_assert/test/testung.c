#include <stdio.h>
#include <assert.h>
#include "../inserts/STRING_UTILS.h"

int main(){
    assert(custom_len("Test") == 4);
    assert(custom_len("T") == 1);
    assert(custom_len("") == 0);
    printf("Alles custom_len Tests erfolgreich bestenaden\n");

    assert(read_line_dynamics("Test") == 0);
    assert(read_line_dynamics("T") == 0);
    assert(read_line_dynamics("") == 0);
    printf("Alles read_line_dynamics Tests erfolgreich bestenaden\n");

return 0;
}