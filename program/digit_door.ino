int const rs0=12;//リードスイッチ1
int const rs1=13;//リードスイッチ2
int const led=5;
int const button=14;

void setup() {
  // put your setup code here, to run once:
  pinMode(rs0,INPUT_PULLUP);
  pinMode(rs1,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  checkReadSwitch();
  delay(1000); 
}

//リードスイッチの値を確認
void checkReadSwitch(void){
  int rs_value0=digitalRead(rs0);
  int rs_value1=digitalRead(rs1);
  
  /*
  Serial.print(rs_value0);
  Serial.print(" ");
  Serial.println(rs_value1);
  */

  if(!(rs_value1 && rs_value0)){
    ///ネットワーク処理関数///
    digitalWrite(led,1);
  }else{
    digitalWrite(led,0);
  }
}


