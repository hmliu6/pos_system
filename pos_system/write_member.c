#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define SIZE 5
struct data{
       char user[100];
       char pw[100];
       char type[2];
       }db[SIZE];
void text_write();
void text_write(){
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
main(){
       int i;
       for(i=0;i<SIZE;i++){
       scanf("%s %s %s",db[i].user,db[i].pw,db[i].type);
       }
       text_write();
       system("pause");
       }
