// Arduino Line Follower Robot Code

#define enA 5 //Enable1 L293 Pin enA 

#define in1 7 //Motor1  L293 Pin in1 

#define in2 8 //Motor1  L293 Pin in1 

#define in3 9 //Motor2  L293 Pin in1 

#define in4 10 //Motor2  L293 Pin in1 

#define enB 6 //Enable2 L293 Pin enB 

#define detect_S 0 //ir sensor Right

//int count = 0;
int distance = 0;
bool go = true;



void forward(){  //forword

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, HIGH);  //Right Motor backword Pin 

digitalWrite(in3, HIGH);  //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 

digitalWrite(enA, HIGH); 

digitalWrite(enB, HIGH); 

}

void stops(){  //forword

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, LOW);  //Right Motor backword Pin 

digitalWrite(in3, LOW);  //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 

digitalWrite(enA, LOW); 

digitalWrite(enB, LOW); 

}


void setup(){

pinMode(detect_S, INPUT); 

pinMode(enA, OUTPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(enB, OUTPUT);

//digitalWrite(enA, HIGH); 

//digitalWrite(enB, HIGH); 

delay(1000);

}

void loop(){  

  if(go) {
    forward();
  }
  else {
    stops();  
  }
  
  
  
  bool detected = false;
  
  if((digitalRead(detect_S) == 1)){
    detected = true;
    delay(10);
  } 
  
  if((digitalRead(detect_S) == 0)){
    if(detected) {
      //count += 1;
      distance += 20;
      Serial.println(distance);
      detected = false;
    }
    delay(10);    
  } 

  if(distance >= 101) {
    go = false;  
  }




}
