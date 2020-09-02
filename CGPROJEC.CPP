
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void drawBoundries() {
line(0, 375, 700, 375);
}

void drawCar(int i) {

//line left of left wheel
line(0 + i, 360, 35 + i, 360);
//vertical line from initial point of this line
line(0 + i, 360, 0 + i, 320);

//line betn two wheels
line(65 + i, 360, 135 + i, 360);

//line right of right wheel
line(165 + i, 360, 210 + i, 360);
//vertical line from this point
line(210 + i, 360, 210 + i, 320);

//horizontal line connecting both end points of car
line(0 + i, 320, 210 + i, 320);

//bonnet of the car
line(20 + i, 320, 55 + i, 290);
line(55 + i, 290, 150 + i, 290);
line(150 + i, 290, 180 + i, 320);

//left wheel of car
circle(50 + i, 360, 15);
circle(50 + i, 360, 2);

//right wheel of car
circle(150 + i, 360, 15);
circle(150 + i, 360, 2);

}

void drawTrafficLight() {
//base of traffic light
rectangle(315,180, 325, 240);
//upper traffic light part
rectangle(290, 40, 350, 180);

//circle for red dot
circle(320, 70, 15);
outtextxy(318, 68,"R");

//circle for yellow dot
circle(320, 110, 15);
outtextxy(317, 108, "Y");

//circle for green dot
circle(320, 150, 15);
outtextxy(318, 148, "G");


}

void moveCar() {

for(int i = 0; i <= 100; i += 5) {
drawBoundries();
drawCar(i);

if(i >= 60) {

//base of traffic light
rectangle(315,180, 325, 240);
//upper traffic light part
rectangle(290, 40, 350, 180);

//circle for red dot
circle(320, 70, 15);
setfillstyle(SOLID_FILL, YELLOW);
floodfill(320, 70, WHITE);
outtextxy(318, 68,"Y");

//circle for yellow dot
circle(320, 110, 15);
outtextxy(317, 108, "R");

//circle for green dot
circle(320, 150, 15);
outtextxy(318, 148, "G");
} else {
drawTrafficLight();
}
delay(100);
cleardevice();
}

drawBoundries();
drawCar(100);

//base of traffic light
rectangle(315,180, 325, 240);
//upper traffic light part
rectangle(290, 40, 350, 180);

//circle for red dot
circle(320, 70, 15);
outtextxy(318, 68, "Y");

//circle for yellow dot
circle(320, 110, 15);
setfillstyle(SOLID_FILL, RED);
floodfill(317, 108, WHITE);
outtextxy(317, 108, "R");

//circle for green dot
circle(320, 150, 15);
outtextxy(318, 148, "G");

delay(5000);

for( i = 100; i <= 600; i += 5) {
drawBoundries();

//base of traffic light
rectangle(315,180, 325, 240);
//upper traffic light part
rectangle(290, 40, 350, 180);

//circle for red dot
circle(320, 70, 15);
outtextxy(318, 68,"Y");

//circle for yellow dot
circle(320, 110, 15);
outtextxy(317, 108, "R");

//circle for green dot
circle(320, 150, 15);
setfillstyle(SOLID_FILL, GREEN);
floodfill(320, 150, WHITE);
outtextxy(318, 148, "G");

drawCar(i);
delay(100);
cleardevice();
}
}


void main() {

int gd = DETECT, gm;
initgraph(&gd, &gm, "c:\\turboc3\\bgi");
moveCar();
getch();
closegraph();

}