#include <TFile.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <iostream>
#include <fstream>

void plotHiggsMass() {
    TH1F* hMass = new TH1F("hMass", "Higgs Boson Mass Distribution;Mass (GeV);Events", 100, 120, 130);
    
    std::ifstream file("higgs_masses.dat");
    float mass;
    
    while (file >> mass) {
        hMass->Fill(mass);
    }
    
    TCanvas* c1 = new TCanvas("c1", "Higgs Mass Distribution", 800, 600);
    hMass->Draw();
    
    c1->SaveAs("hmassdist.png");
    
    double bwWidth = hMass->GetRMS();
    std::cout << "final Breit-Wigner width = " << bwWidth << " GeV" << std::endl;
}
