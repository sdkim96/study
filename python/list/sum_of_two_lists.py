# You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

# Example 1:


# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.
# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]
# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]


def add_two_nums(l1: list[int], l2: list[int]):
    
    l1_int = 0
    l2_int = 0

    for i, n in enumerate(l1):
        current = (10**i) * n
        l1_int += current
    
    for j, m in enumerate(l2):
        current1 = (10**j) * m
        l2_int += current1
    
    final: str = str(l1_int + l2_int)
    result = [int(f)for f in final]
    result.reverse()
    return result
    

if __name__ == "__main__":
    l1 = [9,9,9,9,9,9,9]
    l2 = [9,9,9,9]

    res = add_two_nums(l1, l2)
    print(res)