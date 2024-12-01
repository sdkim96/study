def find_max_sum_of_array(k:int , l: list) -> int:

    size = len(l)

    max_l = []
    for i in range(size-k+1):
        current_sum = 0
        start = i
        end = start+k
        
        for j in range(start, end):
            current_sum += l[j]

        max_l.append(current_sum)

    return max(max_l)



def find_max_sum_of_array2(k, l):

    # sliding window
    c_sum=0
    max_l= []
    for i in range(k):
        c_sum += l[i]
    
    max_l.append(c_sum)

    for j in range(1, len(l)-k+1):
        c_sum = c_sum - l[j-1] + l[j+k-1]
        print(c_sum)
        max_l.append(c_sum)

    return max(max_l)    

    


if __name__ == "__main__":

    find_max_sum_of_array2(4,[-2,9,3,6,9,10])
