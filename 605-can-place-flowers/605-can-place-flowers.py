class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        cnt, prev = 0, 0

        for cur in flowerbed:
            if cur == 1:
                if prev == 1: # violation!
                    cnt -= 1
                prev = 1
            else:
                if prev == 1: # can't plant
                    prev = 0 
                else:
                    cnt += 1
                    prev = 1 # the cur plot gets taken
            
        return cnt >= n