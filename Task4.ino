#define task4LED 4
#define task4Pot 8
unsigned int analogVal[4];
int sumVoltage = 0;
float avarageVoltage = 0;

void setup()
{
 Serial.begin(9600); 
 pinMode (task4Pot, INPUT);
}

void loop(){

  for (int i = 0; i < 4; i++){
  
  analogVal[i] = analogRead(task4LED);
  

  }


  for ( int i = 0; i < 4; i++){

    sumVoltage += analogVal[i]; 

  }

  avarageVoltage = sumVoltage/4;
  Serial.print(avarageVoltage);
  Serial.print('V');

  if (avarageVoltage > 2047){
    Serial.print ('Voltage too high');
  }

}