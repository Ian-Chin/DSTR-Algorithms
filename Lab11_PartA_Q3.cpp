// Lab 11 - Part A, Exercise 3 : build the animal binary search tree and display its traversals
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

    return 0;
}
