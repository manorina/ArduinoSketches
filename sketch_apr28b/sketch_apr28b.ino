int inputPin = 2;
int outputPin = 13;
bool is_low = false;
bool is_busy = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);

}
void do_output() {
  //TODO stuff
  is_busy = true;
  digitalWrite(outputPin, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(inputPin) == LOW)
  {
    is_low = true;
    if (!is_busy)
    {
      //do_output();
      is_busy = true;
      digitalWrite(outputPin, HIGH);
      //digitalWrite(outputPin, LOW);
    }
  }
  else
  {
    is_low = false;
    digitalWrite(outputPin, LOW);
    //digitalWrite(outputPin, HIGH);
    is_busy=false;
    //just waiting for next pulse
  }

}
