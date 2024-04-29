class Solution:

    def CountPrimes(self, n):
        if n == 0 or n == 1:
            return 0
        else:
            axis = [1 for _ in range(n)]
            axis[0] = 0
            axis[1] = 0
            for i in range(2, n):
                if axis[i] == 1:
                    axis[i*i:n:i] = [0 for _ in axis[i*i:n:i]]
            
            return sum(axis)

if __name__ == "__main__":
    s = Solution()
    for i in range(10):
        print(s.CountPrimes(i))