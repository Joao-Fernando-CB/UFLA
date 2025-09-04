const int led1 = 5, led2 = 6, led3 = 9;

void write(int pin, int val){
    analogWrite(pin, val);
}

void up(int led, int val){
    if(val<255){
      for(int x = val; x < 255; x++){
          write(led, x);
          delay(5);
      }
    }else{
      for(int x = val; x >= 0; x--){
          write(led, x);
          delay(5);
      }
    }
}

void intensity(){
    up(led1, 0);
    up(led2, 0);    
    up(led3, 0);
    up(led3, 255);
    up(led2, 255);
    up(led1, 255);
}

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);    
    pinMode(led3, OUTPUT);
}

void loop() {
    
    intensity();
    
}
