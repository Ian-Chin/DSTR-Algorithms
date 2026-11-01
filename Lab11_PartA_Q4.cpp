// Lab 11 - Part A, Exercise 4 : animal binary search tree with height and node count
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node *left;
    Node *right;
};

class binaryTree {
private:
    Node *root;

    void insert(Node *&node, string name) {
        if (node == NULL) {
            node = new Node;
            node->name = name;
            node->left = NULL;
            node->right = NULL;
        }
        else if (name < node->name)
            insert(node->left, name);
        else
            insert(node->right, name);
    }

    void preorder(Node *node) {
        if (node != NULL) {
            cout << node->name << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node *node) {
        if (node != NULL) {
            inorder(node->left);
            cout << node->name << " ";
            inorder(node->right);
        }
    }

    void postorder(Node *node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            cout << node->name << " ";
        }
    }

    // height = number of nodes on the longest path from root to a leaf
    int height(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + max(height(node->left), height(node->right));
    }

    int nodeCount(Node *node) {
        if (node == NULL)
            return 0;
        return 1 + nodeCount(node->left) + nodeCount(node->right);
    }

    void destroy(Node *&node) {
        if (node != NULL) {
            destroy(node->left);
            destroy(node->right);
            delete node;
            node = NULL;
        }
    }

public:
    binaryTree() {
        root = NULL;
    }

    ~binaryTree() {
        destroy(root);
    }

    void insert(string name) { insert(root, name); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    int height() { return height(root); }
    int nodeCount() { return nodeCount(root); }
};

int main() {
    string animals[] = { "Monkey", "Rat", "Tiger", "Dog", "Cat",
                         "Elephant", "Salmon", "Zebra", "Panda" };
    int size = sizeof(animals) / sizeof(animals[0]);

    binaryTree tree;
    for (int i = 0; i < size; i++)
        tree.insert(animals[i]);

    cout << "Preorder  : "; tree.preorder();
    cout << "Inorder   : "; tree.inorder();
    cout << "Postorder : "; tree.postorder();
    cout << endl;
    cout << "Height of tree  : " << tree.height() << endl;
    cout << "Number of nodes : " << tree.nodeCount() << endl;

    return 0;
}
