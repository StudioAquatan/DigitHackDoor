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

void setup() {
  // pin mode setting
  pinMode(RS0, INPUT_PULLUP);
  pinMode(RS1, INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);

  // serial setup
  Serial.begin(115200);
}

void loop() {
  if(checkReadSwitch()){
    ledOn();
  }else{
    ledOff();
  }
  delay(1000); 
}

//リードスイッチの値を確認
bool checkReadSwitch(){
  int rs0Val=digitalRead(RS0);
  int rs1Val=digitalRead(RS1);

  if(!(rs0Val && rs1Val)){
    return true;
  }else{
    return false;
  }
}


