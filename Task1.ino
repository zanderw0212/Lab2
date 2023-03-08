//Task 1 Zander Westland

#define signalT1 4
unsigned long time1;
unsigned long time2;



void setup(){
  pinMode(signalT1,OUTPUT);
  Serial.begin(9600);
 // while(!Serial){}
}
void loop(){

  time1 = micros();
  task1();
  time2 = micros() - time1;

  Serial.println (time2);

}
void task1(){

    digitalWrite(signalT1, HIGH);
     delay(0.2);
    digitalWrite(signalT1, LOW);
     delay(0.05);
    digitalWrite(signalT1, HIGH);
     delay(0.03);
    digitalWrite(signalT1, LOW);

}