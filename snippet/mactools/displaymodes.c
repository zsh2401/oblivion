// clang displaymode.c -o displaymode -framework CoreGraphics
#include <stdio.h>
#include <stdlib.h>
#include <CoreGraphics/CGDirectDisplay.h>
#include <CoreGraphics/CGDisplayConfiguration.h>

// https://github.com/robbertkl/ResolutionMenu/blob/master/Resolution%20Menu/DisplayModeMenuItem.m
// CoreGraphics DisplayMode struct used in private APIs
typedef struct {
  uint32_t modeNumber;
  uint32_t flags;
  uint32_t width;
  uint32_t height;
  uint32_t depth;
  uint8_t unknown[170];
  uint16_t freq;
  uint8_t more_unknown[16];
  float density;
} CGSDisplayMode;
// CoreGraphics private APIs with support for scaled (retina) display modes
void CGSGetCurrentDisplayMode(CGDirectDisplayID display, int* modeNum);
void CGSConfigureDisplayMode(
  CGDisplayConfigRef config, CGDirectDisplayID display, int modeNum);
void CGSGetNumberOfDisplayModes(CGDirectDisplayID display, int* nModes);
void CGSGetDisplayModeDescriptionOfLength(
  CGDirectDisplayID display, int idx, CGSDisplayMode* mode, int length);

int main(int argc, char* argv[]) {
  CGDirectDisplayID display = CGMainDisplayID();
  int count;
  CGSGetNumberOfDisplayModes(display, &count);
  //printf("%d\n", modeCount);
  if (argc == 2) {
    char* endp = argv[1];
    const int mode = strtol(argv[1], &endp, 10);
    if (*argv[1] == '\0' || *endp != '\0') {
      fprintf(stderr, "Error: mode should be integer: %s\n", argv[1]);
      return 1;
    }
    if (mode < 0 || count <= mode) {
      fprintf(stderr, "Error: mode should be 0-%d: %d\n", count - 1, mode);
      return 1;
    }
    CGDisplayConfigRef config;
    CGBeginDisplayConfiguration(&config);
    CGSConfigureDisplayMode(config, display, mode);
    CGCompleteDisplayConfiguration(config, kCGConfigurePermanently);
  }

  int currentMode;
  CGSGetCurrentDisplayMode(display, &currentMode);
  //printf("%d\n", currentMode);
  for (int i = 0; i < count; i++) {
    const int size = sizeof (CGSDisplayMode);
    CGSDisplayMode mode;
    CGSGetDisplayModeDescriptionOfLength(display, i, &mode, size);
    const char* mark = i == currentMode ? "(current)" : "";
    printf("mode %2d: %5d x %-5d %s\n",
           mode.modeNumber, mode.width, mode.height, mark);
  }
  return 0;
}