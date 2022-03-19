/*#include <stdio.h>
#include <time.h>

int main(void) {

    time_t rawtime;
    struct tm*  time_;

    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i \n", time_->tm_hour, time_->tm_min, 
            time_->tm_sec/* time_->tm_mday, time_->tm_mon+1,
            time_->tm_year+1900);

    getch();
}*/
#include <stdio.h>
#include <time.h>
#include <conio.h>

void updateTimer()
{
  int minute=0;
  int timeinfo = time(NULL);
      gotoxy(1,1);
  if(timeinfo%60==0&&minute==0){
  clrscr();
  minute=1;
  printf ( "Current local time and date: %d:%d:0%d",(timeinfo/86400)%24,(timeinfo/60)%60,timeinfo%60);}
  else if(timeinfo%60<10)
  printf ( "Current local time and date: %d:%d:0%d",(timeinfo/86400)%24,(timeinfo/60)%60,timeinfo%60);
  else if((timeinfo/60)%60<10)
  printf ( "Current local time and date: %d:0%d:%d",(timeinfo/86400)%24,(timeinfo/60)%60,timeinfo%60);
  else if((timeinfo/86400)%24<10)
  printf ( "Current local time and date: 0%d:%d:%d",(timeinfo/86400)%24,(timeinfo/60)%60,timeinfo%60);
  else printf ( "Current local time and date: %d:%d:%d",(timeinfo/86400)%24,(timeinfo/60)%60,timeinfo%60);
 }

int main ()
{ 
  int x=2,y=2;
  char ch;
  while(1)
  {
          gotoxy(x,y);
   if(kbhit()==1)
   {
          ch=getch();
          if(ch=='\n'){
          y++;}
          else x++;
          printf("%c",ch);
          }
   else
       updateTimer();
  }

  system("pause");
}
