#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
    int r = lseek(STDIN_FILENO, 0, SEEK_CUR);
    printf("STDIN IS: %s\n", (r && r != -1)  ? "seekable" : "NOT seekable");
    return 0;
}
