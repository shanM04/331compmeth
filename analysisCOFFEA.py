import coffea
from coffea import processor
from coffea import run
import matplotlib.pyplot as plt

class PileupProcessor(processor.ProcessorABC):
    def __init__(self):
        self.columns = ["PV_npvs"]
        self.hist = processor.Histogram(
            "pileup", 
            [50, 0, 100], 
            title="Pileup Distribution;Number of Primary Vertices;Events"
        )

    def process(self, events):
        selected_events = events[events.HLT_IsoMu24]

        self.hist.fill(PV_npvs=selected_events.PV_npvs)
        return { "pileup": self.hist }

    def postprocess(self, accumulator):
        return accumulator

files = ['DYJetsToLL.root']
processor_instance = PileupProcessor()

output = processor.run(files, processor_instance)

output["pileup"].plot()
plt.show()
