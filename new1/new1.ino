const int leftSpeed = 90;
const int rightSpeed = 90;
const int Kp = 16;
const int Ki = 0;
const int Kd = 2;
int m1Speed = 0;
int m2Speed = 0;
int P = 0;
int I = 0;
int D = 0;
int PID = 0;
int prevError = 0;
int curError = 0;
int extleftSense = 8;
int leftSense = 5;
int centreSense = 4;
int rightSense = 3;
int extrightSense = 7;
int val1 = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
void setup() 
{
  pinMode(extleftSense, INPUT);
  pinMode(leftSense, INPUT);
  pinMode(centreSense, INPUT);
  pinMode(rightSense, INPUT);
  pinMode(extrightSense, INPUT);
  pinMode(6, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop() 
{
  int fast = 0;
// readData();
  val1 = digitalRead(extleftSense);
  val2 = digitalRead(leftSense);
  val3 = digitalRead(centreSense);
  val4 = digitalRead(rightSense);
  val5 = digitalRead(extrightSense);  
  if (fast == 0)
  {
// calculatePID();
  
    P = curError;
    I = prevError + curError;
    D = prevError - curError;
    prevError = curError;

// runBOT();  
    PID = (Kp*P) + (Ki*I) + (Kd*D);

    m1Speed = leftSpeed + PID;
    m2Speed = rightSpeed - PID;

    analogWrite(9, m1Speed);
    analogWrite(6, 0);
    analogWrite(10, m2Speed);
    analogWrite(11, 0);
  }
}
