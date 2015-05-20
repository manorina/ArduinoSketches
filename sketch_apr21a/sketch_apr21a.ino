int myOutput = 13;
int myInput = 5;
bool is_on = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(myOutput, OUTPUT);
  pinMode(myInput, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (is_on) {
    digitalWrite(myOutput, HIGH);
  }
  else
  {
    digitalWrite(myOutput, LOW);
  }
  delay(1);
  is_on = !is_on;
  

}
