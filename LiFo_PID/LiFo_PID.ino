const int speedLeft = 200;
const int speedRight = 200;
const int Kp = 1;
const int Ki = 1;
const int Kd = 1;
int m1Speed = 0;
int m2Speed = 0;
int P = 0;
int I = 0;
int D = 0;
int prevError = 0;
int curError = 0;
int extleftSense = 7;
int leftSense = 3;
int centreSense = 4;
int rightSense = 5;
int extrightSense = 8;
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
}

void readData()
{
  val1 = digitalRead(extleftSense);
  val2 = digitalRead(leftSense);
  val3 = digitalRead(centreSense);
  val4 = digitalRead(rightSense);
  val5 = digitalRead(extrightSense);

  if (val1 = 0 && val2 = 1 && val3 = 1 && val4 = 1 && val5 = 1)
  {
    curError = -4;
  }
  
  else if (val1 = 0 && val2 = 0 && val3 = 1 && val4 = 1 && val5 = 1)
  {
    curError = -3;
  }

  else if (val1 = 1 && val2 = 0 && val3 = 1 && val4 = 1 && val5 = 1)
  {
    curError = -2;
  }

  else if (val1 = 1 && val2 = 0 && val3 = 0 && val4 = 1 && val5 = 1)
  {
    curError = -1;
  }

  else if (val1 = 1 && val2 = 1 && val3 = 0 && val4 = 1 && val5 = 1)
  {
    curError = 0;
  }

  else if (val1 = 1 && val2 = 1 && val3 = 0 && val4 = 0 && val5 = 1)
  {
    curError = 1;
  }

  else if (val1 = 1 && val2 = 1 && val3 = 1 && val4 = 0 && val5 = 1)
  {
    curError = 2;
  }

  else if (val1 == 1 && val2 == 1 && val3 == 1 && val4 == 0 && val5 == 0)
  {
    curError = 3;
  }

  else if (val1 == 1 && val2 == 1 && val3 == 1 && val4 == 1 && val5 == 0)
  {
    curError = 4;
  }
  
}

void calculatePID()
{
  readData();

  P = curError;
  I = prevError + curError;
  D = prevError + curError;
  prevError = curError;  
}

void runBOT()
{
  calculatePID();

  PID = (Kp*P) + (Ki*I) + (Kd*D);

  m1Speed = leftSpeed + PID;
  m2Speed = rightSpeed + PID;

  analogWrite(6, m1Speed);
  analogWrite(9, 0);
  analogWrite(10, m2Speed);
  analogWrite(11, 0);
}
