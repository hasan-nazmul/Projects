#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

using namespace std;

#define up_most 4
#define left_most 5
#define down_most 24
#define right_most 90
#define red 60
#define green 234
#define yellow 242
#define blue 233
#define light_blue 243
#define cyan 235
#define dark_cyan 245
#define grey 56
#define block (char) 219
#define snake_skin (char) 219
#define delay 90
#define point (char) 254

char smallG[10][10] = {

    {block, block, block, block, block},

    {block},

    {block, (char)32, (char)32, block, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, block, block, block, block}

};

char smallA[10][10] = {

    {block, block, block, block, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, block, block, block, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block}

};

char smallM[10][10] = {

    {block, (char)32, (char)32, (char)32, block},

    {block, block, (char)32, block, block},

    {block, (char)32, block, (char)32, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block}

};

char smallE[10][10] = {

    {block, block, block, block, block},

    {block},

    {block, block, block, block},

    {block},

    {block, block, block, block, block}

};

char smallO[10][10] = {

    {block, block, block, block, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, block, block, block, block}

};

char smallV[10][10] = {

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, (char)32, block},

    {(char)32, block, (char)32, block, (char)32},

    {(char)32, (char)32, block}

};

char smallR[10][10] = {

    {block, block, block, block},

    {block, (char)32, (char)32, (char)32, block},

    {block, block, block, block},

    {block, (char)32, block},

    {block, (char)32, (char)32, block}

};

char smallS[10][10] = {

    {block, block, block, block, block},

    {block, (char)32, (char)32, (char)32, (char)32},

    {block, block, block, block, block},

    {(char)32, (char)32, (char)32, (char)32, block},

    {block, block, block, block, block}

};

char smallN[10][10] = {

    {block, (char)32, (char)32, (char)32, block},

    {block, block, (char)32, (char)32, block},

    {block, (char)32, block, (char)32, block},

    {block, (char)32, (char)32, block, block},

    {block, (char)32, (char)32, (char)32, block}

};

char smallK[10][10] = {

    {block, (char)32, (char)32, (char)32, block},

    {block, (char)32, (char)32, block, (char)32},

    {block, block, block, (char)32, (char)32},

    {block, (char)32, block, (char)32, (char)32},

    {block, (char)32, (char)32, block, (char)32}

};

char smallX[10][10] = {

    {block, (char)32, (char)32, (char)32, block},

    {(char)32, block, (char)32, block, (char)32},

    {(char)32, (char)32, block, (char)32, (char)32},

    {(char)32, block, (char)32, block, (char)32},

    {block, (char)32, (char)32, (char)32, block}

};

char smallZ[10][10] = {

    {block, block, block, block, block},

    {(char)32, (char)32, (char)32, (char)32, block},

    {block, block, block, block, block},

    {block, (char)32, (char)32, (char)32, (char)32},

    {block, block, block, block, block}
};

char smallI[10][10] = {

    {block, block, block, block, block},

    {(char)32, (char)32, block, (char)32, (char)32},

    {(char)32, (char)32, block, (char)32, (char)32},

    {(char)32, (char)32, block, (char)32, (char)32},

    {block, block, block, block, block}
};

deque <COORD> snake_body;
short direction = 1;
bool direction_changed = 0;
int score = 0, high_score = 13330;
COORD food, tail;

void gotoxy(COORD a)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void setColor(short ForgC)
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

void draw_alphabet(char str[20][10], int x, int y, int color)
{
    setColor(color);

    int i;

    for(i = 0; i < 5; i++)
    {
        gotoxy({x, y});
        printf("%s", str[i]);
        y++;
    }

    gotoxy({0, 0});
}

void game_crash()
{
    gotoxy({0, 0});

    Sleep(1000);

    int i = 20, j = 12;

    draw_alphabet(smallG, i, j, yellow);

    Sleep(100);

    draw_alphabet(smallA, i + 7, j, yellow);

    Sleep(100);

    draw_alphabet(smallM, i + 14, j, yellow);

    Sleep(100);

    draw_alphabet(smallE, i + 21, j, yellow);

    Sleep(100);

    draw_alphabet(smallO, i + 31, j, yellow);

    Sleep(100);

    draw_alphabet(smallV, i + 38, j, yellow);

    Sleep(100);

    draw_alphabet(smallE, i + 45, j, yellow);

    Sleep(100);

    draw_alphabet(smallR, i + 52, j, yellow);

    Sleep(3000);
}

void play_title()
{
    gotoxy({0, 0});

    int i = 31, j = 8;

    draw_alphabet(smallS, i, j, red);

    draw_alphabet(smallN, i + 7, j, red);

    draw_alphabet(smallA, i + 14, j, red);

    draw_alphabet(smallK, i + 21, j, red);

    draw_alphabet(smallE, i + 28, j, red);

    i -= 4;

    draw_alphabet(smallX, i, j + 7, red);

    draw_alphabet(smallE, i + 7, j + 7, red);

    draw_alphabet(smallN, i + 14, j + 7, red);

    draw_alphabet(smallZ, i + 21, j + 7, red);

    draw_alphabet(smallI, i + 28, j + 7, red);

    draw_alphabet(smallA, i + 35, j + 7, red);
}

void canvas(COORD up_left, COORD down_right, short color)
{
    setColor(color);

    /// Drawing two lines vertically

    for(short i = up_left.X; i <= down_right.X; i++)
    {
        gotoxy({i, up_left.Y});
        cout << block;

        gotoxy({i, down_right.Y});
        cout << block;
    }

    /// Drawing two lines horizaontally

    for(short i = up_left.Y; i <= down_right.Y; i++)
    {
        gotoxy({up_left.X, i});
        cout << block;

        gotoxy({down_right.X, i});
        cout << block;
    }
}

short random(short left_val, short right_val)
{
    time_t t;

    srand((unsigned) time(&t));

    short val = rand() % (right_val + 1);

    if(val < left_val)
        val = (val + left_val) % (right_val + 1);

    return val;
}

void snake()
{
    int N = (int) snake_body.size();

    /// Erasing the tail

    tail = snake_body.back();

    gotoxy(snake_body.back());
    cout << ' ';

    /// Tail following previous bend

    if(snake_body[N - 1].X == snake_body[N - 2].X)
    {
        if(snake_body[N - 1].Y > snake_body[N - 2].Y)   snake_body[N - 1].Y--;
        else    snake_body[N - 1].Y++;
    }

    else
    {
        if(snake_body[N - 1].X > snake_body[N - 2].X)   snake_body[N - 1].X--;
        else    snake_body[N - 1].X++;
    }

    /// Direction changed means, new bend

    if(direction_changed)
    {
        snake_body.push_front(snake_body[0]);
        direction_changed = 0;
        N++;
    }

    /// Head following the last command

    switch(direction)
    {
        case 1:
            snake_body[0].X++;
            break;
        case -1:
            snake_body[0].X--;
            break;
        case 2:
            snake_body[0].Y--;
            break;
        default:
            snake_body[0].Y++;
            break;
    }

    setColor(dark_cyan);

    gotoxy(snake_body[0]);

    cout << snake_skin;

    if(snake_body[N - 1].X == snake_body[N - 2].X && snake_body[N - 1].Y == snake_body[N - 2].Y)
        snake_body.pop_back();

    return;
}

bool overBody(COORD C, string object)   /// checks if C exists over the body of the snake
{
    int N = (int) snake_body.size();

    for(int i = 1; i < N - 1; i++)
    {
        bool f1 = snake_body[i].X == snake_body[i + 1].X && snake_body[i].X == C.X;
        bool f2 = C.Y >= snake_body[i].Y && C.Y <= snake_body[i + 1].Y || C.Y <= snake_body[i].Y && C.Y >= snake_body[i + 1].Y;

        if(f1 && f2)    return 1;

        f1 = snake_body[i].Y == snake_body[i + 1].Y && snake_body[i].Y == C.Y;
        f2 = C.X >= snake_body[i].X && C.X <= snake_body[i + 1].X || C.X <= snake_body[i].X && C.X >= snake_body[i + 1].X;

        if(f1 && f2)    return 1;
    }

    if(object == "food")
    {
        int i = 0;

        bool f1 = snake_body[i].X == snake_body[i + 1].X && snake_body[i].X == C.X;
        bool f2 = C.Y >= snake_body[i].Y && C.Y <= snake_body[i + 1].Y || C.Y <= snake_body[i].Y && C.Y >= snake_body[i + 1].Y;

        if(f1 && f2)    return 1;

        f1 = snake_body[i].Y == snake_body[i + 1].Y && snake_body[i].Y == C.Y;
        f2 = C.X >= snake_body[i].X && C.X <= snake_body[i + 1].X || C.X <= snake_body[i].X && C.X >= snake_body[i + 1].X;

        if(f1 && f2)    return 1;
    }

    return 0;
}

bool gameOver() /// checks for gameover condition
{
    if(snake_body[0].X == left_most || snake_body[0].X == right_most)   return 1;

    else if(snake_body[0].Y == up_most || snake_body[0].Y == down_most)   return 1;

    else if(overBody(snake_body.front(), "head"))   return 1;

    return 0;
}

void scoreBoard()   /// updates score
{
    if(score > high_score)  high_score = score;

    gotoxy({left_most, up_most - 2});
    setColor(red);
    cout << "SCORE : ";
    setColor(yellow);
    setw(5);
    cout << score;

    gotoxy({right_most - 17, up_most - 2});
    setColor(red);
    cout << "High Score : ";
    setColor(yellow);
    setw(5);
    cout << high_score;
}

void foodGenerator()    /// creating food inside the canvas
{
    food.X = random(left_most + 1, right_most - 1);
    food.Y = random(up_most + 1, down_most - 1);

    while(overBody(food, "food"))
    {
        food.X = random(left_most + 1, right_most - 1);
        food.Y = random(up_most + 1, down_most - 1);
    }

    setColor(yellow);

    gotoxy(food);

    cout << point;
}

bool foodEaten()    /// checks for points
{
    return food.X == snake_body[0].X && food.Y == snake_body[0].Y;
}

void setUp()    /// setting up the gameboard
{
    system("cls");

    canvas({left_most, up_most}, {right_most, down_most}, cyan);

    scoreBoard();

    setColor(dark_cyan);

    int N = (int) snake_body.size();

    for(int i = 0; i < N - 1; i++)
    {
        if(snake_body[i].X == snake_body[i + 1].X)
        {
            int m = snake_body[i].Y, n = snake_body[i + 1].Y;

            if(m > n)   swap(m, n);

            for(int j = m; j <= n; j++)
            {
                gotoxy({snake_body[i].X, j});
                cout << snake_skin;
            }
        }

        else
        {
            int m = snake_body[i].X, n = snake_body[i + 1].X;

            if(m > n)   swap(m, n);

            for(int j = m; j <= n; j++)
            {
                gotoxy({j, snake_body[i].Y});
                cout << snake_skin;
            }
        }
    }

    foodGenerator();
}

void read()     /// reading previous updates from files
{
    FILE *fp = fopen("snake_game_pause.txt", "r");

    if(!fp)
    {
        fp = fopen("snake_game_pause.txt", "w");
        fprintf(fp, "1\n10 14\n7 14\n");
        fclose(fp);
        fp = fopen("snake_game_pause.txt", "r");
    }

    COORD C;

    fscanf(fp, "%d", &direction);

    while(fscanf(fp, "%hi %hi", &C.X, &C.Y) != EOF)
    {
        snake_body.push_back(C);
    }

    fclose(fp);

    fp = fopen("snake_game_score.txt", "r");

    if(!fp)
    {
        fp = fopen("snake_game_score.txt", "w");
        fprintf(fp, "0\n0");
        fclose(fp);
        fp = fopen("snake_game_score.txt", "r");
    }

    fscanf(fp, "%d", &score);

    fscanf(fp, "%d", &high_score);

    fclose(fp);
}

void write()    /// writes game update on file
{
    FILE *fp = fopen("snake_game_pause.txt", "w");

    fprintf(fp, "%d\n", direction);

    for(int i = 0; i < (int) snake_body.size(); i++)
    {
        fprintf(fp, "%hi %hi\n", snake_body[i].X, snake_body[i].Y);
    }

    fclose(fp);

    fp = fopen("snake_game_score.txt", "w");

    fprintf(fp, "%d %d\n", score, high_score);

    fclose(fp);
}

void gamePlay()
{
    setUp();

    int ch, speed = 90;

    /// Game Loop starts

    while(1)
    {
        /// Controls

        if(kbhit())
        {
            ch = _getch();

            direction_changed = 1;

            if(ch == 224)
            {
                ch = _getch();

                switch(ch)
                {
                    case 72:
                        if(direction == 2 || direction == -2)
                        {
                            direction_changed = 0;
                            break;
                        }
                        direction = 2;
                        break;

                    case 80:
                        if(direction == 2 || direction == -2)
                        {
                            direction_changed = 0;
                            break;
                        }
                        direction = -2;
                        break;

                    case 75:
                        if(direction == 1 || direction == -1)
                        {
                            direction_changed = 0;
                            break;
                        }
                        direction = -1;
                        break;

                    case 77:
                        if(direction == 1 || direction == -1)
                        {
                            direction_changed = 0;
                            break;
                        }
                        direction = 1;
                        break;

                    default:
                        direction_changed = 0;
                        break;
                }
            }

            else if(ch == 27)
            {
                write();
                return;
            }
        }

        /// drawing current state of the snake
        snake();

        /// checking for score
        if(foodEaten())
        {
            foodGenerator();
            score += 10;
            scoreBoard();

            /// enlarging body
            snake_body.push_back(tail);
            gotoxy(tail);
            cout << snake_skin;

            /// speeding up gradually, in every 100 benchmark
            if(score && !(score % 100) && speed > 30) speed -= 5;
        }

        /// checking for gameover conditions otherwise
        else if(gameOver())
        {
            snake_body.clear();
            snake_body.push_back({10, 6});
            snake_body.push_back({7, 6});
            direction = 1;
            score = 0;
            write();
            game_crash();
            return;
        }

        gotoxy({0, 0});

        Sleep(speed);
    }
}

int main()
{
    read();

    canvas({left_most, up_most}, {right_most, down_most}, cyan);

    play_title();

    gotoxy({0, 0});

    char ch = '2';

    Sleep(3000);

    system("cls");

    canvas({left_most, up_most}, {right_most, down_most}, cyan);

    string cmd1 = "1. Press arrow keys to move the snake.";
    string cmd2 = "2. Press ESC key to exit the game.";
    string cmd3 = "Press any key to continue.";
    string cmd4 = "Do you want to play again?";
    string cmd5 = "Press 1 to play again, press 0 to exit";

    setColor(light_blue);

    gotoxy({10, 12});
    for(int i = 0; cmd1[i]; i++)
    {
        cout << cmd1[i];
        Sleep(100);
    }
    Sleep(1000);
    gotoxy({10, 14});
    for(int i = 0; cmd2[i]; i++)
    {
        cout << cmd2[i];
        Sleep(100);
    }
    gotoxy({10, 16});
    Sleep(2000);
    for(int i = 0; cmd3[i]; i++)
    {
        cout << cmd3[i];
        Sleep(100);
    }

    gotoxy({0, 0});

    getch();

    system("cls");

    do {
        gamePlay();
        system("cls");
        canvas({left_most, up_most}, {right_most, down_most}, cyan);
        setColor(light_blue);
        gotoxy({10, 12});
        for(int i = 0; cmd4[i]; i++)
        {
            cout << cmd4[i];
            Sleep(100);
        }
        gotoxy({10, 14});
        for(int i = 0; cmd5[i]; i++)
        {
            cout << cmd5[i];
            Sleep(100);
        }
        gotoxy({10, 16});
        ch = '2';
        while(ch != '0' && ch != '1') ch = getch();

    } while(ch == '1');

    system("cls");

    return 0;
}

