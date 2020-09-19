# Configurable USB MIDI Foot Pedal

## Setup Instructions

### Mechanical and Electrical Setup

Coming soon

### Firmware
This project uses PlatformIO to load the firmware onto a Teensy microcontroller. Before uploading code to your controller, make sure the environment is set correctly for your specific Teensy version in `platform.ini`. By default it is configurated for teensy31. 

If you are using different pins than those designated in the above section, you can adjust the pin numbers in firmware in `include/constants.h`

Once the default firmware is loaded onto the Teensy, the four stomp boxes should produce note-on messages with pitches 60,62,64,65 on a press, and do nothing on release. Read on to learn how to customize the MIDI output of your pedal board!

### Pedal Configuration

A Python application is included in this repo under `config_app` that will allow you to customize the MIDI output of your pedal. The configuration app works by communicating with your pedal over serial USB.

To run the app, first install the depencies. We recommend using a virtual environment
```
python -m pip install -r config_app/requirements.txt
```

You can then launch the configuration app with
```
python config_app/pedal_config.py
```

## MIDI Configuration Notes

### Supported message types
Note On, Note Off, Program Change, or Control Change

All parameters are configurable

### Modes
Press: emit a MIDI message when stomp box is pressed
Press & Release: emit a MIDI message when a stomp box is pressed, and an independent message when it is release
Cycle: Loop through a cycle of messages on repeated presses, with a max cycle length of 7

## To-Do List
- Add electrical diagram to README
- Save configurations on the controller between power cycles
- Allow saving/loading of configuration setups within the app
- Set up pyinstaller for configuration app
