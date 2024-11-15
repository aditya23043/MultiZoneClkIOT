# Portable Multi Time-Zone Clock

![IMG_20241115_234016](https://github.com/user-attachments/assets/31e49c02-a7cd-4cd3-880c-56e96d5cb2a7)

## Motivation
Since the recent shift in time gap in most of American States due to "Daylight Saving" and since my brother has moved to New York for pursuing his masters, me and my family has to once again get adjusted to the new shift even if it seems like an easy conversion.
Just like in embedded systems, we keep the main processor free as much as possible to handle emergency situations and offload the work to specific co-processors, I would rather have a simple iot device do the work for me.
Furthermore, I can add stuff like todo, calendar, time table etc to the OLED display in the future while keeping the same mcu (ESP8266 d1 mini v2) since it has enough memory for that.
Additionally, since my ssd1306 display is driven by the I2C protocol, it does not require much wiring and hence I am able to design quite a low profile case for this project.

## Dependencies

### Libraries
- Arduino_JSON by Arduino
- ssd1306 by Alexey Dynda

### Boards
- esp8266 by ESP8266 Community (optional: i.e. needed if you are using ESP8266)

## How To Run?
- Make sure you are connected to the Internet since the program uses WorldTimeApi.org for getting the time right
- Connect your mcu
- Install the corresponding mcu driver
- Install the dependencies
- Move the source code to your destination
```bash
mv src/display.ino ~/path/to/your/destination/
```
- Run the program either through Arduino IDE or compile and upload with Arduino CLI through the terminal directly (preferred by me)


![IMG_20241115_234035](https://github.com/user-attachments/assets/2c0dfa38-e490-43c5-8c79-fa9951bf2bfd)

## Demo Video
https://github.com/user-attachments/assets/227c5e0d-5cf3-4d44-8e01-807f4a7e28fd

## Case


