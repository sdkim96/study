# 배열을 입력받아 합으로 0을 만들 수 있는 3개의 엘리먼트 출력

array = [-1,0,1,2,-1,-4]
target=0

left = 0
left2 = 1
right = len(array) -1

array.sort()
# [-4,-1,-1,0,1,2]
while left2 < right:
    condition = array[left] + array[left2] + array[right]
    if condition == target:
        print(array[left], array[left2], array[right])
        break
    elif condition < target:
        left += 1
        left2 += 1
    else:
        right -= 1
        

#위에거 문제 좀 있음