# 前期准备工作:
Arduino IDE软件安装:
 - 官网下载地址(https://www.arduino.cc/en/Main/Software?setlang=cn)
 - 国内下载地址(https://www.arduino.cn/thread-5838-1-1.html)

Arduino IDE需安装好esp8266扩展:
 - 如果你在国外可以使用 IDE进行安装(https://www.arduino.cn/thread-75969-1-2.html)
 - 如果下载太慢或者无法下载，可以直接下载esp8266安装包，直接运行并解压即可。
下载地址1：https://pan.baidu.com/s/19yEQ4UDF-bQCzt3BsdV6Yw
下载地址2：https://share.weiyun.com/5CGEKJO
如果安装过其他版本的esp8266sdk，请先删除，再使用本安装包
解压完成后，再打开Arduino IDE，即可在 菜单栏>工具>开发板 中找到你使用的esp8266开发板

# 使用方法:

  - 打开需要升级为一键配网的项目
  - 在void setup()下添加smartConfig();
  - 复制void smartConfig()函数到项目代码的最后即可


Arduino ESP8266 一件配网函数

  - 无需引用其他库文件
  - 无需安装SmartConfig客户端
  - 包含配网二维码,微信扫码即可