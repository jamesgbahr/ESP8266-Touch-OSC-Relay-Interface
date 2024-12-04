# ESP8266 Touch OSC Relay Interface

An interface to control relays via TouchOSC, using an ESP8266 microcontroller. This project is designed for smart home enthusiasts, IoT developers, and anyone interested in creating a custom remote-controlled relay system.

## Features

- **TouchOSC Integration**: Seamlessly control relays using the TouchOSC app.
- **WiFi Connectivity**: Built on the ESP8266, enabling wireless communication with your local network.
- **Relay Control**: Supports multiple relays for home automation and IoT projects.
- **Customizable**: Easily modify the code to suit your specific requirements.
- **Real-Time Feedback**: Bi-directional communication with TouchOSC for status updates.

## Components Required

- **ESP8266 Module** (e.g., NodeMCU, Wemos D1 Mini)
- **Relay Module** (Single or multi-channel relay board)
- **TouchOSC App** (Available for iOS and Android)
- **Power Supply** (5V for ESP8266 and relays)
- Connecting wires and a breadboard (optional for prototyping)

## Installation

### Set Up Arduino IDE

1. Install the [ESP8266 Board Package](https://arduino-esp8266.readthedocs.io/).
2. Install the required libraries:
   - `WiFiManager`
   - `OSC`
   - `ArduinoJson`

### Configure the Code

1. Open `ESP8266-Touch-OSC-Relay-Interface.ino` in the Arduino IDE.
2. Update the WiFi credentials (if not using WiFiManager).
3. Customize the relay GPIO pin assignments as needed.

### Upload the Code

1. Connect your ESP8266 to your computer via USB.
2. Select the correct board and port in the Arduino IDE.
3. Upload the code.

## Configuration

### TouchOSC Layout

1. Create a custom layout in TouchOSC to match the relay controls.
2. Assign OSC addresses corresponding to the code logic (e.g., `/relay1`, `/relay2`).

### ESP8266 Setup

1. On first boot, the ESP8266 will create an access point.
2. Connect to the AP and configure your WiFi credentials via the captive portal.

### Relay Connections

1. Connect the relay module to the ESP8266 GPIO pins.
2. Ensure proper voltage and current requirements are met.

## Usage

1. Open the TouchOSC app and load your custom layout.
2. Connect to the ESP8266 via its IP address in the app settings.
3. Use the TouchOSC controls to toggle relays on and off.

## Example

- TouchOSC sends a message to `/relay1` to toggle Relay 1.
- ESP8266 receives the message, toggles the relay, and sends a status update back to TouchOSC.

## Pinout Diagram

| GPIO Pin | Function        |
|----------|-----------------|
| D1       | Relay 1 Control |
| D2       | Relay 2 Control |
| D3       | Relay 3 Control |
| D4       | Relay 4 Control |

## Troubleshooting

- **Cannot Connect to WiFi**: Verify credentials and ensure your router is compatible with the ESP8266 (2.4GHz only).
- **Relays Not Responding**: Check wiring and GPIO pin assignments.
- **TouchOSC Communication Issues**: Confirm the OSC IP and port settings in the app match the ESP8266 code.

## License

This project is licensed under the [MIT License](LICENSE).

## Contributions

Contributions are welcome! Feel free to open an issue or submit a pull request.
