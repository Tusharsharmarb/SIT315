const uint8_t BTN_PIN = 2;    // Define the digital pin number for the button input
const uint8_t LED_PIN = 13;   // define the digital pin number for the LED output

uint8_t buttonPrevState = LOW;    // stores the previous state of buttons
uint8_t ledState = LOW;           // stores the current state of LED

void setup() {
  // put your setup code here, to run once:
  pinMode(BTN_PIN, INPUT_PULLUP);     // Sets the button pin as the input 
  pinMode(LED_PIN, OUTPUT);       // Sets the LED pin as the output
  Serial.begin(9600);           // Initiate the serial communication
}

void loop() {
  // put your main code here, to run repeatedly:
  uint8_t buttonState = digitalRead(BTN_PIN); // Read the state of the button and store it in buttonState

  Serial.print("buttonState: ");
  Serial.println(buttonState); //print the values
  Serial.print("buttonPrevState: ");
  Serial.println(buttonPrevState);
  Serial.print("Led State: ");
  Serial.println(ledState);

  if(buttonState != buttonPrevState) // check if current button state is different from previous button state
  {
    ledState = !ledState;     // Toggle the state of the LED
    digitalWrite(LED_PIN, ledState);    // Update the LED State on the LED pin
  }

  buttonPrevState = buttonState; // Stores the current button state as the previous button state for next iterations of the loop
  delay(500); // delay the loop for 500 milliseconds
}
