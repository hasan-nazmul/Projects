#include<bits/stdc++.h>
#include<windows.h>

using namespace std;

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
    string s = {(char) 219, (char) 219, (char) 219, (char) 219, (char) 219};

    for(int i = 0; i <= 255; i++)
    {
        setColor(i);
        cout << setw(3);
        cout << i << " : " << s << endl;
    }
}
