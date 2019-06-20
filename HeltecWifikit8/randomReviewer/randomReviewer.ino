//! @brief randomReviewer: smol fun project to relieve the stress of finding a fitting reviewer
//! @author mail@marcelpetrick.it

#include <Arduino.h>
#include <U8x8lib.h>

// Pin 16   OLED Reset
// Pin 4,5  I2C

// use Board "Wemos D1 Mini R2", 80Mhz, 4 MB Flash, 921600baud to flash
// COM10

U8X8_SSD1306_128X32_UNIVISION_HW_I2C u8x8(16);

void setup(void)
{
  u8x8.begin();

  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generate
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

//----------------------------------------------------------------------------------------------------

void loop(void)
{
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  u8x8.drawString(0, 0, "Laku noc,");
  delay(1000);
  u8x8.clearLine(0);

  u8x8.drawString(0, 2, "Puska! <3");
  delay(1000);
  u8x8.clearLine(2);

  u8x8.drawString(0, 0, getRandomReviewer());
  delay(1000);
  u8x8.clearLine(0);
}

//----------------------------------------------------------------------------------------------------

//! @todo improve this later by using a std::vector ..
#define PEOPLEARRAYSIZE 7
// @brief function to determine randomly inside a given array one of the values
// @returns String like "MPE was picked".
String getRandomReviewer()
{
  Serial.println("getRandomReviewer()");

  // init the array of possible reviewers
  String people[PEOPLEARRAYSIZE] = {
    "GSC",
    "MPE",
    "NLE",
    "RNI",
    "HGA",
    "MDR",
    "NKU",
  };

  // randomly determine an index
  int const randomIndex = random(PEOPLEARRAYSIZE); // exclusive the last value
  Serial.println(randomIndex);

  // create the result-string
  String returnValue = people[randomIndex] + " is your guy! :)";

  // and return it
  return returnValue;
}

//----------------------------------------------------------------------------------------------------
