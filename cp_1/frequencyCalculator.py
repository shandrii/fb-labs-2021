import sys

def sortDict(rawDict):
    sortedDict = {}
    for i in sorted(rawDict):
        sortedDict[i]=rawDict[i]
    return sortedDict

if len(sys.argv) < 2:
    print("Usage: entrophyCalculator.py <source file>")
    exit(0)

f = open(sys.argv[1])

freq = {}
for string in f:
    for i in string:
        if i in freq:
            freq[i] += 1
        else:
            freq[i] = 1

print(str(sortDict(freq)), end="\n\n\n")

f.seek(0)

biFreq = {}
for string in f:
    for i in range(0, len(string) - 1, 1): # ..., 2) to count bigrams with 2 char step.
        biGram = string[i:i+2]
        if biGram in biFreq:
            biFreq[biGram] += 1
        else:
            biFreq[biGram] = 1

print(str(sortDict(biFreq)), end="\n\n\n")

sum = 0
for i in freq:
    sum += freq[i]
print("Number of characters: ", sum)

sum = 0
for i in biFreq:
    sum += biFreq[i]
print("Number of bigrams: ", sum)

    

