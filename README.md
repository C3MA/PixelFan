[![Build STM32 Project](https://github.com/C3MA/PixelFan/actions/workflows/build_STM32.yml/badge.svg)](https://github.com/C3MA/PixelFan/actions/workflows/build_STM32.yml)
[![Build ESP Project](https://github.com/C3MA/PixelFan/actions/workflows/build_ESP.yml/badge.svg)](https://github.com/C3MA/PixelFan/actions/workflows/build_ESP.yml)


# Projektbeschreibung
In diesem Projekt wurde ein Handelsüblicher Standventilator zum Rotationsdisplay umfunktioniert.

Details und eine Präsentation dazu gibt es hier:

[C3MA Vortrag](https://www.ccc-mannheim.de/wiki/Seminar_17._M%C3%A4rz_2023)

## Aufbau
Es gibt insgesamt 3 identische LED Leisten (PCB/LED_Leiste) mit jeweils 26 HD107S LEDs.

Die LED Leisten werden dann auf der Hauptplatine (PCB/PixelFan) bestückt.

Die Hauptplatine besteht aus 2 Controllern: 

* ein STM32G071KBTX (Software unter STM_PixelFan) für die schnelle zeitkritische Ansteuerung der LEDs und der Synchronisation zur Drehung
* ein ESP32 (Software unter ESP_PixelFan) um per W-LAN eine Verbindung zur Außenwelt herzustellen

Der Ventilator öffnet ein W-LAN (SSID: PixelFan) auf dem er eine Website (unter 192.168.4.1) anzeigt. Auf der Seite können Bilder, Smileys und Text auf den Ventilator gesendet werden.
