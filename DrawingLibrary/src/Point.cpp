// 
// 
// 
#include "Color.h"
#include "Point.h"

#ifndef _POINT_CPP
#define _POINT_CPP
//Arduino somehow redefines swap in Hardware_XXX_defines
template <class T> void swapIt(T& a, T& b)					{	T c(a); a = b; b = c; }

inline TwoValue::TwoValue()												{ V1 = 0;     V2 = 0; }
inline TwoValue::TwoValue(TwoValue const &p)							{ V1 = p.V1;  V2 = p.V2; }
inline TwoValue::TwoValue(TwoValueF const &p)							{ V1 = p.V1;  V2 = p.V2; }
inline TwoValue::TwoValue(int v1, int v2)								{ V1 = v1;    V2 = v2; }
inline TwoValue & TwoValue::operator=(const TwoValue & p)				{ V1 = p.V1;  V2 = p.V2;  return (*this); }
inline TwoValue & TwoValue::operator+=(const TwoValue & p)				{ V1 += p.V1; V2 += p.V2; return (*this); }
inline TwoValue & TwoValue::operator-=(const TwoValue & p)				{ V1 -= p.V1; V2 -= p.V2; return (*this); }
inline TwoValue & TwoValue::operator/=(const TwoValue & p)				{ V1 /= p.V1; V2 /= p.V2; return (*this); }
inline TwoValue & TwoValue::operator*=(const TwoValue & p)				{ V1 *= p.V1; V2 *= p.V2; return (*this); }
inline TwoValue & TwoValue::operator+=(int num)							{ V1 += num;  V2 += num; return (*this); }
inline TwoValue & TwoValue::operator-=(int num)							{ V1 -= num;  V2 -= num; return (*this); }
inline TwoValue & TwoValue::operator/=(int num)							{ V1 /= num;  V2 /= num; return (*this); }
inline TwoValue & TwoValue::operator*=(int num)							{ V1 *= num;  V2 *= num; return (*this); }
inline TwoValue TwoValue::operator+(const TwoValue & p)			const	{ return{ V1 + p.V1,V2 + p.V2 }; }
inline TwoValue TwoValue::operator-(const TwoValue & p)			const	{ return{ V1 - p.V1,V2 - p.V2 }; }
inline TwoValue TwoValue::operator*(const TwoValue & p)			const	{ return{ V1 * p.V1,V2 * p.V2 }; }
inline TwoValue TwoValue::operator/(const TwoValue & p)			const	{ return{ V1 / p.V1,V2 / p.V2 }; }
inline TwoValue TwoValue::operator+(int num)					const	{ return{ V1 + num, V2 + num }; }
inline TwoValue TwoValue::operator-(int num)					const	{ return{ V1 - num, V2 - num }; }
inline TwoValue TwoValue::operator*(int num)					const	{ return{ V1 * num, V2 * num }; }
inline TwoValue TwoValue::operator/(int num)					const	{ return{ V1 / num, V2 / num }; }
inline TwoValue::operator TwoValueF()							const	{ return{ (double)V1, (double)V1 }; }
inline TwoValue TwoValue::Swap()								const	{ return{ V2,V1 }; }
inline TwoValue &TwoValue::SwapMe()										{ swapIt(V1, V2); return (*this); }
inline int TwoValue::Diff()										const   { return V2 - V1; }
inline int TwoValue::AbsDiff()									const	{ return abs(Diff()); }
inline bool TwoValue::IsZeroDiff()								const	{ return V2 == V1; }

inline TwoValueF::TwoValueF()											{ V1 = 0;     V2 = 0; }
inline TwoValueF::TwoValueF(TwoValue const &p)							{ V1 = p.V1;  V2 = p.V2; }
inline TwoValueF::TwoValueF(TwoValueF const &p)							{ V1 = p.V1;  V2 = p.V2; }
inline TwoValueF::TwoValueF(double v1, double v2)						{ V1 = v1;    V2 = v2; }
inline TwoValueF & TwoValueF::operator=(const TwoValueF & p)			{ V1 = p.V1;  V2 = p.V2;  return (*this); }
inline TwoValueF & TwoValueF::operator+=(const TwoValueF & p)			{ V1 += p.V1; V2 += p.V2; return (*this); }
inline TwoValueF & TwoValueF::operator-=(const TwoValueF & p)			{ V1 -= p.V1; V2 -= p.V2; return (*this); }
inline TwoValueF & TwoValueF::operator/=(const TwoValueF & p)			{ V1 /= p.V1; V2 /= p.V2; return (*this); }
inline TwoValueF & TwoValueF::operator*=(const TwoValueF & p)			{ V1 *= p.V1; V2 *= p.V2; return (*this); }
inline TwoValueF & TwoValueF::operator+=(double num)					{ V1 += num;  V2 += num; return (*this); }
inline TwoValueF & TwoValueF::operator-=(double num)					{ V1 -= num;  V2 -= num; return (*this); }
inline TwoValueF & TwoValueF::operator/=(double num)					{ V1 /= num;  V2 /= num; return (*this); }
inline TwoValueF & TwoValueF::operator*=(double num)					{ V1 *= num;  V2 *= num; return (*this); }
inline TwoValueF TwoValueF::operator+(const TwoValueF & p)		const	{ return{ V1 + p.V1,V2 + p.V2 }; }
inline TwoValueF TwoValueF::operator-(const TwoValueF & p)		const	{ return{ V1 - p.V1,V2 - p.V2 }; }
inline TwoValueF TwoValueF::operator*(const TwoValueF & p)		const	{ return{ V1 * p.V1,V2 * p.V2 }; }
inline TwoValueF TwoValueF::operator/(const TwoValueF & p)		const	{ return{ V1 / p.V1,V2 / p.V2 }; }
inline TwoValueF TwoValueF::operator+(double num)				const	{ return{ V1 + num, V2 + num }; }
inline TwoValueF TwoValueF::operator-(double num)				const	{ return{ V1 - num, V2 - num }; }
inline TwoValueF TwoValueF::operator-()							const	{ return{ -V1, -V2 }; }
inline TwoValueF TwoValueF::operator*(double num)				const	{ return{ V1 * num, V2 * num }; }
inline TwoValueF TwoValueF::operator/(double num)				const	{ return{ V1 / num, V2 / num }; }
inline bool		 TwoValueF::IsEqualIncreasing()					const	{ return V1 >= V2; }
inline bool		 TwoValueF::IsEqualDecreasing()					const   { return V1 <= V2 ; }
inline TwoValueF TwoValueF::Floor()								const	{ return{ floor(V1),floor(V2) }; }
inline TwoValueF TwoValueF::FloorCeil()							const	
{ 
	if (IsEqualDecreasing())	return{ floor(V2),ceil(V1) };
	else						return{ floor(V1),ceil(V2) };
}
inline TwoValueF TwoValueF::Swap()								const	{ return { V2,V1 }; }
inline TwoValueF &TwoValueF::SwapMe()									{ swapIt(V1, V2); return (*this); }
inline TwoValueF::operator TwoValue()							const	{ return{ (int)V1, (int)V2 }; }
inline double TwoValueF::Diff()									const	{ return V2 - V1; }
inline double TwoValueF::AbsDiff()								const	{ return abs(Diff()); }
inline static TwoValueF TwoValueF::CombineV1(TwoValueF const &x, TwoValueF const &y)	{ return{ x.V1, y.V1 }; }
inline static TwoValueF TwoValueF::CombineV2(TwoValueF const &x, TwoValueF const &y)	{ return{ x.V2, y.V2 }; }

inline Point::Point()													{ X() = 0; Y() = 0; }
inline Point::Point(TwoValue const & val):  TwoValue(val)				{}
inline Point::Point(TwoValueF const & val): TwoValue(val)				{}
inline Point::Point(int x, int y)										{ X() =  x;		Y() =  y; }
inline Point & Point::operator=(const Point &p)							{ X() =  p.X();	Y() =  p.Y(); return (*this); }
inline Point & Point::operator%=(const Point & p)						{ X() -= p.X(), Y() += p.Y(); return (*this); }
inline Point   Point::operator%(const Point & p)				const	{ return{ X() - p.X(),Y() + p.Y() }; }
inline Point & Point::DecX(int xx = 1)									{ X() -= xx; return (*this); }
inline Point & Point::DecY(int yy = 1)									{ Y() -= yy; return (*this); }
inline Point & Point::IncX(int xx = 1)									{ X() += xx; return (*this); }
inline Point & Point::IncY(int yy = 1)									{ Y() += yy; return (*this); }
inline Point::operator PointF()											{ return{ (double)X(),(double)Y() }; }

inline PointF::PointF()													{ X() = 0; Y() = 0; }
inline PointF::PointF(TwoValue const & val)  : TwoValueF(val)			{}
inline PointF::PointF(TwoValueF const & val) : TwoValueF(val)			{}
inline PointF::PointF(double x, double y)								{ X() = x; Y() = y; }
inline PointF &PointF::DecX(double xx = 1)								{ X() -= xx; return (*this); }
inline PointF &PointF::DecY(double yy = 1)								{ Y() -= yy; return (*this); }
inline PointF &PointF::IncX(double xx = 1)								{ X() += xx; return (*this); }
inline PointF &PointF::IncY(double yy = 1)								{ Y() += yy; return (*this); }
inline PointF::operator Point()											{ return{ (int)X(), (int)Y() }; }

#endif

