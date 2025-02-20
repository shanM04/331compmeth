#include <TFile.h>
#include <TTree.h>
#include <TH1D.h>
#include <TCanvas.h>
#include <TF1.h>
#include <TAxis.h>
#include <iostream>

void plotwfit() {
    TFile *file = TFile::Open("randnos35.root");
    if (!file || file->IsOpen() == false) {
        std::cerr << "error" << std::endl;
        return;
    }
    TTree *tree = (TTree*)file->Get("tree");
    if (!tree) {
        std::cerr << "tree not found" << std::endl;
        return;
    }

    TH1D *hist = new TH1D("hist", "random number distribution", 50, -5, 5);  // 50 bins, range [-5, 5]

    tree->Draw("randomNumber>>hist");

    TCanvas *canvas = new TCanvas("canvas", "random number histogram", 800, 600);

    canvas->SetFillColor(kWhite);
    hist->SetLineColor(kBlack);
    hist->SetLineWidth(2);
    hist->SetFillColor(kYellow);
    hist->SetFillStyle(1001);

    hist->Draw();

    hist->GetXaxis()->SetTitle("Random Number Value");
    hist->GetYaxis()->SetTitle("Frequency");

    TF1 *fit = new TF1("fit", "gaus", -5, 5);
    hist->Fit(fit);

    fit->Draw("same");
    canvas->Update();

    canvas->SaveAs("hist5.png");
    file->Close();
}
