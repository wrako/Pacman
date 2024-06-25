#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <time.h>
#include <string.h>
#include <windows.h>
int s , m , t;
int goststep, mark;
int score = 0;
int row = 13,col = 43;
int gost_1x = 23, gost_1y = 1;

char null[7][7] = {
{" ##### "},
{"#     #"},
{"#     #"},
{"#     #"},
{"#     #"},
{"#     #"},
{" ##### "}
};
char one[7][7] = {
{"   #   "},
{"   #   "},
{"   #   "},
{"   #   "},
{"   #   "},
{"   #   "},
{"   #   "}
};
char two[7][7] = {
{"#######"},
{"      #"},
{"      #"},
{"#######"},
{"#      "},
{"#      "},
{"#######"}
};
char three[7][7] = {
{"#######"},
{"      #"},
{"      #"},
{"#######"},
{"      #"},
{"      #"},
{"#######"}
};
char four[7][7] = {
{"#     #"},
{"#     #"},
{"#     #"},
{"#######"},
{"      #"},
{"      #"},
{"      #"}
};
char five[7][7] = {
{"#######"},
{"#      "},
{"#      "},
{"#######"},
{"      #"},
{"      #"},
{"#######"}
};
char six[7][7] = {
{"#######"},
{"#      "},
{"#      "},
{"#######"},
{"#     #"},
{"#     #"},
{"#######"}
};
char seven[7][7] = {
{"#######"},
{"      #"},
{"     # "},
{"    #  "},
{"   #   "},
{"  #    "},
{" #     "}
};
char eight[7][7] = {
{"#######"},
{"#     #"},
{"#     #"},
{"#######"},
{"#     #"},
{"#     #"},
{"#######"}
};
char nine[7][7] = {
{"#######"},
{"#     #"},
{"#     #"},
{"#######"},
{"      #"},
{"      #"},
{"#######"}
};
char twopoints[7][7] = {
{"  ###  "},
{"  ###  "},
{"       "},
{"       "},
{"       "},
{"  ###  "},
{"  ###  "}
};

char Pac[12][117] = { 
    {"  #############           ##               ############  #####           #####          ##          ####           ##"},
    {"  ##          ##         ####            ###             ##  ##         ##  ##         ####         ## ##          ##"},
    {"  ##           ##       ##  ##          ##               ##   ##       ##   ##        ##  ##        ##  ##         ##"},
    {"  ##           ##      ##    ##        ##                ##    ##     ##    ##       ##    ##       ##   ##        ##"},
    {"  ##          ##      ##      ##      ##                 ##     ##   ##     ##      ##      ##      ##    ##       ##"},    
    {"  ##         ##      ##        ##     ##                 ##      ## ##      ##     ##        ##     ##     ##      ##"},     
    {"  ###########       ##          ##    ##                 ##       ###       ##    ##          ##    ##      ##     ##"},    
    {"  ##               ################    ##                ##                 ##   ################   ##       ##    ##"},
    {"  ##              ##              ##    ##               ##                 ##  ##              ##  ##        ##   ##"},
    {"  ##             ##                ##    ##              ##                 ## ##                ## ##         ##  ##"},
    {"  ##             ##                ##     ###            ##                 ## ##                ## ##          ## ##"},
    {"  ##             ##                ##       ###########  ##                 ## ##                ## ##           ####"}
    };
char win[7][52] = {
    {" ##           ##           ##   ##    ####      ##  "},
    {"  ##         ####         ##    ##    ## ##     ##  "},
    {"   ##       ##  ##       ##     ##    ##  ##    ##  "},
    {"    ##     ##    ##     ##      ##    ##   ##   ##  "},
    {"     ##   ##      ##   ##       ##    ##    ##  ##  "},
    {"      ## ##        ## ##        ##    ##     ## ##  "},
    {"       ###          ###         ##    ##      ####  "}
    };
char lose[7][48] = {
    {" ##             #####     #########  ########## "},
    {" ##           ##     ##   ##      #  ##         "},
    {" ##          ##       ##  ##         ##         "},
    {" ##          ##       ##  #########  ########## "},
    {" ##          ##       ##         ##  ##         "},
    {" ##           ##     ##   #      ##  ##         "},
    {" #########      #####     #########  ########## "}
    };

void generator(char level[row][col]){
    int r;
    r = (rand() % 3) + 1;
    if(r == 1){

    for(int i = 0; i < row; i++){
        for(int t = 0; t < col; t++){
            if(i % 2 == 0)
                level[i][t] = '+';
            else 
                level[i][t] = 'o';
        }
        if(i % 2 == 0 && i != 0 && i != row - 1){
        int r = 10;
        for(int l =0;l<3;l++){
        while(level[i][r - 1] == 'o' || level[i][r + 1] == 'o' || level[i][r] == 'o' || level[i - 2][r] == 'o')
            r = (rand() % (col - 3)) + 1;
        level[i][r] = 'o';
        }
    }
    }
    for(int i = 0; i < row; i++){
        level[i][0] = '+';
        level[i][42] = '+';
    }
    }
    if(r == 2){
    for(int i = 0; i < col; i++){
        for(int t = 0; t < row; t++){
            if(i % 2 == 0)
                level[t][i] = '+';
            else 
                level[t][i] = 'o';
        }
        if(i % 2 == 0 && i != 0 && i < (col - 1)){
            int r = 10;
            for(int l =0;l<2;l++){
            while(level[r - 1][i] == 'o' || level[r + 1][i] == 'o' || level[r][i] == 'o' || level[r][i - 2] == 'o')
                r = (rand() % (row - 3)) + 1;
            level[r][i] = 'o';
            }
        }
    }
    for(int i = 0; i < col; i++){
        level[0][i] = '+';
        level[12][i] = '+';
    }

    }
    if(r == 3){
    for(int i = 0; i < row; i++)
        for(int t = 0; t < col; t++)
            level[i][t] = 'o';

    for(int i = 0; i < row; i++){
        for(int t =0;t<col;t++){
            if(i % 2 == 0){
                if(t < col - i - 1 && t > 0 + i && i < row / 2)
                    level[i][t] = '+';
                else if(t < col - (row - i) && t > 0 + (row - i) - 1)
                    level[i][t] = '+';    
            }
            if(t % 2 == 0){
                if(i < row - t && i > t - 1 && t < col / 2)
                    level[i][t] = '+';
                else if(i < row - (col - t) + 1 && i > (col - t) - 2)
                    level[i][t] = '+';    
            }
            }
            if(i < row / 2 && i % 2 == 0 && i > 0){
                while(r > col - i - 2 || r < i || level[i][r] == 'o' || level[i - 2][r] == 'o')
                    r = rand() % col;
            level[i][r] = 'o';        
            }
            else if(i > row / 2 && i % 2 == 0 && i < row - 2){
                while(r > col - (row - i) || r < 0 + (row - i) - 2 || level[i][r] == 'o' || level[i - 2][r] == 'o')
                     r = rand() % col;
            level[i][r] = 'o';
            }           
    }

    for(int t =2;t<col;t++){
            if(t < col / 8 && t % 2 == 0){
                while(r >= row - t - 2 || r < t + 1 || level[r][t - 2] == 'o')
                    r = rand() % 13;
                level[r][t] = 'o';}
            if(t > 37 && t % 2 == 0 && t < col - 1){
                while(r >= row - (col - t) - 1 || r < (col - t) || level[r][t - 2] == 'o')
                    r = rand() % 13;
                level[r][t] = 'o';}
    }

    }
    for(int i =0;i < 5; i++){
        while(level[r / 4][r] == '+' || level[r / 4][r] == '@' || level[r / 4][r + 1] == '@' || level[r / 4][r - 1] == '@' || level[(r / 4) - 1][r] == '@' || level[(r / 4) + 1][r] == '@'){
            r = rand() % col;
        }
        level[r / 4][r] = '@';
    }

}
int drawPac(){
int ypac = 1; 
for(int i = 0;i < 12;i++){
    move(ypac,1);
    ypac++;
    for(int t = 0;t < 117; t++){
        if(Pac[i][t] == '#'){
            attron(COLOR_PAIR(2));
            printw("%c",Pac[i][t]);
            attroff(COLOR_PAIR(2));
        } 
        else
            printw("%c",Pac[i][t]);
    }
}
    return ypac;
}
int draw_level(int col, int row, char level[row][col] , char Pac[12][117]){

        if(s > 59){
                m++;
                s -= 60;
            }
        if(s != 0 && t == 10){
            s--;
            t = 0;
        }
        else if(t == 10){
            m--;
            s = 59;
            t = 0;
        }

    int y1 = 15;
    clear();
    move(y1, 2);
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    int ypac = drawPac();
        int s1;
        for(int j=0;j<4;j++){
            if(j == 0)
                s1 = m;
            if(j == 1)
                s1 = 10;
            if(j == 2)
                s1 = s / 10;
            if(j == 3)
                s1 = s - (s / 10) * 10;
            for(int b = 0;b < 7;b++){
            move(y1 + b + 3, (8 * j) + 4);
                for(int i = 0;i < 7;i++){
                    char l;
                    if(s1 == 0)
                        l = null[b][i];
                    if(s1 == 1)
                        l =  one[b][i];
                    if(s1 == 2)
                        l = two[b][i];
                    if(s1 == 3)
                        l = three[b][i];
                    if(s1 == 4)
                        l = four[b][i];
                    if(s1 == 5)
                        l = five[b][i];
                    if(s1 == 6)
                        l = six[b][i];
                    if(s1 == 7)
                        l = seven[b][i];
                    if(s1 == 8)
                        l = eight[b][i];
                    if(s1 == 9)
                        l = nine[b][i];
                    if(s1 == 10)
                        l = twopoints[b][i];
                    if(l == '#'){
                        attron(COLOR_PAIR(1));
                        printw("%c", l);
                        attroff(COLOR_PAIR(1));
                    }
                    else 
                        printw("%c", l);
                }
                printw("\n");
            }
        }
            for(int j=0;j<4;j++){
            if(j == 0)
                s1 = score / 1000;
            if(j == 1)
                s1 = (score % 1000) / 100;
            if(j == 2)
                s1 = (score % 100) / 10;
            if(j == 3)
                s1 = score % 10;
            for(int b = 0;b < 7;b++){
            move(y1 + b + 3, (8 * j) + 82);
                for(int i = 0;i < 7;i++){
                    char l;
                    if(s1 == 0)
                        l = null[b][i];
                    if(s1 == 1)
                        l =  one[b][i];
                    if(s1 == 2)
                        l = two[b][i];
                    if(s1 == 3)
                        l = three[b][i];
                    if(s1 == 4)
                        l = four[b][i];
                    if(s1 == 5)
                        l = five[b][i];
                    if(s1 == 6)
                        l = six[b][i];
                    if(s1 == 7)
                        l = seven[b][i];
                    if(s1 == 8)
                        l = eight[b][i];
                    if(s1 == 9)
                        l = nine[b][i];
                    if(s1 == 10)
                        l = twopoints[b][i];
                    if(l == '#'){
                        attron(COLOR_PAIR(1));
                        printw("%c", l);
                        attroff(COLOR_PAIR(1));
                    }
                    else 
                        printw("%c", l);
                }
                printw("\n");
            }
        }
    for (int i = 0; i < row; i++){
        y1++;

        move(y1, 37);
        for (int t = 0; t < col; t++){
            if (level[i][t] == '+')
            {
                attron(COLOR_PAIR(1));
                printw("%c", level[i][t]);
                attroff(COLOR_PAIR(1));
            }
            else if(level[i][t] == 'o'){
                
                int r = t + i;
                while(r > 8)
                    r -= 5;
                attron(COLOR_PAIR(r));
                printw("%c", level[i][t]);
                attroff(COLOR_PAIR(r));
            }
            else if (level[i][t] == 'h' || level[i][t] == '&')
                printw("&");
            else{
                attron(COLOR_PAIR(9));
                printw("%c", level[i][t]);
                attroff(COLOR_PAIR(9));
            }      
        }
    }

        Sleep(100);
        t++;
        if(s == 0 && m == 0)
            return 0;
        else 
            return 1;
}
void movepac(int ypac, int light, int num){
    move(ypac, light*27 + 27);
    attron(COLOR_PAIR(9));
    printw("Y");
    attroff(COLOR_PAIR(9));
    refresh();
    Sleep(120);
    move(ypac, light*27 + 27);
    printw(" ");
    move(ypac + 1, light*27 + 27);
    attron(COLOR_PAIR(9));
    printw("Y");
    attroff(COLOR_PAIR(9));
    move(ypac + 1, light*27 + 27);
    refresh();
    Sleep(100);
    if(num == 0){
    for(int i=0;i<27;i++){
        move(ypac + 1, light*27 + 27 + i);
        attron(COLOR_PAIR(9));
        printw(">");
        attroff(COLOR_PAIR(9));
        refresh();
        Sleep(60);
        move(ypac + 1, light*27 + 27 + i);
        printw(" ");
    }
    light++;
    }
    if(num == 1){
    for(int i=0;i<27;i++){
        move(ypac + 1, light*27 + 27 - i);
        attron(COLOR_PAIR(9));
        printw("<");
        attroff(COLOR_PAIR(9));
        refresh();
        Sleep(60);
        move(ypac + 1, light*27 + 27 - i);
        printw(" ");
    }
    light--;
    }
    move(ypac + 1, light*27 + 27);
    attron(COLOR_PAIR(9));
    printw("^");
    attroff(COLOR_PAIR(9));
    refresh();
    Sleep(90);
}
void Ender(int num){ 
    int xmax,ymax;
    getmaxyx(stdscr,ymax,xmax);
    if(num == 2){
        for(int t=0;t< 7;t++){
            move((ymax / 2) - 7 + t,(xmax - 52) / 2);
            for(int i = 0;i<52;i++){
                if(win[t][i] == '#'){
                    attron(COLOR_PAIR(11));
                    printw("%c", win[t][i]);
                    attroff(COLOR_PAIR(11));
                }
                else 
                    printw("%c", win[t][i]);
            }}
    }
    else{
        for(int t=0;t< 7;t++){
            move((ymax / 2) - 7 + t,(xmax - 48) / 2);
            for(int i = 0;i<48;i++){
                if(lose[t][i] == '#'){
                    attron(COLOR_PAIR(10));
                    printw("%c", lose[t][i]);
                    attroff(COLOR_PAIR(10));
                }
                else 
                    printw("%c", lose[t][i]);
            }}
    }
}

void Goster(int x, int y, int col, int row, char level[row][col]){
    if(mark == 2)
        level[gost_1y][gost_1x] = ' ';
    else if(mark == 3)
        level[gost_1y][gost_1x] = '@';
    else 
        level[gost_1y][gost_1x] = 'o';

    if (gost_1x == x || goststep == 1 || goststep == 2){
        if (gost_1y < y && level[gost_1y + 1][gost_1x] != '+'){
            gost_1y++;
            goststep = 0;
        }
        else if (gost_1y > y && level[gost_1y - 1][gost_1x] != '+'){
            gost_1y--;
            goststep = 0;
        }
        else if(goststep == 1 && level[gost_1y][gost_1x - 1] != '+')
            gost_1x--;
        else if(goststep == 2 && level[gost_1y][gost_1x + 1] != '+')
            gost_1x++;
        else if(level[gost_1y][gost_1x - 1] != '+'){
            goststep = 1;
        }
        else if(level[gost_1y][gost_1x + 1] != '+'){
            goststep = 2;
        }
    }
    else if (gost_1y == y || goststep == 3 || goststep == 4){
        if (gost_1x < x && level[gost_1y][gost_1x + 1] != '+'){
            gost_1x++;
            goststep = 0;
        }
        else if (gost_1x > x && level[gost_1y][gost_1x - 1] != '+'){
            gost_1x--;
            goststep = 0;
        }
        else if(goststep == 4 && level[gost_1y - 1][gost_1x] != '+')
            gost_1y--;
        else if(goststep == 3 && level[gost_1y + 1][gost_1x] != '+')
            gost_1y++;
        else if(level[gost_1y + 1][gost_1x] != '+'){
            goststep = 3;
        }
        else if(level[gost_1y - 1][gost_1x] != '+'){
            goststep = 4;
        }
    }

    else if (gost_1x < x && gost_1y < y){
        if (level[gost_1y][gost_1x + 1] != '+'){
            gost_1x++;
        }
        else if (level[gost_1y + 1][gost_1x] != '+' && (level[gost_1y - 1][gost_1x + 1] == '+' || level[gost_1y + 1][gost_1x + 1] != '+')){
            gost_1y++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+')
            gost_1y--;
        else if (level[gost_1y][gost_1x - 1] != '+')
            gost_1x--;
    }

    else if (gost_1x > x && gost_1y < y){
        if (level[gost_1y][gost_1x - 1] != '+'){
            gost_1x--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+' && (level[gost_1y - 1][gost_1x - 1] == '+' || level[gost_1y + 1][gost_1x - 1] != '+')){
            gost_1y++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+')
            gost_1y--;

        else if (level[gost_1y][gost_1x + 1] != '+')
            gost_1x++;
    }

    else if (gost_1x > x && gost_1y > y)
    {
        if (level[gost_1y][gost_1x - 1] != '+'){
            gost_1x--;
        }
        else if (level[gost_1y - 1][gost_1x] != '+' && (level[gost_1y + 1][gost_1x - 1] == '+' || level[gost_1y - 1][gost_1x - 1] != '+')){
            gost_1y--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+'){
            gost_1y++;
        }

        else if (level[gost_1y][gost_1x + 1] != '+'){
            gost_1x++;
        }
    }

    else if (gost_1x < x && gost_1y > y){
        if (level[gost_1y][gost_1x + 1] != '+'){
            gost_1x++;
        }
        else if (level[gost_1y - 1][gost_1x] != '+' && (level[gost_1y + 1][gost_1x + 1] == '+' || level[gost_1y - 1][gost_1x + 1] != '+')){
            gost_1y--;
        }
        else if (level[gost_1y + 1][gost_1x] != '+')
            gost_1y++;
        else if (level[gost_1y][gost_1x + 1] != '+')
            gost_1x--;
    }

    if (level[gost_1y][gost_1x] == 'o')
        mark = 1;
    else if(level[gost_1y][gost_1x] == ' ')
        mark = 2;
    else if(level[gost_1y][gost_1x] == '@')
        mark = 3;
    level[gost_1y][gost_1x] = '&';
}
int end(int col, int row, char level[row][col], int x, int y){
    int check = 0;
    for(int i = 0;i < col; i++)
        for(int t = 0;t<row;t++)
            if(level[t][i] == 'o')
                check++;
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
    else if(s == 0 && m == 0)
        return 1;
    else if(check == 0 || score == 9999)
        return 2;
    else
        return 0;
}
void PacmanMove(int col, int row, int x, int y, char level[row][col], char Pac[12][117]){
    int step;
    level[1][1] = '>';
    while (step != 27 && end(col, row, level, x, y) == 0){
        int g = 0;
        if (step != KEY_UP && step != KEY_DOWN && step != KEY_LEFT && step != KEY_RIGHT)
            while ((step = getch()) == ERR && end(col, row, level, x, y) == 0){
                draw_level(col, row, level, Pac);
                clear();
                Goster(x, y, col, row, level);
                draw_level(col, row, level, Pac);
            }
        if (step == KEY_UP && level[y - 1][x] == '+')
            step = getch();
        if (step == KEY_DOWN && level[y + 1][x] == '+')
            step = getch();
        if (step == KEY_RIGHT && level[y][x + 1] == '+')
            step = getch();
        if (step == KEY_LEFT && level[y][x - 1] == '+')
            step = getch();

        if (step == KEY_UP && end(col, row, level, x, y) == 0){
            int u = 1;
            while (level[y - 1][x] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0){
                clear();
                level[y][x] = ' ';
                y--;
                if(level[y][x] == '@')
                    s += 15;
                if(level[y][x] == 'o')
                    score++;
                level[y][x] = '^';
                if (u == 2){
                    Goster(x, y, col, row, level);
                    u = 0;}
                else
                    u++;
                draw_level(col, row, level, Pac);
            }
            if (step == KEY_RIGHT || step == KEY_LEFT){
                while (level[y - 1][x] != '+' && end(col, row, level, x, y) == 0){
                    clear();
                    level[y][x] = ' ';
                    y--;
                    if(level[y][x] == '@')
                    s += 15;
                    if(level[y][x] == 'o')
                    score++;
                    level[y][x] = '^';
                    if (g == 2){
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    draw_level(col, row, level, Pac);
                    refresh();
                    if (level[y][x + 1] != '+' && step == KEY_RIGHT)
                        break;
                    if (level[y][x - 1] != '+' && step == KEY_LEFT)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_DOWN && end(col, row, level, x, y) == 0){
            while (level[y + 1][x] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0){
                clear();
                level[y][x] = ' ';
                y++;
                if(level[y][x] == '@')
                    s += 15;
                if(level[y][x] == 'o')
                    score++;
                level[y][x] = 'Y';
                if (g == 3){
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                draw_level(col, row, level, Pac);
            }

            if (step == KEY_RIGHT || step == KEY_LEFT){
                while (level[y + 1][x] != '+' && end(col, row, level, x, y) == 0){
                    clear();
                    level[y][x] = ' ';
                    y++;
                    if(level[y][x] == '@')
                        s += 15;
                    if(level[y][x] == 'o')
                    score++;
                    level[y][x] = 'Y';
                    if (g == 2){
                        Goster(x, y, col, row, level);
                        g = 0;}
                    else
                        g++;
                    draw_level(col, row, level, Pac);
                    refresh();
                    if (level[y][x + 1] != '+' && step == KEY_RIGHT)
                        break;
                    if (level[y][x - 1] != '+' && step == KEY_LEFT)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_RIGHT && end(col, row, level, x, y) == 0){
            while (level[y][x + 1] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0){
                clear();
                level[y][x] = ' ';
                x++;
                if(level[y][x] == '@')
                    s += 15;
                if(level[y][x] == 'o')
                    score++;
                level[y][x] = '>';
                if (g == 2)
                {
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                if (level[y][x] == '&' || level[y][x] == 'h')
                    break;
                draw_level(col, row, level, Pac);
            }
            if (step == KEY_UP || step == KEY_DOWN){
                while (level[y][x + 1] != '+' && end(col, row, level, x, y) == 0){
                    clear();
                    level[y][x] = ' ';
                    x++;
                    if(level[y][x] == '@')
                        s += 15;
                    if(level[y][x] == 'o')
                        score++;
                    level[y][x] = '>';
                    if (g == 2)
                    {
                        Goster(x, y, col, row, level);
                        g = 0;
                    }
                    else
                        g++;
                    if (level[y][x] == '&' || level[y][x] == 'h')
                        break;
                    draw_level(col, row, level, Pac);
                    refresh();
                    if (level[y + 1][x] != '+' && step == KEY_DOWN)
                        break;
                    if (level[y - 1][x] != '+' && step == KEY_UP)
                        break;
                }
            }
        }
        g = 0;
        if (step == KEY_LEFT && end(col, row, level, x, y) == 0){
            while (level[y][x - 1] != '+' && (step = getch()) == ERR && end(col, row, level, x, y) == 0){
                clear();
                level[y][x] = ' ';
                x--;
                if(level[y][x] == '@')
                    s += 15;
                if(level[y][x] == 'o')
                    score++;
                level[y][x] = '<';
                if (g == 3)
                {
                    Goster(x, y, col, row, level);
                    g = 0;
                }
                else
                    g++;
                draw_level(col, row, level, Pac);
            }
            if (step == KEY_UP || step == KEY_DOWN){
                while (level[y][x - 1] != '+' && end(col, row, level, x, y) == 0){
                    clear();
                    level[y][x] = ' ';
                    x--;
                    if(level[y][x] == '@')
                        s += 15;
                    if(level[y][x] == 'o')
                        score++;
                    level[y][x] = '<';
                    if (g == 3){
                        Goster(x, y, col, row, level);
                        g = 0;}
                    else
                        g++;
                    draw_level(col, row, level, Pac);
                    refresh();
                    if (level[y + 1][x] != '+' && step == KEY_DOWN)
                        break;
                    if (level[y - 1][x] != '+' && step == KEY_UP)
                        break;
                }
            }
        }
    }
}

int main(){
    initscr();
    keypad(stdscr, 1);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    start_color();
    srand(time(NULL));
    init_pair(2,COLOR_YELLOW,COLOR_YELLOW);
    init_pair(3,COLOR_BLUE,COLOR_BLACK);
    init_pair(4,COLOR_RED,COLOR_BLACK);
    init_pair(5,COLOR_GREEN,COLOR_BLACK);
    init_pair(6,COLOR_MAGENTA,COLOR_BLACK);
    init_pair(7,COLOR_CYAN,COLOR_BLACK);
    init_pair(8,COLOR_WHITE,COLOR_BLACK);
    init_pair(9,COLOR_YELLOW,COLOR_BLACK);
    init_pair(10,COLOR_RED,COLOR_RED);
    init_pair(11,COLOR_GREEN,COLOR_GREEN);
    
    int x = 1, y = 1;
    int choise;
    int light = 2;
    int lev = 1;
    char Menu[3][7] = {
        {" Play  "},
        {" About "},
        {" Exit  "},
        };
    char Levels[5][11] = {
        {" Level 1"},
        {" Level 2"},
        {" Level 3"},};


//loading(pacman run away from ghost)
    while (lev != 4){
        clear();
        Menu[light][0] = '>';
        int ypac = drawPac(); 
        ypac += 6;
        for (int t = 0; t < 3; t++){
            move(ypac, 27*t + 27);
            for (int i = 0; i < 7; i++){
                if(Menu[t][i] == '>'){
                    attron(COLOR_PAIR(9));
                    printw("%c", Menu[t][i]);
                    attroff(COLOR_PAIR(9));
                }
                else
                    printw("%c", Menu[t][i]);
                }
        }
        Menu[light][0] = ' ';

        if((choise = getch()) == KEY_LEFT && light != 0){
            movepac(ypac,light,1);
            light--;}
        else if(choise == KEY_RIGHT && light != 2){            
            movepac(ypac,light,0);
            light++;}

        else if (choise == 'e'){
            while(1 > 0 && light == 0){
            char levf[row][col];
            generator(levf);
            levf[1][23] = '&';
            
            s = 40, t = 0, m = 0;
            PacmanMove(col, row, x, y, levf, Pac);
            clear();
            
            if(end(col, row, levf, x, y) == 2)
                Ender(2);
            else
                Ender(0);
            gost_1y = 1;
            gost_1x = 23;
            refresh();
            Sleep(1000);
            if(end(col, row, levf, x, y) != 2){
                score = 0;
                break;         
            }
            }
            if (light == 1){
                while ((choise = getch()) != 27){
                    refresh();
                    Sleep(100);
                    clear();
                    ypac = 1;
                    ypac = drawPac();
                    move(ypac + 7, 35);
                    printw("Character controlling by cursor keys.");
                    move(ypac + 8, 35);
                    printw("If you press key he will go while he can.");
                    move(ypac + 9, 35);
                    printw("But you can change direction in any moment"); 
                    move(ypac + 10, 35);
                    printw("and if you try turn and side what you choose is blocked,");
                    move(ypac + 11, 35);
                    printw("Character will remember key, and will be go");
                    move(ypac + 12, 35);
                    printw("until this side is clear and turn.");
                }
            }
            if(light == 2)
                lev = 4;
        }
    }
    getch();
    endwin();
}
