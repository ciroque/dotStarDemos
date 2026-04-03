#include "pattern_runner.h"

#include <Arduino.h>

PatternRunner::PatternRunner(Adafruit_DotStar& strip, const LightPattern& pattern)
    : strip_(strip), pattern_(pattern), currentStep_(0), finished_(false) {
}

void PatternRunner::begin() {
    strip_.begin();
    strip_.clear();
    strip_.show();
    reset();
}

void PatternRunner::runOneStep() {
    if (finished_ || pattern_.stepCount <= 0) {
        return;
    }

    const PatternStep& step = pattern_.steps[currentStep_];
    applyStep(step);
    delay(step.delayMs);

    currentStep_++;
    if (currentStep_ >= pattern_.stepCount) {
        if (pattern_.repeat) {
            currentStep_ = 0;
        } else {
            finished_ = true;
        }
    }
}

void PatternRunner::reset() {
    currentStep_ = 0;
    finished_ = false;
}

void PatternRunner::applyStep(const PatternStep& step) {
    for (int i = 0; i < step.numPositions; i++) {
        const int index = step.positions[i];
        if (index >= 0 && index < strip_.numPixels()) {
            strip_.setPixelColor(index, step.color);
        }
    }

    strip_.show();
}
