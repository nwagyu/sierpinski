#include "eadkpp.h"

extern const char eadk_app_name[] __attribute__((section(".rodata.eadk_app_name"))) = "Sierpinski";
extern const uint32_t eadk_api_level __attribute__((section(".rodata.eadk_api_level"))) = 0;

constexpr int ScrollBufferHeight = 10;

int main(int argc, char * argv[]) {
  int numberRows[2][EADK_SCREEN_WIDTH] = {0};
  EADK::Display::Color pixelRow[EADK_SCREEN_WIDTH];

  int * previousRow = numberRows[0];
  int * currentRow = numberRows[1];

  EADK::Display::Color scrollPixelBuffer[EADK_SCREEN_WIDTH*ScrollBufferHeight];

  for (int j=0; true; j++) {
    previousRow = numberRows[j%2];
    currentRow = numberRows[(j+1)%2];
    for (int i=0; i<EADK_SCREEN_WIDTH; i++) {
      if (i==0) {
        currentRow[i] = 1;
      } else {
        currentRow[i] = previousRow[i-1] + previousRow[i];
      }
      pixelRow[i] = (currentRow[i]%2) ? EADK::Display::Color(0xFFFF) : EADK::Display::Color(0x0);
    }
    if (j<EADK_SCREEN_HEIGHT) {
      EADK::Display::pushRect(EADK::Display::Rect(0, (j%EADK_SCREEN_HEIGHT), EADK_SCREEN_WIDTH, 1), pixelRow);
    } else {
      for (int i=0; i<EADK_SCREEN_HEIGHT/ScrollBufferHeight; i++) {
        EADK::Display::pullRect(EADK::Display::Rect(0, i*ScrollBufferHeight+1, EADK_SCREEN_WIDTH, ScrollBufferHeight), scrollPixelBuffer);
        EADK::Display::pushRect(EADK::Display::Rect(0, i*ScrollBufferHeight, EADK_SCREEN_WIDTH, ScrollBufferHeight), scrollPixelBuffer);
      }
      EADK::Display::pushRect(EADK::Display::Rect(0, EADK_SCREEN_HEIGHT-1, EADK_SCREEN_WIDTH, 1), pixelRow);
    }
  }
}
