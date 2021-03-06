#ifndef GUI_h
#define GUI_h

#include <TFT_eSPI.h>

namespace GUI {
  static const uint32_t Color_Online = TFT_GREEN;
  static const uint32_t Color_Offline = TFT_RED;
  static const uint32_t Color_Progress = TFT_DARKGREEN;
  static const uint32_t Color_Inactive = TFT_DARKGREY;

  static const uint32_t Color_AlertError = TFT_RED;
  static const uint32_t Color_AlertGood = TFT_GREEN;

  static const uint32_t Color_Nickname = 0xE51D;      // Light Purple
  static const uint32_t Color_NormalText = TFT_WHITE;
  static const uint32_t Color_DimText = TFT_LIGHTGREY;

  static const uint32_t Color_Border = TFT_WHITE;
  static const uint32_t Color_Background = TFT_BLACK;

  static const uint32_t Color_SplashBkg = TFT_BLACK;  // Can swap white and black
  static const uint32_t Color_SplashText = TFT_WHITE; // Can swap white and black
  static const uint32_t Color_SplashOcto = TFT_GREEN;
  static const uint32_t Color_SplashDuet = TFT_BLUE;

  static const uint32_t Color_WeatherTxt = TFT_PURPLE;
  static const uint32_t Color_WeatherBkg = TFT_WHITE;

  static const uint32_t Color_UpdatingWeather = TFT_ORANGE;
  static const uint32_t Color_UpdatingPrinter = TFT_DARKGREEN;
  static const uint32_t Color_UpdatingText = TFT_WHITE;
  static const uint32_t Color_UpdatingFill = TFT_BLACK;

  static const uint32_t Color_WiFiBlue = 0x7D1A;

  static const uint32_t Mono_Background = 0x0000;     // Background for 1bpp sprites
  static const uint32_t Mono_Foreground = 0x0001;     // Foreground for 1bpp sprites

  void init(bool flipDisplay = false);
  void setOrientation(bool flip);

  void setBrightness(uint8_t b);
  uint8_t getBrightness();

  uint8_t getTouch(uint16_t *x, uint16_t *y);  // Takes orientation into account
  
  void loop();

  void displayHomeScreen();
  void displayCalibrationScreen();
  void displayConfigScreen(String &ssid);
  void displayDetailScreen(int index);
  void displayForecastScreen();
  void displayInfoScreen();
  void displayRebootScreen();
  void displaySplashScreen();
  void displayStatusScreen();
  void displayTimeScreen();
  void displayWeatherScreen();
  void displayWiFiScreen();

  void showUpdatingIcon(uint16_t accentColor);
    // Overlay the current screen with an icon to indicate that a potentially
    // long-running update is in progress. this lets the user know that the UI
    // will be unresponsive in this period. Calling showUpdatingIcon()
    // when the icon is already displayed is safe and does nothing.

  void hideUpdatingIcon();
    // Remove the "updating icon" from the current screen and restore the original
    // screen content. Calling hideUpdatingIcon() when no icon is displayed
    // is safe and does nothing.

  extern TFT_eSPI tft;
  extern TFT_eSprite *sprite;
}

#endif  // GUI_h