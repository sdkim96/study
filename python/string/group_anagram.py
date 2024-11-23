import collections
def group_anangram(strs: list[str]) -> list[list[str]]:
    
    anagrams = collections.defaultdict(list)
    for word in strs:
        empty = ""
        key = empty.join(sorted(word))
        anagrams[key].append(word)

    returning = [values for values in anagrams.values()]

    return returning



if __name__ == "__main__":

    array = ['eat', 'tea', 'tan', 'ate', 'nat', 'bat']
    result = group_anangram(array)

    print(result)