# 자기 자신을 제외한 곱

array = [1,2,3,4]
length = len(array)

#On2
for i in range(len(array)):
    new_array = array[:i] + array[i+1:]
    multiply = 1
    for n in new_array:
        multiply *= n

    print(multiply) 