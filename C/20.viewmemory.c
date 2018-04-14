#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BYTE_CHUNK 50

typedef unsigned char BYTE;

void die(const char *msg) {
    printf("FUCKED UP: %s\n", msg);
    exit(1);
}

int main(void) {
    uintptr_t addr;
    int bytes;

    printf("Address of main() sub: 0x%016lX\n",   (uintptr_t)main);
    printf("Address of `addr` var: 0x%016lX\n\n", (uintptr_t)&addr);

    addr = (uintptr_t)&addr;
    bytes = 6000;

    // printf("Enter a fucking hex address: ");
    // if (scanf("%lx", &addr)  != 1) die("failed to read address");
    // printf("Enter number of bytes to show: ");
    // if (scanf("%d", &bytes) != 1) die("failed to read number of bytes");

    BYTE *ptr = (BYTE *)addr;
    for (; bytes > 0; bytes -= BYTE_CHUNK) {
        printf("0x%lX  ", (uintptr_t)ptr);
        for (int i = 0; i < BYTE_CHUNK; i++) {
            i < bytes ? printf("%02X ", *(ptr+i)) : printf("   ");
        }
        putchar(' ');
        for (int i = 0; i < BYTE_CHUNK && i < bytes; i++) {
            if (i < bytes) {
                putchar(isprint(*ptr) ? *ptr : '.');
                ptr++;
            }
            else
                putchar(' ');
        }
        putchar('\n');
    }

    return 0;
}
