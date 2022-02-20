 // Line tracer code: Use L9110S motor driver 
 //  Written by Se H. Yang
 
 byte AIB = 5 ; // Left motor
 byte AIA = 6 ; // Left motor

 byte BIA =  9  ; // Right motor
 byte BIB =  10 ; // Right motor

 byte SensorL = 3 ; // Left side sensor
 byte SensorR = 4 ; // Right side sensor
  
  void setup() {
  pinMode(SensorR, INPUT) ;
  pinMode(SensorL, INPUT) ;
  pinMode(AIA, OUTPUT);
  pinMode(AIB, OUTPUT);

  pinMode(BIA, OUTPUT);
  pinMode(BIB, OUTPUT);   
  }
  
 void loop() {   

  if ( !digitalRead(SensorL) == 1 &&  !digitalRead(SensorR) == 1 )
  { 
    Control(0, 200, 0, 200) ; // Forward(속도A, 속도B)
  }

  if ( digitalRead( SensorL) == 1 && !digitalRead(SensorR) == 1) 
  {
    Control( 250, 0, 0, 250) ; // Left turn (A Backward, B Forward)        
  }

  else if ( !digitalRead(SensorL) == 1 &&  digitalRead(SensorR) == 1 )
   {
    Control(0, 250, 250, 0) ; // Right turn (A Forward, B Backward)  
   }

  else if ( digitalRead(SensorL) == 1 &&  digitalRead(SensorR) == 1 )
   {
    Control(0, 0, 0, 0) ; // STOP (A Stop, B Stop)  
   }  
 } // end of Loop

 void Control( int A1HL, int A2HL, int B1HL, int B2HL )
 {  
  analogWrite(AIA, A1HL);
  analogWrite(AIB, A2HL);  

  analogWrite(BIA, B1HL);
  analogWrite(BIB, B2HL);
 }
