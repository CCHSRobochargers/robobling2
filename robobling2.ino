
#include <Adafruit_NeoPixel.h>

#define PIN              6
#define NUM_PIXELS       169

#define VSTRAND_V	10
#define VSTRAND_H	71

// 0 = dark, 255 = full brightness
int  brightness = 32;

#define			__ ((byte)-1)	/* More visible fillers */

byte neoArray[VSTRAND_V][VSTRAND_H] = {
  {  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, __, __, 23, 24, 25, 26, 27, 28, 29, 30,111,112,113,114,115,116,117,118,119, __, __, __, __, __, __, __, __,120,121,122,123,124,125,126,127,128,129,130,131,132,133,134, __, __,135,136,137,138,139,140,141,142,143,144,145,146,147 }, //0
  // The Robot -------------------------------------------|         Instagram --------------------| Robo -----------------------------|                                 4507 -----------------| Outreach -------------------------|         Scrimmage ----------------------------------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __,110,109,108,107,106,105,104,103,102,101,100, 99, 98, 97, 96, 95, 94, 93, 92, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //1
  //                                                                                                Chargers -----------------------------------------------------------------|
  {  0,  1,  2,  3,  4,  5,  6,  7,  8, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //2
  // Jessie --------------------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __,148,149,150,151,152,153, __, __, __, __, __ }, //3
  //                                                                                                                                                                                                                                                Zach (vertical)       |
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, 38, 37, 36, 35, 34, 33, 32, 31, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //4
  //                                                                Jeremy Jack ------------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //5
  //                                                                                                                                                    Elgin ------------------------------------|
  { __, __, __, __, __, __, __, __, 39, 40, 41, 42, 43, 44, 45, 46, 47, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, 80, 79, 78, 77, 76, 75, 74, 73, 72, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //6
  //                                Ross (vertical) ------------------|                                                                 Jeremy (vertical) ----------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __,162,161,160,159,158,157,156,155,154, __ }, //7
  //                                                                                                                                                                                                                                                    KDL Library ----------------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, 62, 61, 60, 59, 58, 57, __, __, __, __, __, __, __, __, __, __, __, 63, 64, 65, 66, 67, 68, 69, 70, 71, __, __, __, __, __, __,163,164,165,166,167,168, __, __, __, __, __, __, __ }, //8
  //                                                                                                        Alison Gary (vertical)|                                             Jeremy Whiteboard ---------- -----|                         FLL ------------------|
  { __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, 48, 49, 50, 51, 52, 53, 54, 55, 56, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __, __ }, //9
  //                                                                Tyler Jack -----------------------|
};

#undef __

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

#ifdef COMMENT_OUT
  //colorWipe random LEDs
  colorWipe(4, 9, strip.Color(255,215,0), 0); // Gold
  
  //color wipe on Robo-
  //              Chargers
  colorWipe(0, 1, strip.Color(255,215,0), 50); // Gold
  
  //coloWipe for Tower
  colorWipe(2, strip.Color(255,215,0), 50); // Gold
  colorWipe(2, 0, 50);
  
  //colorWipe for Kicker
  colorWipe(3, 3, strip.Color(255,215,0), 50); // Gold
  colorWipe(3, 0, 50);
  
  //colorWipe for Game Strategy
  colorWipe(5, 6, strip.Color(255,215,0), 50); // Gold
  colorWipe(5, 6, 0, 50);
  
  //colorWipe for Autonomous
  colorWipe(7, 7, strip.Color(255,215,0), 50); // Gold
  colorWipe(7, 0, 50);
  
  //colorWipe for Peripherals
  colorWipe(8, 8, strip.Color(255,215,0), 50); // Gold
  colorWipe(8, 0, 50);
    
  //LED strips turn on one at a time for rainbow
  
  //random LEDS
  rainbow(4, 9, 5);
  
  //rainbow on Robo-
  //           Chargers
  rainbow(0, 1, 50);
  
  //rainbow on Tower
  rainbow(2, 2, 50);
 
  //rainbow on Kicker
  rainbow(3, 3, 50);
 
  //rainbow on Game Strategy
  rainbow(5, 6, 50);
 
  //rainbows on Autonomous
  rainbow(7, 7, 50);
 
  //rainbows on peripherals
  rainbow(8, 8, 50);
  
 //LEDs turn on one at a time for colorWipe (and stay on )
   colorWipe(strip.Color(0, 0, 0), 50); // start all off
 
  //colorWipe random LEDs
  colorWipe(4, 9, strip.Color(255,215,0), 0); // Gold
  
  //color wipe on Robo-
  //              Chargers
  colorWipe(0, 1, strip.Color(255,215,0), 50); // Gold
  
  //coloWipe for Tower
  colorWipe(2, strip.Color(255,215,0), 50); // Gold
  
  //colorWipe for Kicker
  colorWipe(3, 3, strip.Color(255,215,0), 50); // Gold

  //colorWipe for Game Strategy
  colorWipe(5, 6, strip.Color(255,215,0), 50); // Gold

  //colorWipe for Autonomous
  colorWipe(7, 7, strip.Color(255,215,0), 50); // Gold

  //colorWipe for Peripherals
  colorWipe(8, 8, strip.Color(255,215,0), 50); // Gold
#endif

  strip.setBrightness(brightness);

  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255,215,0), 50); // Gold
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(255,215,0), 50); // Gold
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(255,215,0), 50); // Gold
  colorWipe(strip.Color(0, 0, 255), 50); // Blue

  // Send a theater pixel chase in...
  theaterChase(strip.Color(255, 215,   0), 50); // Gold
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127,   0,   0), 50); // Red
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
}

// Set LEDs in a virtual strand driving physical strands
void vStrand(int pixel, uint32_t c) {
  int j;

  for(j = 0; j < VSTRAND_V; j++) {
    if(neoArray[j][pixel] >= 0)
      strip.setPixelColor((uint16_t)neoArray[j][pixel], c);
  }
}

// Set LEDs in a virtual strand driving physical strands in lines
void vStrand(int line, int pixel, uint32_t c) {
  if(neoArray[line][pixel] >= 0)
    strip.setPixelColor((uint16_t)neoArray[line][pixel], c);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < VSTRAND_H; i++) {
      vStrand(i, c);
      strip.show();
      delay(wait);
  }
}

// colorWipe for 1 line
void colorWipe(int line, uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < VSTRAND_H; i++) {
      vStrand(line, i, c);
      strip.show();
      delay(wait);
  }
}

// colorWipe for 2 lines
void colorWipe(int line1, int line2, uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < VSTRAND_H; i++) {
      vStrand(line1, i, c);
      vStrand(line2, i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<VSTRAND_H; i++) {
      vStrand(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//rainbow for one line
void rainbow(int line, uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<VSTRAND_H; i++) {
      vStrand(line, i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//rainbow for two lines
void rainbow(int line1, int line2, uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<VSTRAND_H; i++) {
      vStrand(line1, i, Wheel((i+j) & 255));
      vStrand(line2, i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< VSTRAND_H; i++) {
      vStrand(i, Wheel(((i * 256 / VSTRAND_H) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < VSTRAND_H; i=i+3) {
        vStrand(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < VSTRAND_H; i=i+3) {
        vStrand(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < VSTRAND_H; i=i+3) {
          vStrand(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < VSTRAND_H; i=i+3) {
          vStrand(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}

