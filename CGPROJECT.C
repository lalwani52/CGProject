#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
void fractal(int l, double a, int x, int y)
{
double angle=(30*3.14/180);
if(l!=0)
{
double a1=a+angle;
double a2=a-angle;
int x1=x+l*cos(a1);
int y1=y-l*sin(a1);
setcolor(YELLOW);
line(x,y,x1,y1);
fractal(l/2,a1,x1,y1);
x1=x+l*cos(a2);
y1=y-l*sin(a2);
line(x,y,x1,y1);
fractal(l/2,a2,x1,y1);
a1=a1+angle;
a2=a2-angle;
x1=x+l*cos(a1);
y1=y-l*sin(a1);
line(x,y,x1,y1);
fractal(l/2,a1,x1,y1);
x1=x+l*cos(a2);
y1=y-l*sin(a2);
setcolor(GREEN);
line(x,y,x1,y1);
fractal(l/2,a2,x1,y1);
}
}

void wind(float x[7],float y[7]);
void main()
{
float x[7],y[7],maxx,maxy,xw1,yw1,xw2,yw2;
float theta=30;
int gd=DETECT,gm;
initgraph(&gd,&gm,"d:\\turboc3\\bgi");
int j=1,k=0,rhx,rhy;
maxx=getmaxx();
maxy=getmaxy();
x[0]=maxx/2;
y[0]=maxy/2;
x[1]=y[4]=x[2]=-90;
y[6]=y[5]=y[1]=60;
y[2]=35;
y[3]=-100;
x[4]=20;
x[3]=0;
x[5]=90;
x[6]=65;
theta=theta*22/7/180;


while(kbhit()==0)
{

wind(x,y);
xw1=cos(theta)*x[1]+sin(theta)*y[1];
yw1=-sin(theta)*x[1]+cos(theta)*y[1];
xw2=cos(theta)*x[2]+sin(theta)*y[2];
yw2=-sin(theta)*x[2]+cos(theta)*y[2];
x[1]=xw1;
y[1]=yw1;
x[2]=xw2;
y[2]=yw2;
xw1=cos(theta)*x[3]+sin(theta)*y[3];
yw1=-sin(theta)*x[3]+cos(theta)*y[3];
xw2=cos(theta)*x[4]+sin(theta)*y[4];
yw2=-sin(theta)*x[4]+cos(theta)*y[4];
x[3]=xw1;
y[3]=yw1;
x[4]=xw2;
y[4]=yw2;
xw1=cos(theta)*x[5]+sin(theta)*y[5];
yw1=-sin(theta)*x[5]+cos(theta)*y[5];
xw2=cos(theta)*x[6]+sin(theta)*y[6];

yw2=-sin(theta)*x[6]+cos(theta)*y[6];
x[5]=xw1;
y[5]=yw1;
x[6]=xw2;
y[6]=yw2;
delay(50);
/***CAR BODY ******/
setcolor(CYAN);
line(50+j,470,90+j,470);
arc(110+j,470,0,180,20);
line(130+j,470,220+j,470);
arc(240+j,470,0,180,20);
line(260+j,470,300+j,470);
line(300+j,470,300+j,450);
line(300+j,450,240+j,430);
line(240+j,430,200+j,400);
line(200+j,400,110+j,400);
line(110+j,400,80+j,430);
line(80+j,430,50+j,440);
line(50+j,440,50+j,470);
//COLOR
setfillstyle(SOLID_FILL,CYAN);
floodfill(100+j,435,CYAN);


/***CAR Windows***/
setcolor(WHITE);
line(165+j,405,165+j,430);
line(165+j,430,230+j,430);
line(230+j,430,195+j,405);
line(195+j,405,165+j,405);
//COLOR
setfillstyle(SOLID_FILL,WHITE);
floodfill(200+j,410,WHITE);
setcolor(WHITE);
line(160+j,405,160+j,430);
line(160+j,430,95+j,430);
line(95+j,430,120+j,405);
line(120+j,405,160+j,405);
//COLOR
setfillstyle(SOLID_FILL,WHITE);
floodfill(140+j,410,WHITE);


/**Wheels**/
circle(110+j,470,17);
circle(240+j,470,17);
j++;
delay(10);
//snow

rhx=getmaxx();
rhy=getmaxy();
outtextxy(random(rhx),random(rhy-50),"|");
outtextxy(random(rhx),random(rhy-50),"|");
outtextxy(random(rhx),random(rhy-50),"|");
outtextxy(random(rhx),random(rhy-50),"|");
outtextxy(random(rhx),random(rhy-50),"|");
outtextxy(random(rhx),random(rhy-50),"|");
setcolor(WHITE);
delay(1);
k++;
//frac tree
 setcolor(GREEN);
fractal(50,90*3.14/180,550,435);
setcolor(BROWN);
 setcolor(GREEN);
fractal(50,90*3.14/180,50,435);


cleardevice();
//Moon
setcolor(WHITE);
circle(200,100,50);
setfillstyle(SOLID_FILL,WHITE);
floodfill(200,100,WHITE);
}
closegraph();
}
void wind(float x[7],float y[7])
{
cleardevice();
//MOON
setcolor(WHITE);
circle(200,100,50);
setfillstyle(SOLID_FILL,WHITE);
floodfill(200,100,WHITE);
setcolor(RED);
line(x[0],y[0],x[0]-50,y[0]+200);
line(x[0],y[0],x[0]+50,y[0]+200);
setcolor(WHITE);
line(x[0]-500,y[0]+200,x[0]+500,y[0]+200);
setcolor(RED);
line(x[0],y[0],x[0]+x[1],y[0]-y[1]);
line(x[0],y[0],x[0]+x[2],y[0]-y[2]);
line(x[0]+x[1],y[0]-y[1],x[0]+x[2],y[0]-y[2]);
line(x[0],y[0],x[0]+x[3],y[0]-y[3]);
line(x[0],y[0],x[0]+x[4],y[0]-y[4]);
line(x[0]+x[3],y[0]-y[3],x[0]+x[4],y[0]-y[4]);
line(x[0],y[0],x[0]+x[5],y[0]-y[5]);
line(x[0],y[0],x[0]+x[6],y[0]-y[6]);
line(x[0]+x[5],y[0]-y[5],x[0]+x[6],y[0]-y[6]);

}