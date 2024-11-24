nums =[2,7,11,15]
target = 9

# O(n^2)
def solve_on2():
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            print(nums[i], nums[j])
            if nums[i] + nums[j] == target:
                print(i, j)
# O(n)
def solve_on1():
    for i, n in enumerate(nums):
        # 타겟에서 n을 뺀 값이 그 리스트에 있는지 
        lookforval = target-n
        if lookforval in nums[i:]:
            print(i, nums.index(lookforval))

# 투 포인터 사용하기
# 대신 이 경우엔 인덱스가 엉망됨, 밸류로만 찾아야함
def solve_two_pt(array: list[int], target: int):

    if isinstance(array, list):
        array.sort()
    else:
        raise ValueError('array에 리스트를 넣어주세요.')

    left_idx, right_idx = 0, len(array)-1

    while left_idx < right_idx:
        current_sum = array[left_idx] + array[right_idx]
        if current_sum == target:
            return array[left_idx], array[right_idx]
        elif current_sum < target:
            left_idx += 1
        elif current_sum > target:
            right_idx -= 1
        else:
            raise ValueError('찾지 못함')
        
int1, int2 = solve_two_pt([7,0,6,4], 6)

print(int1, int2)

#근데 아래처럼 하면 됨
nums = [3,2,4]
target = 6

mapping=[(i,n) for i, n in enumerate(nums)]
sortted = sorted(mapping, key=lambda x:x[1])

left = 0
right = len(sortted) -1

while left < right:
    if sortted[left][1] + sortted[right][1] == target:
        print(sortted[left][0], sortted[right][0])
        break
    elif sortted[left][1] + sortted[right][1] < target:
        left += 1
    else:
        right -= 1
