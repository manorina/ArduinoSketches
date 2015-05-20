int inputPin = 2;
int outputPin = 13;
int count = 0;
bool is_low = false;
bool is_busy = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  //digitalWrite(outputPin, HIGH);

}
void do_output() {
  //TODO stuff
  //not used
  is_busy = true;
  digitalWrite(outputPin, HIGH);
  delay(4);
  digitalWrite(outputPin, LOW);
}

void loop() {
  // this loop can introduce up to 22 microseconds lag
  // put your main code here, to run repeatedly:
  digitalWrite(outputPin, HIGH);
  delay(4);
  digitalWrite(outputPin, LOW);
  delay(300);
  //if (count < 10) {
  /*if (digitalRead(inputPin) == LOW)
  {
    is_low = true;
    
    if ((!is_busy))
    {
      //do_output();
      is_busy = true;
      digitalWrite(outputPin, HIGH);
      count++;
      //digitalWrite(outputPin, LOW);
    }
  }
  else
  {
    
    is_low = false;
    digitalWrite(outputPin, LOW);
    //delay(10);
    //digitalWrite(outputPin, HIGH);
    is_busy=false;
    //just waiting for next pulse
  }
  */
  //} else {
  //  delay(100);
  //  count = 0;
 // }
  //count ++;
}
