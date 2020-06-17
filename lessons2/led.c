void setup()
{

  for(int i=0;i<8;i++)
    pinMode(i+6, OUTPUT);
}

void set_8_leds(char state)
{
  for(int i=0;i<8;i++)
    if(( state >>i ) & 0x01 == 0x01 )
  	{
    	digitalWrite(i+6, HIGH);
  	}
    else
    	digitalWrite(i+6, LOW);
}

void loop()
{
  char cnt,sta=0x01;
  for(cnt=0;cnt<8;cnt++)
  {
  	set_8_leds(sta);
    sta<<=1;
  	delay(100);
  }
  sta=0x80;
  for(cnt=0;cnt<8;cnt++)
  {
  	set_8_leds(sta);
    sta = sta>>1 &0x7F;
  	delay(100);
  }
}