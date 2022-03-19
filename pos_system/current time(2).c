#include <stdio.h>
#include <time.h>
#include <conio.h>
int main(){ 
  int x,y;
  int count=0,countt=0;
  char ch;
  x=wherex();
  y=wherey();
  while(1)
  {
          count++;
          if(count==1000){
            //gotoxy(x,y);
            count=0;
            countt=1;
          }
   if(kbhit()){
      
   }
   else{
       if(countt==1){
          time_t t;
          time(&t);
          gotoxy(56,1);
          printf("%s",ctime(&t));
          countt=0;
          gotoxy(x,y);
       }
   }
 }
 system("pause");
}
