#include <ESP8266WiFi.h>

void setup()
{
  Serial.begin(115200);  
  smartConfig();//这里调用一键配网函数,替换上面的普通配网
}
void loop()
{
  // put your main code here, to run repeatedly:
}

//==========将下列代码添加到需要一键配网项目代码的最后==========
void smartConfig()
{
  WiFi.begin();
  for (int i = 0; i < 3; i++)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      Serial.println("AutoConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      //WiFi.printDiag(Serial); //打印关键的Wi-Fi诊断信息，信息比较多
      break;
    }
    else
    {
      Serial.println("AutoConfig Waiting...");
      //Serial.println(WiFi.status());
      delay(1000);
    }
  }
  if (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("AutoConfig Faild!" );
    WiFi.mode(WIFI_STA);
    Serial.println("\r\nWait for Smartconfig");
    WiFi.beginSmartConfig();
    while (1)
    {
      Serial.print(".");
      if (WiFi.smartConfigDone())
      {
        Serial.println("SmartConfig Success");
        Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
        Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
        WiFi.setAutoConnect(true);  // 设置自动连接
        break;
      }
      delay(3000);
    }
  }
}
