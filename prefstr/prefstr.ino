const int leftSpeed = 95;
const int rightSpeed = 95;
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
int lor=2;
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

  if (val1 == LOW && val2 == HIGH && val3 == HIGH && val4 == HIGH && val5 == HIGH)
  {
    curError = -4;
  }
  
  else if (val1 == LOW && val2 == LOW && val3 == HIGH && val4 == HIGH && val5 == HIGH)
  {
    curError = -3;
  }

  else if (val1 == HIGH && val2 == LOW && val3 == HIGH && val4 == HIGH && val5 == HIGH)
  {
    curError = -2;
  }

  else if (val1 == HIGH && val2 == LOW && val3 == LOW && val4 == HIGH && val5 == HIGH)
  {
    curError = -1;
  }

  else if ((val1 == HIGH && val2 == HIGH && val3 == LOW && val4 == HIGH && val5 == HIGH) || (val1 == HIGH && val2 == LOW && val3 == LOW && val4 == LOW && val5 == HIGH))
  {
    curError = 0;
    fast = 25;
  }

  else if (val1 == HIGH && val2 == HIGH && val3 == LOW && val4 == LOW && val5 == HIGH)
  {
    curError = 1;
  }

  else if (val1 == HIGH && val2 == HIGH && val3 == HIGH && val4 == LOW && val5 == HIGH)
  {
    curError = 2;
  }

  else if (val1 == HIGH && val2 == HIGH && val3 == HIGH && val4 == LOW && val5 == LOW)
  {
    curError = 3;
  }

  else if (val1 == HIGH && val2 == HIGH && val3 == HIGH && val4 == HIGH && val5 == LOW)
  {
    curError = 4;
  }

  else if ((val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW && val5 == HIGH) || (val1 == LOW && val2 == LOW && val3 == LOW && val4 == HIGH && val5 == HIGH) || (val1 == LOW && val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW))
  {
    fast = 75; // LEFT TURN
    while (fast == 75) // LEFT TURN
    { lor=0; 
      analogWrite(9, 150);
      analogWrite(6, 0);
      analogWrite(10, 150);
      analogWrite(11, 0);
      //delay(250);
      break;
    } 
  }

  else if ((val1 == HIGH && val2 == LOW && val3 == LOW && val4 == LOW && val5 == LOW) || (val1 == HIGH && val2 == HIGH && val3 == LOW && val4 == LOW && val5 == LOW))
  {
    fast = 50; // RIGHT TURN
    while (fast == 50) // RIGHT TURN
    { lor=1;
      analogWrite(9, 150);
      analogWrite(6, 0);
      analogWrite(10, 150);
      analogWrite(11, 0);
      //delay(180);
      break;
    }
  }
  else if (val1 == HIGH && val2 == HIGH && val3 == HIGH&& val4 == HIGH && val5 == HIGH)
  {
    if(lor==0)
    {
      analogWrite(9, 100);
      analogWrite(6, 0);
      analogWrite(10,0);
      analogWrite(11, 100);
    }
    else if(lor==1)
    {
      analogWrite(9, 0);
      analogWrite(6, 100);
      analogWrite(10, 100);
      analogWrite(11, 0);
    }
  }

  /*else if (val1 == HIGH && val2 == HIGH && val3 == HIGH && val4 == HIGH && val5 == HIGH)
  { // U - TURN
    fast = 100;
  }*/
  
  if (fast == 0)
  {
// calculatePID();
  
    P = curError;
    I = prevError + curError;
    D = prevError - curError;
    prevError = curError;

// runBOT();  
    PID = (Kp*P) + (Ki*I) + (Kd*D);

    m1Speed = leftSpeed - PID;
    m2Speed = rightSpeed + PID;

    analogWrite(9, m1Speed);
    analogWrite(6, 0);
    analogWrite(10, m2Speed);
    analogWrite(11, 0);
  }

  else if (fast == 25)
  {
    analogWrite(9, 110);
    analogWrite(6, 0);
    analogWrite(10, 110);
    analogWrite(11, 0);
  }
}
