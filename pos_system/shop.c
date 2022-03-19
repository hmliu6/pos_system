#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include<limits.h>
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
       
int count,option,selectt=1;

char timenow[100];

char login_user[100];
       
void current_time();

void function();

void read_user();

void add();

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

void shop_panel();

void searching();

void add_goods();

void count_goods();

void stoch_alarm();

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
       int j;
       FILE *fp;       /* Start of reading data */
       fp=fopen("data1","rb");
       
       
       if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
          
          
       for(j=0;j<SIZE;j++){
           fread(&item[j],sizeof(struct item),1,fp);
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

void count_goods(){
    int i=0;
    for(i=0;i<SIZE;i++){
        if(item[i].name[0]<1){  
        count=i;
        i=100;
        }
     }
}

void add(){
     textcolor(7);
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

void show_goods(){
     textcolor(7);
     clrscr();
     int j=0;
     read_item();
     count_goods();
     char store[100];
     setbuf(stdin,NULL);
     printf("\n        NAME            AMOUNT         PRICE       PLACE         EXPIRY DATE\n");
     printf("     -----------      ----------      -------    ---------     ---------------\n");
     while(j<count){
           printf("%d.   %-20s%-16d%-12d%-13s%s\n",j+1,item[j].name,item[j].amount,item[j].price,item[j].place,item[j].expired_date);
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
     textcolor(7);
     int i=0,j,k=0;
     char input[100];
     setbuf(stdin,NULL);
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
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
          function();
}

void stock_alarm(){
     textcolor(7);
     clrscr();
     int j,a;
     read_item();
     setbuf(stdin,NULL);
     printf("\n        NAME            AMOUNT         PRICE       PLACE         EXPIRY DATE\n");
     printf("     -----------      ----------      -------    ---------     ---------------\n");
     for(j=0;j<count;j++){
         if(item[j].amount<=10){
           a++;
           printf("%d.   %-20s%-16d%-12d%-13s%s\n",a,item[j].name,item[j].amount,item[j].price,item[j].place,item[j].expired_date);}
     }
     printf("\n");
     printf("\nPlease Press Any Button to Continue...");
     getch();
     setbuf(stdin,NULL);
     clrscr();
     function();
}

void sale_rate(){
     clrscr();
     system("shop.exe");}

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
     printf("    4. Low Stock Alarm               ");
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
           cha=_getch ();   /* up=224,72 down=224,80 left=224,75 right=224,77 */
           if(cha==72){
              if(selectt!=1){
                 selectt--;
                 textcolor(159);
                 gotoxy(22,9+selectt);
                 print(selectt+1);
                 textcolor(207);
                 gotoxy(22,8+selectt);
                 print(selectt);}}
           if(cha==80){
              if(selectt!=7){
                 selectt++;
                 textcolor(159);
                 gotoxy(22,7+selectt);
                 print(selectt-1);
                 textcolor(207);
                 gotoxy(22,8+selectt);
                 print(selectt);}}
        }
    }
    else return 0;
}

void shop_panel(){
     selectt=1;
     int select;
     read_user();
     read_data();
     read_info();
     read_item();
     count_goods();
     HideCursor();
     gotoxy(22,7);
     textcolor(159);
     printf("         Shop Administration         ");
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
     printf("    4. Low Stock Alarm               ");
     gotoxy(22,13);
     printf("    5. User Administration           ");
     gotoxy(22,14);
     printf("    6. Logout                        ");
     gotoxy(22,15);
     printf("    7. Exit                          ");
     textcolor(7);
}

void current_time(){
     time_t t;
     time(&t);
     strcpy(timenow,ctime(&t));
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

void function(){
    int x,y;
  int count=0,countt=0;
  char ch;
  x=wherex();
  y=wherey();
    shop_panel();
    while(1)
  {
          count++;
          if(count==1000){
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
    if(selectt==1){
          clrscr();
          show_goods();}
     else if(selectt==2){
          clrscr();
          add();}
     else if(selectt==3){
          clrscr();
          searching();}
     else if(selectt==4){
          clrscr();
          stock_alarm();}
     else if(selectt==5){
          clrscr();
          system("admin.exe");}
     else if(selectt==6){
          clrscr();
          system("welcome.exe");}
     else if(selectt==7)
          exit(1);
}

int main(){
    function();
}
