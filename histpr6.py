import ROOT

def plotwfit():
    file = ROOT.TFile("randnos35.root")
    if not file or not file.IsOpen():
        print("error - cannot open file.")
        return
    
    tree = file.Get("tree")
    if not tree:
        print("error. tree not found")
        return

    hist = ROOT.TH1D("hist", "Random number distribution", 50, -5, 5)
    tree.Draw("randomNumber>>hist")

    canvas = ROOT.TCanvas("canvas", "Random number histogram", 800, 600)
    canvas.SetFillColor(ROOT.kWhite)

    hist.SetLineColor(ROOT.kBlack)
    hist.SetLineWidth(2)
    hist.SetFillColor(ROOT.kYellow)
    hist.SetFillStyle(1001)
    hist.Draw()

    hist.GetXaxis().SetTitle("random number value")
    hist.GetYaxis().SetTitle("frequency")

    fit = ROOT.TF1("fit", "gaus", -5, 5)
    hist.Fit(fit)

    fit.Draw("same")
    canvas.Update()
    canvas.SaveAs("histpr6.png")
    file.Close()

if __name__ == "__main__":
    plotwfit()
