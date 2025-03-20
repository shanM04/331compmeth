#include "Pythia8/Pythia.h"

using namespace Pythia8;

int main() {
    Pythia pythia;

    pythia.readFile("params8.cmnd");

    if (!pythia.init()) {
	std::cout <<"this did not work" << std::endl;
	return 1;
}

    double higgs_mass = 125.0;
    pythia.particleData.m0(25, higgs_mass);

    double width = pythia.particleData.mWidth(25);

    printf("%.9f\n", width);
    return 0;
}
