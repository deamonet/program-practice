import numpy as np

def binarySearch(sortedList, target):
    begin = 0
    end = len(sortedList)

    while begin <= end:
        mid = (begin + end) // 2
        if sortedList[mid] == target:
            return mid
        elif sortedList[mid] > target:
            end = mid - 1
        else:
            begin = mid + 1
        
    return -1

def binarySearch2(sortedList, target):
    begin = 0
    end = len(sortedList)

    while begin <= end:
        mid = (begin + end) // 2
        print(mid)
        if sortedList[mid] == target:
            return mid
        elif sortedList[mid] > target:
            end = mid
        else:
            begin = mid
        
    return -1


def binarySearch3(sortedList, target):
    begin = 0
    end = len(sortedList) - 1

    while begin <= end:
        mid = (begin + end) // 2
        print(mid)
        if sortedList[mid] == target:
            return mid
        elif sortedList[mid] > target:
            end = mid
        else:
            begin = mid
        
    return -1

sortedList = list(set(np.random.randint(100, size=29)))
sortedList.sort()
print(sortedList)

# target = eval(input("target:\t"))
for index, target in enumerate(sortedList):
    temp = binarySearch(sortedList, target)
    if index != temp:
        print("wrong")

    print(index, temp)

a = [1, 2, 3, 4, 5]
b = 1
c = binarySearch3(a, b)
print(a, b, c)

