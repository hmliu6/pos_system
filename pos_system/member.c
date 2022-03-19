#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#define SIZE 100
struct item{
       char name[100];
       int amount;
       int price;
       char place[100];
       char expired_date[100];
       }item[SIZE];
       
struct data{
       char user[100];
       char pw[100];
       char type[2];
       }db[SIZE];
       
struct info{
       char name[100];
       char gender;
       int age;
       char address[200];
       char login_name[100];
       char password[100];
       int phone;
       char email[100];
       }info[SIZE];
       
int b=1;       

char login_user[100];

char timenow[100];

int count,option,m;

char Type[2]="M";

void current_time();

void function();

void read_info();

void read_data();

void store_data();

void read_user();

void read_data();

void HideCursor();

void UnhideCursor();

void print(int );

int keypress();

void show_goods();

void information();

void password_change();

void member_panel();

void searching();

void count_goods();

void read_info(){
     int i;
     FILE *fp;       /* Start of reading data */
     fp=fopen("info","rb");
       
       
     if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
        }
          
          
     for(i=0;i<SIZE;i++){
         fread(&info[i],sizeof(struct info),1,fp);
         }           /* End of reading data */
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

void read_item(){
       int i;
       FILE *fp;       /* Start of reading data */
       fp=fopen("data1","rb");
       
       
       if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
          
          
       for(i=0;i<SIZE;i++){
           fread(&item[i],sizeof(struct item),1,fp);
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

void count_m(){
    int i=0,j=0;
    m=0;
    for(i=0;i<100;i++){
        if(strcmp(db[i].type,Type)==0){  
        if(strcmp(login_user,info[m].login_name)==0)
           break;
        m++;
        }
     }
}

void count_goods(){
    int i=0;
    for(i=0;i<100;i++){
        if(item[i].name[0]<1){  
        count=i;
        i=100;
        }
     }
}

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

void password_change(){
     textcolor(7);
     char change[100],password[100],new_pw[100],again[100];
     int i;
     int count=0;
     UnhideCursor();
     setbuf(stdin,NULL);
     clrscr();
     for(i=0;i<100;i++){
         if(strcmp(login_user,db[i].user)==0)
            break;
         }
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
         else printf("New password are not the same!\n");
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

void show_goods(){
     textcolor(7);
     clrscr();
     read_item();
     count_goods();
     int j=0;
     setbuf(stdin,NULL);
     printf("\n         NAME            AMOUNT         PRICE       PLACE         EXPIRY DATE\n");
     printf("     -----------       ----------      -------    ---------     ---------------\n");
     while(j<count){
           printf("%d.   %-22s%-14d%-12d%-13s%s\n",j+1,item[j].name,item[j].amount,item[j].price,item[j].place,item[j].expired_date);
           j++;
     }
     printf("\n");
     printf("\nPlease Press Any Button to Continue...");
     while(!getch());
     clrscr();
     function();
}

void searching(){
     textcolor(7);
     int i=0,j,k=0;
     char input[100];
     UnhideCursor();
     setbuf(stdin,NULL);
     clrscr();
     printf("Enter name/price/place of goods : ");
     scanf("%s",input);
     while(i<count){
           j=atoi(input);
           if(i==0){
           printf("\n         NAME            AMOUNT         PRICE       PLACE         EXPIRY DATE\n");
           printf("     -----------       ----------      -------    ---------     ---------------\n");}
         if(strcmp(item[i].name,input)==0){
            printf("%d.   %-18s%-16d%-11d%-14s%s\n\n",i+1,item[i].name,item[i].amount,item[i].price,item[i].place,item[i].expired_date);
            k=1;}
         else if(item[i].price==j&&strcmp(item[i].name,input)==1){
            printf("%d.   %-18s%-16d%-11d%-14s%s\n\n",i+1,item[i].name,item[i].amount,item[i].price,item[i].place,item[i].expired_date);
            k=1;}
         else if((strcmp(item[i].place,input)==0&&strcmp(item[i].name,input)==1)&&item[i].price==j){
            printf("%d.   %-18s%-16d%-11d%-14s%s\n\n",i+1,item[i].name,item[i].amount,item[i].price,item[i].place,item[i].expired_date);
            k=1;}
         else if(i==count-1&&k==0){
            printf("\nSearching does not exist.\n\n");
            printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
            clrscr();
          function();
            }
         i++;
     }
     HideCursor();
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void information(){
     textcolor(7);
     int i,j;
     int k=0;
     int printlength=0,row=0;
     clrscr();
     setbuf(stdin,NULL);
     for(i=0;i<100;i++){
         if(strcmp(info[i].login_name,login_user)==0){
            j=i;
            i=100;}
         }
     printf("\n\n\n");
     printf("         Name              :\n\n");
     printf("         Gender(M/F)       :\n\n");
     printf("         Age               :\n\n");
     printf("         Address           :\n\n\n\n");
     printf("         Phone Number      :\n\n");
     printf("         E-mail Address    :\n\n");
     printf("         Login name        :\n\n");
     printf("         Password          :\n\n");
     gotoxy(30,4);
     printf("%s",info[j].name);
     gotoxy(30,6);
     printf("%c",info[j].gender);
     gotoxy(30,8);
     printf("%d",info[j].age);
     gotoxy(30,10);
     while(info[j].address!='\0'){
           if(row<4&&printlength<40){
              printf("%c",info[j].address[k]);
              printlength++;
              }
           else if(row<4&&printlength==40){
                row++;
                gotoxy(30,10+row);
                }
           else if(row==4)
                 break;
           }
     gotoxy(30,14);
     printf("%d",info[j].phone);
     gotoxy(30,16);
     printf("%s",info[j].email);
     gotoxy(30,18);
     printf("%s",info[j].login_name);
     gotoxy(30,20);
     printf("%s\n\n",info[j].password);
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
     }
     
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
     printf("    3. Personal Information          ");
     else if(i==4)
     printf("    4. Change Password               ");
     else if(i==5)
     printf("    5. Logout                        ");
     else if(i==6)
     printf("    6. Exit                          ");
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
              if(b!=7){
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


void member_panel(){
     b=1;
     int select;
     read_data();
     read_user();
     read_info();
     read_item();
     count_m();
     count_goods();
     HideCursor();
     gotoxy(22,7);
     textcolor(159);
     printf("               Setting               ");
     gotoxy(22,8);
     printf("-------------------------------------");
     gotoxy(22,9);
     textcolor(207);
     printf("    1. Show All Goods                ");
     textcolor(159);
     gotoxy(22,10);
     printf("    2. Search Goods                  ");
     gotoxy(22,11);
     printf("    3. Personal Information          ");
     gotoxy(22,12);
     printf("    4. Change Password               ");
     gotoxy(22,13);
     printf("    5. Logout                        ");
     gotoxy(22,14);
     printf("    6. Exit                          ");
     textcolor(7);
     }

void current_time(){
     time_t t;
     time(&t);
     strcpy(timenow,ctime(&t));
}

void function(){
     int x,y;
  int count=0,countt=0;
  char ch;
  x=wherex();
  y=wherey();
    member_panel();
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
          gotoxy(x,y);
       }
   }
 }
 if(b==1){
          clrscr();
          show_goods();}
     else if(b==2){
          clrscr();
          searching();}
     else if(b==3){
          clrscr();
          information();}
     else if(b==4){
          clrscr();
          password_change();}
     else if(b==5){
          clrscr();
          system("welcome.exe");}
     else if(b==6)
          exit(1);
}

int main(){
    function();
}
