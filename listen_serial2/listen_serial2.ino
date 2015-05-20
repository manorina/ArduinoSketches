int inputPin = 2;
int outputPin = 13;
int count =0;
int outputOnTime = 4; //output "on" time in mS
bool inputLow = false;

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
  //echo_input();
  
  gated_echo_input(true);
  //delay(5);
  //gated_echo_input(false);
  delay(400);

}

void echo_input() {
    if ( (digitalRead(inputPin) == LOW)&& (inputLow == false) )
    {
      inputLow = true;
      if (count > 1)
      {
        digitalWrite(outputPin, HIGH);
        count = 0;
      }
      count ++;
    }
    else if ( (digitalRead(inputPin) == HIGH) && (inputLow == true) )
    {
      inputLow = false;
      
      
        digitalWrite(outputPin, LOW);
        //count = 0;
      
    }
  
}

void gated_echo_input(bool trg) {
  if (trg == true) {
    //wait for next available input pulse
    while (true)
    {
      if ( (digitalRead(inputPin) == LOW)&& (inputLow == false) )
      {
        inputLow = true;
        digitalWrite(outputPin, HIGH);
        delay(outputOnTime);
        digitalWrite(outputPin, LOW);
        break;
      }
    }
    //now wait for input to stop
    while (true)
    {
      if ( (digitalRead(inputPin) == HIGH) )
        {
          inputLow = false;
          digitalWrite(outputPin, LOW);
          break;
        }
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
      
