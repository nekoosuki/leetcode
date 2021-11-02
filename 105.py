class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        if not preorder: 
            return None
        
        x = preorder.pop(0)
        root = TreeNode(x)
        i = inorder.index(x)
        
        root.left = self.buildTree(preorder[:i], inorder[:i])
        root.right = self.buildTree(preorder[i:], inorder[i+1:])
        return root