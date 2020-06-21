void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  Serial.begin(9600);
}
void motor(bool a,bool b,bool c,bool d)
{
  digitalWrite(2,a);
  digitalWrite(3,b);
  digitalWrite(4,c);
  digitalWrite(5,d);
  Serial.print(a,BIN);
  Serial.print(b,BIN);
  Serial.print(c,BIN);
  Serial.println(d,BIN);
}
void loop()
{
  if(Serial.available()>0)
  {
    switch(Serial.read()){
      case 'f':motor(1,0,1,0);break;
      case 'b':motor(0,1,0,1);break;
      case 'l':motor(1,0,0,1);break;
      case 'r':motor(0,1,1,0);break;
      default:break;
    }
  }
}
