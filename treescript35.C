#include <TFile.h>
#include <TTree.h>
#include <TRandom3.h>
#include <iostream>

void gennormrands() {
    const int N = 1000;  // Number of random numbers
    TRandom3 randGen;    // Random number generator (TRandom3)

    // Create a new ROOT file to save the tree
    TFile *file = new TFile("randnos35.root", "RECREATE");

    // Check if the file was opened successfully
    if (!file->IsOpen()) {
        std::cout << "error" << std::endl;
        return;
    }
    std::cout << "no problem" << std::endl;

    // Create a TTree with a branch to store the random number
    TTree *tree = new TTree("tree", "tree w/ normal random numbers");
    double randomNumber;  // Variable to store the generated random number
    tree->Branch("randomNumber", &randomNumber, "randomNumber/D");

    // Generate N random numbers and fill the tree
    for (int i = 0; i < N; ++i) {
        randomNumber = randGen.Gaus(0, 1);  // Generate normally distributed number (mean=0, sigma=1)
        tree->Fill();
        
        // Print progress every 100 iterations
        if (i % 100 == 0) {
            std::cout  << i << "th number..." << std::endl;
        }
    }

    // Write the tree to the file
    tree->Write();
    std::cout << "tree written to file." << std::endl;
    
    // Close the file
    file->Close();
    std::cout << "closed." << std::endl;
}

