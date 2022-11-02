class Solution {
public:
    int getDiff(string gene1, string gene2)
    {
        if(gene1.size() != gene2.size())
            return max(gene1.size(), gene2.size());
        int diffCount = 0;
        for(int i=0;i<8;i++)
            diffCount += gene1[i] != gene2[i];
        return diffCount;
    }
    
    int minMutationCount(string start, string end, vector<string>& bank) {
        if(start == end)
        {
            return 0;
        }
        int minMutations = INT_MAX;
        for(int i=0; i<bank.size(); i++)
        {
            string gene = bank[i];
            bank[i] = "-1";
            int diffCount = getDiff(start, gene);
            if(diffCount == 1)
            {
                int minMutationForCurrGene = minMutationCount(gene, end, bank);
                if(minMutationForCurrGene!=INT_MAX)
                    minMutations = min(minMutations, 1+minMutationForCurrGene);
            }
            bank[i] = gene;
        }
        return minMutations;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        int minMutations = minMutationCount(start, end, bank);
        return minMutations == INT_MAX ? -1 : minMutations;
    }
};