#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include "setting.h"

#define RS0 12  // リードスイッチ1
#define RS1 13  // リードスイッチ2
#define LED 5
#define BUTTON 14

void ledOn(){
  digitalWrite(LED, 1);
}
void ledOff(){
  digitalWrite(LED, 0);
}
void ledToggle(){
  if(digitalRead(LED)){
    ledOff();
  }else{
    ledOn();
  }
}

void post(){
  Serial.println("ring");
  HTTPClient http;
  http.begin("http://192.168.42.2/door");
  http.GET();
  http.end();
}

void setup() {
  // pin mode setting
  pinMode(RS0, INPUT_PULLUP);
  pinMode(RS1, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  // serial setup
  Serial.begin(115200);
  delay(100);
  Serial.println("this is door program");

  // wifi setting
  WiFi.mode(WIFI_STA);
  WiFi.begin(APSSID, APPASS);
  Serial.println("WiFi connecting");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
    ledToggle();
  }
  Serial.println("\nconnected");
}

int cnt=0;
void loop() {
  if(checkReadSwitch()){
    cnt++;
    if(cnt>=10){
      ledOn();
      post();
      while(checkReadSwitch()){
        delay(50);
      }
      cnt=0;
    }
  }else{
    ledOff();
    cnt=0;
  }
  delay(100); 
}

//リードスイッチの値を確認
bool checkReadSwitch(){
  int rs0Val=digitalRead(RS0);
  int rs1Val=digitalRead(RS1);

  if(!(rs0Val && rs1Val)){
    return false;
  }else{
    return true;
  }
}


