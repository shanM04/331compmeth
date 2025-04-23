void analyzeDY() {
    TFile *file = TFile::Open("DYJetsToLL.root");
    TTree *tree = (TTree*)file->Get("Events");

    Bool_t HLT_IsoMu24;
    Int_t PV_npvs;

    tree->SetBranchStatus("*", 0);
    tree->SetBranchStatus("HLT_IsoMu24", 1);
    tree->SetBranchStatus("PV_npvs", 1);
    tree->SetBranchAddress("HLT_IsoMu24", &HLT_IsoMu24);
    tree->SetBranchAddress("PV_npvs", &PV_npvs);

    // histogram
    TH1F *hPileup = new TH1F("hPileup", "Pileup Proxy (PV_npvs);Number of Primary Vertices;Events", 60, 0, 60);

    Long64_t nentries = tree->GetEntries();
    for (Long64_t i = 0; i < nentries; ++i) {
        tree->GetEntry(i);
        if (!HLT_IsoMu24) continue;

        hPileup->Fill(PV_npvs);
    }

    TCanvas *c = new TCanvas("c", "Pileup", 800, 600);
    hPileup->SetFillColor(kAzure+7);
    hPileup->Draw();
    c->SaveAs("pileupdist.png");
}
