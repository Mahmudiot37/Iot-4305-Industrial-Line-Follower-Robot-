#include <AFMotor.h>
#include <Servo.h>
Servo servo;

// AF_DCMotor LF(1);
// AF_DCMotor LB(2);
// AF_DCMotor RF(3);
// AF_DCMotor RB(4);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define R_S A3 // IR sensor Right
#define L_S A5 // IR sensor Left
#define trigPin  A0  
#define echoPin  A2 

void setup()
  {
    Serial.begin(9600);           // set up Serial library at 9600 bps
    Serial.println("Motor party!");


    

    servo.attach(10);
    pinMode(trigPin, OUTPUT);          // Declare "trigPin" as "Output Pin". 
    pinMode(echoPin, INPUT);           // Declare "echoPin" as "Input Pin". 
    // 
    
    // turn on motor #2
    motor1.setSpeed(115);
    motor1.run(RELEASE);
    motor2.setSpeed(115);
    motor2.run(RELEASE);
    motor3.setSpeed(115);
    motor3.run(RELEASE);
    motor4.setSpeed(115);
    motor4.run(RELEASE);
    pinMode(R_S, INPUT); // declare if sensor as input  
    pinMode(L_S, INPUT); // declare ir sensor as input
  }

void loop()
  {
     if (digitalRead(R_S) == LOW && digitalRead(L_S) == LOW) {
    RobotForward();
  } else if (digitalRead(R_S) == HIGH && digitalRead(L_S) == LOW) {
    RobotRight();
  } else if (digitalRead(R_S) == LOW && digitalRead(L_S) == HIGH) {
    RobotLeft();
  } else if (digitalRead(R_S) == HIGH && digitalRead(L_S) == HIGH) {
    RobotStop();
  }

    float distance = 0.00;
    float RightDistance = 0.00;
    float LeftDistance = 0.00;    
    distance = search();  
        
    if(distance <= 20) // If obstracle found in 40 CM.
      {
          RobotStop(); //Robot Stop
          delay(100);
          servo.write(90);
          delay(300);
          RightDistance = search();
          delay(100);
          servo.write(90);
          delay(300);
          LeftDistance = search();
          delay(100);
          servo.write(90);
          delay(300);
         if(LeftDistance > RightDistance)
           { 
              RobotBackward();
              delay(100);
              RobotStop();
              delay(100);
              RobotStop();
              delay(500);
              RobotStop();
              delay(100);  
           }
          else 
            {
              RobotBackward();
              delay(100);
              RobotStop();
              delay(100);
              RobotStop();
              delay(500); 
              RobotStop();
              delay(100);             
            }
      }
   else
   {
     RobotForward();
   }
}


float search(void)
  {
    float duration = 0.00;             // Float type variable declaration 
    float CM = 0.00;      
    digitalWrite(trigPin, LOW);        // Trig_pin output as OV (Logic Low-Level) 
    delayMicroseconds(2);              // Delay for 2 us    
    //Send 10us High Pulse to Ultra-Sonic Sonar Sensor "trigPin" 
    digitalWrite(trigPin, HIGH);       // Trig_pin output as 5V (Logic High-Level)
    delayMicroseconds(10);             // Delay for 10 us     
    digitalWrite(trigPin, LOW);        // Trig_pin output as OV (Logic Low-Level)    
    duration = pulseIn(echoPin, HIGH); // Start counting time, upto again "echoPin" back to Logical "High-Level" and puting the "time" into a variable called "duration" 
    CM = (duration / 58.82); //Convert distance into CM.     
    return CM;
  }

void RobotForward()
{
  // LF.run(FORWARD);
  // RF.run(FORWARD);
  // LB.run(FORWARD);
  // RB.run(FORWARD);

    motor1.setSpeed(115);
    motor1.run(FORWARD);
    motor2.setSpeed(115);
    motor2.run(FORWARD);
    motor3.setSpeed(115);
    motor3.run(FORWARD);
    motor4.setSpeed(115);
    motor4.run(FORWARD);
}
void RobotBackward()
{
  // LF.run(BACKWARD);
  // LB.run(BACKWARD);
  // RF.run(BACKWARD);
  // RB.run(BACKWARD);
    motor1.setSpeed(90);
    motor1.run(BACKWARD);
    motor2.setSpeed(90);
    motor2.run(BACKWARD);
    motor3.setSpeed(90);
    motor3.run(BACKWARD);
    motor4.setSpeed(90);
    motor4.run(BACKWARD);
    
}
void RobotLeft()
{
    motor1.setSpeed(115);
    motor1.run(FORWARD);
    motor2.setSpeed(115);
    motor2.run(FORWARD);
    motor3.setSpeed(35);
    motor3.run(BACKWARD);
    motor4.setSpeed(60);
    motor4.run(BACKWARD);

  // LF.run(BACKWARD);
  // LB.run(BACKWARD);
  // RF.run(FORWARD);
  // RB.run(FORWARD);
}
void RobotRight()
{
    motor1.setSpeed(40);
    motor1.run(BACKWARD);
    motor2.setSpeed(35);
    motor2.run(BACKWARD);
    motor3.setSpeed(115);
    motor3.run(FORWARD);
    motor4.setSpeed(115);
    motor4.run(FORWARD);

  // LF.run(FORWARD);
  // LB.run(FORWARD);
  // RF.run(BACKWARD);
  // RB.run(BACKWARD);
}
void RobotStop()
{
  // LF.run(RELEASE);
  // LB.run(RELEASE);
  // RF.run(RELEASE);
  // RB.run(RELEASE);

    motor1.setSpeed(115);
    motor1.run(RELEASE);
    motor2.setSpeed(115);
    motor2.run(RELEASE);
    motor3.setSpeed(115);
    motor3.run(RELEASE);
    motor4.setSpeed(115);
    motor4.run(RELEASE);
}

  