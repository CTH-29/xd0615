#include <MsTimer2.h>

int pinInterrupt = 2;
int tick = 0; 
int IN[4]={3,4,5,6};

void onChange()
{
  if ( digitalRead(pinInterrupt) == HIGH )
      tick = 0;
}

void onTimer()
{
  if( ++tick > 9 )
    tick = 0;
}

void BCD2SEG(char num)
{
  for(int i=0;i<4;i++)
    digitalWrite( IN[i], num & (0x01<<i)?HIGH:LOW );

}

void setup()
{
  pinMode( pinInterrupt, INPUT);
  attachInterrupt( digitalPinToInterrupt(pinInterrupt), onChange, CHANGE);
  MsTimer2::set(1000, onTimer);
  MsTimer2::start(); 
}
 
void loop()
{
  BCD2SEG(tick);
}
