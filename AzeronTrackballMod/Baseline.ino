
/*
  Derived from
   Azeron Simplified Firmware for XIM Apex by W11cE, 2019: 
   https://github.com/W11cE/Azeron-Simplified-Firmware-for-XIM-Apex (kept button variable names) 
   
   Sherbet Firmware by Colin Fein, 2019: 
   https://gist.github.com/Billiam/ec4ccf967088edef36e67010839f3dd1#file-sherbet-ino

 Libraries used:
  PMW3360 Module Library for Arduino by Sunjun Kim: 
  https://www.arduino.cc/reference/en/libraries/pmw3360-module/
  
  Bounce2 Library by Thomas Fredericks:
  https://github.com/thomasfredericks/Bounce2
*/

// Use USB Type: Serial+Keyboard+Mouse+Joystick

#include <PMW3360.h>
#include <Bounce2.h>
#include <avr/sleep.h>

#define SS  20
#define countPerInch 1200

/*T1: pinky, T2: ring, T3: middle, T4: index, T5: side, T6: thumb*/
/*P1: pull, P2: push, P3: flick, P4: high flick, P5: highest flick*/

#define PIN_T1_P1 38  //1
#define PIN_T2_P1 42  //2
#define PIN_T3_P1 27  //3
#define PIN_T4_P1 4 //4
#define PIN_T5_P1 11  //5
#define PIN_T1_P2 39  //6
#define PIN_T2_P2 43  //7
#define PIN_T3_P2 0 //8
#define PIN_T4_P2 5 //9
#define PIN_T1_P3 40  //10
#define PIN_T2_P3 44  //11
#define PIN_T3_P3 1 //12
#define PIN_T4_P3 8 //13
#define PIN_T1_P4 41  //14
#define PIN_T2_P4 45  //15
#define PIN_T3_P4 2 //16
#define PIN_T4_P4 9 //17
#define PIN_T3_P5 3 //18
#define PIN_T4_P5 10  //19
#define PIN_T6_P1 12  //20

#define SWITCH_1    14
#define SWITCH_2    13

#define LED_1     16
#define LED_2     15
#define LED_TEENSY    6

    // Keymap 0: Default Layer - Azeron Classic
     //            Side       Index      Middle      Ring      Pinky
     // ,------------------------------------------------------------------.
     // |                   |T.Flick | |T.Flick |                          |
     // |------------------------------------------------------------------|       Profile    LED
     // |                   |M.Flick | |M.Flick | |M.Flick | |M.Flick |    |     ,-------------------.
     // |------------------------------------------------------------------|     | Switch 1|LED 1    |
     // |                   |Flick   | |Flick   | |Flick   | |Flick   |    |     |-------------------|
     // |------------------------------------------------------------------|     | Switch 2|LED 2    |
     // |        |S.Flick | |Press   | |Press   | |Press   | |Press   |    |     `-------------------'
     // |------------------------------------------------------------------|
     // |Flick |            |Pull    | |Pull    | |Pull    | |Pull    |    |
     // `------------------------------------------------------------------'
     //  Thumb

    // Pinout Map - Teensy 2.0++
     //             Side      Index      Middle      Ring      Pinky
     // ,------------------------------------------------------------------.
     // |                   | C0/10  | |  D3/3  |                          |       Profile    LED
     // |------------------------------------------------------------------|     ,-------------------.
     // |                   |  E1/9  | |  D2/2  | | F7/45  | | F3/41  |    |     |  C3/13  | C5/C15  |  
     // |------------------------------------------------------------------|     |-------------------|
     // |                   |  E0/8  | |  D1/1  | | F6/44  | | F2/40  |    |     |  C4/14  | C6/C16  |
     // |------------------------------------------------------------------|     `-------------------'
     // |        | C1/11  | |  D5/5  | |  D0/0  | | F5/43  | | F1/39  |    |
     // |------------------------------------------------------------------|
     // | C2/12 |           |  D4/4  | | B7/27  | | F4/42  | | F0/38  |    |
     // `------------------------------------------------------------------'
     //  Thumb

     //   ,---------------------.     PMW3360 -> TEENSY 2.0++
     //   |    GD   | |  Block  | 
     //   |---------------------|
     //   |    SS   | |   B0    | 
     //   |---------------------| 
     //   |    SC   | |   B1    |
     //   |---------------------|
     //   |    MO   | |   B2    |
     //   |---------------------|
     //   |    MI   | |   B3    |                               Not Connected Pins: B4, B5, B6, E6, E7,
     //   |---------------------|                                                   REF, C7, D6, D7
     //   |    VI   | |   +5V   |                                    Teensy LED D6: 6 
     //   `---------------------'

//pull
int BUTTON_T1_P1 = KEYPAD_0;  //1
int BUTTON_T2_P1 = KEY_ESC; //2 
int BUTTON_T3_P1 = KEY_LEFT_ALT; //3 
int BUTTON_T4_P1 = KEY_PAGE_DOWN; //4 

//side button
int BUTTON_T5_P1 = KEY_TAB;  //5

//push
int BUTTON_T1_P2 = KEYPAD_1;  //6
int BUTTON_T2_P2 = KEY_LEFT_SHIFT;  //7
int BUTTON_T3_P2 = MOUSE_RIGHT; //8
int BUTTON_T4_P2 = MOUSE_LEFT;  //9
  
//flick
int BUTTON_T1_P3 = KEYPAD_2; //10
int BUTTON_T2_P3 = KEYPAD_3; //11 
int BUTTON_T3_P3 = MOUSE_MIDDLE; //12
int BUTTON_T4_P3 = KEY_PAGE_UP;  //13

//high flick
int BUTTON_T1_P4 = KEYPAD_4;  //14
int BUTTON_T2_P4 = KEYPAD_5;  //15
int BUTTON_T3_P4 = KEYPAD_6;  //16
int BUTTON_T4_P4 = KEYPAD_7;  //17

//highest flick
int BUTTON_T3_P5 = KEYPAD_8; //18
int BUTTON_T4_P5 = KEYPAD_9; //19

//thumb
int BUTTON_T6_P1 = KEY_SPACE; //20

const int KB_COUNT = 17;    // Number of keyboard buttons
const int MOUSE_COUNT = 3;   // Number of mouse buttons

const int DEBOUNCE = 3;        //Adjust as needed: increase if bouncing problem, decrease if not all keypresses register; not less than 2
const int SCAN_DELAY = 5;      //Delay between scan cycles in ms

Bounce keyButtons[KB_COUNT];
Bounce mouseButtons[MOUSE_COUNT];

boolean keyStatus[KB_COUNT]; //store button status so that inputs can be released
boolean mouseStatus[MOUSE_COUNT]; //store button status so that inputs can be released 

const int keyPins[] = {
           PIN_T4_P5, PIN_T3_P5, 
           PIN_T4_P4, PIN_T3_P4, PIN_T2_P4, PIN_T1_P4,
           PIN_T4_P3,            PIN_T2_P3, PIN_T1_P3,
PIN_T5_P1,                       PIN_T2_P2, PIN_T1_P2,
           PIN_T4_P1, PIN_T3_P1, PIN_T2_P1, PIN_T1_P1,            
PIN_T6_P1
};              
const int mousePins[] = {  
                     PIN_T3_P3,     
          PIN_T4_P2, PIN_T3_P2
};      
//int keyMode = true; // Whether to begin in standard qwerty mode or joystick button mode

// Keycodes
const int keyLayer[] = {
              BUTTON_T4_P5, BUTTON_T3_P5, 
              BUTTON_T4_P4, BUTTON_T3_P4, BUTTON_T2_P4, BUTTON_T1_P4,
              BUTTON_T4_P3,               BUTTON_T2_P3, BUTTON_T1_P3,
BUTTON_T5_P1,                             BUTTON_T2_P2, BUTTON_T1_P2,
              BUTTON_T4_P1, BUTTON_T3_P1, BUTTON_T2_P1, BUTTON_T1_P1,               
BUTTON_T6_P1
};              
const int mouseLayer[] = {  
                            BUTTON_T3_P3,
              BUTTON_T4_P2, BUTTON_T3_P2 
}; 

PMW3360 sensor;

void idle() {
  set_sleep_mode(SLEEP_MODE_IDLE);
  noInterrupts();
  sleep_enable();
  interrupts();
  sleep_cpu();
  sleep_disable();
}

void setup() {
  Serial.begin(9600);
  int i;  
  // create debouncers for mouse input pins
  for (i = 0; i < MOUSE_COUNT; i++) {
    Bounce debouncer = Bounce();

    debouncer.attach(mousePins[i], INPUT_PULLUP);
    debouncer.interval(DEBOUNCE);
    mouseButtons[i] = debouncer;
  };
  // create debouncers for keyboard input pins
  for (i = 0; i < KB_COUNT; i++) {
    Bounce debouncer = Bounce();

    debouncer.attach(keyPins[i], INPUT_PULLUP);
    debouncer.interval(DEBOUNCE);
    keyButtons[i] = debouncer;
  };
  sensor.begin(SS,countPerInch);
  //pin assignments for define#LED and SWITCH
  pinMode(LED_1, OUTPUT);  //LED 1
  pinMode(LED_2, OUTPUT);  //LED 2
  pinMode(SWITCH_1, INPUT_PULLUP); //Pushbutton
  pinMode(SWITCH_2, INPUT_PULLUP); //Pushbutton
}

void loop() {
  scanMouse();
  scanKeyboard();
  pointerCtrl();
  delay(SCAN_DELAY);
  if (digitalRead(SWITCH_1)) {
    //Profile switch pressed
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    analogWrite(LED_1, 20);
    analogWrite(LED_2, 20);
    //Profile switch depressed
  }else{
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    analogWrite(LED_1, 20);
  };
}

void scanMouse() {
  int i;
  for (i = 0; i < MOUSE_COUNT; i++) {
    mouseButtons[i].update();
    if (mouseButtons[i].fell()) {
      mousePress(i);
    } else if (mouseButtons[i].rose()) {
      mouseRelease(i);
    }
  }
}

void scanKeyboard() {
  int i;
  for (i = 0; i < KB_COUNT; i++) {
    keyButtons[i].update();
    if (keyButtons[i].fell()) {
      keyPress(i);
    } else if (keyButtons[i].rose()) {
      keyRelease(i);
    }                                                                                    
  }
}
void pointerCtrl(){
    PMW3360_DATA data = sensor.readBurst();
  if(data.isOnSurface && data.isMotion)
  {
    int mdx = constrain(data.dx, -127, 127);
    int mdy = constrain(data.dy, -127, 127);

    Mouse.move(-mdx, mdy, 0);
  }
}

//Send key press event
void keyPress(int keyCode) {
  Keyboard.press(keyLayer[keyCode]);
  keyStatus[keyCode]=true;
}

//Send key release event
void keyRelease(int keyCode) {
  Keyboard.release(keyLayer[keyCode]);
  keyStatus[keyCode]=false;
}

//Send key press event
void mousePress(int keyCode) {
  Mouse.press(mouseLayer[keyCode]);
  mouseStatus[keyCode]=true;
}

//Send key release event
void mouseRelease(int keyCode) {
  Mouse.release(mouseLayer[keyCode]);
  mouseStatus[keyCode]=false;
}
