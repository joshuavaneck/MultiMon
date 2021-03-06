/*
 * CalibrationScreen:
 *    Provides a way to calibrate the touch sensor on the screen
 *                    
 * TO DO:
 *
 * COMPLETE:
 *
 */

//--------------- Begin:  Includes ---------------------------------------------
//                                  Core Libraries
#include <Arduino.h>
//                                  Third Party Libraries
#include <TimeLib.h>
//                                  Local Includes
#include "MMScreen.h"
//--------------- End:    Includes ---------------------------------------------

using GUI::tft;


class CalibrationScreen : public Screen {
public:
  CalibrationScreen() {
    init();
  }

  void display(bool activating = false) {
    if (activating) state = pre;

    tft.fillScreen(GUI::Color_Background);
    if (state == pre) {
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setTextColor(GUI::Color_AlertGood);
      tft.setTextDatum(MC_DATUM);
      tft.drawString("Touch to begin calibration", Screen::XCenter, Screen::YCenter);
    } else if (state == post) {
      tft.setFreeFont(&FreeSansBold9pt7b);
      tft.setTextColor(GUI::Color_AlertGood);
      tft.setTextDatum(MC_DATUM);
      tft.drawString("Done! Touch to continue", Screen::XCenter, Screen::YCenter);
      state = complete;
    }
  }

  virtual void processPeriodicActivity() {
    if (state == post) { display(); }
  }

private:
  enum {pre, post, complete} state;

  void init() {
    auto buttonHandler =[&](int id, PressType type) -> void {
      Log.verbose("In CalibrationScreenButtonHandler, id = %d", id);
      switch (state) {
        case pre:
          tft.fillScreen(GUI::Color_Background);
          tft.setFreeFont(&FreeSansBold9pt7b);
          tft.setTextColor(GUI::Color_AlertGood);
          tft.setTextDatum(MC_DATUM);
          tft.drawString("Touch each corner arrow", Screen::XCenter, Screen::YCenter);
          tft.calibrateTouch(MultiMon::settings.calibrationData, TFT_WHITE, TFT_BLACK, 15);
          state = post;
          break;
        case complete:
          uint16 *cd = &MultiMon::settings.calibrationData[0];
          Log.verbose("Finished calibration, saving settings : [");
          for (int i = 0; i < MMSettings::nCalReadings; i++) { Log.verbose("  %d,", MultiMon::settings.calibrationData[i]); }
          Log.verbose("]");
          MultiMon::Protected::saveSettings();
          GUI::displayHomeScreen();
          break;
      }
    };

    buttons = new Button[(nButtons = 1)];
    buttons[0].init(0, 0, Screen::Width, Screen::Height, buttonHandler, 0);
    state = pre;
  }

};