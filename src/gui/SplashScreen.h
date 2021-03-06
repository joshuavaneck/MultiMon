//--------------- Begin:  Includes ---------------------------------------------
//                                  Core Libraries
#include <Arduino.h>
//                                  Third Party Libraries
#include <TimeLib.h>
//                                  Local Includes
#include "MMScreen.h"
#include "images/Duet3dMono.h"
#include "images/OctoMono.h"
//--------------- End:    Includes ---------------------------------------------

using GUI::tft;

class SplashScreen : public Screen {
public:
  SplashScreen() {
    nButtons = 0;
    buttons = NULL;
  }

  void display(bool activating = false) {
    // #include "src/images/OctoLogo.h"
    // tft.pushImage(0, 0, Screen::Width, Screen::Height, logo_320x240);
    tft.fillScreen(GUI::Color_SplashBkg);
    tft.drawBitmap(
        6, 0, OctoMono, OctoMono_Width, OctoMono_Height,
        GUI::Color_SplashBkg, GUI::Color_SplashOcto);
    tft.drawBitmap(
        Screen::XCenter+6, 0, Duet3dMono, Duet3dMono_Width, Duet3dMono_Height,
        GUI::Color_SplashBkg, GUI::Color_SplashDuet);

    tft.setFreeFont(&FreeSansBoldOblique24pt7b);
    tft.setTextColor(GUI::Color_SplashText);
    tft.setTextDatum(BC_DATUM);
    tft.drawString("MultiMon", Screen::XCenter, Screen::Height-1);
  }

  virtual void processPeriodicActivity() {
    // Nothing to do here, we're displaying a static screen
  }

private:
};