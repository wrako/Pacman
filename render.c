#include <curses.h>
#include "render.h"

void draw_level(int col, int row, char level[row][col]) {
    int y1 = 2;
    move(y1, 2);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);

    for (int i = 0; i < row; i++) {
        for (int t = 0; t < col; t++) {
            if (level[i][t] == '+') {
                attron(COLOR_PAIR(1));
                printw("%c", level[i][t]);
                attroff(COLOR_PAIR(1));
            } else if (level[i][t] != 'h') {
                printw("%c", level[i][t]);
            } else {
                printw("&");
            }
        }
        y1++;
        move(y1, 2);
    }
}
