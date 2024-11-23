paragraph ="Bob hit a ball, the hit BALL flew far after it was hit."

banned =["hit"]

words = paragraph.split(" ")
hashmap = {}
for word in words:
    cleaned_word = word.replace(',','').replace('.','').lower()
    if cleaned_word != banned[0]:        
        try:
            hashmap[cleaned_word] +=1
        except KeyError:
            hashmap[cleaned_word] = 1

print(max(hashmap, key=hashmap.get))

## defaultdict를 사용하면 훨씬 간단함.

from collections import defaultdict
paragraph ="Bob hit a ball, the hit BALL flew far after it was hit."

banned =["hit"]

words = paragraph.split(" ")
hashmap = defaultdict(int)

for word in words:
    cleaned_word = word.replace(',','').replace('.','').lower()
    if cleaned_word != banned[0]:        
        hashmap[cleaned_word] +=1

print(max(hashmap, key=hashmap.get))