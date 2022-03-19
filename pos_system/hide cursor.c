#include<stdio.h>
#include<conio.h>
#include<windows.h>

void HideCursor()
{
    HANDLE h0ut;
    CONSOLE_CURSOR_INFO ConCurInf;
    h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 20;
    ConCurInf.bVisible = FALSE;
    SetConsoleCursorInfo(h0ut,&ConCurInf);
}

void UnhideCursor()
{
    HANDLE h0ut;
    CONSOLE_CURSOR_INFO ConCurInf;
    h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
    ConCurInf.dwSize = 20;
    ConCurInf.bVisible = TRUE;
    SetConsoleCursorInfo(h0ut,&ConCurInf); 

}



int main(){
    HideCursor();
    //void _setcursortype(int _type);
    //_setcursortype(_NOCURSOR);
    
    int i;
    scanf("%d",&i);
    UnhideCursor();
    system("pause");
}
