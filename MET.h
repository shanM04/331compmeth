#ifndef MET_H
#define MET_H

#include <cmath>

class MET{
private:
	double xmet;
	double ymet;
public:
	MET(double x, double y): xmet(x), ymet(y) {}
	double getMET() const{
		return std::sqrt(xmet*xmet + ymet*ymet);
	}
	double getMetX() const{
		return xmet;
	}
	double getMetY() const{
		return ymet;
	}
	double getPhi() const{
		return std::atan2(ymet, xmet);
	}
};

#endif
