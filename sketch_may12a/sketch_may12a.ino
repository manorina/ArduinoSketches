int inputPin = 2;
int outputPin = 13;

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
  wait_trigger();

}

void wait_trigger() {
  if (Serial.available() > 0) 
  {
    char ch = Serial.read();
    if (ch == '1')
    {
      digitalWrite(outputPin, HIGH);
    }
    else if (ch == '0')
    {
      digitalWrite(outputPin, LOW);
    }
  }
}
      
