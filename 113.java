import java.util.*;
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
};

class Solution113 {
    List<List<Integer>> res = new LinkedList<List<Integer>>();
    List<Integer> path = new LinkedList<Integer>();
    public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
        dfs(root, targetSum);
        return res;
    }
    public void dfs(TreeNode root, int targetSum){
        if(root==null)return;
        path.add(root.val);
        if(root.val == targetSum && root.left==null && root.right==null){
            res.add(new LinkedList<Integer>(path));
        }
        dfs(root.left, targetSum-root.val);
        dfs(root.right, targetSum-root.val);
        path.remove(path.size()-1);
    }
}
