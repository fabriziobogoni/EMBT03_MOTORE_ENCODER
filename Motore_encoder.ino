#define LED_PIN D7
#define PULS_PIN D4
int puls;
int pulsState = 0;
int ledState = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PULS_PIN, INPUT);
}

void loop() {
  puls = digitalRead(PULS_PIN);
  Serial.print(puls);
  Serial.print(" ,");
  
  if(puls == HIGH && pulsState == LOW){
    if(ledState == LOW){
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    Serial.println(ledState);
  }
  pulsState = puls;
 
  // put your main code here, to run repeatedly:
  
  digitalWrite(LED_PIN, ledState);
  

  delay(100);
  
  
}
