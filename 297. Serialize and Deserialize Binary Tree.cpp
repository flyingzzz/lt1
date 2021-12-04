class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
    void serialize(TreeNode* node, ostringstream &out) {
        if(node != NULL) {
            out << node->val << " ";
            serialize(node->left, out);
            serialize(node->right, out);
        } else {
            out << "# ";
        }
    } 
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if(val == "#") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
