/*

*/
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionswitchPin = 7;
const int onoffswitchstateswitchPin = 5;
const int potPin = A0;
int onoffswitchstate = 0;
int previousonoffswitchstate = 0;
int directionswitchstate = 0;
int previousdirectionswitchstate = 0;
int motorEnable = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
    Serial.begin(9600);
    pinMode(directionswitchPin, INPUT);
    pinMode(onoffswitchstateswitchPin, INPUT);
    pinMode(controlPin1, OUTPUT);
    pinMode(controlPin2, OUTPUT);
    pinMode(enablePin, OUTPUT);
    digitalWrite(enablePin, LOW);
}

void loop() {
    onoffswitchstate = digitalRead(onoffswitchstateswitchPin);
    delay(1);
    directionswitchstate = digitalRead(directionswitchPin);
    motorSpeed = analogRead(potPin)/4;

    if(onoffswitchstate != previousonoffswitchstate){
      if(onoffswitchstate == HIGH){
        motorEnable = !motorEnable;
      }
    }
    if(directionswitchstate != previousdirectionswitchstate){
      if(directionswitchstate == HIGH){
        motorDirection = !motorDirection;
      }
    }
    if(motorDirection == 1){
      digitalWrite(controlPin1, HIGH);
      digitalWrite(controlPin2, LOW);
    }
    else{
      digitalWrite(controlPin1, LOW);
      digitalWrite(controlPin2, HIGH);
    }
    if(motorEnable == 1){
      analogWrite(enablePin, motorSpeed);
    }
    else{
      analogWrite(enablePin, 0);
    }
    previousdirectionswitchstate = directionswitchstate;
    previousonoffswitchstate = onoffswitchstate;
    Serial.print("\nDirection SwitchPin: ");
    Serial.print(digitalRead(directionswitchPin));
}
