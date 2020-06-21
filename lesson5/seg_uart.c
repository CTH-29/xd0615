#define LT 6   //测试
#define BT 7   //消隐
int IN[4]={2,3,4,5};	//BCD输入
int S[4]={11,10,9,8};   //片选信号
void setup()
{
  Serial.begin(9600);
  pinMode(LT,OUTPUT);
  pinMode(BT,OUTPUT);
  
  for(int i=0;i<4;i++)
  {
    pinMode(S[i], OUTPUT);
    pinMode(IN[i], OUTPUT);
    digitalWrite(IN[i],HIGH);

  }
  for(int i=0;i<4;i++)
    digitalWrite(S[i],LOW);
  for(int i=0;i<4;i++)
    digitalWrite(S[i],HIGH);
  digitalWrite(LT,LOW);
  delay(1000);
  digitalWrite(LT,HIGH);
  
  digitalWrite(BT,LOW);
  delay(1000);
  digitalWrite(BT,HIGH);
}

void BCD2SEG(char num)
{
  if(num<='9' && num>='0')
    for(int i=0;i<4;i++)
    	digitalWrite(IN[i],(num-'0')&(0x01<<i)?HIGH:LOW);
  else
  {
    Serial.println("warning 1:invaliad parameter in BCD2SEG");
    for(int i=0;i<4;i++)
    	digitalWrite(IN[i],HIGH);
  }
  return;
}

void seg(char *str)
{
  int len=strlen(str);
  if(len<=4)
  {
    int i;
    for(i=0;i<len;i++)
    {
      BCD2SEG(str[i]);
      digitalWrite(S[i],LOW);
      digitalWrite(S[i],HIGH);
    }
    for(;i<4;i++)
    {
      BCD2SEG(0);
      digitalWrite(S[i],LOW);
      digitalWrite(S[i],HIGH);
    }
  }
  else
  {
    Serial.println("warning 2:input string length is too long");
  }
}

void loop()
{
  char str[10];
  if(Serial.available())
  {
    delay(10);
    memset(str,0,10);
    Serial.readBytes(str,9);
    seg(str);
  }
}