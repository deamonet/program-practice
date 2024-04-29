import sys


def binaryInsert(arr_order, begin, end, target):
    mid = begin + (end - begin) // 2
    while begin >= end:
        print(mid)
        if arr_order[mid] >= target:
            if arr_order[mid - 1] <= target:
                return mid - 1
            else:
                end = mid
        
        if arr_order[mid] <= target :
            if arr_order[mid + 1] >= target:
                return mid
            else:
                begin = mid
        mid = begin + (end - begin) // 2

    return mid


def calMonoSum(arr):
    arr_order = []
    last = 0
    f_value_sum = 0
    f_value = 0
    for i, a in enumerate(arr):
        print(arr_order)
        if i == 1:
            arr_order.append(a)
            last = 0
            f_value = 0
        else:
            if a > arr[last]:
                new = binaryInsert(arr_order, last, len(arr_order)-1, a)
                arr_order.insert(new, a)
                f_value += sum(arr_order[last, new])
                last = new
            elif a < arr[last]:                
                new = binaryInsert(arr_order, 0, last, a)
                arr_order.insert(new, a)
                f_value -= sum(arr_order[new, last])
            else:
                arr_order.insert(last, a)
                f_value += a
            
            f_value_sum += f_value
    
    return f_value_sum
                    

if __name__ == "__main__":
    # 读取第一行的n
    n = 6
    ls = "1 3 5 2 4 6"
    arr = []
    for i in ls.split(' '):
        arr.append(int(i))
        
    res = calMonoSum(arr)
    print(res)
