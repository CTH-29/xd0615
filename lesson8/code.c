/*
这是官方的展示多个音调驱动蜂鸣器的示例

其中的主要函数为
tone()
    作用是用某个IO产生频率可设置的，长度可设置的占空比为50%的方波，定义如下：
    tone(pin, frequency)
    tone(pin, frequency, duration)
    参数pin是用来产生方波的引脚，frequency是频率，duration是持续时间，不设置会持续产生
notone()
    作用是停止某个IO产生方波

由于在硬件的接法比较简单，断电时会有刺啦的声音
*/

int pos = 0;    //这个变量程序中未使用

void setup()
{
  pinMode(8, OUTPUT);       //设置6，7，8为输出
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  //在引脚上输出一定频率和持续时长的方波，然后关闭

  tone(6, 880, 200); // 880Hz是中音 LA
  delay(200); // 延时200ms
  noTone(6); // 关闭pin6的输出

  tone(7, 988, 500); //// 988Hz是中音 SI
  delay(500);
  noTone(7);

  tone(8, 1047, 300); // // 1047Hz是高音 DO
  delay(300);
  noTone(8);
}
