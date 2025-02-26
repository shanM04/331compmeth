#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include <iostream>

int main() {
    TFile *file = new TFile("randnos35.root", "RECREATE");
    if (!file || !file->IsOpen()) {
        std::cerr << "error" << std::endl;
        return 1;
    }

    std::cout << "no error" << std::endl;

    TTree *tree = new TTree("tree", "Tree of random numbers");
    Double_t randomNumber;
    tree->Branch("randomNumber", &randomNumber, "randomNumber/D");

    TRandom3 randGen;
    randGen.SetSeed(0);

    std::cout << "generating 1000 random numbers..." << std::endl;
    for (int i = 0; i < 1000; ++i) {
        randomNumber = randGen.Gaus(0, 1);
        tree->Fill();
        if (i % 100 == 0) {
            std::cout << i << " random numbers generated." << std::endl;
        }
    }

    std::cout << "done." << std::endl;
    file->Write();
    file->Close();
    std::cout << "tree written and file closed." << std::endl;

    return 0;
}
