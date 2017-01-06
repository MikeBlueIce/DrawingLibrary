// 
// 
// 
#include "Color.h"

#ifndef _COLOR_CPP
#define _COLOR_CPP

inline Color::Color()											{ R = 0; G = 0; B = 0; }
inline Color::Color(Color const & color)						{ R = color.R; G = color.G; B = color.B; }
inline Color::Color(ColorF const & color)						{ R = (byte)color.R; G = (byte)color.G; B = (byte)color.B; }
inline Color::Color(byte r, byte g, byte b)						{ R = r; G = g; B = b; }
inline bool Color::operator==(Color const &color)		const	{ return (R == color.R && G == color.G && B == color.B); }
inline bool Color::operator!=(Color const & color)		const	{ return (R != color.R || G != color.G || B != color.B); }
inline bool Color::operator!=(ColorF const & color)		const	{ return (R != (byte)color.R || G != (byte)color.G || B != (byte)color.B); }

inline Color &Color::operator=(Color const &color)				{ R = color.R; G = color.G; B = color.B; return *this; }
inline Color &Color::operator+=(Color const &color)				{ R += color.R; G += color.G; B += color.B; return *this; }
inline Color &Color::operator-=(Color const &color)				{ R -= color.R; G -= color.G; B -= color.B; return *this; }
inline Color &Color::operator/=(Color const &color)				{ R /= color.R; G /= color.G; B /= color.B; return *this; }
inline Color &Color::operator*=(Color const &color)				{ R *= color.R; G *= color.G; B *= color.B; return *this; }

inline Color Color::operator-(Color const & color)		const	{ return{ R - color.R,G - color.G,B - color.B }; }
inline Color Color::operator+(Color const & color)		const	{ return{ R + color.R,G + color.G,B + color.B }; }
inline Color Color::operator/(Color const & color)		const	{ return{ R / color.R,G / color.G,B / color.B }; }
inline Color Color::operator*(Color const & color)		const	{ return{ R * color.R,G * color.G,B * color.B }; }

inline ColorF Color::operator-(ColorF const & color)	const	{ return { (double)R - (double)color.R,(double)G - (double)color.G,(double)B - (double)color.B }; }
inline ColorF Color::operator+(ColorF const & color)	const	{ return { (double)R + (double)color.R,(double)G + (double)color.G,(double)B + (double)color.B }; }
inline ColorF Color::operator/(ColorF const & color)	const	{ return { (double)R / (double)color.R,(double)G / (double)color.G,(double)B / (double)color.B }; }
inline ColorF Color::operator*(ColorF const & color)	const	{ return { (double)R * (double)color.R,(double)G * (double)color.G,(double)B * (double)color.B }; }

inline Color Color::operator-(byte num)					const	{ return ((ColorF)(*this)) - num; }
inline Color Color::operator+(byte num)					const	{ return ((ColorF)(*this)) + num; }
inline Color Color::operator/(byte num)					const	{ return ((ColorF)(*this)) / num; }
inline Color Color::operator*(byte num)					const	{ return ((ColorF)(*this)) * num; }


inline ColorF Color::operator-(double num)				const	{ return ((ColorF)(*this)) - num; }
inline ColorF Color::operator+(double num)				const	{ return ((ColorF)(*this)) + num; }
inline ColorF Color::operator/(double num)				const	{ return ((ColorF)(*this)) / num; }
inline ColorF Color::operator*(double num)				const	{ return ((ColorF)(*this)) * num; }

inline uint16_t Color::ToRGB16()						const	{ return ((R & 0xF8) << 8) | ((G & 0xFC) << 3) | ((B & 0xF8) >> 3);}

inline bool	Color::IsBlack()							const	{ return ((R == 0) && (G == 0) && (B == 0));}
inline void	Color::Zero()										{ R = 0; G = 0;  B = 0; }

//inline Color::operator ColorF()							const	{ return { (double)R,(double)G,(double)B }; }

inline ColorF::ColorF()											{ R = 0; G = 0; B = 0; }
inline ColorF::ColorF(Color const & color)						{ R = color.R; G = color.G; B = color.B; }
inline ColorF::ColorF(ColorF const & color)						{ R = color.R; G = color.G; B = color.B; }
inline ColorF::ColorF(double r, double g, double b)				{ R = r; G = g; B = b; }

inline bool ColorF::operator==(ColorF const &col)		const	{ return (R == col.R && G == col.G && B == col.B); }
inline ColorF &ColorF::operator=(ColorF const &col)				{ R = col.R; G = col.G; B = col.B; return *this; }
inline ColorF &ColorF::operator+=(ColorF const &col)			{ R += col.R; G += col.G; B += col.B; return *this; }
inline ColorF &ColorF::operator-=(ColorF const &col)			{ R -= col.R; G -= col.G; B -= col.B; return *this; }
inline ColorF &ColorF::operator/=(ColorF const &col)			{ R /= col.R; G /= col.G; B /= col.B; return *this; }
inline ColorF &ColorF::operator*=(ColorF const &col)			{ R *= col.R; G *= col.G; B *= col.B; return *this; }

inline ColorF &ColorF::operator+=(double const num)				{ R += num; G += num; B += num; return *this; }
inline ColorF &ColorF::operator-=(double const num)				{ R -= num; G -= num; B -= num; return *this; }
inline ColorF &ColorF::operator/=(double const num)				{ R /= num; G /= num; B /= num; return *this; }
inline ColorF &ColorF::operator*=(double const num)				{ R *= num; G *= num; B *= num; return *this; }

inline ColorF ColorF::operator+(ColorF const &col)		const	{ return { R + col.R, G + col.G, B + col.B }; }
inline ColorF ColorF::operator-(ColorF const &col)		const	{ return { R - col.R, G - col.G, B - col.B }; }
inline ColorF ColorF::operator-()						const	{ return { -R, -G , -B}; }
inline ColorF ColorF::operator/(ColorF const &col)		const	{ return { R / col.R, G / col.G, B / col.B }; }
inline ColorF ColorF::operator*(ColorF const &col)		const	{ return { R * col.R, G * col.G, B * col.B }; }

inline ColorF ColorF::operator+(double const num)		const	{ return { R + num, G + num, B + num }; }
inline ColorF ColorF::operator-(double const num)		const	{ return { R - num, G - num, B - num }; }
inline ColorF ColorF::operator*(double const num)		const	{ return { R * num, G * num, B * num }; }
inline ColorF ColorF::operator/(double const num)		const	{ return { R / num, G / num, B / num }; }

inline bool ColorF::IsBlack()							const	{ return !((R > 0) || (G > 0) || (B > 0) || (R < 0) || (G < 0) || (B < 0)); }
inline ColorF ColorF::Abs()								const	{ return { abs(R), abs(G), abs(B) };}
inline double ColorF::MaxValue()						const	{ return max(R,max(G,B)); }
inline void ColorF::Zero()										{ R = 0; G = 0;  B = 0; }
inline uint16_t ColorF::ToRGB16()						const	{ return Color(*this).ToRGB16(); }

//inline ColorF::operator Color()							const	{ return{ (byte)R,(byte)G,(byte)B }; }

#endif

