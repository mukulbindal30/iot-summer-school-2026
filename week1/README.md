# Week 1: LED Control & Firmware Diagnostics

## Project Description
This directory contains the core embedded firmware implementations for **Week 1** of the IoT development curriculum. The module progresses from basic hardware-software interfacing (toggling a single onboard LED) to advanced digital control paradigms, including sequential array illumination, randomized interval processing, dynamic analog feedback loops, and multi-variable pulse control using RGB configurations.

## Week 1 Tasks & Projects
The repository includes implementations for the following specific assignments:
1. **Blink LED using Arduino Pin 13** (`blink_led_using_arduino_pin_131.ino`): The foundational setup demonstrating digital output and timing loops, updated systematically through multiple architectural phases (v1.0 to v1.3 production documentation).
2. **Modifications on Blinking LED using Pin 13 of arduino**: A dedicated subfolder containing the progressive stages of development:
   - **v1.0**: Basic LED blink at a 500ms baseline interval.
   - **v1.1**: Integrated asynchronous serial communications (`9600 baud`) to output diagnostic telemetry tracking the execution loop iteration (`blinkCount`).
   - **v1.2**: Interfaced a 10kΩ linear potentiometer via an analog input port to govern execution cycles dynamically.
   - **v1.3**: Applied a rigorous Doxygen-compliant documentation block embedding authorship metadata and structural overviews.
3. **Blink 5 LEDs One by One**: Sequential linear array illumination tracking multiple pins.
4. **Blink 13 LEDs One by One (Exact 10 Times)**: Advanced iteration counters managing a wide digital bus array executing finite control loop targets.
5. **Blink Random LED for Random Duration**: Stochastic timing models using pseudo-random distribution algorithms to alter both target execution channels and duration variables.
6. **control_rgb_led**: Multi-variable Pulse Width Modulation (PWM) configurations delivering precise duty-cycle color mixing.

---

## Hardware Required
To build and test all firmware variants included in this module, the following hardware components are required:

| Component | Specification / Description | Quantity |
| **Microcontroller Board** | Arduino Uno R3 (or compatible ATmega328P development board) | 1 |
| **Light Emitting Diodes (LEDs)** | Standard 5mm LEDs (Red/Green/Yellow/Blue for arrays) | Up to 13 |
| **RGB LED** | Common Cathode or Common Anode 4-pin RGB LED | 1 |
| **Potentiometer** | 10kΩ Rotary Linear Potentiometer (for dynamic delay tuning) | 1 |
| **Current-Limiting Resistors** | 220Ω to 330Ω axial resistors (protects LEDs from overcurrent) | 1 per LED |
| **Breadboard** | Standard Full-Size or Half-Size solderless breadboard | 1 |
| **Jumper Wires** | Premium Male-to-Male and Male-to-Female hookup wires | As required |

---

## Circuit Diagram Description
Because this directory hosts multiple experimental tasks, the circuit configurations scale dynamically based on the target execution file:

1. **Standard Single LED Configuration (Pin 13):**
   * The Anode (long leg) of the LED connects to Digital Pin 13 of the Arduino.
   * The Cathode (short leg) connects in series to a **220Ω resistor**, which terminates at the system Ground (`GND`).

2. **Multi-LED Sequential Array (5 to 13 LEDs):**
   * Anodes are mapped sequentially to consecutive digital output pins (e.g., Digital Pins 2 through 13).
   * Each LED has its own dedicated inline **220Ω current-limiting resistor** leading to the shared `GND` rail on the breadboard.

3. **Dynamic Potentiometer Speed Control:**
   * The outer pins of the 10kΩ potentiometer are connected to `5V` and `GND` respectively.
   * The middle pin (Wiper) connects directly to Analog Input Pin `A0` to deliver a variable $0\text{V} - 5\text{V}$ DC signal to the ADC.

4. **RGB LED Interface:**
   * The Common Cathode pin hooks directly to system Ground (`GND`).
   * The **R**, **G**, and **B** pins connect through discrete **220Ω resistors** to separate PWM-capable digital output pins (e.g., Pins 9, 10, and 11) to facilitate multi-color mixing.

---

## How to Upload Code

Follow these precise structural steps to flash the firmware onto the micro-processing unit using the desktop Arduino IDE or the Git CLI toolset:

1. **Clone & Target the Directory:**
   Open your Git Bash or system terminal and navigate into the designated workspace:
   ```bash
   cd ~/iot-summer-school-2026/week1/
   ```
2. **Open the Project:**
   Launch your preferred integrated development environment (Arduino IDE or VS Code with the PlatformIO extension) and select the specific `.ino` sketch you wish to execute (e.g., `blink_led_using_arduino_pin_131.ino`).
3. **Configure Board Target:**
   Navigate to **Tools > Board** and select **Arduino Uno**.
4. **Bind the Communication Port:**
   Connect the Arduino hardware to your computer's USB port. Under **Tools > Port**, select the active port designated by the OS architecture (e.g., `COM3` on Windows systems, or `/dev/ttyACM0` on Linux kernels).
5. **Compile and Verify:**
   Click the **Verify/Compile** checkmark button in the upper left corner to validate that code blocks pass syntactical evaluation without linking exceptions.
6. **Flash the Chip:**
   Click the **Upload** right-facing arrow button. The onboard `TX/RX` diagnostic LEDs will flash aggressively, indicating active data transit across the serial bridge. The IDE status bar will conclude with `Done uploading`.

---

## Expected Output
* **Single LED Execution:** The designated LED will transition between states (`HIGH`/`LOW`) at the designated software interval. If using firmware **v1.1** or higher, opening the IDE **Serial Monitor** at `9600 baud` will display live diagnostic metrics updating the current iteration loop counter in real-time.
* **Sequential Loop (5 or 13 LED Array):** The system cascades power across pins sequentially, shifting illumination linearly down the line before looping back to the initial index. The 13-LED variant completes exactly 10 complete iterations and terminates cleanly.
* **Randomized Processing:** LEDs scatter firing paths randomly, lingering across highly volatile operational intervals based on the entropy parameters defined inside the code blocks.
* **Potentiometer Control:** Rotating the physical dial modifies the ADC voltage value, causing the blinking sequence to accelerate smoothly or decelerate dynamically.

---

## Troubleshooting Tips

* **Issue 1: Serial Monitor Output Garbage/Corrupted Characters**
  * *Resolution:* The firmware initiates communications explicitly at `Serial.begin(9600);`. If the monitor panel is set to a conflicting rate (e.g., `115200 baud`), character data will break down. Match the dropdown box configuration at the bottom of your Serial Monitor directly to **9600 Baud**.

* **Issue 2: LED Remains Entirely Dim or Inactive**
  * *Resolution:* LEDs are polar semiconductor diodes and only conduct current in one direction. Disconnect the system power source and reverse the orientation of the component ($180^\circ$ rotation) to align the Anode with the positive supply line. Ensure the pin mappings specified in the code constants accurately reflect the hardware layout pins.

* **Issue 3: Git Workspace Rejection Errors (`Filename too long` or `Rejected Push`)**
  * *Resolution:* When tracking deeply nested firmware files on Windows environments, run `git config --global core.longpaths true` to override native character constraints. If upstream tracking mismatches occur during pushes, synchronize the indexing by performing a `git pull origin main --rebase` before re-issuing your local push command sequence.
