#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define SIZE 5
struct data{
       char name[100];
       int amount;
       int price;
       char place[100];
       char expired_date[100];
       }db[SIZE];
void text_write();
void text_write(){
     int i;
     char ch;
     FILE *fp;
     fp=fopen("data1","wb");
     if(fp==NULL){
          printf("Cannot open the file!\n");
          exit(1);
          }
     for(i=0;i<SIZE;i++){
         if(fwrite(&db[i],sizeof(struct data),1,fp)!=1)
         printf("File write error.\n");
         }
}
main(){
       int i;
       for(i=0;i<SIZE;i++){
       printf("%d\n",i+1);
       gets(db[i].name);
       setbuf(stdin,NULL);
       scanf("%d",&db[i].amount);
       setbuf(stdin,NULL);
       scanf("%d",&db[i].price);
       setbuf(stdin,NULL);
       gets(db[i].place);
       setbuf(stdin,NULL);
       gets(db[i].expired_date);
       setbuf(stdin,NULL);
       
       }
       text_write();
       system("pause");
       }
