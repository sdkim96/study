import time

array = [5,1,4,2,7,9,3]

def solve_on2():
    s = time.time()
    array2 = []
    for i in range(len(array)):
        for j in range(i+1, len(array)):

            subs = array[j] - array[i]
            array2.append([i,j,subs])

    result = sorted(array2, key=lambda x:x[2], reverse=True)
    f = time.time()

    print(f"{result[0][0]}번째에 사서 {result[0][1]}에 파는게 {result[0][2]}를 얻어서 가장 이득입니다")
    print(f"걸린 시간은 {f-s}초 입니다.")


def solve_on1():
    pass