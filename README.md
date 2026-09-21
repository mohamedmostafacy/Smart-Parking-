# 🚗 Smart Parking System (Arduino + C++)

An automated parking gate system built with **Arduino Uno**, **IR sensors**, a **servo motor**, and a **16x2 I2C LCD**. The system tracks available parking slots in real time, opens/closes a gate barrier automatically, and displays live slot availability on the LCD.

---

## 📋 Features

- Automatic gate control on car **entry** and **exit**
- Real-time tracking of available parking slots
- 16x2 I2C LCD display showing:
  - Number of slots left
  - "Welcome" message when space is available
  - "FULL" message when the lot is at capacity
- Prevents entry when the parking lot is full
- Simple, beginner-friendly Arduino C++ code

---

## 🔧 Hardware Components

| Component                  | Quantity | Purpose                          |
|-----------------------------|----------|-----------------------------------|
| Arduino Uno                | 1        | Main controller                   |
| IR Obstacle Sensor          | 2        | Detect entering / exiting cars    |
| SG90 Servo Motor           | 1        | Acts as the gate barrier          |
| 16x2 I2C LCD Display        | 1        | Shows slot status                 |
| Breadboard + Jumper Wires   | -        | Connections                       |

---

## 🔌 Wiring / Pin Configuration

| Arduino Pin | Connected To          |
|-------------|------------------------|
| D2          | IR Sensor (Entry) OUT  |
| D3          | IR Sensor (Exit) OUT   |
| D9          | Servo Signal           |
| A4 (SDA)    | LCD SDA                |
| A5 (SCL)    | LCD SCL                |
| 5V / GND    | Power rail for all components |

> LCD I2C address used in code: `0x27` (change in code if your module uses `0x3F`).

A Tinkercad circuit diagram is included in the repo (see `.<img width="1536" height="632" alt="circuit-diagram" src="https://github.com/user-attachments/assets/be3a204a-dcb5-46e8-9636-f51dd7e72039" />`)


---

## 📚 Required Libraries

Install these via the Arduino Library Manager before uploading:

- `Wire.h` (built-in)
- `LiquidCrystal_I2C` by Frank de Brabander
- `Servo.h` (built-in)

---

## ⚙️ How It Works

1. On startup, the LCD shows a welcome message and the gate closes (servo at 90°).
2. When the **entry IR sensor** detects a car and slots are available:
   - The gate opens (servo moves to 0°)
   - Available slots decrease by 1
   - The gate closes after the car passes
3. When the **exit IR sensor** detects a car:
   - The gate opens
   - Available slots increase by 1
   - The gate closes after the car passes
4. If the lot is full, the LCD displays **"Parking is FULL"** and the entry gate stays closed.

---

## 🚀 Getting Started

1. Clone this repository:
   ```bash
   git clone https://github.com/mohamedmostafacy/Smart-Parking-.git
   ```
2. Open `Smart_Parking.cc` (or rename to `.ino`) in the Arduino IDE.
3. Install the required libraries listed above.
4. Connect the hardware as described in the wiring table.
5. Select your board (**Arduino Uno**) and port, then upload.

---

## 🛠️ Troubleshooting

**Servo jitters or jumps to a random/wrong angle:**
This is almost always a **power supply issue**, not a code issue. The servo, LCD, and two IR sensors are all being powered directly from the Arduino's 5V pin. When the servo moves (especially under any resistance), it draws a current spike that the Arduino's onboard regulator can't supply cleanly. This causes a voltage sag that:
- Makes the servo twitch or jump to an unintended angle
- Can even reset/glitch the Arduino or LCD momentarily

**Fix:** Power the servo from a separate 5V source (e.g., a dedicated 5V supply or 4x AA battery pack), and connect that supply's **GND to the Arduino's GND** (common ground is required). Keep the LCD and IR sensors on the Arduino's 5V as before.

---

## 📄 License

This project is open source and available under the [MIT License](LICENSE).

---

## 👤 Author

**Mohamed Mostafa**
GitHub: [@mohamedmostafacy](https://github.com/mohamedmostafacy)
