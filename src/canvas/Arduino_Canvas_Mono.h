#include "../Arduino_DataBus.h"
#if !defined(LITTLE_FOOT_PRINT)

#ifndef _ARDUINO_CANVAS_MONO_H_
#define _ARDUINO_CANVAS_MONO_H_

#include "../Arduino_GFX.h"

class Arduino_Canvas_Mono : public Arduino_GFX
{
public:
  Arduino_Canvas_Mono(int16_t w, int16_t h, Arduino_G *output, int16_t output_x = 0, int16_t output_y = 0, bool verticalByte = false);
  ~Arduino_Canvas_Mono();

  bool begin(int32_t speed = GFX_NOT_DEFINED) override;
  void writePixelPreclipped(int16_t x, int16_t y, uint16_t color) override;
  void flush(bool force_flush = false) override;

  uint8_t *getFramebuffer();

protected:
  uint8_t *_framebuffer = nullptr;
  Arduino_G *_output = nullptr;
  int16_t _output_x, _output_y;
  bool _verticalByte;
  int16_t _canvas_width, _canvas_height;  // width and height of canvas buffer

private:
};

#endif // _ARDUINO_CANVAS_MONO_H_

#endif // !defined(LITTLE_FOOT_PRINT)
