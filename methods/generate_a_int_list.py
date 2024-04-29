from random import randint
from random import shuffle

def gen_a_incre_int_lst(length):
    lst = []
    increment = 2
    for i in range(length):
        lst.append(randint(i*increment, i*increment+increment))
    
    return lst

def gen_a_shuffle_int_lst(length, included):
    lst = []
    included_num = length // 3
    for _ in range(length-included_num):
        lst.append(randint(0, 100))


    for _ in range(included_num):
        lst.append(included)

    shuffle(lst)
    return lst


if __name__ == "__main__":
    lst = gen_a_incre_int_lst(100)
    print(lst)