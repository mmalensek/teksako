#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

void disableRawMode(){
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode(){
    // UGASNEMO ECHO in
    // OMOGOČIMO RAW INPUT
    // torej ni potrebno
    // pritiskati ENTER
    tcgetattr(STDIN_FILENO, &orig_termios);
    atexit(disableRawMode);

    // ICANON ugasne cannonical mode
    struct termios raw = orig_termios;
    raw.c_lflag &= ~(ECHO | ICANON);

    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

int main(){
    enableRawMode();

    char c;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
        // PREVERI ali je znak, kontrolni znak
        // tega nočemo printat
        if (iscntrl(c)) {
            printf("%d\n", c);
        } else {
            printf("%d ('%c')\n", c, c);
        }
    }

    disableRawMode();
    return 0;
}
