# -*- coding: utf-8 -*-
"""
Created on Thu Sep 20 18:09:50 2018

@author: Jeran
"""

from pymatgen import MPRester, Composition
from pymatgen.analysis.phase_diagram import PhaseDiagram
from pymatgen.entries.computed_entries import ComputedEntry
from pymatgen.apps.borg.hive import VaspToComputedEntryDrone
from pymatgen.entries.compatibility import MaterialsProjectCompatibility
from pymatgen.analysis.phase_diagram import ReactionDiagram, PDPlotter, PDEntry

mp = MPRester("6ycZ7v9nGu4TsKlA")
compat = MaterialsProjectCompatibility()
chemsys = ["H", "P", "V","O", "C"]

all_entries = mp.get_entries_in_chemsys(chemsys)