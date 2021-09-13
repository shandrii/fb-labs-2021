import osgeo.gdal as gdal
import glob
import numpy 
import numpy as np

inPath = "/home/sofi/gdalenv/task/"


import rasterio

src2 = rasterio.open(inPath +"3.tif")
#reading

array = src2.read()
print (array.shape)


for i in range(0, array.shape[0]):
	array[i] = array[i].astype(float)

#array = array.astype(float)

xsize = array.shape[1]
ysize = array.shape[2]

#нормалізація

for col in range(0, ysize):
    for row in range(0, xsize):
    	if array[0:12,row,col].all()!=0:
    		array[0:12,row,col] = (array[0:12,row,col] - np.min(array[0:12,row,col]))/(np.max(array[0:12,row,col])-np.min(array[0:12,row,col]))
    	
   		
for col in range(0, ysize):
    for row in range(0, xsize):
    	if array[12:,row,col].all()!=0:
    		array[12:,row,col] = (array[12:,row,col] - np.min(array[12:,row,col]))/(np.max(array[12:,row,col])-np.min(array[12:,row,col]))
    	
	
bands = []
bands1 = []


#шукаю індекси
for col in range(0, ysize):
    for row in range(0, xsize):
    	
    	if array[0:12,row,col].all()!=0:
    		
	    	bands.append(numpy.nonzero(array[0:12,row, col])[0][0])
	 
	    	bands1.append(numpy.nonzero(array[0:12,row, col])[0][-1])
	    	
	
    	else:
    		bands.append(-999)
    		bands1.append(-999)	  


print(len(bands))
i = 0      
#віднімаю від ЛАІ вофост з індексом-1 першого ненульового каналу	
for col in range(0, ysize):
    for row in range(0, xsize):
    	if bands[i]!=-999:
    		array[12:,row,col]= array[12:,row,col] - array[bands[i]-1,row,col]
    		i = i+1
#віднімаю від   ЛАІ вофост
for col in range(0, ysize):
    for row in range(0, xsize):
    	array[12:,row, col] = array[12:,row, col] - array[0:12,row, col]
#віднімаю від    вофост ЛАІ
for col in range(0, ysize):
    for row in range(0, xsize):
    	array[0:12,row, col] = array[0:12,row, col] - array[12:,row, col]
    	

    	
#рахую суму для пікселів    	
rez1 = numpy.zeros(shape=(array.shape[1],array.shape[2]))
rez2 = numpy.zeros(shape=(array.shape[1],array.shape[2]))
for col in range(0, ysize):
    for row in range(0, xsize):
    	rez1[row,col] = numpy.sum(array[0:12,row, col])
    	rez2[row,col] = numpy.sum(array[12:,row, col])

for band in range(0, 24):		
	for col in range(0,ysize:
		for row in range(0,xsize):
			if array[band,row,col]<=0:
				array[band,row,col] = -999   	


#маскую 0 і менше 0 
rez1[rez1==0] = -999
rez1[rez1<0] = -999

rez2[rez2==0] = -999
rez2[rez2<0] = -999
