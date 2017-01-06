// Point.h

#ifndef _POINT_h
#define _POINT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class PointF;
class Point;
class TwoValue; 
class TwoValueF;

struct TwoValue
{
	int V1;
	int V2;

	inline TwoValue();
	inline TwoValue(TwoValue const & p);
	inline TwoValue(TwoValueF const & p);
	inline TwoValue(int x, int y);
	inline TwoValue & operator=(const TwoValue & p);
	inline TwoValue & operator+=(const TwoValue & p);
	inline TwoValue & operator/=(const TwoValue & p);
	inline TwoValue & operator*=(const TwoValue & p);
	inline TwoValue & operator-=(const TwoValue & p);
	inline TwoValue & operator+=(int num);
	inline TwoValue & operator-=(int num);
	inline TwoValue & operator*=(int num);
	inline TwoValue & operator/=(int num);
	inline TwoValue operator-(const TwoValue & p) const;
	inline TwoValue operator+(const TwoValue & p) const;
	inline TwoValue operator/(const TwoValue & p) const;
	inline TwoValue operator*(const TwoValue & p) const;
	inline TwoValue operator-(int num) const;
	inline TwoValue operator+(int num) const;
	inline TwoValue operator*(int num) const;
	inline TwoValue operator/(int num) const;
	inline operator TwoValueF() const;
	inline TwoValue Swap() const;
	inline TwoValue & SwapMe();
	inline bool IsZeroDiff() const;
	inline int Diff() const;
	inline int AbsDiff() const; 
};

struct TwoValueF
{
public:
	double V1;
	double V2;

	inline TwoValueF();
	inline TwoValueF(TwoValue const & p);
	inline TwoValueF(TwoValueF const & p);
	inline TwoValueF(double x, double y);
	inline TwoValueF & operator=(const TwoValueF & p);
	inline TwoValueF & operator+=(const TwoValueF & p);
	inline TwoValueF & operator/=(const TwoValueF & p);
	inline TwoValueF & operator*=(const TwoValueF & p);
	inline TwoValueF & operator-=(const TwoValueF & p);
	inline TwoValueF & operator+=(double num);
	inline TwoValueF & operator-=(double num);
	inline TwoValueF & operator*=(double num);
	inline TwoValueF & operator/=(double num);
	inline TwoValueF operator-(const TwoValueF & p) const;
	inline TwoValueF operator+(const TwoValueF & p) const;
	inline TwoValueF operator/(const TwoValueF & p) const;
	inline TwoValueF operator*(const TwoValueF & p) const;
	inline TwoValueF operator-(double num) const;
	inline TwoValueF operator-() const;
	inline TwoValueF operator+(double num) const;
	inline TwoValueF operator/(double num) const;
	inline TwoValueF operator*(double num) const;

	inline bool IsEqualIncreasing() const;
	inline bool IsEqualDecreasing() const;
	inline TwoValueF Floor() const;
	inline TwoValueF FloorCeil() const;
	inline TwoValueF Swap() const;
	inline TwoValueF &SwapMe();
	inline operator TwoValue() const;
	inline double Diff() const;
	inline double AbsDiff() const;

	inline static TwoValueF CombineV1(TwoValueF const &x, TwoValueF const &y);
	inline static TwoValueF CombineV2(TwoValueF const &x, TwoValueF const &y);

};


struct Point : public TwoValue
{
	inline Point();
	inline Point(TwoValue const &val);
	inline Point(TwoValueF const &val);
	inline Point(int x, int y);
	inline Point &operator=(const Point &p);
	inline Point &operator%=(const Point &p);
	inline Point operator%(const Point & p) const;
	inline Point & DecX(int xx = 1);
	inline Point & DecY(int yy = 1);
	inline Point & IncX(int xx = 1);
	inline Point & IncY(int yy = 1);
	inline operator PointF();
	
	inline int & X() { return V1; }
	inline int & Y() { return V2; }
};

struct PointF : public TwoValueF
{
	inline PointF();
	inline PointF(TwoValue const &val);
	inline PointF(TwoValueF const &val);
	inline PointF(double x, double y);
	inline operator Point();
	inline PointF & DecX(double xx = 1);
	inline PointF & DecY(double yy = 1);
	inline PointF & IncX(double xx = 1);
	inline PointF & IncY(double yy = 1);

	inline double & X() { return V1; }
	inline double & Y() { return V2; }
};

#define PointArrayCount(PointArray)			(sizeof(PointArray)/sizeof(Point))
#define PointFArrayCount(PointFArray)		(sizeof(PointFArray)/sizeof(PointF))

#include "Point.cpp"
#endif

