void hdplot7() {

    const int n = 11;
    double mass[n], width[n];

    ifstream infile("higgswidths.dat");

    for (int i = 0; i < n; ++i) {
        infile >> mass[i] >> width[i];
    }

    TGraph *graph = new TGraph(n, mass, width);

    graph->SetTitle("Higgs Decay Width");
    graph->GetXaxis()->SetTitle("Mass (GeV)");
    graph->GetYaxis()->SetTitle("Decay Width (GeV)");

    graph->Draw("ALP");
}
