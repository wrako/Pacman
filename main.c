#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include "render.h"
#include "game.h"
#include "level.h"

int main() {
    initscr();
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);

    int x = 1, y = 1;
    int choise, light = 2, lev = 1;

    char Menu[5][9] = {
        {"_________"},
        {"| Play  |"},
        {"| Levels|"},
        {"| Sett  |"},
        {"---------"}};

    while (1) {
        refresh();
        clear();
        Menu[light][1] = '>';
        for (int t = 0; t < 5; t++) {
            for (int i = 0; i < 9; i++)
                printw("%c", Menu[t][i]);
            printw("\n");
        }
        Menu[light][1] = ' ';
        
        if ((choise = getch()) == KEY_UP && light != 1)
            light--;
        else if (choise == KEY_DOWN && light != 3)
            light++;
        else if (choise == 'e') {
            if (light == 1) {
                start_game(lev, x, y);
            } else if (light == 2) {
                lev = select_level();
            }
        }
    }

    endwin();
    return 0;
}
