#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#define SIZE 100
struct data{
       char user[100];
       char pw[100];
       char type[2];
       }db[SIZE];
       
char login_user[100];

void pos();

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
       
void login_username();

void login_username(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("name","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     if(fwrite(login_user,100,1,fp)!=1)
        printf("File write error.\n");
     fclose(fp);
}

void login();

void login(){
     textcolor(7);
       int c;
       int abcd=0;
       int i,j,k,z;
       int ac=0;
       int login=0;
       int count=0,countt=0;
       int x,y;
       char a[100],b[100];
       char admin[2]="A",sales[2]="S",member[2]="M";
       int store,loop=0;
       
       FILE *fp;       /* Start of reading data */
       fp=fopen("data","rb");
       
       
       if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
          
          
       for(i=0;i<SIZE;i++){
           fread(&db[i],sizeof(struct data),1,fp);
           }           /* End of reading data */
       fclose(fp);
           
           
       do{             /* Check the input */
       clrscr();
       pos();
       printf("Please enter your login name : ");
       x=wherex();
       y=wherey();
       printf("\n");
       printf("\nPlease enter your password : ");
       gotoxy(x,y);
       gets(a);
       setbuf(stdin,NULL);
       gotoxy(x-2,y+2);
       loop=0;
       setbuf(stdin,NULL);
       b[loop]=getch();
       setbuf(stdin,NULL);
       while(b[loop]!=13){
          if(b[loop]!=8){
             printf("*");
             loop+=1;
             setbuf(stdin,NULL);
             b[loop]=getch();
             setbuf(stdin,NULL);
             }
          else{
               if(loop>0){
               setbuf(stdin,NULL);
               x=wherex();
               setbuf(stdin,NULL);
               y=wherey();
               setbuf(stdin,NULL);
               x=x-1;
               gotoxy(x,y);
               printf(" ");
               gotoxy(x,y);
               loop-=1;
               }
          b[loop]=getch();}
       }
       b[loop]='\0';
       //gets(b);
       setbuf(stdin,NULL);
       
       
       for(k=0;k<SIZE;k++){
           if(strcmp(db[k].user,a)==0){
              count=1;
              store=k;
              
              
              if(strcmp(db[k].pw,b)==0&&store==k){
                 countt=2;
                 }
              }
              
           if(strcmp(db[k].type,admin)==0&&store==k){
              ac=9999;
              break;
              }
           else if(strcmp(db[k].type,sales)==0&&store==k){
              ac=99;
              break;
              }
           else if(strcmp(db[k].type,member)==0&&store==k){
              ac=9;
              break;
              }
              
           }
           
           
             
       if(count==1&&countt==2){
          strcpy(login_user,a);
          login_username();
          clrscr();
          pos();
          printf("Login Successful!\n\n");
          login=1;
          }
       else if(count==1){
          clrscr();
          pos();
          printf("\n");
          y=wherey();
          gotoxy(23,y);
          printf("Wrong password , Please try again!");
          getch();
          }
       else{
          clrscr();
          pos();
          printf("\n");
          y=wherey();
          gotoxy(25,y);
          printf("Wrong username and password!");
          getch();
          }
          
       if(login==1&&ac==9999){
          printf("    1. User administration                 ");
          printf("    2. Shop administration\n");
          printf("\n");
          do{
          printf("Enter the option : ");
          scanf("%d",&z);
          setbuf(stdin,NULL);
          if(z!=1&&z!=2){
          printf("\nWrong input!Please try again.\n");
          getch();
          clrscr();
          pos();
          printf("    1. User administration                 ");
          printf("    2. Shop administration\n");
          printf("\n");
          }
          }while(z!=1&&z!=2);
          clrscr();
          if(z==1){
                   setbuf(stdin,NULL);
          system("admin.exe");}
          else if(z==2){
               setbuf(stdin,NULL);
          system("shop.exe");}
          }
       else if(login==1&&ac==99){
          printf("Please Press Any Button to Continue...");
          getch();
          setbuf(stdin,NULL);
          clrscr();
          system("sales.exe");
          }
       else if(login==1&&ac==9){
          printf("Please Press Any Button to Continue...");
          getch();
          setbuf(stdin,NULL);
          clrscr();
          system("member.exe");
          }
       }while(!(count==1&&countt==2));
}
int main(){
    login();
}
