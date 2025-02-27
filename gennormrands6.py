import ROOT

def gennormrands():
    file = ROOT.TFile("randnos35.root", "RECREATE")
    
    if not file or not file.IsOpen():
        print("error")
        return

    print("no error")
    tree = ROOT.TTree("tree", "Tree of random numbers")
    randomNumber = ROOT.std.vector('double')()
    tree.Branch("randomNumber", randomNumber)

    randGen = ROOT.TRandom3()
    randGen.SetSeed(0)

    print("generating 1000 random numbers...")
    
    for i in range(1000):
        randomNumber.clear()
        randomNumber.push_back(randGen.Gaus(0, 1))
        tree.Fill()
        if i % 100 == 0:
            print(f"{i} random numbers generated.")

    file.Write()
    file.Close()
    print("tree written and file closed.")


if __name__ == "__main__":
    gennormrands()
