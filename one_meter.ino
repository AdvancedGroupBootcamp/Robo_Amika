// pins
#define enA 5 
#define enB 6 

#define in1 7
#define in2 8 
#define in3 9 
#define in4 10

#define detect_S 0 

// global variables
int distance = 0;
bool go = true;
bool detected = false;

// functions
void forward() {  

  digitalWrite(in1, LOW); 
  digitalWrite(in2, HIGH); 
  digitalWrite(in3, HIGH); 
  digitalWrite(in4, LOW); 
  
  digitalWrite(enA, HIGH); 
  digitalWrite(enB, HIGH); 

}

void stops() {  //forword

  digitalWrite(in1, LOW); 
  digitalWrite(in2, LOW); 
  digitalWrite(in3, LOW); 
  digitalWrite(in4, LOW); 
  
  digitalWrite(enA, LOW); 
  digitalWrite(enB, LOW); 

}


void setup() {

  pinMode(detect_S, INPUT); 
 
  pinMode(enA, OUTPUT); 
  pinMode(enB, OUTPUT);
  
  pinMode(in1, OUTPUT); 
  pinMode(in2, OUTPUT); 
  pinMode(in3, OUTPUT); 
  pinMode(in4, OUTPUT); 

  delay(1000);

}


void loop(){  

  if(go) {
    forward();
  } else {
    stops();  
  }
  
  if((digitalRead(detect_S) == 1)) {
    
    detected = true;
    delay(10);
    
  } else if((digitalRead(detect_S) == 0)) {
    
    if(detected) {
      distance += 20;
      Serial.println(distance);
      detected = false;
    }
    delay(10);    
    
  } 

  if(distance > 100) {
    go = false;  
  }

}
