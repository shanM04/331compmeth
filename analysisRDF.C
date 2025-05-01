#include <ROOT/RDataFrame.hxx>
#include <TH1F.h>
#include <TFile.h>
#include <TCanvas.h>

void pileup_analysis_RDF(const char* filename = "DYJetsToLL.root") {
    ROOT::RDataFrame df("Events", filename);

    auto filtered_df = df.Filter("HLT_IsoMu24");
    auto h_pileup = filtered_df.Histo1D({"h_pileup", "Pileup Distribution;Number of Primary Vertices;Events", 50, 0, 100}, "PV_npvs");

    TCanvas c("c", "Pileup", 800, 600);
    h_pileup->Draw();
    c.SaveAs("pileupdistRDF.png");
}
