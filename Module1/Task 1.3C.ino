const int motionSensor = 2;              
const int buzzer = 8;
const int IRSensor = 3;
int led = 13;

uint8_t motionState = LOW;
uint8_t IRState = LOW;


void setup() {  
  
  pinMode(buzzer, OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(IRSensor, INPUT_PULLUP);
  pinMode(motionSensor, INPUT);    // initialize sensor as an input
  
  Serial.begin(9600);        // initialize serial
  
  attachInterrupt(digitalPinToInterrupt(motionSensor), motion, CHANGE);
  attachInterrupt(digitalPinToInterrupt(IRSensor), IR, CHANGE);

}

void loop(){
  
  delay(500);
  
}

void motion(){
  motionState = !motionState;
  Serial.println("Motion detected!");
  digitalWrite(led, motionState);
  Serial.println("Interrupt! LED");

}

void IR(){
  IRState = !IRState;
  Serial.println("IR Detected!");
  digitalWrite(buzzer, IRState);
  Serial.println("Interrupt! BUZZER");
  
}
