#include<stdio.h>
#include<windows.h>

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

int main()
{
    int i;

    for(i = 0; i <= 255; i++)
    {
        setColor(i);
        printf("%3d : %c%c%c%c%c\n", i, (char) 219, (char) 219, (char) 219, (char) 219, (char) 219);
    }
}
