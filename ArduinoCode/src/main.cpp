#include <Arduino.h>

bool AppInput=0;                 //Signal from the wifi module
bool TchSnsrInput=0;             //Signal from the touch sensor
bool SwchStatus=0;                //Initial Status of switch
bool Value=0;

void setup() 
{
  pinMode(14,INPUT);
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
}

bool CheckTouchSnsr()
{
  if(digitalRead(14)==1)return 1;
  else return 0;
}

bool GetSwitchInp()
{
  return 0;
}

void ActSwitch(int Input)
{
  if(Input==1)
  {
    digitalWrite(12,1);
    digitalWrite(13,0);
    delay(500);
    digitalWrite(12,0);
    digitalWrite(13,0);
  }
  if(Input==-1)
  {
    digitalWrite(12,0);
    digitalWrite(13,1);
    delay(500);
    digitalWrite(12,0);
    digitalWrite(13,0);
  }
  if(Input==0)
  {
    digitalWrite(12,0);
    digitalWrite(13,0);
    delay(500);
    digitalWrite(12,0);
    digitalWrite(13,0);
  }
}

void loop()
{
  AppInput = GetSwitchInp();
  TchSnsrInput = CheckTouchSnsr();
  SwchStatus = AppInput + TchSnsrInput;

  int Signal = SwchStatus - Value;
  ActSwitch(Signal);
  Value = SwchStatus;
}