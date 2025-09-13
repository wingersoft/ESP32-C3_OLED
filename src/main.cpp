// Include the U8g2 library for OLED display
#include <U8g2lib.h>

// Define the reset pin for the OLED display
#define OLED_RESET U8X8_PIN_NONE  // Reset pin

// Define the I2C pins for the OLED display
#define OLED_SDA 5
#define OLED_SCL 6

// Define the blue LED pin
#define BLUE_LED 8

// Initialize the U8g2 library for the SSD1306 OLED display
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, OLED_RESET, OLED_SCL, OLED_SDA);

// Define the dimensions and offset for the display content
int width = 72;
int height = 40;
int xOffset = 30;  // = (132-w)/2
int yOffset = 12;  // = (64-h)/2

// Initialize a counter for uptime
int counter = 0;

// Function to display content on the OLED
void display_oled(int c)
{
    // Initialize serial communication
    Serial.begin(115200);
    // Clear the buffer
    u8g2.clearBuffer();
    // Set the font
    u8g2.setFont(u8g2_font_4x6_tr);
    // Draw the strings on the display
    u8g2.drawStr(xOffset + 0, yOffset + 20, "Display is working!");
    u8g2.drawStr(xOffset + 0, yOffset + 30, "Have fun with it");

    // Create a buffer for the uptime string
    char buffer[20];
    // Format the uptime string
    snprintf(buffer, sizeof(buffer), "Uptime: %ds", c);
    // Draw the uptime string on the display
    u8g2.drawStr(xOffset + 0, yOffset + 40, buffer);
    // Send the buffer to the display
    u8g2.sendBuffer();
}

// Setup function to run once on startup
void setup(void)
{
    // Set the blue LED pin as an output
    pinMode(BLUE_LED, OUTPUT);
    // Initialize serial communication
    Serial.begin(115200);
    // Initialize the OLED display
    u8g2.begin();
    // Set the contrast to maximum
    u8g2.setContrast(255);
    // Set the I2C bus clock speed
    u8g2.setBusClock(400000);  // 400kHz I2C
}

// Loop function to run repeatedly
void loop(void)
{
    // Toggle the blue LED
    digitalWrite(BLUE_LED, !digitalRead(BLUE_LED));
    // Display the uptime on the OLED
    display_oled(counter);
    // Print the uptime to the serial monitor
    Serial.print("Uptime = ");
    Serial.println(counter);
    // Increment the counter
    counter++;
    // Wait for 1 second
    delay(1000);
}