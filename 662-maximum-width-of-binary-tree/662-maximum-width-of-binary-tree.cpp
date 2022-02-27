/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//   int widthOfBinaryTree(TreeNode* root) {
//     long long maxRes = 0;
//     queue<pair<TreeNode*, long long>> q;
//     q.push({root,1});
//     int l = 1;
//     while(!q.empty())
//     {
//       long long qSize = q.size(), minQInd = INT_MAX, maxQInd = INT_MIN, count=0;
//       while(qSize--)
//       {
//         TreeNode* node = q.front().first;
//         long long currNodeVal = q.front().second;
//         // cout<<"currNodeVal: "<<currNodeVal<<"\n";
//         q.pop();
//         minQInd = min(minQInd, currNodeVal);
//         maxQInd = max(maxQInd, currNodeVal);
//         if(node->left)
//           q.push({node->left,(long long)2*currNodeVal-1});
//         if(node->right)
//           q.push({node->right,(long long)2*currNodeVal});
//         count++;
//       }
//       cout<<"l: "<<l++<<" "<<maxQInd<<" "<<minQInd<<" "<<count<<" ";
//       cout<<maxRes<<"\n";
//       maxRes = max(maxRes, (maxQInd - minQInd + 1));
//     }
//     return maxRes;
//   }
// };

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int width = 0;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            int n = q.size();
            int max_index = INT_MIN, min_index = INT_MAX;
            while(n--){
                TreeNode* tmp = q.front().first;
                int dist = q.front().second;
                q.pop();
                max_index = max(max_index, dist);
                min_index = min(min_index, dist);
                if(tmp->left){
                    q.push({tmp->left, (long long)2 * dist + 1});
                }
                if(tmp->right){
                    q.push({tmp->right, (long long)2 * dist + 2});
                }
            }
            width = max(width, max_index - min_index + 1);
        }
        return width;   
    }
};
