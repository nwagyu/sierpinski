#include "eadkpp.h"

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Sierpinski";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

constexpr int DisplayWidth = 320;
constexpr int DisplayHeight = 240;
constexpr int ScrollBufferHeight = 10;

int main(int argc, char * argv[]) {
  int numberRows[2][DisplayWidth] = {0};
  EADK::Display::Color pixelRow[DisplayWidth];

  int * previousRow = numberRows[0];
  int * currentRow = numberRows[1];

  EADK::Display::Color scrollPixelBuffer[DisplayWidth*ScrollBufferHeight];

  for (int j=0; true; j++) {
    previousRow = numberRows[j%2];
    currentRow = numberRows[(j+1)%2];
    for (int i=0; i<DisplayWidth; i++) {
      if (i==0) {
        currentRow[i] = 1;
      } else {
        currentRow[i] = previousRow[i-1] + previousRow[i];
      }
      pixelRow[i] = (currentRow[i]%2) ? EADK::Display::Color(0xFFFF) : EADK::Display::Color(0x0);
    }
    if (j<DisplayHeight) {
      EADK::Display::pushRect(EADK::Display::Rect(0, (j%DisplayHeight), DisplayWidth, 1), pixelRow);
    } else {
      for (int i=0; i<DisplayHeight/ScrollBufferHeight; i++) {
        EADK::Display::pullRect(EADK::Display::Rect(0, i*ScrollBufferHeight+1, DisplayWidth, ScrollBufferHeight), scrollPixelBuffer);
        EADK::Display::pushRect(EADK::Display::Rect(0, i*ScrollBufferHeight, DisplayWidth, ScrollBufferHeight), scrollPixelBuffer);
      }
      EADK::Display::pushRect(EADK::Display::Rect(0, DisplayHeight-1, DisplayWidth, 1), pixelRow);
    }
  }
}
