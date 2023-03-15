#include <Ticker.h>
#include <Arduino.h>
#include <B31DGMonitor.h>
#define FRAME_DURATION_MS 2
#define task4LED 4
#define signalT1 3
#define task4Pot 8
unsigned long time1;
unsigned long time2;
//task 2 perameters
const int task2SW = 7;
int freq2Val;
float task2Tot;
float task2Freq;
float total2Freq;
//task 3 perameters
const int task3SW = 2;
int freq3Val;
float task3Tot;
float task3Freq;
float total3Freq;
//task4 perameters
unsigned int analogVal[4];
int sumVoltage = 0;
int voltage;
float avarageVoltage = 0;
unsigned long frameTime = 0;
unsigned long frameCounter = 0;

B31DGCyclicExecutiveMonitor monitor;
Ticker FrameTick; 

void setup(){

  Serial.begin(9600);
  
  FrameTick.attach_ms(4, Frame);  
  monitor.startMonitoring();
  task1();                        
  delayMicroseconds(2000);       
  monitor.startMonitoring();      
  pinMode(signalT1,OUTPUT);
  pinMode(task2SW, INPUT);  
  pinMode(task3SW, INPUT);
  pinMode (task4Pot, INPUT);
  pinMode (task4LED, OUTPUT);
  
}


void Frame()
{
  unsigned int slot = frameCounter % 10;

switch  (slot){
     case 0: task1();                task3();     task4();   task5();  break;
     case 1: task1();    task2();                                      break;
     case 2: task1();                task3();                          break;
     case 3: task1();                                                  break;
     case 4: task1();                task3();                          break;
     case 5: task1();                             task4();   task5();  break;
     case 6: task1();                task3();                          break;
     case 7: task1();    task2();                                      break;
     case 8: task1();                task3();                          break;
     case 9: task1();                                                  break;
  }
  frameCounter = frameCounter + 1  ; 
}
void loop(void){}


  void task1(){

monitor.jobStarted(1);
    digitalWrite(signalT1, HIGH);
     delayMicroseconds(200);
    digitalWrite(signalT1, LOW);
     delayMicroseconds(50);
    digitalWrite(signalT1, HIGH);
     delayMicroseconds(30);
    digitalWrite(signalT1, LOW);
monitor.jobEnded(1);    

}

void task2(){
 
monitor.jobStarted(2);

  
  freq2Val = pulseIn(task2SW,HIGH,1000);
  task2Tot = (freq2Val*2);
  task2Freq = 1000000/task2Tot;

  

//if (task2Freq >= 333 && task2Freq<=1000){
 // Serial.print("frequancy is");
 // Serial.print(task2Freq);
 // Serial.print("Hz");

//}
//else {
 // Serial.print("frequancy out-with limits");

//}
  monitor.jobEnded(2);
}



void task3(){
monitor.jobStarted(3);
 
  
  freq3Val = pulseIn(task3SW,HIGH,1000);
  task3Tot = (freq3Val*2);
  task3Freq = 1000000/task3Tot;

//if (task3Freq >= 500 && task3Freq<=1000){
 // Serial.print("frequancy is");
 // Serial.print(task3Freq);
//  Serial.print("Hz");
//}
//else {
  //Serial.print("frequancy out-with limits");


//}
monitor.jobEnded(3);
}


void task4(){

monitor.jobStarted(4);
  for (int i = 0; i < 4; i++){
  
  analogVal[i] = analogRead(task4Pot);
  
  }

  for ( int i = 0; i < 4; i++){

    sumVoltage += analogVal[i]; 
  }

  avarageVoltage = sumVoltage/4;

  voltage = avarageVoltage*(3.3/4095.0);

  if (voltage >= 1.65){
    
   digitalWrite (task4LED, HIGH);
    
  }

  else {
    
  digitalWrite (task4LED, LOW);    

  }

  
  //Serial.print(voltage);
 // Serial.print('V');

 // if (avarageVoltage > 2047){
   // Serial.print ('Voltage too high');
 // }
monitor.jobEnded(4);
}



void task5(){
if(frameCounter % 25 == 0){  
  monitor.jobStarted(5);

  int Frequancy2task5 = map(task2Freq, 333, 1000, 0, 99);
  int Frequancy3task5 = map(task3Freq, 500, 1000, 0, 99);

  Frequancy2task5 = constrain(Frequancy2task5, 0, 99);
  Frequancy3task5 = constrain(Frequancy3task5, 0, 99);

//Serial.print(Frequancy2task5);
//Serial.print(Frequancy3task5);

monitor.jobEnded(5);
  }
}





