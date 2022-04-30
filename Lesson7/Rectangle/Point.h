#ifndef POINT_H
#define POINT_H

class Point{
public:
	explicit Point(double=0, double=0);
	void setX(const double&);
	void setY(const double&);
	double getX() const;
	double getY() const;
	const double& checkPoint(const double&);
private:
	double x;
	double y;
};

#endif
