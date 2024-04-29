"""
127. 单词接龙
给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。
通过次数48,774提交次数114,010
"""

import string
from collections import deque  # line 158
from typing import List
from collections import defaultdict  # line 141
from pprint import pprint
from tqdm import tqdm


class Solution_batter_answer:
    def findLadders(self, beginWord, endWord, wordList):
        # 先将 wordList 放到哈希表里，便于判断某个单词是否在 wordList 里
        word_set = set(wordList)
        if len(word_set) == 0 or endWord not in word_set:
            return 0

        #successors = defaultdict(set)
        # defaultdict 是初始化一个字典，默认键值是一个set，可选参数包括list, dict, tuple, deque等，这些都是factory function.
        # factory function的意思是表面上看list()是一个函数，但其实他是类的初始化。这主要是指python内置的类型（容器）。
        # 所以相比于一般的设置 int string 的默认值，defaultdict 提供了设置这种以内置容器为默认值的方法。

        # 第 1 步：使用广度优先遍历得到后继结点列表 successors
        # key：字符串，value：广度优先遍历过程中 key 的后继结点列表

        return self.__bfs(beginWord, endWord, word_set)
        # if not found:
        #     return res
        # # 第 2 步：基于后继结点列表 successors ，使用回溯算法得到所有最短路径列表
        # path = [beginWord]
        # self.__dfs(beginWord, endWord, successors, path, res)
        # return res

    def __bfs(self, beginWord, endWord, word_set):
        queue = deque()
        # deque 是跟 list 差不多的东西，只不过他的初始化方式更接近于类。
        # 区别在于 deque 支持左右两边append, extend, pop，相比于 list 更快。
        queue.append(beginWord)

        visited = set()
        visited.add(beginWord)

        found = False
        word_len = len(beginWord)
        next_level_visited = set()
        # 重点：由于要记录所有的路径，广度优先遍历「当前层」到「下一层」的所有路径都得记录下来。
        # 因此找到下一层的结点 wordA 以后，不能马上添加到 visited 哈希表里，还需要检查当前队列中未出队的单词是否还能与 wordA 建立联系；
        # 这是因为本题的节点之间的连线不止一条，层与层之间的连续都是多对多的。一个节点可以有多个入口，也可以有多个出口。
        cnt = 1
        while queue:
            current_size = len(queue)
            for i in range(current_size):
                current_word = queue.popleft()

                # print(type(current_word))
                # print(current_word)
                word_list = list(current_word)
                # print(word_list)

                for j in range(word_len):
                    origin_char = word_list[j]

                    for k in string.ascii_lowercase:
                        word_list[j] = k
                        next_word = ''.join(word_list)

                        if next_word in word_set:
                            if next_word not in visited:
                                if next_word == endWord:
                                    found = True

                                # 避免下层元素重复加入队列，这里感谢 https://leetcode-cn.com/u/zhao-da-ming/ 优化了这个逻辑
                                if next_word not in next_level_visited:
                                    next_level_visited.add(next_word)
                                    queue.append(next_word)

                                # successors[current_word].add(next_word)
                    word_list[j] = origin_char
            cnt += 1
            if found:
                return cnt
                
            # 取两集合全部的元素（并集，等价于将 next_level_visited 里的所有元素添加到 visited 里）
            visited |= next_level_visited
            next_level_visited.clear()
            
        return 0

    # def __dfs(self, beginWord, endWord, successors, path, res):
    #     if beginWord == endWord:
    #         res.append(path[:])
    #         return

    #     if beginWord not in successors:
    #         return

    #     successor_words = successors[beginWord]
    #     for next_word in successor_words:
    #         path.append(next_word)
    #         self.__dfs(next_word, endWord, successors, path, res)
    #         path.pop()


if __name__ == "__main__":
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
    #s=Solution()
    
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log", "cog"]

    beginWord = "qa"
    endWord = "sq"
    wordList = ["si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"]
    
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot", "dot", "dog", "lot", "log"]

    solution = Solution_batter_answer()
    res = solution.findLadders(beginWord, endWord, wordList)
    print(res)
