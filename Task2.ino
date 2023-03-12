#include <Ticker.h>
const int task2SW = 7;
//int task2H;
//int task2L;
unsigned int freq2Val[5];
float task2Tot;
float task2Freq;
float total2Freq;
unsigned long time1;
unsigned long time2;

void setup(){
  Serial.begin(9600);
  pinMode(task2SW, INPUT);

}

void loop(){

  digitalWrite(12, LOW);
  //delay (0.0025);
  digitalWrite(12, HIGH);

   time1 = micros();
  task2();
  time2 = micros() - time1;

  Serial.println (time2);

}

void task2(){
 
  for (int i = 0; i <5; i++){   
  //task2H = digitalRead(task2SW);
  freq2Val[i] = pulseIn(task2SW,HIGH,1000);
  total2Freq += freq2Val[i];
  task2Tot = (total2Freq*2)/5;
  }

  
if (task2Freq >= 333 && task2Freq<=1000){
  Serial.print("frequancy is");
  Serial.print(task2Freq);
  Serial.print("Hz");
}
else {
  Serial.print("frequancy out-with limits");


}



  
  //task2H = pulseIn(task2SW,HIGH);
  //delay(0.00025);
  //task2L = pulseIn(task2SW,LOW);
  //task2Tot = task2H * 2;


  //task2Tot = task2H + task2L; 
  task2Freq = 1000000/task2Tot;


}