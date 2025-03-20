#include "Pythia8/Pythia.h"
#include <fstream>
using namespace Pythia8;

int main() {
    std::ofstream output_file("higgs_masses.dat");

    Pythia pythia;
    
    pythia.readFile("params28.cmnd");

    if (!pythia.init()) return 1;

    for (int n_event = 0; n_event < 1000; n_event++) {
        if (!pythia.next()) continue;

        if (n_event % 100 == 0) {
            std::cout << "Simulating event number " << n_event << " of 1000" << std::endl;
        }

        for (int i = 0; i < pythia.event.size(); i++) {
            if (pythia.event[i].id() == 25) {
                double higgs_mass = pythia.event[i].m();
                output_file << higgs_mass << "\n";
            }
        }
    }

    output_file.close();

    return 0;
}
