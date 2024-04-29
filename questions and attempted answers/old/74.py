class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        rows = len(matrix)
        if rows == 0:
            return False
        columns = len(matrix[0])
        if columns == 0:
            return False
        elif rows == 1:
            for i in matrix[0]:
                if target == i:
                    return True
            return False
        elif columns == 1:
            for i in matrix:
                if target == i[0]:
                    return True
            return False

        ls2 = [row[-1] for row in matrix]
        ls1 = [row[0] for row in matrix]
        for index, i in enumerate(zip(ls1, ls2)):
            if target >= i[0] and target <= i[1]:
                for j in matrix[index]:
                    if target == j:
                        return True
                    else:
                        continue
                return False
            elif target == i[0] or target == i[1]:
                return Ture

        return False
