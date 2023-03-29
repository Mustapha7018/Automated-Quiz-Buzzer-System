/*
  This is a code for my mini project. It is an automated quiz buzzer system
  that comes with several different features from other systems that exists.
*/

// define constants for pins and time limit
const int BUTTON1_PIN = 2;
const int BUTTON2_PIN = 3;
const int BUTTON3_PIN = 4;
const int RESET_PIN = 5;

const int LED1_PIN = 6;
const int LED2_PIN = 7;
const int LED3_PIN = 8;
const int COORDINATOR_LED_PIN = 9;

const int TIME_LIMIT = 5000; // time limit in milliseconds (5 seconds)

// define variables for the buzzer states, time, and rankings
int buzzer1State = LOW;
int buzzer2State = LOW;
int buzzer3State = LOW;
int resetState = LOW;
unsigned long buzzer1Time = 0;
unsigned long buzzer2Time = 0;
unsigned long buzzer3Time = 0;
int buzzerRankings[3] = {0, 0, 0};


int buttonState = 0;  //variable for reading pushbutton status

int ledState = LOW;  //variable that sets the led low at the beginning

// This setup funtion runs once when the program starts
void setup()
{
  Serial.begin(9600);  // initialize serial communication

  pinMode(BUTTON1_PIN, INPUT_PULLUP);
  pinMode(BUTTON2_PIN, INPUT_PULLUP);
  pinMode(BUTTON3_PIN, INPUT_PULLUP);
  pinMode(RESET_PIN, INPUT_PULLUP);

  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(COORDINATOR_LED_PIN, OUTPUT);

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