#pragma once

#include <Adafruit_DotStar.h>

#include "light_pattern.h"

class PatternRunner {
public:
    PatternRunner(Adafruit_DotStar& strip, const LightPattern& pattern);

    void begin();
    void runOneStep();
    void reset();

private:
    void applyStep(const PatternStep& step);

    Adafruit_DotStar& strip_;
    const LightPattern& pattern_;
    int currentStep_;
    bool finished_;
};
