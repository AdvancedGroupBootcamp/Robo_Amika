const int enA = 5;
const int enB = 6;
const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;

#define EXE_INTERVAL_STRAIGHT 1200
#define EXE_INTERVAL_TURN 3600

unsigned long currentMillis;
unsigned long lastExecutedMillis_1 = 0;
unsigned long lastExecutedMillis_2 = 0;


void setup() {

  // Set all the motor control pins to outputs
  
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

}

void turn() {

  analogWrite(enA, 200);
  analogWrite(enB, 200);

  if (currentMillis - lastExecutedMillis_1 >= EXE_INTERVAL_TURN) {
    
    lastExecutedMillis_1 = currentMillis; // save the last executed time
    
    Serial.println("straight");
  
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW); 
  }

}

void straight() {
  analogWrite(enA, 200);
  analogWrite(enB, 200);

  if (currentMillis - lastExecutedMillis_2 >= EXE_INTERVAL_STRAIGHT) {
    lastExecutedMillis_2 = currentMillis; // save the last executed time
    
    Serial.println("turn");
    
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);  
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW); 
}

}
void loop() {
  
  currentMillis = millis();
  
  straight();
  turn();
}
