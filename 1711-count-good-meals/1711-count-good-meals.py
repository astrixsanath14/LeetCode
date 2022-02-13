MOD = 1E9+7
class Solution:
    def countPairs(self, deliciousness: List[int]) -> int:
        powers=[]
        for i in range(21,-1,-1):
          powers.append(1<<i)
        counter = {}
        for deli in deliciousness:
          if deli not in counter:
            counter[deli]=0
          counter[deli]+=1
        deliciousness = set(deliciousness)
        print(counter)
        print(powers)
        print(deliciousness)
        goodMeals = 0
        for deli in deliciousness:
          for power in powers:
            if power < deli:
              break
            counterSum = power - deli
            if counterSum < deli:
              break
            if counterSum in counter:
              ways=0
              if counterSum != deli:
                ways = counter[counterSum] * counter[deli]
              elif counterSum == deli:
                ways = (counter[deli]*(counter[deli]-1))//2
              if ways>0:
                print('found',counterSum, deli, power, ways)
                goodMeals += ways
                goodMeals%=MOD
        return int(goodMeals)
      
# [149,107,1,63,0,1,6867,1325,5611,2581,39,89,46,18,12,20,22,234]