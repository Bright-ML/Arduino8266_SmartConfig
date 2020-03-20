#include <ESP8266WiFi.h>


void setup()
{
    smartConfig ();//执行一键配网
}

void loop() {
    // put your main code here, to run repeatedly:
}


void smartConfig() //一键配网函数
{
  WiFi.mode(WIFI_STA);
  Serial.println("\r\nWait for Smartconfig");
  WiFi.beginSmartConfig();//SmartConfig配网开始
  while (!WiFi.smartConfigDone())
  {
    delay(500);
    Serial.println(".");
  }
  Serial.println("SmartConfig Success");
  Serial.printf("SSID:%s\r\n",WiFi.SSID().c_str());
  Serial.printf("PSW:%s\r\n",WiFi.psk().c_str());
}
