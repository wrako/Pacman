#include <curses.h>
#include <windows.h>
#include "game.h"
#include "render.h"
#include "ghost.h"
#include "level.h"

void start_game(int lev, int x, int y) {
    char (*level)[43];
    int row, col;

    if (lev == 1) {
        level = level1;
        row = 15;
        col = 43;
    } else {
        level = level2;
        row = 15;
        col = 43;
    }

    PacmanMove(col, row, x, y, level);
}

int end_game(int col, int row, char level[row][col], int x, int y) {
    return (level[y][x] == '&' || level[y][x] == 'h' ||
            level[y-1][x] == '&' || level[y-1][x] == 'h' ||
            level[y+1][x] == '&' || level[y+1][x] == 'h' ||
            level[y][x+1] == '&' || level[y][x+1] == 'h' ||
            level[y][x-1] == '&' || level[y][x-1] == 'h');
}
