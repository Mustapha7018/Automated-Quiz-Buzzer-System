// C++ code
const int led = 7;
const int button = 2;
const int buzzer = 8;

int buttonState = 0;  //variable for reading pushbutton status

int ledState = LOW;  //variable that sets the led low at the beginning

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  buttonState = digitalRead(button);  //read the state of the pushbutton
 
  if(buttonState == LOW) {
    digitalWrite(led, HIGH);  //turn on LED
    digitalWrite(buzzer, HIGH);
    
    //set tone to buzzer
    tone(buzzer, 1000);
  	delay(3000);
  	noTone(buzzer);
  	delay(3000);
  }
  else{
    digitalWrite(led, LOW);  //turn off LED
    digitalWrite(buzzer, LOW);
  }
}