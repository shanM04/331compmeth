TARGET=feyndiag3
BIBFILE=references.bib

all: $(TARGET).pdf

$(TARGET).pdf: $(TARGET).tex $(BIBFILE)
	lualatex $(TARGET).tex
	bibtex $(TARGET).tex
	lualatex $(TARGET).tex
	lualatex $(TARGET).tex

clean:
	rm -f *.aux *.log *.bbl *.blg *.out

cleanall: clean
	rm -f $(TARGET).pdf
