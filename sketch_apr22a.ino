 const int red_led=25; 
 const int amber_led=27; 
 const int green_led=13; 

void setup(){
     pinMode(red_led, OUTPUT);
     pinMode(amber_led, OUTPUT);
     pinMode(green_led, OUTPUT);
}

void loop(){
  digitalWrite(amber_led, HIGH);
  digitalWrite(red_led, LOW);
  digitalWrite(green_led, LOW);
  delay(1000);
  digitalWrite(red_led, LOW);
  digitalWrite(amber_led, HIGH);
  digitalWrite(green_led, LOW);
  delay(1000);
  digitalWrite(red_led, HIGH);
  digitalWrite(amber_led, LOW);
  digitalWrite(green_led, LOW); 
  delay(1000);
  digitalWrite(red_led, HIGH);
  digitalWrite(amber_led, HIGH);
  digitalWrite(green_led, LOW); 
  delay(1000);
  digitalWrite(red_led, LOW);
  digitalWrite(amber_led, LOW);
  digitalWrite(green_led, HIGH);
  delay(1000);
}
