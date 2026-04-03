# DotStar Patterns for Beginners (PlatformIO + CLion)

A beginner-friendly Arduino/PlatformIO project for students (ages 12-18) to learn C++ basics by creating LED light patterns on an Adafruit DotStar strip.

This project is designed for a **60-90 minute lesson** and focuses on one core idea:

- Define light patterns mostly with **simple data tables**
- Keep code changes small and easy to understand
- Switch patterns by changing **one line**

---

## What Students Learn

- How code controls physical hardware (LEDs)
- Basic C++ structs and arrays
- How to represent animation as a list of steps
- How to debug simple hardware/software issues

---

## Hardware

- Arduino Nano Every (or compatible board)
- Adafruit DotStar strip
- USB cable
- Power for strip (if needed for larger strips)

Default pin setup in this project:

- `DATA_PIN = 4`
- `CLOCK_PIN = 5`

You can change these in `include/led_config.h`.

---

## Project Layout

- `src/main.cpp` - setup, loop, and one-line pattern selection
- `include/led_config.h` - strip length and pin settings
- `include/light_pattern.h` - beginner-friendly pattern structs
- `include/pattern_runner.h` + `src/pattern_runner.cpp` - tiny pattern engine
- `include/pattern_library.h` + `src/pattern_library.cpp` - example patterns (table-driven)
- `src/sketches/` - original/advanced examples (kept for later)

---

## Quick Start (Teacher)

1. Open project in CLion (PlatformIO plugin).
2. Connect board over USB.
3. In `include/led_config.h`, set:
   - `NUM_PIXELS` to your strip length
   - `DATA_PIN` and `CLOCK_PIN` to your wiring
4. In `src/main.cpp`, choose pattern by changing one line:
   - `const LightPattern& CURRENT_PATTERN = ...`
5. Build and upload.

---

## How Patterns Work

Each pattern is a list of `PatternStep` entries.

Each step says:

- Which LED indexes to change (`positions`)
- How many LED indexes are listed (`numPositions`)
- What color to set (`color` in `0xRRGGBB`)
- How long to wait (`delayMs`)

Because each step can hold multiple positions, students can light **several LEDs at once**.

---

## Student Editing Rules

When editing `src/pattern_library.cpp`:

- Keep LED indexes between `0` and `NUM_PIXELS - 1`
- Use `0xRRGGBB` colors (`0` means OFF)
- Start with small delays (80-200 ms)
- Change only one thing at a time, then upload and test

---

## Included Beginner Patterns

- `PATTERN_SPARKLE_CHASE`
- `PATTERN_PATRIOTIC_SPARKLES`
- `PATTERN_COLOR_BLOCK_WALK`

Use these as templates for new student-created patterns.

---

## 60-90 Minute Lesson Flow (Suggested)

### 1) Intro + Demo (10 min)

- Show one running pattern
- Explain: animation = list of timed steps

### 2) First Edit (15 min)

- Change active pattern in `src/main.cpp`
- Upload and observe differences

### 3) Data Table Edits (20-30 min)

- Change colors
- Change delays
- Change LED positions
- Add one new step

### 4) Create a New Pattern (20-25 min)

- Copy one existing pattern in `src/pattern_library.cpp`
- Rename it and expose it in `include/pattern_library.h`
- Select it in `src/main.cpp`

### 5) Share + Reflect (5-10 min)

- Students present their pattern
- Discuss what each table edit changed

---

## Troubleshooting

### Upload error: `avrdude: ser_open(): can't open device ... Permission denied`

- Make sure the correct serial port is selected
- Add your user to the `dialout` group on Linux:
  - `sudo usermod -aG dialout $USER`
  - then log out/in
- Close any serial monitor app using the port

### Nothing lights up

- Check `NUM_PIXELS`
- Check `DATA_PIN` and `CLOCK_PIN`
- Check strip power and ground
- Confirm strip orientation/direction arrows

### Lights are wrong colors

- DotStar strips may use different color order
- If needed, adjust strip type in `src/main.cpp`

---

## Advanced (Optional Later)

The original sketches in `src/sketches/` (like `cylon` and `lightning`) are kept as extension material after students are comfortable with the beginner system.

---

## Teaching Goal

Keep the first session about confidence:

- small edits
- immediate visual results
- clear connection between data and behavior
