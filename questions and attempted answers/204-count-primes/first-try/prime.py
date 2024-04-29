from tqdm import tqdm

def isPrime(num):
    for i in range(2, num):
        if num % i == 0:
            return False

    return True

if __name__ == "__main__":
    lst = []
    with open("primes.txt", "w") as fi:
        for i in tqdm(range(2, 500000)):
            if isPrime(i):
                fi.write(str(i))
                fi.write(", ")