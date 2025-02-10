#ifndef TRACK4_H
#define TRACK4_H

#include <cmath>

class track4{
private:
	double px, py, pz, E;

public:
	track4(double px, double py, double pz, double E);

	double pt() const;
	double eta() const;
};

#endif // TRACK4_H
