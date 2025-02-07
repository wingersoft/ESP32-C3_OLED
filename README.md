# ESP32-C3_OLED
![AHT20_BMP280 logo](https://github.com/peff74/ESP32-C3_OLED/blob/main/ESP32-C3_oled.jpg)


- The ESP32-C3 OLED is a very practical and cheap ESP32-C3 Supermini with 0.42 Inch OLED Display.
- It is sold on all known platforms.
- Most dealers provide no technical data, which sometimes makes it difficult to get it up and running...
- The OLED display requires a workaround to function correctly because there is no dedicated 72x40 constructor in the U8g2 library.



## Technical specs
- SDA is D6
- SCL is D5
- Resolution is 72x40

## Code using U8g2

```
#include <U8g2lib.h>
#define OLED_RESET U8X8_PIN_NONE  // Reset pin
#define OLED_SDA 5
#define OLED_SCL 6


U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_RESET, OLED_SCL, OLED_SDA);
int width = 72;
int height = 40;
int xOffset = 30;  // = (132-w)/2
int yOffset = 12;  // = (64-h)/2


int c = 0;

void handle_oled(int c) {
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_4x6_tr);
  u8g2.drawStr(xOffset + 0, yOffset + 10, "Display is working!");
  u8g2.drawStr(xOffset + 0, yOffset + 20, "Have fun with it");
  char buffer[20];
  snprintf(buffer, sizeof(buffer), "Uptime: %ds", c);
  u8g2.drawStr(xOffset + 0, yOffset + 30, buffer);
  u8g2.sendBuffer();
}


void setup(void) {
  u8g2.begin();
  u8g2.setContrast(255);     // set contrast to maximum
  u8g2.setBusClock(400000);  //400kHz I2C
}

void loop(void) {
  handle_oled(c);
  c++;
  delay(1000);
}
```
[![Hits](https://hits.seeyoufarm.com/api/count/incr/badge.svg?url=https%3A%2F%2Fgithub.com%2Fpeff74%2FESP32-C3_OLED&count_bg=%2379C83D&title_bg=%23555555&icon=&icon_color=%23E7E7E7&title=hits&edge_flat=false)](https://hits.seeyoufarm.com)
