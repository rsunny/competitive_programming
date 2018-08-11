#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024

// AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\x76\xb8\x49\x42flag
// \x90\x90\x90\x90\x90\x90\x90\x90\x90\x76\xb8\x49\x42flag

typedef struct {
    char flag_content[BUFSIZE];
    char guess[47];
    unsigned canary;
    char flag_file[BUFSIZE];
} st_t;

int main(){
    FILE *f = NULL;
    st_t st = {
        .flag_file = "fake_flag",
        .canary = 0x4249b876
    };
    printf("%x\n", st.canary);

    printf("Guess the flag!\n");
    scanf("%s", st.guess);

    printf("%s\n", st.guess);
    printf("%x\n", st.canary);
    printf("%s\n", st.flag_file);
    f = fopen(st.flag_file, "rb");
    if (f == NULL){
        printf("flag error\n");
        exit(-1);
    }

    if (fread(st.flag_content, BUFSIZE, 1, f) < 0){
        printf("flag error\n");
        exit(-1);
    }

    if (st.canary != 0x3234785c) {//4249b876) {
        printf("canary error\n");
        exit(-1);
    }

    if (!strcmp(st.guess, st.flag_content)){
        printf("You guessed it right!\n");
    } else {
        printf("Sorry but the flag is \"%s\"\n", st.flag_content);
    }
    exit(1);
}