#include "Pythia8/Pythia.h"
#include <iostream>
#include <fstream>

using namespace Pythia8;

int main() {
    Pythia pythia;
    pythia.readFile("params9.cmnd");
    pythia.init();

    std::ofstream outFile("muondata9.txt");

    for (int i = 0; i < pythia.mode("Main:numberOfEvents"); ++i) {
        if (!pythia.next()) continue;

        for (int j = 0; j < pythia.event.size(); ++j) {
            if (abs(pythia.event[j].id()) == 13) { // Muons only
                double pT = pythia.event[j].pT();
                double eta = pythia.event[j].eta();
                outFile << pT << " " << eta << "\n";
            }
        }
    }

    outFile.close();
    return 0;
}
