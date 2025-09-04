const int led[]={3,5,6};
const int buzzer = 9, buzzer2 = 10;

void off(int led1, int led2){
  analogWrite(led1, 0);
  analogWrite(led2, 0);
}

void tonebuzzer(){
  for(int i = 400; i<5500; i+=100){
      if(i<1000){
        off(led[0], led[1]);
        analogWrite(led[2], (i-400)/2.4);
      }else if(i<2000){
        off(led[0], led[2]);
        analogWrite(led[1], (i-400)/6.3);
      }else{
        off(led[2], led[1]);
        analogWrite(led[0], (i-400)/11.4);
      }
      tone(buzzer, i);
      delay(30);
      noTone(buzzer);
      tone(buzzer2, 5900-i);
      delay(30);
      noTone(buzzer2);
  }
}

void untonebuzzer(){
  for(int i = 400; i<5500; i+=100){
      if(i<1000){
        off(led[0], led[1]);
        analogWrite(led[2], 255);
      }else if(i<2000){
        off(led[0], led[2]);
        analogWrite(led[1], 255);
      }else{
        off(led[2], led[1]);
        analogWrite(led[0], 255);
      }
      tone(buzzer2, i);
      delay(30);
      noTone(buzzer2);
      tone(buzzer, 5900-i);
      delay(30);
      noTone(buzzer);
  }
}

void setup() {
  for(int x = 0; x<3; x++){
    pinMode(led[x], OUTPUT);
  }

  pinMode(buzzer, OUTPUT);
  pinMode(buzzer2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  tonebuzzer();
}
