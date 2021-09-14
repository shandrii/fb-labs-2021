#!/usr/bin/env python
# coding: utf-8

# In[408]:


#text prepare

import regex 
import collections
import unicodedata
text = open("/home/sofi/1.txt").read()
text = text.lower()
text = text.replace("n","")
text = text.replace("\n"," ")
text = ' '.join(text.split())

import re
#without space
newstring = ''.join(c for c in text if unicodedata.category(c).startswith('L'))

#with space
#newstring = regex.sub(r'[^\w\s]+|[\d]+', r'',text).strip()

word = sorted(newstring)
print(newstring)
print("OK")


# In[409]:


#Count
alp = []    
for i in range(0,len(word)):
    alp.append(word[i])

alpcount = dict(collections.Counter(alp))
print(alpcount)
print("\n")
freq = {k: alpcount[k] / len(word) for k in alpcount}
print(freq)


# In[410]:


#print count
sot = sorted(alpcount, key=lambda x : alpcount[x],reverse=1) 

temp = []
for i in range(0,len(sot)):
    temp.append(alpcount[sot[i]])

data = pd.DataFrame(index = sot)
data['count'] = temp
print(data.head(10))
data.to_excel("bukws.xlsx")


# In[411]:


#print freq
fr= sorted(freq, key=lambda x : alpcount[x],reverse=1) 

temp = []
for i in range(0,len(sot)):
    temp.append(freq[sot[i]])
   
data2 = pd.DataFrame(index = sot)
data2['freq'] = temp
data2.head()
data2.to_excel("freq.xlsx")


# In[403]:


#Bigram
text = newstring
bigram = []
bigramtwo = []
for j in range(0, len(text)-1):
    bigram.append(text[j]+text[j+1])
    
for j in range(0, len(text)-2,2):
    bigramtwo.append(text[j]+text[j+1])

from collections import Counter
bigramcount = dict(Counter(bigram))

freqbigram = {k: bigramcount[k] / len(bigram) for k in bigramcount}

bigramtwocount = dict(Counter(bigramtwo))
freqbigramtwo = {k: bigramtwocount[k] / len(bigramtwo) for k in bigramtwocount}


# In[393]:


print(freqbigram[bigram[1]])
print(bigram[1])


# In[404]:


#H1
import math
h1 = []
for f in freq.values():
    h1.append(f*math.log(f,2))
h1 = sorted(h1)
print(h1)
H1 = -sum(h1)    
print(H1) 


# In[405]:


#H2
def H(bigram,freqbigram):
    hn = []
    for f in freqbigram.values():
        hn.append(f*math.log(f,2))
    hn = sorted(hn)
    H = -sum(hn)/2
    return H
  
H2 = H(bigram,freqbigram) 
H22 = H(bigramtwo,freqbigramtwo) 

print(H2)
print(H22)


# In[361]:


print(bigramcount)


# In[396]:


import pandas as pd


data = pd.DataFrame.from_dict(freqbigram,'index').stack().reset_index(level=0)  
print(data.columns)
data = data.sort_values(by=0, ascending=False)
data = data.rename(columns = {'level_0': 'bigram', 0: 'freq'})
data


# In[325]:


print(freqbigram['аа'])


# In[330]:





# In[323]:


data2 = pd.DataFrame.from_dict(freqbigramtwo,'index').stack().reset_index(level=0)  
data2 = data2.sort_values(by=0, ascending=False)
data2 = data2.rename(columns = {'level_0': 'bigram2', 0: 'freq2'})
data2


# In[406]:


#Alp = ['а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж',' з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э', 'ю', 'я']
Alp = [' ', 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж',' з', 'и', 'й', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ','ы', 'ь', 'э', 'ю', 'я']
df = pd.DataFrame(index = Alp, columns=Alp)

bg = []

for i in Alp:
    for j in Alp:
        bg.append(i+j)
 
n = 0
for i in range(0,len(Alp)):
    df[Alp[i]] = bg[n:len(Alp)+n]
    n = len(Alp)+n
df = df.T

import numpy as np

for b in list(freqbigram.keys()):
    a,c = np.where(df == b)
    df.iloc[a,c] = freqbigram[b]
    
for b in bg:
    a,c = np.where(df == b)
    df.iloc[a,c] = 0




    

print(df)
print(freqbigram['гб'])
df.to_excel("freqbigram.xlsx")


# In[292]:


freqbigram['ми']


# In[407]:




df = pd.DataFrame(index = Alp, columns=Alp)

bg = []

for i in Alp:
    for j in Alp:
        bg.append(i+j)
 
n = 0
for i in range(0,len(Alp)):
    df[Alp[i]] = bg[n:len(Alp)+n]
    n = len(Alp)+n
df = df.T

for b in list(freqbigramtwo.keys()):
    a,c = np.where(df == b)
    df.iloc[a,c] = freqbigramtwo[b]
    
for b in bg:
    a,c = np.where(df == b)
    df.iloc[a,c] = 0
    
print(df.head())
df.to_excel("freqbigramstwo.xlsx")


# In[5]:


import math
R = 1 - 1.906/math.log(33,2)
R1 = 1 - 2.601/math.log(33,2)
R2 = 1 - 2.07/math.log(33,2)
R3 = 1 - 2.66/math.log(33,2)
R4 = 1 - 1.68/math.log(33,2)
R5 = 1 - 2.03/math.log(33,2)


# In[7]:


print(R,R1,R2,R3,R4,R5)


# In[ ]:




