#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <WiFiUdp.h>
            
#include <ESP8266HTTPClient.h>
            
const char* ssid = "";
const char* pswd = "";
            
WiFiClient client;
int server_port = 6969;
            
void wifi_Setup() {
  Serial.println("wifiSetup");
  //WiFi.begin(ssid);
    WiFi.begin(ssid, pswd);
            
  while (WiFi.status() != WL_CONNECTED) 
  {
     Serial.println("trying ...");
     digitalWrite(pinLedY,HIGH);
     delay(200);
     digitalWrite(pinLedY,LOW);
     delay(200);
  }
   digitalWrite(pinLedY,HIGH);
   Serial.println("Connected to network");
}
                       
String GetData() {
   String ret = "ereor";
   HTTPClient http;
   String dataURL = "";
  dataURL+=String(timnig);
   http.begin(client, "http://10.100.102.15:6969/T/DAN"+ dataURL);
   int httpCode = http.GET();
   Serial.println(httpCode);
   if (httpCode == HTTP_CODE_OK) {
       Serial.print("HTTP response code ");
       Serial.println(httpCode);
       String Res = http.getString();
       Serial.println(Res);
       ret = Res;
     }
       http.end();
            
    return ret;
}
            
