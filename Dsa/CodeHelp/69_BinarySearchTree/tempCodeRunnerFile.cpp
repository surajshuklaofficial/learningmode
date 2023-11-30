
            // 0 child
            if (!root->left && !root->right) {
                delete root;
                return NULL;
            }

            // 1 child
            else if (root->left == nullptr && root->right != nullptr) {
                Node *t