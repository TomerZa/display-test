#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#define NUM_SCREENS 5
#define DISPLAY_ROTATION 0

void selectScreen(int screen);
void resetScreen();

TFT_eSPI tft = TFT_eSPI();
uint8_t screen_cs[5] = {15, 2, 27, 4, 5};

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting up...");

  for (int i = 0; i < NUM_SCREENS; i++)
  {
    pinMode(screen_cs[i], OUTPUT);
    digitalWrite(screen_cs[i], LOW);
  }

  tft.init();
  tft.setRotation(DISPLAY_ROTATION);
  tft.fillScreen(TFT_WHITE);
  tft.setTextDatum(MC_DATUM);

  for (int i = 0; i < NUM_SCREENS; i++)
  {
    pinMode(screen_cs[i], OUTPUT);
    digitalWrite(screen_cs[i], HIGH);
  }
}

void loop()
{
  for (int i = 0; i < NUM_SCREENS; i++)
  {
    selectScreen(i);
    tft.fillScreen(TFT_WHITE);
    tft.setTextSize(3);
    tft.setTextColor(TFT_BLACK);
    tft.drawCentreString("Screen #" + String(i), 120, 80, 1);
    resetScreen();
  }

  delay(5000);

  for (int i = 0; i < NUM_SCREENS; i++)
  {
    selectScreen(i);
    tft.fillScreen(TFT_BLACK);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.drawCentreString("Screen #" + String(i), 120, 80, 1);
    resetScreen();
  }

  delay(5000);

  for (int i = 0; i < NUM_SCREENS; i++)
  {
    selectScreen(i);
    tft.fillScreen(TFT_BLUE);
    tft.setTextSize(3);
    tft.setTextColor(TFT_ORANGE);
    tft.drawCentreString("Screen #" + String(i), 120, 80, 1);
    resetScreen();
  }

  delay(5000);

  for (int i = 0; i < NUM_SCREENS; i++)
  {
    selectScreen(i);
    tft.fillScreen(TFT_RED);
    tft.setTextSize(3);
    tft.setTextColor(TFT_SILVER);
    tft.drawCentreString("Screen #" + String(i), 120, 80, 1);
    resetScreen();
  }

  delay(5000);
}

void selectScreen(int screen)
{
  for (int i = 0; i < NUM_SCREENS; i++)
  {
    digitalWrite(screen_cs[i], i == screen ? LOW : HIGH);
  }
}

void resetScreen()
{
  for (int i = 0; i < NUM_SCREENS; i++)
  {
    digitalWrite(screen_cs[i], HIGH);
  }
}