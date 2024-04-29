class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        if(preorder.empty()){return nullptr;}
        else if(preorder.size()==1 && inorder.size()==1)
        {
            TreeNode *node = new TreeNode(preorder[0]);
            return node;
        }

        int root_value = preorder[0];
        int root_postion = 0;
        for(int i=0; i<inorder.size(); i++)
        {
            if(inorder[i]==root_value)
            {
                root_postion = i;
            }
        }

        vector<int>::const_iterator first = inorder.begin();
        vector<int>::const_iterator last = inorder.begin() + root_postion - 1;
        vector<int> left_sub_in_order(first, last);

        vector<int>::const_iterator first = inorder.begin() + root_postion + 1;
        vector<int>::const_iterator last = inorder.end();
        vector<int> right_sub_in_order(first, last);


        vector<int>::const_iterator first = preorder.begin() + 1;
        vector<int>::const_iterator last = preorder.begin() + root_postion;
        vector<int> left_sub_pre_order(first, last);

        vector<int>::const_iterator first = inorder.begin() + root_postion + 1;
        vector<int>::const_iterator last = inorder.end();
        vector<int> right_sub_pre_order(first, last);

        TreeNode *root = new TreeNode(root_value);
        root->left = buildTree(left_sub_pre_order, left_sub_in_order);
        root->right = buildTree(right_sub_pre_order, right_sub_in_order);
        return root;
    }
};
