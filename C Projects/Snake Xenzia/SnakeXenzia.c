#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

COORD coord = {0,0};

void gotoxy (int x, int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void canvas(int x, int y, int p, int q, char ch)
{
    int i;

    for(i = x; i <= p; i++)
    {
        gotoxy(i, y);
        printf("%c", ch);

        gotoxy(i, q);
        printf("%c", ch);
    }

    for(i = y + 1; i < q; i++)
    {
        gotoxy(x, i);
        printf("%c", ch);

        gotoxy(p, i);
        printf("%c", ch);
    }
}

void snake(int x, int p, int y)
{
    int i;

    for(i = x; i <= p; i++)
    {
        gotoxy(i, y);
        printf("*");
    }
}

int bends = 1, score = 0, high_score;

int i = 0, t = 90000, end;

struct coordinates
{
    int x, y;
};

typedef struct coordinates C;

C bend[100000], head, tail, border_B, border_E, food, pt;

void track()
{
    int i;

    for(i = 0; i < bends; i++)
    {
        if(bend[i].x)
        {
            if(tail.x == bend[i].x && tail.y == bend[i].y)
            {
                bend[i].x = 0;
                bend[i].y = 0;

                continue;
            }

            else if(tail.x == bend[i].x)
            {
                if(tail.y > bend[i].y)
                    tail.y--;

                else    tail.y++;
            }

            else if(tail.y == bend[i].y)
            {
                if(tail.x > bend[i].x)
                    tail.x--;

                else    tail.x++;
            }

            return;
        }
    }

    if(head.x == tail.x)
    {
        if(head.y > tail.y) tail.y++;

        else    tail.y--;
    }

    else if(head.y == tail.y)
    {
        if(head.x > tail.x) tail.x++;

        else    tail.x--;
    }
}

void setup()
{
    i = 0, bends = 1, score = 0, t = 90000;

    gotoxy(10, 3);

    printf("HIGH SCORE: %5d", high_score);

    gotoxy(74, 3);

    printf("YOUR SCORE: %5d", score);

    canvas(border_B.x, border_B.y, border_E.x, border_E.y, 'H');
}

void food_generator()
{
    time_t t;

    srand((unsigned) time(&t));

    food.x = rand() % border_E.x;

    food.y = rand() % border_E.y;

    while(food.x <= border_B.x || food.x >= border_E.x)
        food.x = rand() % border_E.x;

    while(food.y <= border_B.y || food.y >= border_E.y)
        food.y = rand() % border_E.y;
}

int food_eaten()
{
    if(head.x == food.x && head.y == food.y)
        return 1;

    return 0;
}

int food_over_body(int x, int y)
{
    int i, flag = 1;

    for(i = 0; i < bends; i++)
        if(bend[i].x)
        {
            flag = 0;
            break;
        }

    if(flag)
    {
        if(head.x == tail.x && x == head.x)
            if(y >= head.y && y <= tail.y || y <= head.y && y >= tail.y)
                return 1;

        if(head.y == tail.y && y == head.y)
            if(x >= head.x && x <= tail.x || x <= head.x && x >= tail.x)
                return 1;

        return 0;
    }

    if(tail.x == bend[i].x && tail.x == x)
        if(y >= tail.y && y <= bend[i].y || y <= tail.y && y >= bend[i].y)
            return 1;

    if(tail.y == bend[i].y && tail.y == y)
        if(x >= tail.x && x <= bend[i].x || x <= tail.x && x >= bend[i].x)
            return 1;

    for( ; i < bends - 1; i++)
    {
        if(bend[i].x == bend[i + 1].x && bend[i].x == x)
            if(y >= bend[i].y && y <= bend[i + 1].y || y <= bend[i].y && y >= bend[i + 1].y)
                return 1;

        if(bend[i].y == bend[i + 1].y && bend[i].y == y)
            if(x >= bend[i].x && x <= bend[i + 1].x || x <= bend[i].x && x >= bend[i + 1].x)
                return 1;
    }

    if(bend[i].x == head.x && head.x == x)
        if(y >= bend[i].y && y <= head.y || y <= bend[i].y && y >= head.y)
            return 1;

    if(bend[i].y == head.y && head.y == y)
        if(x >= bend[i].x && x <= head.x || x <= bend[i].x && x >= head.x)
            return 1;

    return 0;
}

int body_bite(int x, int y)
{
    int i, flag = 1;

    for(i = 0; i < bends; i++)
        if(bend[i].x)
        {
            flag = 0;
            break;
        }

    if(flag)    return 0;

    if(tail.x == bend[i].x && tail.x == x)
        if(y >= tail.y && y <= bend[i].y || y <= tail.y && y >= bend[i].y)
            return 1;

    if(tail.y == bend[i].y && tail.y == y)
        if(x >= tail.x && x <= bend[i].x || x <= tail.x && x >= bend[i].x)
            return 1;

    for( ; i < bends - 1; i++)
    {
        if(bend[i].x == bend[i + 1].x && bend[i].x == x)
            if(y >= bend[i].y && y <= bend[i + 1].y || y <= bend[i].y && y >= bend[i + 1].y)
                return 1;

        if(bend[i].y == bend[i + 1].y && bend[i].y == y)
            if(x >= bend[i].x && x <= bend[i + 1].x || x <= bend[i].x && x >= bend[i + 1].x)
                return 1;
    }

    return 0;
}

int game_over()
{
    if(head.x == border_B.x || head.y == border_B.y || body_bite(head.x, head.y))
        return 1;

    else if(head.x == border_E.x || head.y == border_E.y || body_bite(head.x, head.y))
        return 1;

    return 0;
}

void body_enlarge()
{
    int i, flag = 1;

    for(i = 0; i < bends; i++)
        if(bend[i].x)
        {
            flag = 0;
            break;
        }

    if(flag)
    {
        if(head.x == tail.x)
        {
            if(head.y > tail.y) tail.y--;

            else    tail.y++;
        }

        else if(head.y == tail.y)
        {
            if(head.x > tail.x) tail.x--;

            else    tail.x++;
        }
    }

    else
    {
        if(bend[i].x == tail.x && bend[i].y == tail.y)
        {
            i++;

            for( ; i < bends; i++)
                if(bend[i].x)
                {
                    flag = 1;
                    break;
                }

            if(flag)
            {
                if(bend[i].x == tail.x)
                {
                    if(bend[i].y > tail.y)  tail.y--;

                    else    tail.y++;
                }

                else
                {
                    if(bend[i].x > tail.x) tail.x--;

                    else    tail.x++;
                }
            }

            else
            {
                if(head.x == tail.x)
                {
                    if(head.y > tail.y) tail.y--;

                    else    tail.y++;
                }

                else if(head.y == tail.y)
                {
                    if(head.x > tail.x) tail.x--;

                    else    tail.x++;
                }
            }
        }

        else if(bend[i].x == tail.x)
        {
            if(bend[i].y > tail.y) tail.y--;

            else    tail.y++;
        }

        else if(bend[i].y == tail.y)
        {
            if(bend[i].x > tail.x) tail.x--;

            else    tail.x++;
        }
    }
}

void crash()
{
    char str[] = "YOU LOSE!";

    int i;

    system("cls");

    gotoxy(((border_B.x + border_E.x) / 2) - 6, (border_B.y + border_E.y) / 2);

    for(i = 0; i < 9; i++)
    {
        printf("%c ", str[i]);
        usleep(100000);
    }

    gotoxy(((border_B.x + border_E.x) / 2) - 6, ((border_B.y + border_E.y) / 2) + 2);

    printf("Your Score: %5d", score);

    gotoxy(((border_B.x + border_E.x) / 2) - 5, ((border_B.y + border_E.y) / 2) + 4);

    printf("Press r to retry");

    gotoxy(((border_B.x + border_E.x) / 2) - 8, ((border_B.y + border_E.y) / 2) + 6);

    printf("Press any key to exit");

    FILE *f;

    f = fopen("snake.txt", "w");

    fprintf(f, "%d\n", high_score);

    fclose(f);

    usleep(1000000);

    gotoxy(((border_B.x + border_E.x) / 2) + 1, ((border_B.y + border_E.y) / 2) + 8);
}

void scoreboard()
{
    if(score > high_score)  high_score = score;

    gotoxy(10, 3);

    printf("HIGH SCORE: %5d", high_score);

    gotoxy(74, 3);

    printf("YOUR SCORE: %5d", score);
}

int controls()
{
    if(food_eaten())
    {
        pt = tail;

        body_enlarge();

        if(tail.x != border_B.x && tail.x != border_E.x)
        {
            if(tail.y != border_B.y && tail.y != border_E.y)
            {
                gotoxy(tail.x, tail.y);
                printf("*");
            }

            else    tail = pt;
        }

        else    tail = pt;

        score += 10;

        if(!(score % 100))    t *= 0.8;

        scoreboard();

        food_generator();

        while(food_over_body(food.x, food.y))
            food_generator();

        gotoxy(food.x, food.y);
        printf("@");
    }

    if(game_over())
    {
        crash();
        return 0;
    }

    return 1;
}

int game_play()
{
    FILE *f;

    f = fopen("snake.txt", "r");

    if(!f)
    {
        f = fopen("snake.txt", "w");
        fprintf(f, "0\n");
        fclose(f);

        high_score = 0;
    }

    fscanf(f, "%d", &high_score);

    fclose(f);

    border_B.x = 10, border_B.y = 5;

    border_E.x = 90, border_E.y = 30;

    setup();

    char N, temp;

    head.x = 41, head.y = 17;

    tail.x = 39, tail.y = 17;

    snake(tail.x, head.x, head.y);

    food_generator();

    while(food_over_body(food.x, food.y))
        food_generator();

    gotoxy(food.x, food.y);
    printf("@");

    gotoxy(0, 0);

    while(1)
    {
        N = getch();

        bend[i].x = head.x;
        bend[i].y = head.y;

        if(i)
        {
            if(N == 'w' || N == 'W' || N == 'i' || N == 'I')
                if(temp == 'z' || temp == 'Z' || temp == 'm' || temp == 'M')
                    N = temp;

            if(N == 'z' || N == 'Z' || N == 'm' || N == 'M')
                if(temp == 'w' || temp == 'W' || temp == 'i' || temp == 'I')
                    N = temp;

            if(N == 'a' || N == 'A' || N == 'j' || N == 'J')
                if(temp == 's' || temp == 'S' || temp == 'k' || temp == 'K')
                    N = temp;

            if(N == 's' || N == 'S' || N == 'k' || N == 'K')
                if(temp == 'a' || temp == 'A' || temp == 'j' || temp == 'J')
                    N = temp;
        }

        else    if(N == 'a' || N == 'A' || N == 'j' || N == 'J')
            N = 's';

        if(N == 'w' || N == 'W' || N == 'i' || N == 'I')
        {
            temp = N;

            while(!kbhit())
            {
                gotoxy(tail.x, tail.y);
                printf(" ");

                head.y--;
                track();

                gotoxy(head.x, head.y);
                printf("*");

                end = controls();

                if(!end)    return 0;

                usleep(t);
            }
        }

        else if(N == 's' || N == 'S' || N == 'k' || N == 'K')
        {
            temp = N;

            while(!kbhit())
            {
                gotoxy(tail.x, tail.y);
                printf(" ");

                head.x++;
                track();

                gotoxy(head.x, head.y);
                printf("*");

                end = controls();

                if(!end)    return 0;

                usleep(t);
            }
        }

        else if(N == 'z' || N == 'Z' || N == 'm' || N == 'M')
        {
            temp = N;

            while(!kbhit())
            {
                gotoxy(tail.x, tail.y);
                printf(" ");

                head.y++;
                track();

                gotoxy(head.x, head.y);
                printf("*");

                end = controls();

                if(!end)    return 0;

                usleep(t);
            }
        }

        else if(N == 'a' || N == 'A' || N == 'j' || N == 'J')
        {
            temp = N;

            while(!kbhit())
            {
                gotoxy(tail.x, tail.y);
                printf(" ");

                head.x--;
                track();

                gotoxy(head.x, head.y);
                printf("*");

                end = controls();

                if(!end)    return 0;

                usleep(t);
            }
        }

        if(!end)    return 0;

        i++;

        bends++;
    }
}

void snake_xenxia(int x, int y)
{
    canvas(x - 2, y - 2, x + 79, y + 8, '*');

    int i, j, k;

    for(i = x; i <= x + 5; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 3);
        printf("*");
        gotoxy(i, y + 6);
        printf("*");
    }

    for(i = y + 1; i < y + 3; i++)
    {
        gotoxy(x, i);
        printf("*");
    }

    for(i = y + 4; i < y + 6; i++)
    {
        gotoxy(x + 5, i);
        printf("*");
    }

    for(i = y; i <= y + 6; i++)
    {
        gotoxy(x + 7, i);
        printf("*");
        gotoxy(x + 13, i);
        printf("*");
    }

    j = x + 8;

    for(i = y + 1; i < y + 6; i++)
    {
        gotoxy(j, i);
        printf("*");
        j++;
    }

    for(i = x + 16; i < x + 21; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 3);
        printf("*");
    }

    for(i = y + 1; i <= y + 6; i++)
    {
        gotoxy(x + 15, i);
        printf("*");
        gotoxy(x + 21, i);
        printf("*");
    }

    for(i = y; i <= y + 6; i++)
    {
        gotoxy(x + 23, i);
        printf("*");
    }

    j = y + 3, k = y + 4;

    for(i = x + 24; i<= x + 27; i++)
    {
        gotoxy(i, j);
        printf("*");

        if(i > x + 24)
        {
            gotoxy(i, k);
            printf("*");
            k++;
        }

        j--;
    }

    for(i = y; i <= y + 6; i++)
    {
        gotoxy(x + 29, i);
        printf("*");
    }

    for(i = x + 30; i <= x + 33; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 3);
        if(i < x + 33)  printf("*");
        gotoxy(i, y + 6);
        printf("*");
    }

    j = y + 2, k = y + 3;

    for(i = x + 40; i <= x + 43; i++)
    {
        if(i < x + 43)
        {
            gotoxy(i, j);
            printf("*");
            j--;
        }

        if(i > x + 24)
        {
            gotoxy(i, k);
            printf("*");
            k++;
        }
    }

    j = y + 2, k = y + 3;

    for(i = x + 39; i >= x + 37; i--)
    {
        if(i < x + 43)
        {
            gotoxy(i, j);
            printf("*");
            j--;
        }

        if(i >= x + 24)
        {
            gotoxy(i, k);
            printf("*");
            k++;
        }
    }

    gotoxy(i, k);
    printf("*");

    for(i = y; i <= y + 6; i++)
    {
        gotoxy(x + 45, i);
        printf("*");
    }

    for(i = x + 46; i <= x + 49; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 3);
        if(i < x + 49)    printf("*");
        gotoxy(i, y + 6);
        printf("*");
    }

    for(i = y; i <= y + 6; i++)
    {
        gotoxy(x + 51, i);
        printf("*");
        gotoxy(x + 57, i);
        printf("*");
    }

    j = x + 52;

    for(i = y + 1; i < y + 6; i++)
    {
        gotoxy(j, i);
        printf("*");
        j++;
    }

    for(i = x + 59; i <= x + 65; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 6);
        printf("*");
    }

    j = y + 1;

    for(i = x + 64; i > x + 59; i--)
    {
        gotoxy(i, j);
        printf("*");
        j++;
    }

    for(i = x + 67; i <= x + 69; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 6);
        printf("*");
    }

    for(i = y + 1; i < y + 6; i++)
    {
        gotoxy(x + 68, i);
        printf("*");
    }

    for(i = x + 72; i < x + 77; i++)
    {
        gotoxy(i, y);
        printf("*");
        gotoxy(i, y + 3);
        printf("*");
    }

    for(i = y + 1; i <= y + 6; i++)
    {
        gotoxy(x + 71, i);
        printf("*");
        gotoxy(x + 77, i);
        printf("*");
    }

    gotoxy(0, 0);
}

int main()
{
    usleep(5000000);

    char ch, N;

    snake_xenxia(11, 10);
    usleep(10000000);

    system("cls");
    printf("INSTRUCTIONS:\n\n");
    usleep(1000000);
    printf("press i or w to go up.\n");
    usleep(1000000);
    printf("press k or s to go right.\n");
    usleep(1000000);
    printf("press m or z to go down.\n");
    usleep(1000000);
    printf("press j or a to go left.\n");
    usleep(5000000);

    do
    {
        system("cls");

        game_play();

        N = getch();

        ch = getch();

    } while(ch == 'r');

    return 0;
}
