int pos = 1;
unsigned long previousTime = 0;
unsigned long TimeForOne = 0;
int interval;
#define PinRelay D4
#define pinLedY D5
#define lightPin  A0
int pwmValue = 0;  
int lightSum = 0; 
int cnt=0;
int pwmPin = 9; 
char* timnig;


void setup() {
  
 Serial.begin(9600);
  wifi_Setup();
   pinMode(PinRelay, OUTPUT);
   pinMode(pinLedY, OUTPUT);
   pinMode(pwmPin, OUTPUT);
}

void loop() {
  unsigned long currentTime = millis();
  switch (pos) {
    case 1:
      Serial.print("Case 1");
      timnig="timereylay";
      interval=GetData().toInt()*1000;
        digitalWrite(PinRelay, HIGH);
      if (currentTime - previousTime >= interval) {
         digitalWrite(PinRelay, LOW);
        previousTime = currentTime;
        pos = 2;
      }
      break;
    case 2:
      Serial.print("Case 2");
       timnig="timeflash";
        interval=GetData().toInt()*1000;
      if(currentTime - TimeForOne >= 1000){
        cnt++;
        pwmValue += map(analogRead(lightPin), 0, 1023, 0, 255);
        TimeForOne = currentTime;
      }
      if (currentTime - previousTime >= interval) {
        Serial.print(lightSum/cnt);
        previousTime = currentTime;
        pos = 3;
      }
      break;
    case 3:
      Serial.print("Case 3");
       timnig="start";
        interval=GetData().toInt()*1000;
      digitalWrite(pwmPin, pwmValue);
      if (currentTime - previousTime >= interval) {
        digitalWrite(pwmPin, LOW);
        previousTime = currentTime;
        pos = 4;
      }
      break;
    case 4:
      Serial.print("Case 4");
      timnig="delay";
       interval=GetData().toInt()*1000;
      if (currentTime - previousTime >= interval) {
        previousTime = currentTime;
        pos = 1;
      }
      break;
    default:
       
      break;
  }
 
}
