# -*- coding: utf-8 -*-
"""
Created on Thu Nov  8 00:58:40 2018

@author: Jeran
"""

from scipy import misc
import imageio
import numpy as np
from skimage import data

import matplotlib.pyplot as plt

#from skimage import data


#face=misc.face()

im = imageio.imread('S31 cut face 5k_002-CROP.png')
#im = imageio.imread('S14 outisde face 5k PNG.png')
#im = imageio.imread('ANV outside face intersection point_001 PNG.png')

#im = imageio.imread('S2 DB NiTi raw Sanded 600p 26-04-2018 PNG.png')
#print(im.shape)
#imInt = im.astype(int)
#x,y,z = im.shape

#im[:] = im.mean(axis=-1, keepdims=1)

#plt.figure(figsize=(10,20))
#plt.imshow(im)
imData = im[: , :, 2]
imBin = imData.astype(int)

#print(im[ 0 , 1 , 0])
#print(imBin.mean())
#print(im[255:256])
for i in range(0, imBin.shape[1]):
    bindat += np.bincount(imBin[ : , i], minlength=256)
#bindat += np.bincount(imBin[ : , 1], minlength=256)

#print(bindat.max())
#plt.imshow(imData)
bin_counts, bin_edges, patches = plt.hist(im.ravel(), 256)
plt.ylim(0, 80000)


#print(bindat)


#print(bindat)
#plt.plot(x,y)
