#include <iostream>
#include "MET.h"

int main() {

	MET met(10.0,20.0);

	std::cout << "MET value: " << met.getMET() << std::endl;
 	std::cout << "MET x component: " << met.getMetX() << std::endl;
	std::cout << "MET y component: " << met.getMetY() << std::endl;
	std::cout << "MET phi: " << met.getPhi() << std::endl;

	return 0;
}
