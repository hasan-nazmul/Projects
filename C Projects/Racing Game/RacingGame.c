/// RETRO_RUMBLE_
/// 1st_semester-final_project_
/// 1_bit_2_infinity_

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define ALPHA20 {(char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219}
#define BETA20 {(char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32}
#define ALPHA12 {(char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219}
#define BETA12 {(char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32, (char) 32}
#define GROUND1_LEFT 33
#define GROUND1_RIGHT 49
#define GROUND2_LEFT 69
#define GROUND2_RIGHT 85
#define TOP 3
#define BOTTOM 28
#define YELLOW 2
#define CYAN 3
#define RED 12
#define GREEN 10
#define LIGHT_CYAN 11
#define DARK_CYAN 211
#define DARK_GREEN 245
#define BLUE 25
#define YELLOW 2
#define GREY 40
#define GOLDEN 70
#define BLOOD_RED 20
#define PINK 13
#define TARGET_FPS 30
#define FRAME_TIME (1000 / TARGET_FPS)

void gotoxy(int x, int y);
void gotoXY(COORD C);
void setColor(int ForgC);
void canvas(COORD upper_left, COORD lower_right, char ch1, char ch2, char ch3, char ch4, int color);
int random(int left_val, int right_val);
void draw_vehicle(char str[10][10], COORD C, int flag, int color);
void go_track(char str[100][100], COORD C, int color);
COORD linear(COORD pos);
COORD rash1(COORD pos);
COORD rash2(COORD pos);
void threat_generator();
void mono_threat_generator();
void threat_mover(int i);
int game_over();
void multiplay();
void scoreboard();
void pause_read(int *p, COORD *C, int *s);
void pause_write(int p, COORD C, int s);
void monoplay();
void mono_game_crash();
void multi_game_crash(int f);
void draw_alphabet(char str[20][10], int x, int y, int color, int size);
void setup();
int select_mode();
int single_player();
int login(int f);
int profile();
int your_profile();
void selector(COORD C, int flag);
int purchase();
int signup(int f);
int about_us();
int select_car();
void leaderboard();
void sort();
int IDcheck();
int uniqueID();
void saveInfo();
void readData();
void writeData();

char foot_path[100][100] = {ALPHA20, ALPHA20, BETA20, BETA20, BETA20, BETA20, ALPHA20, ALPHA20, BETA20, BETA20, BETA20, BETA20, ALPHA20, ALPHA20, BETA20, BETA20, BETA20, BETA20, ALPHA20, ALPHA20, BETA20, BETA20, BETA20, BETA20, ALPHA20, ALPHA20, BETA20, BETA20, BETA20, BETA20};

char road_divider[100][100] = {ALPHA12, ALPHA12, BETA12, BETA12, BETA12, BETA12, ALPHA12, ALPHA12, BETA12, BETA12, BETA12, BETA12, ALPHA12, ALPHA12, BETA12, BETA12, BETA12, BETA12, ALPHA12, ALPHA12, BETA12, BETA12, BETA12, BETA12, ALPHA12, ALPHA12, BETA12, BETA12, BETA12, BETA12};

char car[10][10][10] = {

    {{(char)254, (char)254, (char)254, (char)254}, {(char)219, (char)223, (char)223, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)220, (char)220, (char)219}, {(char)254, (char)254, (char)254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)219, (char)220, (char)220, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)223, (char)223, (char)219}, {(char)254, (char)254, (char)254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)220, (char)219, (char)219, (char)220}, {(char)32, (char)219, (char)219, (char)32}, {(char)223, (char)219, (char)219, (char)223}, {(char)254, (char)254, (char)254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)223, (char)219, (char)219, (char)223}, {(char)32, (char)219, (char)219, (char)32}, {(char)220, (char)219, (char)219, (char)220}, {(char)254, (char)254, (char)254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)223, (char)219, (char)219, (char)223}, {(char)219, (char)219, (char)219, (char)219}, {(char)220, (char)219, (char)219, (char)220}, {(char)254, (char)254, (char) 254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)220, (char)219, (char)219, (char)220}, {(char)219, (char)219, (char)219, (char)219}, {(char)223, (char)219, (char)219, (char)223}, {(char)254, (char)254, (char) 254, (char)254}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)254, (char)219, (char)219, (char)254}, {(char)219, (char)219, (char)219, (char)219}, {(char)254, (char)219, (char)219, (char)254}, {(char)254, (char)254, (char) 254, (char)254}}

};

char obstacles[20][10][10] = {

    {{(char)254, (char)254, (char)254, (char)254}, {(char)254, (char)32, (char)32, (char)254}, {(char)254, (char)32, (char)32, (char)254}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char) 219, (char)219, (char)219}},

    {{(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)220, (char)32, (char)32, (char)220}},

    {{(char)254, (char)254, (char)254, (char)254}, {(char)219, (char)219, (char)219, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)32, (char)223, (char)223, (char)32}, {(char) 219, (char)254, (char)254, (char)219}},

    {{(char)219, (char)254, (char)254, (char)219}, {(char)220, (char)220, (char)220, (char)220}, {(char)219, (char)219, (char)219, (char)219}, {(char)223, (char)223, (char)223, (char)223}, {(char)219, (char)254, (char)254, (char)219}},

    {{(char)220, (char)219, (char)219, (char)220}, {(char)223, (char)219, (char)219, (char)223}, {(char)32, (char)219, (char)219}, {(char)219, (char)219, (char)219, (char)219}, {(char)254, (char)254, (char)254, (char)254}}

};

char R[20][10] = {

    {(char)219, (char)219, (char)179},

    {(char)219, (char)218, (char)219, (char)179},

    {(char)219, (char)179, (char)32, (char)219, (char)179},

    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},

    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},

    {(char)219, (char)179, (char)32, (char)219, (char)179},

    {(char)219, (char)219, (char)219, (char)218},

    {(char)219, (char)218, (char)219, (char)192},

    {(char)219, (char)179, (char)32, (char)219, (char)192},

    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},

};

char E[20][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)179},
    {(char)219, (char)218, (char)196, (char)196},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)219, (char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)192, (char)196, (char)196},
    {(char)219, (char)219, (char)219, (char)219, (char)179}
};

char T[20][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219, (char)179},
    {(char)196, (char)196, (char)219, (char)218, (char)196},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)32, (char)219, (char)179}
};

char O[20][10] = {
    {(char)32, (char)219, (char)219, (char)219},
    {(char)219, (char)218, (char)196, (char)196, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)219, (char)219, (char)219, (char)218}
};

char U[20][10] = {
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)32, (char)219, (char)219, (char)219, (char)218}
};

char M[20][10] = {
    {(char)219, (char)192, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)219, (char)192, (char)219, (char)219, (char)179},
    {(char)219, (char)179, (char)219, (char)218, (char)219, (char)179},
    {(char)219, (char)179, (char)219, (char)179, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179}
};

char B[20][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)32},
    {(char)219, (char)218, (char)196, (char)196, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)219, (char)219, (char)219, (char)218},
    {(char)219, (char)218, (char)196, (char)196, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)179, (char)32, (char)32, (char)219, (char)179},
    {(char)219, (char)219, (char)219, (char)219, (char)218}
};

char L[20][10] = {
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)179},
    {(char)219, (char)192, (char)196, (char)196},
    {(char)219, (char)219, (char)219, (char)219}
};

char smallG[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219, (char)32, (char)32, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallA[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219}
};

char smallM[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)32, (char)219, (char)219},
    {(char)219, (char)32, (char)219, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219}
};

char smallE[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallO[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallV[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)32, (char)219, (char)32, (char)219, (char)32},
    {(char)32, (char)32, (char)219}
};

char smallR[10][10] = {
    {(char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)219}
};

char smallP[10][10] = {
    {(char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219}
};

char smallL[10][10] = {
    {(char)219},
    {(char)219},
    {(char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallY[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)32, (char)219, (char)32, (char)219, (char)32},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219}
};

char smallW[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)219, (char)32, (char)219},
    {(char)219, (char)219, (char)32, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219}
};

char smallI[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallN[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)219, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219}
};

char smallT[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219},
    {(char)32, (char)32, (char)219}
};

char smallH[10][10] = {
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)32, (char)32, (char)32, (char)219}
};

char smallS[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)32, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char smallC[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

char small1[10][10] = {
    {(char)32, (char)219, (char)219},
    {(char)219, (char)219, (char)219},
    {(char)32, (char)219, (char)219},
    {(char)32, (char)219, (char)219},
    {(char)219, (char)219, (char)219, (char)219}
};

char small2[10][10] = {
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)32, (char)32, (char)32, (char)32, (char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219},
    {(char)219},
    {(char)219, (char)219, (char)219, (char)219, (char)219}
};

int index = 29, i = 0, color[] = {YELLOW, DARK_GREEN, PINK, YELLOW, GOLDEN}, car_color[] = {DARK_CYAN, RED, GREY, BLUE, GOLDEN, BLUE, DARK_CYAN}, gap = 2, p1 = 0, p2 = 1;

COORD coord = {0, 0}, upper_left = {10, 2}, lower_right = {111, 33}, around1 = {11, 3}, around2 = {55, 3}, around3 = {91, 3};

COORD player1 = {41, 23}, player2 = {77, 23}, score_board_pos_A = {85, 10}, score_board_pos_B = {100, 17};

struct threat
{
    short threat_type, vehicle_type, color;
    COORD pos;

} t[100000];

char name[100], user_name[100], pass[100];

struct player
{
    char name[100], user_name[100], pass[100];
    short highest, coins, cars[10], choosed_car, speed;
    COORD pos;
    short pause_coins;

} P[200];

int Number_of_players = 0, avatar, avatar1;

void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void gotoXY(COORD C)
{
    coord = C;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void setColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){

        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

    return;
}

void hidecursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 100;
   info.bVisible = FALSE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void showcursor()
{
   HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_CURSOR_INFO info;
   info.dwSize = 10;
   info.bVisible = TRUE;
   SetConsoleCursorInfo(consoleHandle, &info);
}

void canvas(COORD upper_left, COORD lower_right, char ch1, char ch2, char ch3, char ch4, int color)
{
    setColor(color);

    int i;

    for(i = upper_left.X; i <= lower_right.X; i++)
    {
        gotoxy(i, upper_left.Y);
        printf("%c", ch1);

        gotoxy(i, lower_right.Y);
        printf("%c", ch3);
    }

    for(i = upper_left.Y + 1; i < lower_right.Y; i++)
    {
        gotoxy(upper_left.X, i);
        printf("%c", ch2);

        gotoxy(lower_right.X, i);
        printf("%c", ch4);
    }
}

int random(int left_val, int right_val)
{
    time_t t;

    srand((unsigned) time(&t));

    int val = rand() % (right_val + 1);

    while(val < left_val)   val = rand() % (right_val + 1);

    return val;
}

void draw_vehicle(char str[10][10], COORD C, int flag, int color)
{
    setColor(color);

    int i, j = 0;

    if(flag)
        for(i = C.Y; i < C.Y + 5; i++)
        {
            gotoxy(C.X, i);
            printf("%s", str[j]);
            j++;
        }

    else
        for(i = C.Y; i < C.Y + 5; i++)
        {
            gotoxy(C.X, i);
            printf("    ", str[j]);
            j++;
        }
}

void go_track(char str[100][100], COORD C, int color)
{
    setColor(color);

    int i, j = C.Y;

    for(i = index; i < 30; i++)
    {
        gotoxy(C.X, j);
        printf("%s", str[i]);

        j++;
    }

    for(i = 0; i < index; i++)
    {
        gotoxy(C.X, j);
        printf("%s", str[i]);

        j++;
    }

    if(index == 0) index = 30;

    gotoxy(0, 0);
}

COORD linear(COORD pos)
{
    if(pos.Y == BOTTOM)
        pos.X = 0, pos.Y = 0;

    if(BOTTOM - pos.Y >= gap) pos.Y += gap;

    else    pos.Y = BOTTOM;

    return pos;
}

COORD rash1(COORD pos)
{
    if(pos.Y == BOTTOM)
    {
        pos.X = 0, pos.Y = 0;
        return pos;
    }

    if(BOTTOM - pos.Y >= gap) pos.Y += gap;

    else    pos.Y = BOTTOM;

    static int flag = 0;

    if(pos.X == GROUND1_LEFT)   flag = 1;

    else if(pos.X == GROUND1_RIGHT) flag = 0;

    if(flag)
    {
        if(GROUND1_RIGHT - pos.X >= gap)  pos.X++;

        else    pos.X = GROUND1_RIGHT;
    }

    else
    {
        if(pos.X - GROUND1_LEFT >= gap)   pos.X--;

        else    pos.X = GROUND1_LEFT;
    }

    return pos;
}

COORD rash2(COORD pos)
{
    if(pos.Y == BOTTOM)
    {
        pos.X = 0, pos.Y = 0;
        return pos;
    }

    if(BOTTOM - pos.Y >= gap) pos.Y += gap;

    else    pos.Y = BOTTOM;

    static int flag = 0;

    if(pos.X == GROUND2_LEFT)   flag = 1;

    else if(pos.X == GROUND2_RIGHT) flag = 0;

    if(flag)
    {
        if(GROUND2_RIGHT - pos.X >= gap)  pos.X++;

        else    pos.X = GROUND2_RIGHT;
    }

    else
    {
        if(pos.X - GROUND2_LEFT >= gap)   pos.X--;

        else    pos.X = GROUND2_LEFT;
    }

    return pos;
}

void threat_generator()
{
    t[i].threat_type = random(1, 3);

    t[i].vehicle_type = random(0, 4);

    t[i].pos.X = random(GROUND1_LEFT, GROUND1_RIGHT);

    t[i].pos.Y = TOP;

    draw_vehicle(obstacles[t[i].vehicle_type], t[i].pos, 1, color[t[i].vehicle_type]);

    i++;

    t[i] = t[i - 1];

    t[i].pos.X += 36;

    draw_vehicle(obstacles[t[i].vehicle_type], t[i].pos, 1, color[t[i].vehicle_type]);

    i++;
}

void mono_threat_generator()
{
    t[i].threat_type = random(1, 3);

    t[i].vehicle_type = random(0, 4);

    t[i].pos.X = random(GROUND1_LEFT, GROUND1_RIGHT);

    t[i].pos.Y = TOP;

    draw_vehicle(obstacles[t[i].vehicle_type], t[i].pos, 1, color[t[i].vehicle_type]);

    i++;
}

void threat_mover(int i)
{
    COORD C;

    C = linear(t[i].pos);

    draw_vehicle(obstacles[t[i].vehicle_type], t[i].pos, 0, color[t[i].vehicle_type]);

    t[i].pos = C;

    if(!C.X)    return;

    draw_vehicle(obstacles[t[i].vehicle_type], C, 1, color[t[i].vehicle_type]);
}

int game_over()
{
    int j;

    for(j = 0; j < i; j++)
        if(t[j].pos.Y > 18 && t[j].pos.Y < 29)
        {
            if(abs(t[j].pos.X - player1.X) < 4 && abs(t[j].pos.X - player2.X + 36) < 4)
                return 3;

            else if(abs(t[j].pos.X - player1.X) < 4) return 1;

            else if(abs(t[j].pos.X - player2.X) < 4)    return 2;
        }

    return 0;
}

void multiplay()
{
    system("cls");

    char command;

    int flag = 0, j, e = 80, timecount = 0;

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    draw_vehicle(car[p1], player1, 1, car_color[p1]);

    draw_vehicle(car[p2], player2, 1, car_color[p2]);

    while(1)
    {
        go_track(foot_path, around1, BLUE);

        go_track(road_divider, around2, BLUE);

        go_track(foot_path, around3, BLUE);

        if(kbhit())
        {
            flag = 1;

            command = getch();

            if(player1.X == GROUND1_LEFT && command == 'a') flag = 0;

            else if(player1.X == GROUND1_RIGHT && command == 's')    flag = 0;

            else if(player2.X == GROUND2_LEFT && command == 'j')    flag = 0;

            else if(player2.X == GROUND2_RIGHT && command == 'k')   flag = 0;
        }

        if(flag)
        {
            if(command == 'a')
            {
                draw_vehicle(car[p1], player1, 0, car_color[p1]);
                player1.X -= 4;
                draw_vehicle(car[p1], player1, 1, car_color[p1]);
            }

            else if(command == 's')
            {
                draw_vehicle(car[p1], player1, 0, car_color[p1]);
                player1.X += 4;
                draw_vehicle(car[p1], player1, 1, car_color[p1]);
            }

            else if(command == 'j')
            {
                draw_vehicle(car[p2], player2, 0, car_color[p2]);
                player2.X -= 4;
                draw_vehicle(car[p2], player2, 1, car_color[p2]);
            }

            else if(command == 'k')
            {
                draw_vehicle(car[p2], player2, 0, car_color[p2]);
                player2.X += 4;
                draw_vehicle(car[p2], player2, 1, car_color[p2]);
            }

            flag = 0;
        }

        if(index % 10 == 0) threat_generator();

        for(j = 0; j < i; j++)
            if(t[j].pos.X)  threat_mover(j);

        int g = game_over();

        if(g)
        {
            multi_game_crash(g);
            player1.X = 41, player1.Y = 23, player2.X = 77, player2.Y = 23;
            i = 0;
            index = 29;
            return;
        }

        index--;

        gotoxy(0, 0);

        Sleep(e);

        timecount += 50;

        if(timecount == 1000)
        {
            timecount = 0;

            if(e > 50)  e--;
        }
    }

    getch();
}

int coins = 0, highest;

void scoreboard()
{
    if(coins > highest) highest = coins;

    setColor(GREEN);

    gotoxy(90, 12);
    printf("COINS:");

    setColor(YELLOW);

    gotoxy(91, 15);
    printf("$%d", coins);
}

void pause_read(int *p, COORD *C, int *s)
{
    *p = P[avatar].speed;
    *C = P[avatar].pos;
    *s = P[avatar].pause_coins;
}

void pause_write(int p, COORD C, int s)
{
    P[avatar].speed = p;
    P[avatar].pos = C;
    P[avatar].pause_coins = s;

    writeData();
}

void monoplay()
{
    system("cls");

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    canvas(score_board_pos_A, score_board_pos_B, 219, 219, 219, 219, RED);

    char command;

    int flag = 0, j, time_count = 0, e;

    pause_read(&e, &player1, &coins);

    draw_vehicle(car[P[avatar].choosed_car], player1, 1, car_color[P[avatar].choosed_car]);

    while(1)
    {
        go_track(foot_path, around1, BLUE);

        go_track(foot_path, around2, BLUE);

        if(kbhit())
        {
            flag = 1;

            command = getch();

            if(player1.X == GROUND1_LEFT && command == 75) flag = 0;

            else if(player1.X == GROUND1_RIGHT && command == 77)    flag = 0;
        }

        if(flag)
        {
            if(command == 75)
            {
                draw_vehicle(car[P[avatar].choosed_car], player1, 0, car_color[P[avatar].choosed_car]);
                player1.X -= 4;
                draw_vehicle(car[P[avatar].choosed_car], player1, 1, car_color[P[avatar].choosed_car]);
            }

            else if(command == 77)
            {
                draw_vehicle(car[P[avatar].choosed_car], player1, 0, car_color[P[avatar].choosed_car]);
                player1.X += 4;
                draw_vehicle(car[P[avatar].choosed_car], player1, 1, car_color[P[avatar].choosed_car]);
            }

            else if(command == 27)
            {
                pause_write(e, player1, coins);
                coins = 0;
                return;
            }

            flag = 0;
        }

        if(index % 10 == 0) mono_threat_generator();

        for(j = 0; j < i; j++)
            if(t[j].pos.X)  threat_mover(j);

        int g = game_over();

        if(g)
        {
            mono_game_crash();
            player1.X = 41, player1.Y = 23;
            pause_write(80, player1, 0);
            i = 0;
            index = 29;
            return;
        }

        index--;

        time_count += 50;

        gotoxy(0, 0);

        scoreboard();

        if(time_count == 1000)
        {
            time_count = 0;
            coins++;

            if(e > 50)  e--;
        }

        Sleep(e);
    }
}

void draw_alphabet(char str[20][10], int x, int y, int color, int size)
{
    setColor(color);

    int i;

    for(i = 0; i < size; i++)
    {
        gotoxy(x, y);
        printf("%s", str[i]);
        y++;
    }

    gotoxy(0, 0);
}

void mono_game_crash()
{
    FILE *fp = fopen("highest.txt", "w");

    fprintf(fp, "%d\n", highest);

    if(coins > P[avatar].highest)
    {
        P[avatar].highest = coins;
        writeData();
    }

    fclose(fp);

    gotoxy(0, 0);

    Sleep(1000);

    int i = 33, j = 10;

    system("cls");

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    draw_alphabet(smallG, i, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallA, i + 7, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallM, i + 14, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallE, i + 21, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallO, i + 31, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallV, i + 38, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallE, i + 45, j, YELLOW, 5);

    Sleep(100);

    draw_alphabet(smallR, i + 52, j, YELLOW, 5);

    gotoxy(55, 20);

    setColor(GREEN);

    printf("COINS :  ");

    setColor(YELLOW);

    printf("+ $%d", coins);

    gotoxy(0, 0);

    Sleep(3000);
}

void multi_game_crash(int f)
{
    gotoxy(0, 0);

    Sleep(1000);

    int i = 23, j = 15;

    system("cls");

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    if(f == 1)
    {
        draw_alphabet(smallP, i, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallL, i + 7, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallA, i + 14, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallY, i + 21, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallE, i + 28, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallR, i + 35, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(small2, i + 42, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallW, i + 53, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallI, i + 60, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallN, i + 67, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallS, i + 74, j, YELLOW, 5);

        gotoxy(0, 0);
    }

    else if(f == 2)
    {
        draw_alphabet(smallP, i, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallL, i + 7, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallA, i + 14, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallY, i + 21, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallE, i + 28, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallR, i + 35, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(small1, i + 42, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallW, i + 53, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallI, i + 60, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallN, i + 67, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallS, i + 74, j, YELLOW, 5);

        gotoxy(0, 0);
    }

    else if(f == 3)
    {
        i += 10;

        draw_alphabet(smallM, i, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallA, i + 7, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallT, i + 14, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallC, i + 21, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallH, i + 28, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallT, i + 38, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallI, i + 45, j, YELLOW, 5);

        Sleep(100);

        draw_alphabet(smallE, i + 52, j, YELLOW, 5);

        gotoxy(0, 0);
    }

    Sleep(3000);
}

void setup()
{
    system("cls");

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    draw_alphabet(R, 55, 5, DARK_CYAN, 10);
    draw_alphabet(E, 65, 5, RED, 10);
    draw_alphabet(T, 75, 5, BLUE, 10);
    draw_alphabet(R, 85, 5, GOLDEN, 10);
    draw_alphabet(O, 95, 5, DARK_GREEN, 10);

    draw_alphabet(R, 50, 17, RED, 10);
    draw_alphabet(U, 60, 17, GOLDEN, 10);
    draw_alphabet(M, 70, 17, DARK_CYAN, 10);
    draw_alphabet(B, 80, 17, DARK_GREEN, 10);
    draw_alphabet(L, 90, 17, BLUE, 10);
    draw_alphabet(E, 100, 17, DARK_CYAN, 10);

    gotoxy(67, 31);

    setColor(RED);
    printf("By 1 bit 2 infinity");
}

int select_mode()
{
    setup();

    setColor(YELLOW);

    gotoxy(15, 14);
    printf(">  Single Player");

    setColor(GREEN);

    gotoxy(15, 17);
    printf("   Multi Player");

    gotoxy(15, 20);
    printf("   About Us");

    gotoxy(15, 23);
    printf("   Exit");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 14);
            printf("   Single Player");

            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Multi Player");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Multi Player");

            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  About Us");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(GREEN);

            gotoxy(15, 20);
            printf("   About Us");

            setColor(YELLOW);

            gotoxy(15, 23);
            printf(">  Exit");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  About Us");

            setColor(GREEN);

            gotoxy(15, 23);
            printf("   Exit");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Multi Player");

            setColor(GREEN);

            gotoxy(15, 20);
            printf("   About Us");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 14);
            printf(">  Single Player");

            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Multi Player");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

int single_player()
{
    setup();

    setColor(YELLOW);

    gotoxy(15, 14);
    printf(">  Log In");

    setColor(GREEN);

    gotoxy(15, 17);
    printf("   Sign Up");

    gotoxy(15, 20);
    printf("   Home Page");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 14);
            printf("   Log In");

            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Sign Up");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Sign Up");

            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Sign Up");

            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 14);
            printf(">  Log In");

            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Sign Up");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

int login(int f)
{
    setup();

    showcursor();

    if(f)
    {
        setColor(RED);

        gotoxy(17, 8);
        printf("Invalid User Name");

        gotoxy(17, 10);
        printf("  or Password");
    }

    setColor(YELLOW);

    gotoxy(15, 14);
    printf(">  User Name :");

    setColor(GREEN);

    gotoxy(15, 17);
    printf("   Password  :");

    gotoxy(15, 20);
    printf("   Home Page");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 14);
            printf("   User Name :");

            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Password  :");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Password  :");

            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Home Page");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Password  :  ");

            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Home Page");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 14);
            printf(">  User Name :  ");

            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Password  :  ");

            pos--;
        }

        else if(ch == 32 && !pos)
        {
            setColor(YELLOW);
            gotoxy(31, 14);
            scanf("%s", name);
        }

        else if(ch == 32 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(31, 17);

            int i = 0;

            while(1)
            {
                pass[i] = getch();

                if(pass[i] == 13)   break;

                printf("*");

                i++;
            }

            pass[i] = '\0';

            avatar = IDcheck();

            hidecursor();

            if(avatar < 0)
                return login(1);

            return 1;
        }

        else if(ch == 32)
        {
            hidecursor();
            return pos;
        }
    }
}

int profile()
{
    setup();

    setColor(LIGHT_CYAN);

    gotoxy(17, 8);
    printf("Welcome Back");

    gotoxy(17, 10);
    printf("%s!", P[avatar].name);

    setColor(YELLOW);

    gotoxy(15, 14);
    printf(">  Start Game");

    setColor(GREEN);

    gotoxy(15, 17);
    printf("   Your Profile");

    gotoxy(15, 20);
    printf("   Purchase");

    gotoxy(15, 23);
    printf("   Log Out");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 14);
            printf("   Start Game");

            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Your Profile");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Your Profile");

            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Purchase");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Purchase");

            setColor(YELLOW);

            gotoxy(15, 23);
            printf(">  Log Out");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Purchase");

            setColor(GREEN);

            gotoxy(15, 23);
            printf("   Log Out");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  Your Profile");

            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Purchase");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 14);
            printf(">  Start Game");

            setColor(GREEN);

            gotoxy(15, 17);
            printf("   Your Profile");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

int your_profile()
{
    setup();

    setColor(GREEN);
    gotoxy(15, 11);
    printf("Best      : ");
    setColor(YELLOW);
    printf("%d", highest);
    setColor(GREEN);
    gotoxy(15, 14);
    printf("Your Best : ");
    setColor(YELLOW);
    printf("%d", P[avatar].highest);

    setColor(YELLOW);

    gotoxy(15, 20);
    printf(">  Select Car");

    setColor(GREEN);

    gotoxy(15, 23);
    printf("   Leaderboards");

    gotoxy(15, 26);
    printf("   Return");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Select Car");

            setColor(YELLOW);

            gotoxy(15, 23);
            printf(">  Leaderboards");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 23);
            printf("   Leaderboards");

            setColor(YELLOW);

            gotoxy(15, 26);
            printf(">  Return");

            pos++;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 23);
            printf(">  Leaderboards");

            setColor(GREEN);

            gotoxy(15, 26);
            printf("   Return");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Select Car");

            setColor(GREEN);

            gotoxy(15, 23);
            printf("   Leaderboards");

            pos--;
        }

        else if(ch == 32)   return pos;
    }
}

void selector(COORD C, int flag)
{
    gotoXY(C);

    if(flag)    printf(">");
    else    printf(" ");

    gotoxy(C.X + 7, C.Y);

    if(flag)    printf("<");
    else    printf(" ");
}

int purchase()
{
    system("cls");

    canvas(upper_left, lower_right, 219, 219, 219, 219, BLUE);

    int i, value = 0;

    COORD pos[7] = {{30, 10}, {50, 10}, {70, 10}, {90, 10}, {40, 23}, {60, 23}, {80, 23}}, A, B, Select = {28, 12};

    for(i = 0; i < 7; i++)
    {
        draw_vehicle(car[i], pos[i], 1, car_color[i]);

        A = pos[i];
        B = pos[i];

        A.X -= 2;
        A.Y -= 2;
        B.Y += 7;

        gotoXY(A);

        if(P[avatar].cars[i])
        {
            setColor(GREEN);
            printf("PURCHASED");
        }

        else
        {
            setColor(YELLOW);
            printf("PURCHASE");
        }

        gotoXY(B);

        if(i * 1000 < 1000) printf("$000");

        else    printf("$%d", i * 100);
    }

    gotoxy(50, 4);

    setColor(GREEN);

    printf("Available Balance: ");

    setColor(YELLOW);

    printf("$%d", P[avatar].coins);

    selector(Select, 1);

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 77 && Select.X < 88 && Select.Y == 12)
        {
            selector(Select, 0);
            Select.X += 20;
            selector(Select, 1);
            value += 100;
        }

        else if(ch == 75 && Select.X > 28 && Select.Y == 12)
        {
            selector(Select, 0);
            Select.X -= 20;
            selector(Select, 1);
            value -= 100;
        }

        else if(ch == 77 && Select.X < 78 && Select.Y == 25)
        {
            selector(Select, 0);
            Select.X += 20;
            selector(Select, 1);
            value += 100;
        }

        else if(ch == 75 && Select.X > 38 && Select.Y == 25)
        {
            selector(Select, 0);
            Select.X -= 20;
            selector(Select, 1);
            value -= 100;
        }

        else if(ch == 80 && Select.Y == 12)
        {
            selector(Select, 0);
            Select.X = 38;
            Select.Y = 25;
            selector(Select, 1);
            value = 400;
        }

        else if(ch == 72 && Select.Y == 25)
        {
            selector(Select, 0);
            Select.X = 28;
            Select.Y = 12;
            selector(Select, 1);
            value = 0;
        }

        else if(ch == 32 && P[avatar].cars[value / 100])
        {
            gotoxy(50, 4);

            setColor(RED);

            printf("You already have the car");

            gotoxy(0, 0);

            Sleep(2000);

            gotoxy(50, 4);

            setColor(GREEN);

            printf("Available Balance: ");

            setColor(YELLOW);

            printf("$%d  ", P[avatar].coins);
        }

        else if(ch == 32 && !P[avatar].cars[value / 100])
        {
            if(P[avatar].coins >= value)
            {
                P[avatar].coins -= value;
                P[avatar].cars[value / 100] = 1;
                writeData();
                return 1;
            }

            else
            {
                gotoxy(45, 4);

                setColor(RED);

                printf("You don't have enough balance");

                gotoxy(0, 0);

                Sleep(2000);

                gotoxy(45, 4);

                setColor(GREEN);

                printf("     Available Balance: ");

                setColor(YELLOW);

                printf("$%d  ", P[avatar].coins);
            }
        }

        else if(ch == 27)   return 0;
    }
}

int signup(int f)
{
    setup();

    showcursor();

    if(f)
    {
        setColor(RED);

        gotoxy(17, 8);
        printf("This User Name");

        gotoxy(17, 10);
        printf("isn't available");
    }

    setColor(YELLOW);

    gotoxy(15, 14);
    printf(">  Your Name  :");

    setColor(GREEN);

    gotoxy(15, 17);
    printf("   User Name  :");

    gotoxy(15, 20);
    printf("   Password   :");

    gotoxy(15, 23);
    printf("   Home page");

    int pos = 0;

    char ch;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 80 && !pos)
        {
            setColor(GREEN);

            gotoxy(15, 14);
            printf("   Your Name  :");

            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  User Name  :");

            pos++;
        }

        else if(ch == 80 && pos == 1)
        {
            setColor(GREEN);

            gotoxy(15, 17);
            printf("   User Name  :");

            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Password   :");

            pos++;
        }

        else if(ch == 80 && pos == 2)
        {
            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Password   :");

            setColor(YELLOW);

            gotoxy(15, 23);
            printf(">  Home page");

            pos++;
        }

        else if(ch == 72 && pos == 3)
        {
            setColor(YELLOW);

            gotoxy(15, 20);
            printf(">  Password   :");

            setColor(GREEN);

            gotoxy(15, 23);
            printf("   Home page");

            pos--;
        }

        else if(ch == 72 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(15, 17);
            printf(">  User Name  :");

            setColor(GREEN);

            gotoxy(15, 20);
            printf("   Password   :");

            pos--;
        }

        else if(ch == 72 && pos == 1)
        {
            setColor(YELLOW);

            gotoxy(15, 14);
            printf(">  Your Name  :");

            setColor(GREEN);

            gotoxy(15, 17);
            printf("   User Name  :");

            pos--;
        }

        else if(ch == 32 && !pos)
        {
            setColor(YELLOW);
            gotoxy(31, 14);
            scanf(" %[^\n]", name);
        }

        else if(ch == 32 && pos == 1)
        {
            setColor(YELLOW);
            gotoxy(31, 17);
            scanf("%s", user_name);
        }

        else if(ch == 32 && pos == 2)
        {
            setColor(YELLOW);

            gotoxy(31, 20);

            int i = 0;

            while(1)
            {
                pass[i] = getch();

                if(pass[i] == 13)   break;

                printf("*");

                i++;
            }

            pass[i] = '\0';

            hidecursor();

            if(uniqueID())  return signup(1);

            return 1;
        }

        else if(ch == 32)
        {
            hidecursor();
            return pos;
        }
    }
}

int about_us()
{
    system("cls");
    setup();

    setColor(RED);

    gotoxy(15, 5);
    printf("Retro_Rumble_");

    gotoxy(15, 6);
    printf("By 1 bit 2 infinity");

    setColor(YELLOW);

    gotoxy(15, 10);
    printf("Developed By:");

    setColor(RED);
    gotoxy(15, 13);
    printf("Nazmul Hasan");

    gotoxy(15, 15);
    printf("Pursuing B.Sc in CSE");
    gotoxy(15, 16);
    printf("from IIUC");
    gotoxy(15, 18);
    printf("nh2826239@gmail.com");

    setColor(YELLOW);

    gotoxy(15, 22);
    printf("Sponsored By:");

    setColor(RED);

    gotoxy(15, 25);
    printf("IRAMS");

    gotoxy(15, 27);
    printf("Halal Perfume and");
    gotoxy(15, 28);
    printf("Attar Store");

    gotoxy(15, 30);
    printf("01401975789");

    gotoxy(0, 0);
    getch();
}

int select_car()
{
    system("cls");
    setup();

    COORD C = {28, 16};

    draw_vehicle(car[0], C, 1, car_color[0]);

    setColor(GREEN);

    gotoxy(24, 18);
    printf("<");

    gotoxy(35, 18);
    printf(">");

    char ch;

    int pos = 0, flag = 0, selection = 0;

    while(1)
    {
        gotoxy(0, 0);

        ch = getch();

        if(ch == 77 && pos < 6)
        {
            pos++;

            while(!P[avatar].cars[pos] && pos <= 6) pos++;

            if(P[avatar].cars[pos])
            {
                draw_vehicle(car[0], C, 0, car_color[0]);
                draw_vehicle(car[pos], C, 1, car_color[pos]);
                selection = pos;
            }
        }

        else if(ch == 75 && pos >= 1)
        {
            pos--;

            while(!P[avatar].cars[pos] && pos >= 0) pos--;

            if(P[avatar].cars[pos])
            {
                draw_vehicle(car[0], C, 0, car_color[0]);
                draw_vehicle(car[pos], C, 1, car_color[pos]);
                selection = pos;
            }
        }

        else if(ch == 27)   return 0;

        else if(ch == 32)
        {
            P[avatar].choosed_car = selection;
            writeData();
            return 1;
        }
    }

    gotoxy(0, 0);

    getch();
}

void leaderboard()
{
    sort();

    system("cls");
    setup();

    setColor(YELLOW);

    gotoxy(15, 5);
    printf("Leaderbord");

    int i, j = 8, k = 5;

    if(Number_of_players < 5)   k = Number_of_players;

    for(i = 0; i < k; i++)
    {
        gotoxy(15, j);

        setColor(YELLOW);
        printf("%d.  ", i + 1);

        setColor(LIGHT_CYAN);
        printf("%d  ", P[i].highest);

        setColor(GREEN);
        printf("%s", P[i].user_name);

        j += 2;
    }

    gotoxy(0, 0);

    getch();
}

void sort()
{
    struct player temp;

    int i, j;

    for(i = 0; i < Number_of_players; i++)
        for(j = i + 1; j < Number_of_players; j++)
            if(P[i].highest < P[j].highest)
            {
                temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }

    for(i = 0; i < Number_of_players; i++)
        if(!strcmp(P[i].user_name, name))
        {
            avatar = i;
            break;
        }
}

int IDcheck()
{
    int i;

    for(i = 0; i < Number_of_players; i++)
        if(!strcmp(name, P[i].user_name))
        {
            if(!strcmp(pass, P[i].pass))    return i;
            return -1;
        }

    return -1;
}

int uniqueID()
{
    int i;

    for(i = 0; i < Number_of_players; i++)
        if(!strcmp(user_name, P[i].user_name))
            return 1;

    return 0;
}

void saveInfo()
{
    int i;

    strcpy(P[Number_of_players].name, name);
    strcpy(P[Number_of_players].user_name, user_name);
    strcpy(P[Number_of_players].pass, pass);

    P[Number_of_players].highest = 0;
    P[Number_of_players].coins = 10;

    P[Number_of_players].cars[0] = 1;

    for(i = 1; i < 7; i++)
        P[Number_of_players].cars[i] = 0;

    P[Number_of_players].choosed_car = 0;
    P[Number_of_players].speed = 80;
    P[Number_of_players].pos.X = 41;
    P[Number_of_players].pos.Y = 23;
    P[Number_of_players].pause_coins = 0;

    Number_of_players++;

    writeData();
}

void readData()
{
    FILE *f = fopen("highest.txt", "r");

    fscanf(f, "%d", &highest);

    fclose(f);

    if(!f)
    {
        highest = 0;
        FILE *fp = fopen("highest.txt", "w");
        fprintf(fp, "0\n");
        fclose(fp);
    }

    FILE *fp = fopen("players.txt", "r");

    if(!fp)
    {
        fp = fopen("players.txt", "w");
        fprintf(fp, "0\n");
        fclose(fp);
        return;
    }

    int i, j;

    fscanf(fp, "%d", &Number_of_players);

    for(i = 0; i < Number_of_players; i++)
    {
        fscanf(fp, " %[^\n]", P[i].name);
        fscanf(fp, "%s", P[i].user_name);
        fscanf(fp, "%s", P[i].pass);
        fscanf(fp, "%d", &P[i].highest);
        fscanf(fp, "%d", &P[i].coins);

        for(j = 0; j < 7; j++)
            fscanf(fp, "%d", &P[i].cars[j]);

        fscanf(fp, "%d", &P[i].choosed_car);
        fscanf(fp, "%d", &P[i].speed);
        fscanf(fp, "%d", &P[i].pos.X);
        fscanf(fp, "%d", &P[i].pos.Y);
        fscanf(fp, "%d", &P[i].pause_coins);
    }

    fclose(fp);
}

void writeData()
{
    FILE *fp = fopen("players.txt", "w");

    int i, j;

    fprintf(fp, "%d\n", Number_of_players);

    for(i = 0; i < Number_of_players; i++)
    {
        fprintf(fp, "%s\n", P[i].name);
        fprintf(fp, "%s\n", P[i].user_name);
        fprintf(fp, "%s\n", P[i].pass);
        fprintf(fp, "%d\n", P[i].highest);
        fprintf(fp, "%d\n", P[i].coins);

        for(j = 0; j < 7; j++)
            fprintf(fp, "%d ", P[i].cars[j]);

        fprintf(fp, "\n%d\n", P[i].choosed_car);
        fprintf(fp, "%d\n", P[i].speed);
        fprintf(fp, "%d\n", P[i].pos.X);
        fprintf(fp, "%d\n", P[i].pos.Y);
        fprintf(fp, "%d\n", P[i].pause_coins);
    }

    fclose(fp);
}

int main()
{
    int f, f1, f2, f3, f4, f5, f6, f7, i, j;

    readData();

    hidecursor();

    Sleep(5000);

    while(1)
    {
        f = select_mode();

        if(!f)
        {
            f1 = single_player();

            if(!f1)
            {
                f2 = login(0);

                if(f2 == 1)

                    while(1)
                    {
                        f3 = profile();

                        if(!f3)
                        {
                            monoplay();
                            P[avatar].coins += coins;
                            coins = 0;
                            writeData();
                        }

                        else if(f3 == 1)
                        {
                            while(1)
                            {
                                f4 = your_profile();

                                if(!f4) select_car();

                                else if(f4 == 1) leaderboard();

                                else if(f4 == 2)    break;
                            }
                        }

                        else if(f3 == 2)    purchase();

                        else if(f3 == 3)    break;
                    }
            }

            else if(f1 == 1)
            {
                f5 = signup(0);

                if(f5 == 1) saveInfo();
            }
        }

        else if(f == 1) multiplay();

        else if(f == 2) about_us();

        else
        {
            system("cls");
            return 0;
        }
    }

    showcursor();
}
