// Lab 11 - Part A, Exercise 5 : animal binary search tree with height, node count and total weight
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    double weight;   // in kg
    Node *left;
    Node *right;
};

class binaryTree {
private:
    Node *root;

    void insert(Node *&node, string name, double weight) {
        if (node == NULL) {
            node = new Node;
            node->name = name;
            node->weight = weight;
            node->left = NULL;
            node->right = NULL;
        }
        else if (name < node->name)
            insert(node->left, name, weight);
        else
            insert(node->right, name, weight);
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

    double totalWeight(Node *node) {
        if (node == NULL)
            return 0;
        return node->weight + totalWeight(node->left) + totalWeight(node->right);
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

    void insert(string name, double weight) { insert(root, name, weight); }
    void preorder() { preorder(root); cout << endl; }
    void inorder() { inorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
    int height() { return height(root); }
    int nodeCount() { return nodeCount(root); }
    double totalWeight() { return totalWeight(root); }
};

int main() {
    string animals[] = { "Monkey", "Rat", "Tiger", "Dog", "Cat",
                         "Elephant", "Salmon", "Zebra", "Panda" };
    // approximate average adult weight of each animal in kg
    double weights[] = { 25, 0.3, 220, 30, 4.5, 5000, 4, 380, 100 };
    int size = sizeof(animals) / sizeof(animals[0]);

    binaryTree tree;
    for (int i = 0; i < size; i++)
        tree.insert(animals[i], weights[i]);

    cout << "Preorder  : "; tree.preorder();
    cout << "Inorder   : "; tree.inorder();
    cout << "Postorder : "; tree.postorder();
    cout << endl;
    cout << "Height of tree  : " << tree.height() << endl;
    cout << "Number of nodes : " << tree.nodeCount() << endl;
    cout << "Total weight    : " << tree.totalWeight() << " kg" << endl;

    return 0;
}
