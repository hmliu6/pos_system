#include<stdio.h>
#include<conio.h>
#include<limits.h> 
#include<stdlib.h> 
#include<windows.h> 
#define SIZE 100

void HideCursor();

void UnhideCursor();

void print(int );

int keypress();

void option();

void function();

int a=1;


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

void print(int i){
     if(i==1)
     printf("    1. Show All Goods                ");
     else if(i==2)
     printf("    2. Search Goods                  ");
     else if(i==3)
     printf("    3. Low Stock Alarm               ");
     else if(i==4)
     printf("    4. Rate Of Sale                  ");
     else if(i==5)
     printf("    5. User Administration           ");
     else if(i==6)
     printf("    6. Logout                        ");
     else if(i==7)
     printf("    7. Exit                          ");
}

int keypress(){
    int ch,cha;
    if((ch=_getch())!= 13){
        if(ch==0||ch==224){
           setbuf(stdin,NULL);
           cha=_getch();   /* up=224,72 down=224,80 left=224,75 right=224,77 */
           if(cha==72){
              if(b!=1){
                 b--;
                 textcolor(159);
                 gotoxy(22,7+b);
                 print(b+1);
                 textcolor(80);
                 gotoxy(22,6+b);
                 print(b);}}
           if(cha==80){
              if(b!=7){
                 b++;
                 textcolor(159);
                 gotoxy(22,5+b);
                 print(b-1);
                 textcolor(80);
                 gotoxy(22,6+b);
                 print(b);}}
        }
    }
    else return 0;
}


void option(){
     HideCursor();
     gotoxy(22,5);
     textcolor(159);
     printf("               Setting               ");
     gotoxy(22,6);
     printf("-------------------------------------");
     gotoxy(22,7);
     textcolor(80);
     printf("    1. Show All Goods                ");
     textcolor(159);
     gotoxy(22,8);
     printf("    2. Search Goods                  ");
     gotoxy(22,9);
     printf("    3. Low Stock Alarm               ");
     gotoxy(22,10);
     printf("    4. Rate Of Sale                  ");
     gotoxy(22,11);
     printf("    5. User Administration           ");
     gotoxy(22,12);
     printf("    6. Logout                        ");
     gotoxy(22,13);
     printf("    7. Exit                          ");
     textcolor(7);
}


void function(){
  int x,y;
  int count=0,countt=0;
  char ch;
  x=wherex();
  y=wherey();
    option();
    while(1)
  {
          count++;
          if(count==1000){
            //gotoxy(x,y);
            count=0;
            countt=1;
          }
   if(kbhit()){
      if(keypress()==0)
      break;
   }
   else{
       if(countt==1){
          time_t t;
          time(&t);
          gotoxy(1,1);
          textcolor(394);
          printf("%81s",ctime(&t));
          countt=0;
          gotoxy(x,y);
       }
   }
 }
if(a==1){
          clrscr();
          show_goods();}
     else if(a==2){
          clrscr();
          add();}
     else if(a==3){
          clrscr();
          searching();}
     else if(a==4){
          clrscr();
          stock_alarm();}
     else if(a==5){
          clrscr();
          sale_rate();}
     else if(a==6){
          clrscr();
          system("admin.exe");}
     else if(a==7){
          clrscr();
          system("welcome.exe");}
     else if(a==8)
          exit(1);
}
    
