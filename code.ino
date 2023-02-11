#include <Servo.h>

Servo myservo;  
Servo myservo1; 
int IR1=2;
int IR2=4;
int Nobusypark=0;

int pos = 0;   
void setup() {
  myservo.attach(3);
  myservo1.attach(5);  
  
  Serial.begin(115200);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
}

void loop() {
  int sensorStatus1 = digitalRead(IR1);
  int sensorStatus2 = digitalRead(IR2);
  if (sensorStatus1==1)
  {
    	Nobusypark=Nobusypark+1;
  	if(Nobusypark<=50)
  	{
    
      
    	for (pos = 180; pos >= 0; pos -= 1) 
        { 
    	myservo1.write(pos);             
    	delay(15);        
  		}
    }
    else if (Nobusypark>=50)
    {
      for (pos = 0; pos <= 180; pos += 1) 
      { 
   		 myservo.write(pos);             
    	 delay(15);                       
  	  }
      for (pos = 180; pos >= 0; pos -= 1)
      { 
    	myservo1.write(pos);             
   		delay(15);        
      }
    }
    else if(Nobusypark==0)
    {
         for (pos = 0; pos <= 180; pos += 1) 
      { 
   		 myservo1.write(pos);             
    	 delay(15);                       
  	  }    
  	}
    }
  else if(sensorStatus2==1)
  {
    	Nobusypark=Nobusypark-1;
    if(Nobusypark>0)
    {
    Nobusypark=Nobusypark-1;
    for (pos = 180; pos >= 0; pos -= 1) 
        { 
    	myservo.write(pos);             
    	delay(15);        
  		}
    }
  }   
}
