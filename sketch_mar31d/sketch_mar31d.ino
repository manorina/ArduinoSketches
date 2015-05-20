int led = 11;
int lightLevel;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(led, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  lightLevel = analogRead(A0);
  Serial.print("Light level: ");
  Serial.println(lightLevel, DEC);
  digitalWrite(led, HIGH);
  delay(lightLevel);
  digitalWrite(led,LOW);
  delay(lightLevel);
  

}
