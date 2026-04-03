#include "pattern_library.h"

namespace {
constexpr uint32_t OFF = 0x000000;
constexpr uint32_t RED = 0xFF0000;
constexpr uint32_t BLUE = 0x0000FF;
constexpr uint32_t WHITE = 0xFFFFFF;
constexpr uint32_t YELLOW = 0xFFFF00;

// Pattern 1: Sparkle Chase
// One light moves left to right. Each step turns one LED ON and one LED OFF.
const int STEP_1_POS[] = {0};
const int STEP_2_POS[] = {1};
const int STEP_3_POS[] = {0};
const int STEP_4_POS[] = {2};
const int STEP_5_POS[] = {1};
const int STEP_6_POS[] = {3};
const int STEP_7_POS[] = {2};
const int STEP_8_POS[] = {4};
const int STEP_9_POS[] = {3};
const int STEP_10_POS[] = {5};
const int STEP_11_POS[] = {4};
const int STEP_12_POS[] = {6};
const int STEP_13_POS[] = {5};
const int STEP_14_POS[] = {7};
const int STEP_15_POS[] = {6};
const int STEP_16_POS[] = {7};

const PatternStep SPARKLE_CHASE_STEPS[] = {
    {STEP_1_POS, 1, YELLOW, 120},
    {STEP_2_POS, 1, YELLOW, 120},
    {STEP_3_POS, 1, OFF, 120},
    {STEP_4_POS, 1, YELLOW, 120},
    {STEP_5_POS, 1, OFF, 120},
    {STEP_6_POS, 1, YELLOW, 120},
    {STEP_7_POS, 1, OFF, 120},
    {STEP_8_POS, 1, YELLOW, 120},
    {STEP_9_POS, 1, OFF, 120},
    {STEP_10_POS, 1, YELLOW, 120},
    {STEP_11_POS, 1, OFF, 120},
    {STEP_12_POS, 1, YELLOW, 120},
    {STEP_13_POS, 1, OFF, 120},
    {STEP_14_POS, 1, YELLOW, 120},
    {STEP_15_POS, 1, OFF, 120},
    {STEP_16_POS, 1, OFF, 200},
};

// Pattern 2: Patriotic Sparkles
// Three LEDs at once: red, white, blue, then OFF.
const int GROUP_A[] = {2, 3, 4};
const int GROUP_B[] = {8, 9, 10};
const int GROUP_C[] = {14, 15, 16};

const PatternStep PATRIOTIC_SPARKLE_STEPS[] = {
    {GROUP_A, 3, RED, 160},
    {GROUP_A, 3, OFF, 100},
    {GROUP_B, 3, WHITE, 160},
    {GROUP_B, 3, OFF, 100},
    {GROUP_C, 3, BLUE, 160},
    {GROUP_C, 3, OFF, 140},
};

// Pattern 3: Color Block Walk
// A 3-LED block moves right in red/white/blue colors.
const int BLOCK_1[] = {0, 1, 2};
const int BLOCK_2[] = {1, 2, 3};
const int BLOCK_3[] = {2, 3, 4};
const int BLOCK_4[] = {3, 4, 5};
const int BLOCK_5[] = {4, 5, 6};
const int BLOCK_6[] = {5, 6, 7};

const PatternStep COLOR_BLOCK_WALK_STEPS[] = {
    {BLOCK_1, 3, RED, 140},
    {BLOCK_1, 3, OFF, 80},
    {BLOCK_2, 3, WHITE, 140},
    {BLOCK_2, 3, OFF, 80},
    {BLOCK_3, 3, BLUE, 140},
    {BLOCK_3, 3, OFF, 80},
    {BLOCK_4, 3, RED, 140},
    {BLOCK_4, 3, OFF, 80},
    {BLOCK_5, 3, WHITE, 140},
    {BLOCK_5, 3, OFF, 80},
    {BLOCK_6, 3, BLUE, 140},
    {BLOCK_6, 3, OFF, 120},
};
}  // namespace

const LightPattern PATTERN_SPARKLE_CHASE = {
    "Sparkle Chase",
    SPARKLE_CHASE_STEPS,
    sizeof(SPARKLE_CHASE_STEPS) / sizeof(PatternStep),
    true,
};

const LightPattern PATTERN_PATRIOTIC_SPARKLES = {
    "Patriotic Sparkles",
    PATRIOTIC_SPARKLE_STEPS,
    sizeof(PATRIOTIC_SPARKLE_STEPS) / sizeof(PatternStep),
    true,
};

const LightPattern PATTERN_COLOR_BLOCK_WALK = {
    "Color Block Walk",
    COLOR_BLOCK_WALK_STEPS,
    sizeof(COLOR_BLOCK_WALK_STEPS) / sizeof(PatternStep),
    true,
};
