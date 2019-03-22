#include "util.h"
#include "lcd_image.h"

void setup() {
  // initialize Arduino
  init();

  // initialize zoom pins
  pinMode(clientpins::left_pin, INPUT_PULLUP);
  pinMode(clientpins::right_pin, INPUT_PULLUP);

  // initialize joystick pins and calibrate centre reading
  pinMode(clientpins::joy_button_pin, INPUT_PULLUP);
  // x and y are reverse because of how our joystick is oriented
  

  // initialize serial port
  Serial.begin(9600);
  Serial.flush();  // get rid of any leftover bits


  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(ILI9341_WHITE);

  // initialize SD card
  if (!SD.begin(clientpins::sd_cs)) {
      Serial.println("Initialization has failed. Things to check:");
      Serial.println("* Is a card inserted properly?");
      Serial.println("* Is your wiring correct?");
      Serial.println("* Is the chipSelect pin the one for your shield or module?");
      while (1) {}  // nothing to do here, fix the card issue and retry
  }
}

void textInit() {
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
The textInit function takes in no paramaters.

It does not return any parameters.

This function is responsible for taking care of all the initial duties of
correctly setting up the text and formatting it accordingly. The test used in
this exercise is all in one colour and size.
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
    tft.setTextColor(ILI9341_BLACK);
    tft.setTextSize(1);
    tft.setFont(&FreeSansBold9pt7b);
}

void welcomeScreen() {
    tft.setCursor(displayconsts::tft_width/3, displayconsts::tft_height/4);
    textInit();
    tft.print("Welcome!");
    tft.setCursor(displayconsts::tft_width/6, displayconsts::tft_height/4 + 50);
    tft.print("Periodic Table Database");
    tft.setCursor(displayconsts::tft_width/8, displayconsts::tft_height/2 + 40);
    //tft.setFont(2);
    tft.print("By: Rutvik Patel and Kaden Dreger");
}

int main() {
    setup();
    welcomeScreen();
    return 0;
}