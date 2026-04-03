#include <Adafruit_DotStar.h>
#include <Arduino.h>
#include <SPI.h>

#include "led_config.h"
#include "pattern_library.h"
#include "pattern_runner.h"

/*
How to add or modify a pattern (teacher/student quick guide)
------------------------------------------------------------
1) Open src/pattern_library.cpp.
2) Copy one existing pattern and edit the LED index arrays + colors + delays.
3) Keep LED indexes between 0 and NUM_PIXELS - 1.
4) Choose which pattern runs by changing ONE LINE below:
      const LightPattern& CURRENT_PATTERN = PATTERN_SPARKLE_CHASE;
5) Upload and test.
*/

Adafruit_DotStar strip(NUM_PIXELS, DATA_PIN, CLOCK_PIN, DOTSTAR_BRG);

// Change only this line to switch patterns:
const LightPattern& CURRENT_PATTERN = PATTERN_SPARKLE_CHASE;
// const LightPattern& CURRENT_PATTERN = PATTERN_PATRIOTIC_SPARKLES;
// const LightPattern& CURRENT_PATTERN = PATTERN_COLOR_BLOCK_WALK;

PatternRunner runner(strip, CURRENT_PATTERN);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
    clock_prescale_set(clock_div_1);
#endif

    runner.begin();
}

void loop() {
    runner.runOneStep();
}