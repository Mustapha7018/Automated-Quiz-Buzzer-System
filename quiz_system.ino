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

const int buzzer = 10;

const int TIME_LIMIT = 5000; // time limit in milliseconds (5 seconds)

// define variables for the buzzer states, time, and rankings
bool buzzer1State = false;
bool buzzer2State = false;
bool buzzer3State = false;
bool resetState = false; // reset;
bool buzzerRung = false;
unsigned long buzzerTimestamp = 0;
unsigned long buzzerRankings[3] = {0, 0, 0};
unsigned long rankCounter = 1;


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
 
   // Read button states
  button1Pressed = digitalRead(button1) == LOW;
  button2Pressed = digitalRead(button2) == LOW;
  button3Pressed = digitalRead(button3) == LOW;
  resetButtonPressed = digitalRead(resetButton) == LOW;
  
  // If any button is pressed and the buzzer has not been rung yet, record the timestamp and turn on its corresponding LED
  if (button1Pressed && !buzzerRung) {
    buzzerTimestamp = millis();
    buzzerRank[0] = rankCounter;
    rankCounter++;
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(coordinatorLed, LOW);
    buzzerRung = true;
    
    tone(buzzer, 1000);
    delay(3000);
    noTone(buzzer);
    delay(3000);
    Serial.println("Contestant 1 rang the buzzer. Rank: " + String(buzzerRank[0]));
  } 
    else if (button2Pressed && !buzzerRung) {
      buzzerTimestamp = millis();
      buzzerRank[1] = rankCounter;
      rankCounter++;
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(coordinatorLed, LOW);
      buzzerRung = true;
      
      tone(buzzer, 1500);
      delay(3000);
      noTone(buzzer);
      delay(3000);
      Serial.println("Contestant 2 rang the buzzer. Rank: " + String(buzzerRank[1]));

  } 
    else if (button3Pressed && !buzzerRung) {
      buzzerTimestamp = millis();
      buzzerRank[2] = rankCounter;
      rankCounter++;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(coordinatorLed, LOW);
      buzzerRung = true;
      
      tone(buzzer, 2000);
      delay(3000);
      noTone(buzzer);
      delay(3000);
      Serial.println("Contestant 3 rang the buzzer. Rank: " + String(buzzerRank[2]));

  }
    else if (resetButtonPressed) {
    // If the reset button is pressed, turn off all LEDs, reset the buzzer state variables, and print out the ranks on the serial monitor
      buzzerRung = false;
      rankCounter = 1;
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(coordinatorLed, HIGH);
      tone(buzzer, 3000);
      delay(600);
      noTone(buzzer);
      delay(450);
      digitalWrite(coordinatorLed, LOW);
      

  }
}