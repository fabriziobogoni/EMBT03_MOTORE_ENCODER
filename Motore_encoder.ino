#define LED_PIN D7
#define PULS_PIN D4
#define MOTOR_PIN D9
int puls;
int pulsState = 0;
int ledState = 0;
int motState = 0;
int motSpeed = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(PULS_PIN, INPUT);
}

void loop() {
  puls = digitalRead(PULS_PIN);
  
  if(puls == HIGH && pulsState == LOW){
    if(ledState == LOW){
      ledState = HIGH;
      motState = HIGH;
      for(motSpeed = 0; motSpeed <= 255; motSpeed++){
        analogWrite(MOTOR_PIN, motSpeed);
        delay(10);
      }
    } else {
      ledState = LOW;
      motState = LOW;
      for(motSpeed = 255; motSpeed >= 0; motSpeed--){
        analogWrite(MOTOR_PIN, motSpeed);
        delay(10);
      }

    }
    Serial.println(ledState);
    digitalWrite(LED_PIN, ledState);
    
  }
  pulsState = puls;
 

  
  delay(10);
  
  
}
