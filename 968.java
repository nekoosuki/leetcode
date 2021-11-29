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



class Solution {
    class state{
        static final int NOT_COVER = 0;
        static final int COVER = 1;
        static final int CAMERA = 2;
    }
    int res = 0;
    public int minCameraCover(TreeNode root) {
        if(dfs(root) == state.NOT_COVER){
            res++;
        }
        return res;
    }
    public int dfs(TreeNode root){
        if(root == null){
            return state.COVER;
        }

        int left = dfs(root.left);
        int right = dfs(root.right);

        if(left==state.NOT_COVER||right==state.NOT_COVER){
            res++;
            return state.CAMERA;
        }
        else if(left==state.COVER&&right==state.COVER){
            return state.NOT_COVER;
        }
        else{
            return state.COVER;
        }
    }
}