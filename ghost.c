#include "ghost.h"

void Ghost(int gx, int gy, int x, int y, int col, int row, char level[row][col]) {
    int gost_1x = gx, gost_1y = gy;

    if (gost_1x == x) {
        if (gost_1y < y && level[gost_1y + 1][gost_1x] != '+') gost_1y++;
        else if (gost_1y > y && level[gost_1y - 1][gost_1x] != '+') gost_1y--;
    } else if (gost_1y == y) {
        if (gost_1x < x && level[gost_1y][gost_1x + 1] != '+') gost_1x++;
        else if (gost_1x > x && level[gost_1y][gost_1x - 1] != '+') gost_1x--;
    }

    if (level[gost_1y][gost_1x] == 'o')
        level[gost_1y][gost_1x] = 'h';
    else
        level[gost_1y][gost_1x] = '&';
}
