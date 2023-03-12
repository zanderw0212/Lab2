#include <Ticker.h>
const int task3SW = 4;
//int task3H;
//int task3L;
unsigned int freq3Val[5];
float task3Tot;
float task3Freq;
float total3Freq;
unsigned long time1;
unsigned long time2;


void setup(){
  Serial.begin(9600);
  pinMode(task3SW, INPUT);

}

void loop(){

  digitalWrite(12, LOW);
  digitalWrite(12, HIGH);
  
  time1 = micros();
  task3();
  time2 = micros() - time1;

  Serial.println (time2);

}

void task3(){

  for (int i = 0; i <5; i++){   
  //task2H = digitalRead(task2SW);
  freq3Val[i] = pulseIn(task3SW,HIGH,1000);
  total3Freq += freq3Val[i];
  task3Tot = (total3Freq*2)/5;
  }
 
  //task3H = pulseIn(task3SW,HIGH);
  
  //task3L = pulseIn(task3SW,LOW);

  //task3Tot = task3H + task3L; 
  task3Freq = 1000000/task3Tot;

if (task3Freq >= 500 && task3Freq<=1000){
  Serial.print("frequancy is");
  Serial.print(task3Freq);
  Serial.print("Hz");
}
else {
  Serial.print("frequancy out-with limits");


}
}