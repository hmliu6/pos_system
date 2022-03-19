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
       
struct attendance{
       char name[100];
       char time[100];
       }attendance[SIZE];
       
int b=1;

char login_user[100];

char timenow[100];

int count,option;

void current_time();

void read_item();

void read_attend();

void read_user();

void add();

void HideCursor();

void UnhideCursor();

void print(int );

int keypress();

void show_goods();

void store_item();

void store_attend();

void sales_panel();

void searching();

void calc();

void attend();

void count_goods();

void function();

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

void store_item(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("data1","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(i=0;i<SIZE;i++){
         if(fwrite(&item[i],sizeof(struct item),1,fp)!=1)
         printf("File write error.\n");
         }
     fclose(fp);
}

void store_attend(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("attendance","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(i=0;i<SIZE;i++){
         if(fwrite(&attendance[i],sizeof(struct attendance),1,fp)!=1)
         printf("File write error.\n");
         }
     fclose(fp);
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

void add(){
     count_goods();
     int select;
     int j=1,m,n;
     gotoxy(22,7);
     textcolor(159);
     printf("              Add goods              ");
     gotoxy(22,8);
     printf("-------------------------------------");
     gotoxy(22,9);
     printf("    1. Add existing amount           ");
     gotoxy(22,10);
     printf("    2. Add new product               ");
     textcolor(7);
     printf("\n\n\n Enter the option : ");
     setbuf(stdin,NULL);
     scanf("%d",&select);
     if(select==1){
        clrscr();
        while(j<count){
           printf("%d.   %s\n",j,item[j-1].name);
           j++;}
        printf("\n Enter The code number of goods : ");
        setbuf(stdin,NULL);
        scanf("%d",&m);
        printf("\n Enter the amount of goods : ");
        setbuf(stdin,NULL);
        scanf("%d",&n);
        for(j=0;j<count;j++){
            if(m-1==j){
              break;}}
        item[j].amount+=n;}
        if(select==2){
           count++;
           printf("Enter the name of goods : ");
           setbuf(stdin,NULL);
           gets(item[count].name);
           printf("\n\nEnter the amount of goods (1-1000) : ");
           setbuf(stdin,NULL);
           scanf("%d",&item[count].amount);
           printf("\n\n Enter the price of goods (1-1000) : ");
           setbuf(stdin,NULL);
           scanf("%d",item[count].price);
           printf("\n\nEnter the store place of goods (eg:A1,A2) : ");
           setbuf(stdin,NULL);
           gets(item[count].place);
           printf("\n\nEnter the expired date of goods (DD/MM/YYYY) : ");
           setbuf(stdin,NULL);
           gets(item[count].expired_date);
           }
        printf("Addition success!");
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
     printf("    2. Add Goods                     ");
     else if(i==3)
     printf("    3. Search Goods                  ");
     else if(i==4)
     printf("    4. Settlement of Accounts        ");
     else if(i==5)
     printf("    5. Take Attendance               ");
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

void sales_panel(){
     b=1;
     int select;
     read_attend();
     read_item();
     read_user();
     count_goods();
     HideCursor();
     gotoxy(22,7);
     textcolor(159);
     printf("             Salesperson             ");
     gotoxy(22,8);
     printf("-------------------------------------");
     gotoxy(22,9);
     textcolor(207);
     printf("    1. Show All Goods                ");
     textcolor(159);
     gotoxy(22,10);
     printf("    2. Add Goods                     ");
     gotoxy(22,11);
     printf("    3. Search Goods                  ");
     gotoxy(22,12);
     printf("    4. Settlement of Accounts        ");
     gotoxy(22,13);
     printf("    5. Take Attendance               ");
     gotoxy(22,14);
     printf("    6. Logout                        ");
     gotoxy(22,15);
     printf("    7. Exit                          ");
     textcolor(7);
     }
     
void show_goods(){
     clrscr();
     int j=0;
     read_item();
     count_goods();
     printf("\n         NAME            AMOUNT         PRICE       PLACE         EXPIRY DATE\n");
     printf("     -----------       ----------      -------    ---------     ---------------\n");
     while(j<count){
           printf("%d.   %-22s%-14d%-12d%-13s%s\n",j+1,item[j].name,item[j].amount,item[j].price,item[j].place,item[j].expired_date);
           j++;
     }
     printf("\n");
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void searching(){
     int i=0,j,k=0;
     char input[100];
     UnhideCursor();
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

void calc(){
     int number;
     int amou;
     int total=0;
     int i;
     int row=0;
     int num=0;
     int paid=0;
     int x,y;
     textcolor(240);
     printf("                                                                               \n");
     printf("                              Jay's Market Place                               \n");
     printf("               Shop 1-39, JJBox, Harvest Road, Kowloon, Hong Kong              \n");
     printf("                             Tel:+852 - 2666 9868                              \n");
     printf("¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v¢v \n");
     printf("              Name                       Amount                    Price       \n");
     printf("       -------------------           --------------            -------------   \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("_______________________________________________________________________________\n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     printf("                                                                               \n");
     textcolor(7);
     int j=1;
     read_item();
     count_goods();
     while(j<=count){
           printf("%d.   %s\n",j,item[j-1].name);
           j++;}
     textcolor(240);
     do{
     num++;
     gotoxy(1,8+row);
     printf("%d.",num);
     do{
     gotoxy(8,8+row);
     setbuf(stdin,NULL);
     scanf("%d",&number);
     if(number>count&&number!=9999){
     gotoxy(8,8+row);
     printf("            ");}
     }while(number>count&&number!=9999);
     if(number==9999){
        gotoxy(1,8+row);
        printf("               ");
        gotoxy(1,21);
        printf("  Total       :       $%d\n",total);
        printf("  Paid        :       $");
        x=wherex();
        y=wherey();
        setbuf(stdin,NULL);
        do{
        gotoxy(x,y);
        UnhideCursor();
        scanf("%d",&paid);
        if(paid<total){
        gotoxy(x,y);
        printf("             ");
        printf("\n Not Enough Money ! Please Press Any Button to continue!");
        getch();}
        }while(paid<total);
        HideCursor();
        printf("  Return      :       $%d                                 ",paid-total);
        getch();
        store_item();
        textcolor(7);
        clrscr();
        function();
        }
     for(i=1;i<=count;i++){
         if(i==number){
         gotoxy(8,8+row);
         printf("%s      ",item[i-1].name);
         number-=1;
         break;
         }}
     do{
     gotoxy(38,8+row);
     setbuf(stdin,NULL);
     scanf("%d",&amou);
     if(item[i-1].amount<amou){
     gotoxy(38,8+row);
     printf("             ");}
     else item[i-1].amount-=amou;
     }while(item[i-1].amount<amou);
     if(amou==1){
        gotoxy(64,8+row);
        printf("$%d",item[number].price);
        row++;}
     else{gotoxy(64,8+row);
          printf("%-1d x $%-1d",amou,item[number].price);
          row++;
          gotoxy(64,8+row);
          printf("$%d",amou*item[number].price);
          row++;
          total+=amou*item[number].price;}
     gotoxy(64,8+row);
     }while(number!=9999);
}
void attend(){
     int i=0;
     read_attend();
     do{
           if(strcmp(attendance[i].name,login_user)==0)
              break;
           else i++;
     }while(i<=100);
     current_time();
     strcpy(attendance[i].time,timenow);
     if(strcmp(attendance[i].time,timenow)==0){
        gotoxy(23,7);
        textcolor(79);
        printf("       Attendance Success!       ");
        textcolor(7);
        gotoxy(23,8);
        gotoxy(23,9);
        printf(" User   : %s ",attendance[i].name);
        gotoxy(23,11);
        printf(" Time   : %s ",attendance[i].time);
        store_attend();
        printf("\n\n\n\nPlease press any button to continue...");
        getch();
        clrscr();
        function();
     }
     else{
     printf("Attendance error, Please try again or contact supporter.");
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
     }
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
    sales_panel();
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
          textcolor(7);
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
          add();}
     else if(b==3){
          clrscr();
          searching();}
     else if(b==4){
          clrscr();
          calc();}
     else if(b==5){
          clrscr();
          attend();}
     else if(b==6){
          clrscr();
          system("welcome.exe");}
     else if(b==7)
          exit(1);
}
 
int main(){
    function();
    system("pause");
}
