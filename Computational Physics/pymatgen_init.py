# -*- coding: utf-8 -*-
"""
Created on Wed Sep 19 20:21:39 2018

@author: Jeran
"""

from pymatgen import MPRester
from pymatgen.analysis.pourbaix_diagram import PourbaixDiagram, PourbaixPlotter

mpr = MPRester("6ycZ7v9nGu4TsKlA")

# Get all pourbaix entries corresponding to the Ti-Ni-O-H chemical system.
entries = mpr.get_pourbaix_entries(["Ni", "W"])

# Construct the PourbaixDiagram object
pbx = PourbaixDiagram(entries, comp_dict={"Ni": 0.5, "W": 0.5},
                      conc_dict={"Ni": 1e-8, "W": 1e-8}, filter_solids=False)

# Get an entry stability as a function of pH and V

entry = [e for e in entries if e.entry_id == 'ion-0'][0]

plotter = PourbaixPlotter(pbx)

bivo4_entry = [entry for entry in entries if entry.entry_id=="ion-0"][0]
plt = plotter.plot_entry_stability(bivo4_entry)

#print(pbx.get_decomposition_energy(entry, pH=0, V=-0.85))

plt.show()
#plt = plotter.plot_entry_stability(entry)

