#include <Servo.h>

Servo garra, base, derecha, izquierda;
int a= 90, b= 90, c= 90, d= 90;
int axis1_X, axis1_Y, axis2_X, axis2_Y;
int vel = 1;

void setup(){  
  Serial.begin(9600); 

  base.attach(7);
  garra.attach(6);
  derecha.attach(5);
  izquierda.attach(4);

  base.write(90);     delay(500);
  garra.write(90);    delay(500);
  derecha.write(90);  delay(500);
  izquierda.write(90);delay(500);
}
void loop(){

    axis1_X = analogRead(A0);
    axis1_Y = analogRead(A1);
    axis2_X = analogRead(A2);
    axis2_Y = analogRead(A3);
  
//*******************************control de servo Base
  if(axis1_X < 300 && a < 170){
    a+=vel;
    base.write(a);
  }
  if(axis1_X > 550 && a > 10){
    a-=vel;
    base.write(a);
  }

//*******************************control de servo Garra
  if(axis1_Y < 300 && b < 110){
    b+=vel;
    garra.write(b);.
  }
  if(axis1_Y > 550 && b > 80){
    b-=vel;
    garra.write(b);
  }

//*******************************control de servo Izquierda
  if(axis2_X < 300 && c < 170){
    c+=vel;
    izquierda.write(c);
  }
  if(axis2_X > 550 && c > 80){
    c-=vel;
    izquierda.write(c);
  }

//*******************************control de servo derecha
  if(axis2_Y < 300 && d < 150){
    d+=vel;
    derecha.write(d);
  }
  if(axis2_Y > 550 && d > 70){
    d-=vel;
    derecha.write(d);
  }
//*****************
  delay(10);

}