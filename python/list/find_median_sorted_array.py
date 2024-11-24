# Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

# The overall run time complexity should be O(log (m+n)).

 

# Example 1:

# Input: nums1 = [1,3], nums2 = [2]
# Output: 2.00000
# Explanation: merged array = [1,2,3] and median is 2.
# Example 2:

# Input: nums1 = [1,2], nums2 = [3,4]
# Output: 2.50000
# Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
import math

def find_median_sorted_arrays(l1, l2):

    sorted_list = sorted(l1 + l2) 
    
    if (len(l1) + len(l2)) % 2 == 0:
        center = (len(l1) + len(l2))/2
        res = (sorted_list[int(center)] + sorted_list[int(center)-1])/2
    else:
        center = (len(l1) + len(l2))/2
        center = math.floor(center)
        res = sorted_list[int(center)]
    
    print(res)



if __name__ =="__main__":
    l1 = [1,2]
    l2 = [2,4]

    find_median_sorted_arrays(l1, l2)
    
