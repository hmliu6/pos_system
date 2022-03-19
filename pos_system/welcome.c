#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<conio.h>

void pos();

void start();

void pos(){
     textcolor(7);
    printf("     ―――――――――       ――――――――――        ――――――――\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―              ―       ―                ―        ―\n");
    printf("     ―――――――――       ―                ―        ――――――――\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ―                ―                      ―\n");
    printf("     ―                       ――――――――――        ――――――――\n");
    printf("\n                          Welcome to the POS System\n\n");
}

void start(){
     textcolor(7);
    char i[100];
    char a[2]="1",b[2]="2",c[2]="3";
    pos();
    printf("               1. Login");
    printf("         2. Registration");
    printf("         3. Exit");
    printf("\n\n");
    do{
    printf("Enter the option : ");
    gets(i);
    setbuf(stdin,NULL);
    if(!(strcmp(i,a)||strcmp(i,b)||strcmp(i,c))){
    printf("Wrong Input!Please try again.");
    printf("\nPlease Press Enter to Continue...\n");
    setbuf(stdin,NULL);
    while( getchar() != '\n' );
    clrscr();
    system("welcome.exe");
    }
    }while(!(strcmp(i,a)||strcmp(i,b)||strcmp(i,c)));
    if(strcmp(i,a)==0){
    clrscr();
    pos();
    system("login.exe");}
    else if(strcmp(i,b)==0){
    clrscr();
    system("registry.exe");}
    else if(strcmp(i,c)==0)
    exit(1);
    else{
         clrscr();
         start();}
}

int main(){
    textcolor(7);
    start();
}
