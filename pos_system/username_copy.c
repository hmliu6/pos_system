#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#define SIZE 100

struct attendance{
       char name[100];
       char time[100];
       }attendance[SIZE];
       
struct data{
       char user[100];
       char pw[100];
       char type[2];
       }db[SIZE];
       
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

int main(){
    copy_username();
}
