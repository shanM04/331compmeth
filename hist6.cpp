#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TAxis.h>
#include <iostream>

int main() {
    TFile *file = TFile::Open("randnos35.root");
    if (!file || !file->IsOpen()) {
        std::cerr << "error" << std::endl;
        return 1;
    }

    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cerr << "error: tree not found" << std::endl;
        return 1;
    }

    TH1D *hist = new TH1D("hist", "Random number distribution", 50, -5, 5);
    tree->Draw("randomNumber>>hist");

    TCanvas *canvas = new TCanvas("canvas", "Random Number Histogram", 800, 600);
    canvas->SetFillColor(kWhite);
    hist->SetLineColor(kBlack);
    hist->SetLineWidth(2);
    hist->SetFillColor(kYellow);
    hist->SetFillStyle(1001);

    hist->Draw();
    hist->GetXaxis()->SetTitle("random number");
    hist->GetYaxis()->SetTitle("frequency");

    TF1 *fit = new TF1("fit", "gaus", -5, 5);
    hist->Fit(fit);
    fit->Draw("same");

    canvas->Update();
    canvas->SaveAs("hist6.png");
    
    file->Close();
    return 0;
}
