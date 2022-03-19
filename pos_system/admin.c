#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<limits.h> 
#include<windows.h> 
#define SIZE 100
struct data{
       char user[100];
       char pw[100];
       char type[2];
       }db[SIZE];
       
struct attendance{
       char name[100];
       char time[100];
       }attendance[SIZE];
       
int option,b=1;

char login_user[100];
       
int member_count;  /* Member starts from 0 to null */

void read_data();

void read_attend();

void function();

void store_data();

void read_user();

void admin_panel();

void count_member();  /* Count the number of member */

void print(int );

int keypress();

void HideCursor();

void UnhideCursor();

void add_member();

void delete_member();

void show_member();

void find_member();

void change_password();

void show_record();

void read_user(){
     int i;
     FILE *fp;       /* Start of reading data */
     fp=fopen("name","rb");
       
       
     if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
        }
          
     fread(login_user,100,1,fp);
                   /* End of reading data */
     fclose(fp);
}

void read_data(){
     int i;
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
}

void read_attend(){
     int i;
     FILE *fp;       /* Start of reading data */
     fp=fopen("attendance","rb");
       
       
     if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
        }
          
          
     for(i=0;i<SIZE;i++){
         fread(&attendance[i],sizeof(struct attendance),1,fp);
         }           /* End of reading data */
     fclose(fp);
}

void store_data(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("data","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(i=0;i<SIZE;i++){
         if(fwrite(&db[i],sizeof(struct data),1,fp)!=1)
         printf("File write error.\n");
         }
     fclose(fp);
}

void copy_username(){
     int i;
     FILE *fp;       /* Start of reading data */
     fp=fopen("data","rb");
       
       
     if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
        }
          
          
     for(i=0;i<SIZE;i++){
         fread(&db[i],sizeof(struct data),1,fp);
         }           /* End of reading data */

     int k=0;
     while(k<=100){
           strcpy(attendance[k].name,db[k].user);
           k++;
     }

     int j;
     char ch;
     FILE *fa;
     fa=fopen("attendance","wb");
     if(fa==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(j=0;j<SIZE;j++){
         if(fwrite(&attendance[j],sizeof(struct attendance),1,fa)!=1)
         printf("File write error.\n");
         }
}

void HideCursor()
{
     setbuf(stdin,NULL);
    HANDLE h0ut;
    setbuf(stdin,NULL);
    CONSOLE_CURSOR_INFO ConCurInf;
    setbuf(stdin,NULL);
    h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
    setbuf(stdin,NULL);
    ConCurInf.dwSize = 20;
    ConCurInf.bVisible = FALSE;
    setbuf(stdin,NULL);
    SetConsoleCursorInfo(h0ut,&ConCurInf);
    setbuf(stdin,NULL);
}

void print(int i){
     if(i==1)
     printf("    1. Add member                    ");
     else if(i==2)
     printf("    2. Delete member                 ");
     else if(i==3)
     printf("    3. Show all member               ");
     else if(i==4)
     printf("    4. Find member                   ");
     else if(i==5)
     printf("    5. Change member password        ");
     else if(i==6)
     printf("    6. Show All Attendance Record    ");
     else if(i==7)
     printf("    7. Shop Administration           ");
     else if(i==8)
     printf("    8. Logout                        ");
     else if(i==9)
     printf("    9. Exit                          ");
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
                 gotoxy(22,9+b);
                 print(b+1);
                 textcolor(207);
                 gotoxy(22,8+b);
                 print(b);}}
           if(cha==80){
              if(b!=9){
                 b++;
                 textcolor(159);
                 gotoxy(22,7+b);
                 print(b-1);
                 textcolor(207);
                 gotoxy(22,8+b);
                 print(b);}}
        }
    }
    else return 0;
}

void UnhideCursor()
{
     setbuf(stdin,NULL);
    HANDLE h0ut;
    setbuf(stdin,NULL);
    CONSOLE_CURSOR_INFO ConCurInf;
    setbuf(stdin,NULL);
    h0ut = GetStdHandle(STD_OUTPUT_HANDLE);
    setbuf(stdin,NULL);
    ConCurInf.dwSize = 20;
    ConCurInf.bVisible = TRUE;
    setbuf(stdin,NULL);
    SetConsoleCursorInfo(h0ut,&ConCurInf); 
    setbuf(stdin,NULL);

}

void admin_panel(){
     textcolor(7);
     b=1;
     int select;
     read_user();
     read_data();
     read_attend();
     count_member();
     HideCursor();
     gotoxy(22,7);
     textcolor(159);
     printf("         User Administration         ");
     gotoxy(22,8);
     printf("-------------------------------------");
     gotoxy(22,9);
     textcolor(207);
     printf("    1. Add member                    ");
     textcolor(159);
     gotoxy(22,10);
     printf("    2. Delete member                 ");
     gotoxy(22,11);
     printf("    3. Show all member               ");
     gotoxy(22,12);
     printf("    4. Find member                   ");
     gotoxy(22,13);
     printf("    5. Change member password        ");
     gotoxy(22,14);
     printf("    6. Show All Attendance Record    ");
     gotoxy(22,15);
     printf("    7. Shop Administration           ");
     gotoxy(22,16);
     printf("    8. Logout                        ");
     gotoxy(22,17);
     printf("    9. Exit                          ");
     textcolor(7);
}

void count_member(){
    int i=0,j=0;
    for(i=0;i<100;i++){
        if(db[i].user[0]<1){  
        member_count=i;
        i=100;
        }
     }
}
     
void add_member(){
     textcolor(7);
     int num,i;
     int x,y;
     int m,n;
     char a[100],b[100],c[2];
     UnhideCursor();
     do{
     printf("\nEnter the number of member addition : ");
     scanf("%d",&num);
     setbuf(stdin,NULL);
     printf("\n");
     if((num>(100-member_count))||(num<1))
     printf("\nPlease enter the number between 1 to %d\n",(99-member_count));
     }while((num>(100-member_count))||(num<1));
     for(i=member_count;i<(member_count+num);i++){
         printf("Enter username : ");
         gets(db[i].user);
         setbuf(stdin,NULL);
         printf("\n");
         printf("Enter password : ");
         gets(db[i].pw);
         setbuf(stdin,NULL);
         m=wherex();
         n=wherey();
         do{
         gotoxy(m,n);
         printf("\nEnter the type of user : ");
         x=wherex();
         y=wherey();
         printf("                          ");
         printf("\nA:Manager S:Salesperson M:Member");
         gotoxy(x,y);
         setbuf(stdin,NULL);
         scanf("%c",&c);
         }while(!(c[0]!=65||c[0]!=83||c[0]!=77));
         strcpy(db[i].type,c);
         }
     member_count+=num;
     store_data();
     copy_username();
     HideCursor();
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void delete_member(){
     textcolor(7);
     char del[100];
     int i,j;
     int count=0;
     UnhideCursor();
     printf("\nEnter the username that want to delete : ");
     gets(del);
     setbuf(stdin,NULL);
     for(i=0;i<member_count;i++){
         if(strcmp(db[i].user,del)==0&&count==0){
            count=1;
            }
         if(count==1){
            strcpy(db[i].user,db[i+1].user);
            strcpy(db[i].pw,db[i+1].pw);
            }
         }
     for(j=0;j<member_count;j++){
         if(strcmp(db[i].user,del)==0)
            count=2;
         }
     if(count==2)
        printf("\nDelete Unsuccessful!\n");
     else printf("\nDelete Successful!\n");
     member_count--;
     store_data();
     copy_username();
     HideCursor();
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void show_member(){
     textcolor(7);
     clrscr();
     int j=0;
     char store[100];
     char admin[2]="A",sales[2]="S";
     char manag[100]="Manager",salep[100]="Salesperson",member[100]="Member";
     printf("\n                  USER                PASSWORD           TYPE\n");
     printf("                --------            ------------       --------\n");
     while(j<member_count){
           if(strcmp(db[j].type,admin)==0)
              strcpy(store,manag);
           else if(strcmp(db[j].type,sales)==0)
              strcpy(store,salep);
           else strcpy(store,member);
           printf("%d.              %-20s%-19s%s\n",j+1,db[j].user,db[j].pw,store);
           j++;
     }
     printf("\n");
     printf("\nPlease Press Any Button to Continue...");
     getch();
     clrscr();
     function();
     
}

void find_member(){
     textcolor(7);
     char find[100];
     int i;
     char store[100];
     char admin[2]="A",sales[2]="S";
     char manag[100]="Manager",salep[100]="Salesperson",member[100]="Member";
     UnhideCursor();
     printf("Enter the username : ");
     gets(find);
     setbuf(stdin,NULL);
     printf("\n");
     for(i=0;i<member_count;i++){
         if(strcmp(db[i].user,find)==0)
            break;
         }
     if(strcmp(db[i].type,admin)==0)
        strcpy(store,manag);
        else if(strcmp(db[i].type,sales)==0)
           strcpy(store,salep);
     printf("                 USER           PASSWORD            TYPE \n");
     printf("                ------         ----------       ------------\n");
     printf("                %-15s%-17s%s\n",db[i].user,db[i].pw,store);
     printf("\n");
     HideCursor();
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
     
}

void change_password(){
     textcolor(7);
     char change[100],password[100],new_pw[100],again[100];
     int i;
     int count=0;
     UnhideCursor();
     do{
     printf("\nEnter the username : ");
     gets(change);
     setbuf(stdin,NULL);
     for(i=0;i<member_count;i++){     /* find member */
         if(strcmp(db[i].user,change)==0)
            break;
         }
     if(i==0)
     printf("\nUser does not exist! Please try again!\n");
     }while(i==0);
     do{                 /* check password */
     printf("\nEnter old password : ");
     gets(password);
     printf("\n");
     if(strcmp(db[i].pw,password)==0){
       do{               /* re-enter password */
         printf("Enter new password : ");
         gets(new_pw);
         setbuf(stdin,NULL);
         printf("\n");
         printf("Confirm new password : ");
         gets(again);
         setbuf(stdin,NULL);
         if(strcmp(new_pw,again)==0){
            printf("\nChanging password is successful!\n");
            strcpy(db[i].pw,new_pw);
            }
         else printf("Wrong password!\n");
         }while(strcmp(new_pw,again)!=0);
         break;
       }
     else printf("\nWrong password\n");
     }while(strcmp(db[i].pw,password)!=0);
     store_data();
     HideCursor();
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void show_record(){
     textcolor(7);
     clrscr();
     int j=0,i=0;
     char store[100];
     char sales[2]="S";
     printf("\n                  USER                          TIME         \n");
     printf("                --------             --------------------------\n");
     while(j<member_count){
           if(strcmp(db[j].type,sales)==0){
           printf("%d.               %-20s%-20s\n",i+1,attendance[j].name,attendance[j].time);
           i++;}
           j++;
     }
     printf("\n");
     printf("\nPlease Press Any Button to Continue...");
     getch();
     clrscr();
     function();
     
}

void function(){
  int x,y;
  int count=0,countt=0;
  char ch;
  x=wherex();
  y=wherey();
    admin_panel();
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
          textcolor(112);
          printf("User : %s                                                ",login_user);
          gotoxy(57,1);
          printf("%s",ctime(&t));
          countt=0;
          textcolor(7);
          gotoxy(x,y);
       }
   }
}
   if (b==1){
         clrscr();
         add_member();}
     if (b==2){
         clrscr();
         delete_member();}
     if (b==3){
         clrscr();
         show_member();}
     if (b==4){
         clrscr();
         find_member();}
     if (b==5){
         clrscr();
         change_password();}
     if (b==6){
         clrscr();
         show_record();}
     if (b==7){
         clrscr();
         system("shop.exe");}
     if (b==8){
         clrscr();
         system("welcome.exe");}
     if (b==9)
         exit(1);
 }

main(){
       function();
       }
