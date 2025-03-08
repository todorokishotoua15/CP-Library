
 
#include <bits/stdc++.h>
 
using namespace std;
 



struct Trie {
    
    int size; 

    // change argument of function to get binary trie
    Trie(int child_len = 26) {
        size = child_len;
    }

    struct node {
        bool isend;
        int count = 0;
        vector<node*> child;
    };

    node* create() {
        node* temp = new node();
        for (int i = 0; i < 2; i++) {
            node* temp1 = NULL;
            temp->child.push_back(temp1);
        }
        temp->isend = false;
        return temp;
    }

    node* remove(node* root, string s, int depth = 0) {
        if (!root) {
            return NULL;
        }
        if (depth == s.size()) {
            root->isend = false;

            if (root->child[0] == NULL && root->child[1] == NULL) {
                delete (root);
                return NULL;
            }
            return root;
        }

        root->child[s[depth] - '0'] = remove(root->child[s[depth] - '0'],
                                                s, depth+1);

        if (root->child[0] == NULL && root->child[1] == NULL) {
            delete (root);
            return NULL;
        }
        return root;
    }



    node* root = create();

    // for binary trie, change 'a' to '0'
    void add(string s) {
        node* temp = root;
        if (root->child[0] == NULL) {
            root->child[0] = create();
        }

        if (root->child[1] == NULL) {
            root->child[1] = create();
        }
        for (int i = 0; i < s.size(); i++) {
            if (root->child[s[i] - '0'] == NULL) {
                root->child[s[i] - '0'] = create();
            }
            root = root->child[s[i] - '0'];
        }
        root->isend = true;
        root->count++;
        root = temp;
    }
    
    bool find(string &s) {
        node* temp = root;
        for (int i = 0; i < s.size(); i++) {
            if (root->child[s[i] - '0'] == NULL) {
                root = temp;
                return false;
            }
            root = root->child[s[i] - '0'];
        }
        root = temp;
        return true;
    }

    void dfs(node* temp1, string s) {
        // todo
    }

};
 
int main()

{ 
    
    
 
}
