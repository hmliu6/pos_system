#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define SIZE 100
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
       
int member_count,m,result=9999;

char Type[2]="M";

void read_info();

void read_data();

void store_info();

void store_data();

void count_member(); 

void count_m();

void form();

void registry();

void insert();

void a();

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
}

void read_info(){
     int i;
     FILE *fp;       /* Start of reading data */
     fp=fopen("info","rb");
       
       
     if(fp==NULL){
        printf("Cannot open the file!\n");
        exit(1);
        }
          
          
     for(i=0;i<SIZE;i++){
         fread(&db[i],sizeof(struct info),1,fp);
         }           /* End of reading data */
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
}

void store_info(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("info","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(i=0;i<SIZE;i++){
         if(fwrite(&info[i],sizeof(struct info),1,fp)!=1)
         printf("File write error.\n");
         }
}

void form(){
     clrscr();
     printf("\n\nPlease fill in the form below carefully to registry a member.\n");
     textcolor(12);
     printf("All infomations cannot be changed after registration!\n\n");
     textcolor(7);
     printf("         Name              :\n\n");
     printf("         Gender(M/F)       :\n\n");
     printf("         Age               :\n\n");
     printf("         Address           :\n\n\n\n");
     printf("         Phone Number      :\n\n");
     printf("         E-mail Address    :\n\n");
     printf("         Login name        :\n\n");
     printf("         Password          :\n\n");
     printf("         Confirm Password  :\n\n");
     }
     
void registry(){
     int i=0,j=0,k,xycount=0;
     char confirm[100];
     gotoxy(30,6);
     setbuf(stdin,NULL);
     gets(info[m].name);
     gotoxy(30,8);
     setbuf(stdin,NULL);
     scanf("%c",&info[m].gender);
     gotoxy(30,10);
     setbuf(stdin,NULL);
     scanf("%d",&info[m].age);
     gotoxy(30,12);
     setbuf(stdin,NULL);
     info[m].address[i]=getch();
     while(info[m].address[i]!=13){
           printf("%c",info[m].address[i]);
           i+=1;
           setbuf(stdin,NULL);
           info[m].address[i]=getch();
           setbuf(stdin,NULL);
           if((i-j)==40){
              if(xycount>=3)
                 break;
              xycount+=1;
              gotoxy(30,(xycount+10));
              j=i;
              }
           }
    info[m].address[i]='\0';
    gotoxy(30,16);
    setbuf(stdin,NULL);
    scanf("%d",&info[m].phone);
    gotoxy(30,18);
    setbuf(stdin,NULL);
    scanf("%s",info[m].email);
    gotoxy(30,20);
    setbuf(stdin,NULL);
    scanf("%s",info[m].login_name);
    gotoxy(30,22);
    setbuf(stdin,NULL);
    scanf("%s",info[m].password);
    gotoxy(30,24);
    setbuf(stdin,NULL);
    scanf("%s",confirm);
    setbuf(stdin,NULL);
    if(strcmp(confirm,info[m].password)==1){
       result=1;}
    else{
         for(k=0;k<member_count;k++){
             if(strcmp(db[k].user,info[k].login_name)==0){
               if(result==9999)
                result=2;
                break;}
             }
         insert();
         if(result==9999)
         result=0;
         }
}

void insert(){
     setbuf(stdin,NULL);
     strcpy(db[member_count+1].user,info[m].login_name);
     setbuf(stdin,NULL);
     strcpy(db[member_count+1].pw,info[m].password);
     setbuf(stdin,NULL);
     strcpy(db[member_count+1].type,"M");
     setbuf(stdin,NULL);
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

void count_m(){
    int i=0,j=0;
    m=1;
    for(i=0;i<100;i++){
        if(strcmp(db[i].type,Type)==0){  
        m++;
        i=100;
        }
     }
}

main(){
    int ch,i;
    read_data();
    count_member();
    if(member_count<100){
       count_m();
          form();
          registry();
          if(result==0){
             store_data();
             store_info();
             printf("\nRegistration complete, Press any key back to previous page.");
             ch=getch();
             clrscr();
             system("welcome.exe");
             }
          else if(result==1){
             printf("\nPassword input error, Please check your password carefully!\n\n");
             ch=getch();
             clrscr();
             main();}
          else if(result==2){
             printf("\nLogin name has been used, Please try another login name!");
             ch=getch();
             clrscr();
             main();}
          else{
               printf("\nRegistration incomplete, Press any key back to previous page.");
               ch=getch();
               clrscr();
               system("welcome.exe");
               }
          
    }
    else printf("\nRegistration is now unavailable! Please contact shop assistant.\n");
}
