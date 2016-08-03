#ifndef _ADAFRUIT_GFX_H
#define _ADAFRUIT_GFX_H

#if ARDUINO >= 100
#include "Arduino.h"
#include "Print.h"
#else
#include "WProgram.h"
#endif

#include "gfxfont.h"

class Adafruit_GFX : public Print {

public:

     Adafruit_GFX(int16_t w, int16_t h); // Constructor

     // This MUST be defined by the subclass:
     virtual void drawPixel(int16_t x, int16_t y, uint16_t color) = 0;

     // These MAY be overridden by the subclass to provide device-specific
     // optimized code.  Otherwise 'generic' versions are used.

     /**
      * \brief Draw a line
      *
      * Start at (\p x0, \p y0), and draw a line to (\p x1, \p y1).  If \p color == 1, turn the pixels on.  Otherwise, turn them off.
      */
     virtual void    drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
#ifndef GTRON_ARDUINO_SKIP
     virtual void    drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
     virtual void    drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);

     /**
      * \brief Draw an hollow rectangle
      *
      * Start at (\p x0, \p y0), and draw a hollow rectangle \p w pixels wide
      * and \p h pixels wide.  
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     virtual void    drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
     /**
      * \brief Draw a filled rectangle
      *
      * Start at (\p x0, \p y0), and draw a filled rectangle \p w pixels wide
      * and \p h pixels wide.  
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     virtual void    fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);

     void fillScreen(uint16_t color);
     void invertDisplay(boolean i);

     // These exist only with Adafruit_GFX (no subclass overrides)
     /** 
      * \brief Draw a hollow circle.
      *
      * Draw it at (\p x, \p y) with radius \p r.
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

     void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);

     /** 
      * \brief Draw a filled circle.
      *
      * Draw it at (\p x, \p y) with radius \p r.
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);

     void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername,int16_t delta, uint16_t color);


     /** 
      * \brief Draw a hollow triangle.
      *
      * Draw it from (\p x0, \p y0) to  (\p x1, \p y1) to  (\p x2, \p y2).
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
     /** 
      * \brief Draw a filled triangle.
      *
      * Draw it from (\p x0, \p y0) to  (\p x1, \p y1) to  (\p x2, \p y2).
      *
      * If \p color == 1, turn the pixels on.
      * Otherwise, turn them off.
      */
     void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
#endif
     
#ifndef GTRON_ARDUINO_SKIP
     void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
     void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
     void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
     void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);
     void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
     void drawBitmap(int16_t x, int16_t y, uint8_t *bitmap, int16_t w, int16_t h, uint16_t color, uint16_t bg);
     void drawXBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
#endif

#ifndef GTRON_ARDUINO_SKIP
     void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
     void setCursor(int16_t x, int16_t y);
     void setTextColor(uint16_t c);
     void setTextColor(uint16_t c, uint16_t bg);
     void setTextSize(uint8_t s);
     void setTextWrap(boolean w);
     
     void setRotation(uint8_t r);
#endif

#ifndef GTRON_ARDUINO_SKIP
     void cp437(boolean x=true);
     void setFont(const GFXfont *f = NULL);
     void getTextBounds(char *string, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);
     void getTextBounds(const __FlashStringHelper *s, int16_t x, int16_t y, int16_t *x1, int16_t *y1, uint16_t *w, uint16_t *h);
#endif
     
#if ARDUINO >= 100
     virtual size_t write(uint8_t);
#else
     virtual void   write(uint8_t);
#endif

#ifndef GTRON_ARDUINO_SKIP
     int16_t height(void) const;
     int16_t width(void) const;

     uint8_t getRotation(void) const;

     // get current cursor position (get rotation safe maximum values, using: width() for x, height() for y)
     int16_t getCursorX(void) const;
     int16_t getCursorY(void) const;
#endif
     
protected:
     const int16_t
     WIDTH, HEIGHT;   // This is the 'raw' display w/h - never changes
     int16_t
     _width, _height, // Display w/h as modified by current rotation
	  cursor_x, cursor_y;
     uint16_t
     textcolor, textbgcolor;
     uint8_t
     textsize,
	  rotation;
     boolean
     wrap,   // If set, 'wrap' text at right edge of display
	  _cp437; // If set, use correct CP437 charset (default is off)
     GFXfont
     *gfxFont;
};

class Adafruit_GFX_Button {

public:
     Adafruit_GFX_Button(void);
     void initButton(Adafruit_GFX *gfx, int16_t x, int16_t y,
		     uint8_t w, uint8_t h, uint16_t outline, uint16_t fill,
		     uint16_t textcolor, char *label, uint8_t textsize);
     void drawButton(boolean inverted = false);
     boolean contains(int16_t x, int16_t y);

     void press(boolean p);
     boolean isPressed();
     boolean justPressed();
     boolean justReleased();

private:
     Adafruit_GFX *_gfx;
     int16_t _x, _y;
     uint16_t _w, _h;
     uint8_t _textsize;
     uint16_t _outlinecolor, _fillcolor, _textcolor;
     char _label[10];

     boolean currstate, laststate;
};

class GFXcanvas1 : public Adafruit_GFX {

public:
     GFXcanvas1(uint16_t w, uint16_t h);
     ~GFXcanvas1(void);
     void     drawPixel(int16_t x, int16_t y, uint16_t color),
	  fillScreen(uint16_t color);
     uint8_t *getBuffer(void);
private:
     uint8_t *buffer;
};

class GFXcanvas16 : public Adafruit_GFX {
     GFXcanvas16(uint16_t w, uint16_t h);
     ~GFXcanvas16(void);
     void      drawPixel(int16_t x, int16_t y, uint16_t color),
	  fillScreen(uint16_t color);
     uint16_t *getBuffer(void);
private:
     uint16_t *buffer;
};

#endif // _ADAFRUIT_GFX_H

