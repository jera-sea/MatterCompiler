# -*- coding: utf-8 -*-
"""
Created on Wed Sep 19 20:21:39 2018

@author: Jeran
"""

from pymatgen import MPRester
from pymatgen.analysis.pourbaix_diagram import PourbaixDiagram, PourbaixPlotter

mpr = MPRester("6ycZ7v9nGu4TsKlA")

# Get all pourbaix entries corresponding to the Ti-Ni-O-H chemical system.
entries = mpr.get_pourbaix_entries(["Ni", "Ti"])

# Construct the PourbaixDiagram object
pbx = PourbaixDiagram(entries, comp_dict={"Ni": 0.5, "Ti": 0.5},
                      conc_dict={"Ni": 1e-8, "Ti": 1e-8}, filter_solids=False)

# Get an entry stability as a function of pH and V
#for e in entries:
#    print(e)
    
entry = [e for e in entries if e.entry_id == 'ion-8'][0] #ion-8 is ti++, mp-10257 is Ni(s)


plotter = PourbaixPlotter(pbx)

bivo4_entry = [entry for entry in entries if entry.entry_id=="ion-8"][0]
plt = plotter.plot_entry_stability(bivo4_entry)

#print(pbx.get_decomposition_energy(entry, pH=0, V=-0.85))
plt.title("Ti2+ Stability Range", fontsize=50)
plt.subplots_adjust(top=0.95)

plt.tight_layout()
plt.show(figsize = (20, 15))
#plt = plotter.plot_entry_stability(entry)

