// Color.h

#ifndef _COLOR_h
#define _COLOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
struct ColorF;
struct Color;

struct Color
{
	byte  R;     //RED
	byte  G;     //GREEN
	byte  B;     //BLUE

	inline Color() ;
	inline Color(Color const & color);
	inline Color(ColorF const & color);
	inline Color(byte  r, byte  g, byte  b);
	inline Color(uint16_t col) 
	{ 
		R = (col >> 8 ) & 0xF8;
		G = (col >> 3 ) & 0xFC; 
		B = (col << 3 ) & 0xF8;
	}
	inline bool operator==(Color const &color)   const;
	inline bool operator!=(Color const &color)   const;
	inline bool operator!=(ColorF const &color)   const;
	inline Color &operator=(Color const &color); 
	inline Color &operator+=(Color const &color);
	inline Color &operator-=(Color const &color);
	inline Color &operator/=(Color const &color);
	inline Color &operator*=(Color const &color);
	inline Color operator-(Color const &color)  const;
	inline Color operator+(Color const &color)  const;
	inline Color operator/(Color const &color)  const;
	inline Color operator*(Color const &color)  const;
	inline ColorF operator-(ColorF const &color)  const;
	inline ColorF operator+(ColorF const &color)  const;
	inline ColorF operator/(ColorF const &color)  const;
	inline ColorF operator*(ColorF const &color)  const;
	inline Color operator+(byte num) const;
	inline Color operator-(byte num) const;
	inline Color operator*(byte num) const;
	inline Color operator/(byte num) const;
	inline ColorF operator+(double num) const;
	inline ColorF operator-(double num) const;
	inline ColorF operator*(double num) const;
	inline ColorF operator/(double num) const;
	//inline operator ColorF()  const;
	inline uint16_t ToRGB16() const;
	inline bool IsBlack() const;
	inline void Zero() ;
};

struct ColorF
{
	double  R;     //RED
	double  G;     //GREEN
	double  B;     //BLUE

	inline ColorF();
	inline ColorF(Color const & color);
	inline ColorF(ColorF const & color);
	inline ColorF(double r, double g, double b);

	inline bool operator==(ColorF const &color)   const;
	inline ColorF & operator=(ColorF const &color);
	inline ColorF & operator+=(ColorF const &color);
	inline ColorF & operator-=(ColorF const &color);
	inline ColorF & operator/=(ColorF const &color);
	inline ColorF & operator*=(ColorF const &color);

	inline ColorF & operator+=(double const num);
	inline ColorF & operator-=(double const num);
	inline ColorF & operator*=(double const num);
	inline ColorF & operator/=(double const num);

	inline ColorF operator-(ColorF const &color)  const;
	ColorF operator-() const;
	inline ColorF operator+(ColorF const &color)  const;
	inline ColorF operator/(ColorF const &color)  const;
	inline ColorF operator*(ColorF const &color)  const;

	inline ColorF operator+(double const num)  const;
	inline ColorF operator-(double const num)  const;
	inline ColorF operator*(double const num)  const;
	inline ColorF operator/(double const num)  const;
	//inline operator Color()  const;
	inline bool IsBlack() const;
	inline ColorF Abs() const;
	inline double MaxValue() const;
	inline uint16_t ToRGB16() const;
	inline void Zero();
};

#include "Color.cpp"

#endif

