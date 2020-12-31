class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        
        std::queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            Node* tt = q.front();
            q.pop();
            if (tt->left) q.push(tt->left);
            if (tt->right) q.push(tt->right);
            for (int i = 1; i < n; ++i) {
                Node* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                tt->next = t;
                tt = t;
            }
            
            tt->next = nullptr;
        }
        return root;
    }
};
