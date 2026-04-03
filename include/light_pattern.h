#pragma once

#include <Arduino.h>

struct PatternStep {
    const int* positions;   // Pointer to LED index list for this step
    int numPositions;       // Number of LED indexes in that list
    uint32_t color;         // 0xRRGGBB, use 0 for OFF
    int delayMs;            // Delay after this step
};

struct LightPattern {
    const char* name;
    const PatternStep* steps;
    int stepCount;
    bool repeat;            // true = loop forever
};
