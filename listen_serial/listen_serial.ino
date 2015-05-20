int inputPin = 2;
int outputPin = 13;
int count =0;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  
  //start Serial interface
  Serial.begin(57600);
  Serial.println("Enter 1 or 0");

}

void loop() {
  // put your main code here, to run repeatedly:
  //wait_trigger();
  echo_input();

}

void echo_input() {
    if (digitalRead(inputPin) == LOW)
    {
      digitalWrite(outputPin, HIGH);
    }
    else
    {
      digitalWrite(outputPin, LOW);
      
    }
  
}

void gated_echo_input(bool trg) {
  if (trg == true) {
    if (digitalRead(inputPin) == LOW)
    {
      while (digitalRead(inputPin) == LOW)
      {
        digitalWrite(outputPin, HIGH);
      }
      digitalWrite(outputPin, LOW);
    }
    else
    {
      while (digitalRead(inputPin) == HIGH)
      {
        //do nothin
      }
      digitalWrite(outputPin, HIGH);
      delay(4);
      digitalWrite(outputPin, LOW);
    }
  }
  else
  {
    digitalWrite(outputPin, LOW);
  }
}



void wait_trigger() {
  if (Serial.available() > 0) 
  {
    char ch = Serial.read();
    if (ch == '1')
    {
      //digitalWrite(outputPin, HIGH);
      gated_echo_input(true);
    }
    else if (ch == '0')
    {
      //digitalWrite(outputPin, LOW);
      gated_echo_input(false);
    }
  }
}
      
