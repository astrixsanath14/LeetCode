/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
  public int reverseInOrderTraversal(TreeNode root, int sum)
  {
    if(root == null)
      return sum;
    int right = reverseInOrderTraversal(root.right, sum);
    root.val += right;
    int left = reverseInOrderTraversal(root.left, root.val);
    return left;
  }
  
  public TreeNode bstToGst(TreeNode root) {
    reverseInOrderTraversal(root, 0);
    return root;
  }
}