const int green = 7, red = 5, yellow = 6;

void blink(int pin, int time, int quantity = 5){
    for(int x = 0; x < quantity; x++){
        on(pin);
        delay(time);
        off(pin);
        delay(time);
    }
}

void on(int pin){
    digitalWrite(pin, 1);
}

void off(int pin){
    digitalWrite(pin, 0);
}

void start(){
    blink(green, 100, 3);
    blink(yellow, 100, 3);
    blink(red, 100, 3);
    for(int x = 0; x < 3; x++){
        on(green);
        delay(100);
        on(yellow);
        delay(100);
        on(red);
        delay(100);

        off(yellow);
        off(red);
        off(green);
        delay(100);
    }
}

void setup() {
    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(yellow, OUTPUT);

    start();
}

void loop() {
    on(green);
    off(yellow);
    off(red);
    delay(2000);
    
    blink(yellow, 300, 2);
    blink(yellow, 150, 4);
    off(green);
    delay(100);

    on(red);
    delay(5000);
    
}
