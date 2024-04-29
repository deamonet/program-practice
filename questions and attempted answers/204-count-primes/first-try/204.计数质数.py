#
# @lc app=leetcode.cn id=204 lang=python3
#
# [204] 计数质数
#

# @lc code=start
import random
# from tqdm import tqdm

class Solution:
    def countPrimes(self, n: int) -> int:
        if n < 2:
            return 0
        else:
            cnt = 0
            for i in range(2, n):
                if self.isPrime(i, 10):
                    cnt += 1
        
            return cnt

    # Python3 program Miller-Rabin primality test
 
    # Utility function to do
    # modular exponentiation.
    # It returns (x^y) % p
    def modular_exponentiation(self, x, y, p):
        
        # Initialize result
        res = 1
        
        # Update x if it is more than or
        # equal to p
        x = x % p
        while (y > 0):
            
            # If y is odd, multiply
            # x with result
            if (y & 1):
                res = (res * x) % p
    
            # y must be even now
            y = y>>1; # y = y/2
            x = (x * x) % p
        
        return res
 
    # This function is called
    # for all k trials. It returns
    # false if n is composite and
    # returns false if n is
    # probably prime. d is an odd
    # number such that d*2<sup>r</sup> = n-1
    # for some r >= 1
    def miillerTest(self, d, n):
        
        # Pick a random number in [2..n-2]
        # Corner cases make sure that n > 4
        a = 2 + random.randint(1, n - 4);
    
        # Compute a^d % n
        x = self.modular_exponentiation(a, d, n);
    
        if (x == 1 or x == n - 1):
            return True
    
        # Keep squaring x while one
        # of the following doesn't
        # happen
        # (i) d does not reach n-1
        # (ii) (x^2) % n is not 1
        # (iii) (x^2) % n is not n-1
        while (d != n - 1):
            x = (x * x) % n
            d *= 2
    
            if (x == 1):
                return False
            if (x == n - 1):
                return True
    
        # Return composite
        return False
    
    # It returns false if n is
    # composite and returns true if n
    # is probably prime. k is an
    # input parameter that determines
    # accuracy level. Higher value of
    # k indicates more accuracy.
    def isPrime(self, n, k):
        
        # Corner cases
        if (n <= 1 or n == 4):
            return False
        if (n <= 3):
            return True
    
        # Find r such that n =
        # 2^d * r + 1 for some r >= 1
        d = n - 1
        while (d % 2 == 0):
            d //= 2
    
        # Iterate given nber of 'k' times
        for i in range(k):
            if (self.miillerTest(d, n) == False):
                return False
    
        return True
# @lc code=end

if __name__ == "__main__":
    s = Solution()
    total = s.countPrimes(5000000)
    with open("total_primes.txt", "w") as fi:
        fi.write(str(total))