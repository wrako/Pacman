#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>
#include <windows.h>
void draw_level(int col, int row, char level[row][col])
{
    int y1 = 2;
    move(y1, 2);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    for (int i = 0; i < row; i++)
    {
        for (int t = 0; t < col; t++)
        {
            if (level[i][t] == '+')
            {
                attron(COLOR_PAIR(1));
                printw("%c", level[i][t]);
                attroff(COLOR_PAIR(1));
            }
            else if (level[i][t] != 'h')
                printw("%c", level[i][t]);
            else
                printw("&");
        }
        y1++;
        move(y1, 2);
    }
}
void Ghost(int gx, int gy, int x, int y, int col, int row, char level[row][col])
{
    int gost_1x, gost_1y;
    gost_1x = gx;
    gost_1y = gy;

    if (gost_1x == x)
    {
        if (gost_1y < y && level[gost_1y + 1][gost_1x] != '+')
        {
            gost_1y++;
        }
        else if (gost_1y > y && level[gost_1y - 1][gost_1x] != '+')
        {
            gost_1y--;
        }
    }
    else if (gost_1y == y)
    {
        if (gost_1x < x && level[gost_1y][gost_1x + 1] != '+')
            gost_1x++;
        else if (gost_1x > x && level[gost_1y][gost_1x - 1] != '+')
            gost_1x--;
    }

    else if (gost_1x < x && gost_1y < y)
    {
        if (level[gost_1y][gost_1x + 1] != '+')
        {
            gost_1x++;
        }
        else if (level[gost_1y + 1][gost_1x] != '+' && level[gost_1y - 1][gost_1x + 1] == '+')
        {
            gost_1y++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+')
            gost_1y--;
        else if (level[gost_1y][gost_1x - 1] != '+')
            gost_1x--;
    }

    else if (gost_1x > x && gost_1y < y)
    {
        if (level[gost_1y][gost_1x - 1] != '+')
        {
            gost_1x--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+' && level[gost_1y - 1][gost_1x - 1] == '+')
        {
            gost_1y++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+')
            gost_1y--;

        else if (level[gost_1y][gost_1x + 1] != '+')
            gost_1x++;
    }

    else if (gost_1x > x && gost_1y > y)
    {
        if (level[gost_1y][gost_1x - 1] != '+')
        {
            gost_1x--;
        }
        else if (level[gost_1y - 1][gost_1x] != '+' && level[gost_1y + 1][gost_1x - 1] == '+')
        {
            gost_1y--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+')
        {
            gost_1y++;
        }

        else if (level[gost_1y][gost_1x + 1] != '+')
        {
            gost_1x++;
        }
    }

    else if (gost_1x <= x && gost_1y >= y)
    {
        if (level[gost_1y][gost_1x + 1] != '+')
        {
            gost_1x++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+' && level[gost_1y + 1][gost_1x + 1] == '+')
        {
            gost_1y--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+')
            gost_1y++;
        else if (level[gost_1y][gost_1x + 1] != '+')
            gost_1x--;
    }

    if (level[gost_1y][gost_1x] == 'o')
        level[gost_1y][gost_1x] = 'h';
    else
        level[gost_1y][gost_1x] = '&';
}
void Goster(int x, int y, int col, int row, char level[row][col])
{
    int gx = 0, gy = 0;
    for (int i = 0; i < col; i++)
        for (int p = 0; p < row; p++)
        {
            if (level[p][i] == '&' || level[p][i] == 'h')
            {
                gy = p;
                gx = i;
            }
        }
    if (level[gy][gx] == '&')
        level[gy][gx] = ' ';
    else if (level[gy][gx] == 'h')
        level[gy][gx] = 'o';
    if (gx != 0 || gy != 0)
        Ghost(gx, gy, x, y, col, row, level);
    else
        level[y][x] == '&';
}
int end(int col, int row, char level[row][col], int x, int y){
    if (level[y][x] == '&' || level[y][x] == 'h')
        return 1;
    else if (level[y - 1][x] == '&' || level[y - 1][x] == 'h')
        return 1;
    else if (level[y + 1][x] == '&' || level[y + 1][x] == 'h')
        return 1;
    else if (level[y][x + 1] == '&' || level[y][x + 1] == 'h')
        return 1;
    else if (level[y][x - 1] == '&' || level[y][x - 1] == 'h')
        return 1;
    else
        return 0;
}
void PacmanMove(int col, int row, int x, int y, char level[row][col])
{
    int step;
    int sleep = 120;
    while (step != 27 && end(col, row, level, x, y) == 0)
    {

        int g = 0;
        if (step != KEY_UP && step != KEY_DOWN && step != KEY_LEFT && step != KEY_RIGHT)
            while ((step = getch()) == ERR && end(col, row, level, x, y) == 0)
            {
                Sleep(230);
                clear();
                Goster(x, y, col, row, level);
                draw_level(col, row, level);
            }
        if (step == KEY_UP && level[y - 1][x] == '+')
            step = getch();
        if (step == KEY_DOWN && level[y + 1][x] == '+')
            step = getch();
        if (step == KEY_RIGHT && level[y][x + 1] == '+')
            step = getch();
        if (step == KEY_LEFT && level[y][x - 1] == '+')
            step = getch();

        if (step == KEY_UP && end(col, row, level, x, y) == 0)
        {
            int u = 1;
            while (level[y - 1][x] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0)
            {
                Sleep(sleep);
                clear();
                level[y][x] = ' ';
                y--;
                level[y][x] = '^';
                if (u == 3)
                {
                    Goster(x, y, col, row, level);
                    u = 0;
                }
                else
                    u++;
                draw_level(col, row, level);
            }

            if (step == KEY_RIGHT || step == KEY_LEFT)
            {
                while (level[y - 1][x] != '+' && end(col, row, level, x, y) == 0)
                {
                    Sleep(sleep);
                    clear();
                    level[y][x] = ' ';
                    y--;
                    level[y][x] = '^';
                    if (g == 3)
                    {
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    draw_level(col, row, level);
                    refresh();
                    if (level[y][x + 1] != '+' && step == KEY_RIGHT)
                        break;
                    if (level[y][x - 1] != '+' && step == KEY_LEFT)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_DOWN && end(col, row, level, x, y) == 0)
        {
            while (level[y + 1][x] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0)
            {
                Sleep(sleep);
                clear();
                level[y][x] = ' ';
                y++;
                level[y][x] = 'Y';
                if (g == 3)
                {
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                draw_level(col, row, level);
            }

            if (step == KEY_RIGHT || step == KEY_LEFT)
            {
                while (level[y + 1][x] != '+' && end(col, row, level, x, y) == 0)
                {
                    Sleep(sleep);
                    clear();
                    level[y][x] = ' ';
                    y++;
                    level[y][x] = 'Y';
                    if (g == 3)
                    {
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    draw_level(col, row, level);
                    refresh();
                    if (level[y][x + 1] != '+' && step == KEY_RIGHT)
                        break;
                    if (level[y][x + 1] != '+' && step == KEY_LEFT)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_RIGHT && end(col, row, level, x, y) == 0)
        {
            while (level[y][x + 1] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0)
            {
                Sleep(sleep);
                clear();
                level[y][x] = ' ';
                x++;
                level[y][x] = '>';
                if (g == 3)
                {
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                if (level[y][x] == '&' || level[y][x] == 'h')
                    break;
                draw_level(col, row, level);
            }
            if (step == KEY_UP || step == KEY_DOWN)
            {
                while (level[y][x + 1] != '+' && end(col, row, level, x, y) == 0)
                {
                    Sleep(sleep);
                    clear();
                    level[y][x] = ' ';
                    x++;
                    level[y][x] = '>';
                    if (g == 3)
                    {
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    if (level[y][x] == '&' || level[y][x] == 'h')
                        break;
                    draw_level(col, row, level);
                    refresh();
                    if (level[y + 1][x] != '+' && step == KEY_DOWN)
                        break;
                    if (level[y - 1][x] != '+' && step == KEY_UP)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_LEFT && end(col, row, level, x, y) == 0)
        {
            while (level[y][x - 1] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0)
            {
                Sleep(sleep);
                clear();
                level[y][x] = ' ';
                x--;
                level[y][x] = '<';
                if (g == 3)
                {
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                draw_level(col, row, level);
            }
            if (step == KEY_UP || step == KEY_DOWN)
            {
                while (level[y][x - 1] != '+' && end(col, row, level, x, y) == 0)
                {
                    Sleep(sleep);
                    clear();
                    level[y][x] = ' ';
                    x--;
                    level[y][x] = '<';
                    if (g == 3)
                    {
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    draw_level(col, row, level);
                    refresh();
                    if (level[y + 1][x] != '+' && step == KEY_DOWN)
                        break;
                    if (level[y + 1][x] != '+' && step == KEY_UP)
                        break;
                }
            }
        }
    }
}
int main()
{
    initscr();
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    int row = 22, col = 19;
    int x = 1, y = 1;

    int choise;
    int light = 2;
    int lev = 1;

    char Menu[5][9] = {
        {"_________"},
        {"| Play  |"},
        {"| Levels|"},
        {"| Sett  |"},
        {"---------"}};
    char Levels[5][11] = {
        {"___________"},
        {"| Level 1 |"},
        {"| Level 2 |"},
        {"| Level 3 |"},
        {"-----------"}};

    while (1 > 0)
    {
        char level1[15][43] = {
            {"+++++++++++++++++++++++++++++++++++++++++++"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+o+++++o+o+++++o+o+++++++o+o+++++o+o+++++o+"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+++++o+++++o+o++++o+++++o++++o+o+++++o+++++"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+o+++++++o+++++o+o+++++++o+o+++++o+++++++o+"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+++++o+++++o+o++++o+++++o++++o+o+++++o+++++"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+o+++++o+o+++++o+o+++++++o+o+++++o+o+++++o+"},
            {"+ooooooooooooooooooooooooooooooooooooooooo+"},
            {"+++++++++++++++++++++++++++++++++++++++++++"}
        };
        int col1 = 43, row1 = 15;

        char level2[15][43] = {
            {"+++++++++++++++++++++++++++++++++++++++++++"},
            {"+o+ooo+o+o+o+o+o+o+ooo+o+ooo+o+o+o+ooo+o+o+"},
            {"+o+o+ooooo+ooo+o+o+o+o+o+o+o+o+o+o+ooo+o+o+"},
            {"+ooo+o+o+ooo+o+ooo+o+o+o+o+o+o+o+o+++o+o+o+"},
            {"+o+o+o+o+o+o+o+o+o+o+ooo+o+o+o+o+ooooooooo+"},
            {"+o+o+o+o+o+o+o+o+o+o+o+o+o+ooo+o+o+++++++++"},
            {"+ooooooooooooooooooo+o+ooo+o+ooooooooooooo+"},
            {"+o+o+o+o+o+o+o+o+o+o+o+o+o+ooo+o+o+++++++++"},
            {"+o+o+o+o+o+o+o+o+o+o+ooo+o+o+o+o+ooooooooo+"},
            {"+ooo+o+o+ooo+o+ooo+o+o+o+o+o+o+o+o+++o+o+o+"},
            {"+o+o+ooooo+ooo+o+o+o+o+o+o+o+o+o+o+ooo+o+o+"},
            {"+o+ooo+o+o+o+o+o+o+ooo+o+ooo+o+o+o+ooo+o+o+"},
            {"+++++++++++++++++++++++++++++++++++++++++++"}
           };

        int col2 = 43, row2 = 15;
        int gost_1x = (col2 - 2), gost_1y = 1;
        level2[gost_1y][gost_1x] = '&';
        refresh();
        clear();
        Menu[light][1] = '>';
        for (int t = 0; t < 5; t++)
        {
            for (int i = 0; i < 9; i++)
                printw("%c", Menu[t][i]);
            printw("\n");
        }
        Menu[light][1] = ' ';
        if ((choise = getch()) == KEY_UP && light != 1)
            light--;
        else if (choise == KEY_DOWN && light != 3)
            light++;
        else if (choise == 'e')
        {
            if (light == 1)
            {
                if (lev == 1)
                    PacmanMove(col1, row1, x, y, level1);
                if (lev == 2)
                    PacmanMove(col2, row2, x, y, level2);
            }
            if (light == 2)
            {
                while (choise != 27)
                {
                    refresh();
                    clear();
                    Levels[light][1] = '>';
                    for (int t = 0; t < 5; t++)
                    {
                        for (int i = 0; i < 11; i++)
                            printw("%c", Levels[t][i]);
                        printw("\n");
                    }

                    Levels[light][1] = ' ';
                    if ((choise = getch()) == KEY_UP && light != 1)
                        light--;
                    else if (choise == KEY_DOWN && light != 3)
                        light++;
                    else if (choise == 'e')
                    {
                        if (light == 1)
                            lev = 1;
                        if (light == 2)
                            lev = 2;
                        break;
                    }
                }
            }
        }
    }

    getch();
    endwin();
}
