// Author : youtube channel-dotnetmob
// Date : 21-Jun-2015
// Description : program for animating rain

#include<stdio.h>
#include<graphics.h>

#define WIDTH getmaxx()
#define HEIGHT getmaxy()
#define COLOR_RED "\x1b[31m"
#define COLOR_RESET "\x1b[0m"

int isContinue=1,d=5,del=500;

void ChangeOption()
{
   switch(getch())
   {
	case 'a'://wind to left
	case 'A':
	d=-5;
	break;

	case 'd'://wind to right
	case 'D':
	d=5;
	break;

	case 's'://no wind
	case 'S':
	d=0;
	break;

	case 'w'://increase rain speed
	case 'W':
	if(del!=100)
	del-=200;
	break;

	case 'X'://decrease rain speed
	case 'x':
	if(del!=1100)
	del+=200;
	break;

	case ' '://stop raining
	isContinue=0;
	break;
   }
}

void main()
{
  int gd=DETECT,gm,xr,yr,i,j=0;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  do
  {
  textcolor(0);
  textbackground(15);

  printf(COLOR_RESET"CHANGE WIND DIRECTION:");
  printf(COLOR_RED" S(s): No wind  A(a) : right - left   D(d): left - right\n");
  printf(COLOR_RESET"CHANGE SPEED:  ");
  printf(COLOR_RED"W(w): Speed Up  X(x): Speed Down Space: Stop Rain");

  for(i=10;i<300;i++)
  {
   xr=rand()%640;
   yr=rand()%345;

   if(j%2==0)
   line(xr,yr,xr+d,yr+5);
   else
   line(xr+10,yr,xr+10+d,yr+5);
  }

   delay(del);
   clrscr();
   cleardevice();

   j++;
   if(kbhit())
   ChangeOption();
   }while(isContinue);
}


