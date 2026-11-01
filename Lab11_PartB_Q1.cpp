// Lab 11 - Part B, Homework 1 : car binary search tree (keyed by Car ID)
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Car {
    string id;
    string brand;
    string type;
    string color;
    double price;
    int amount;
};

struct Node {
    Car car;
    Node *left;
    Node *right;
};

class carTree {
private:
    Node *root;

    void insert(Node *&node, Car car) {
        if (node == NULL) {
            node = new Node;
            node->car = car;
            node->left = NULL;
            node->right = NULL;
        }
        else if (car.id < node->car.id)
            insert(node->left, car);
        else
            insert(node->right, car);
    }

    void printCar(Car car) {
        cout << left << setw(9) << car.id << setw(9) << car.brand
             << setw(15) << car.type << setw(8) << car.color
             << right << setw(8) << car.price << setw(4) << car.amount << endl;
    }

    void preorder(Node *node) {
        if (node != NULL) {
            printCar(node->car);
            preorder(node->left);
            preorder(node->right);
        }
    }

    void inorder(Node *node) {
        if (node != NULL) {
            inorder(node->left);
            printCar(node->car);
            inorder(node->right);
        }
    }

    void postorder(Node *node) {
        if (node != NULL) {
            postorder(node->left);
            postorder(node->right);
            printCar(node->car);
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

    double totalPrice(Node *node) {
        if (node == NULL)
            return 0;
        return node->car.price + totalPrice(node->left) + totalPrice(node->right);
    }

    int totalAmount(Node *node) {
        if (node == NULL)
            return 0;
        return node->car.amount + totalAmount(node->left) + totalAmount(node->right);
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
    carTree() {
        root = NULL;
    }

    ~carTree() {
        destroy(root);
    }

    void insert(Car car) { insert(root, car); }
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
    int height() { return height(root); }
    int nodeCount() { return nodeCount(root); }
    double totalPrice() { return totalPrice(root); }
    int totalAmount() { return totalAmount(root); }
};

int main() {
    Car cars[] = {
        { "Car0051", "Proton",  "X50",           "White",  95000,  5 },
        { "Car0302", "Honda",   "Civic",         "Red",    135000, 3 },
        { "Car0024", "Toyota",  "Yaris",         "Red",    87900,  2 },
        { "Car0101", "Toyota",  "Corolla Cross", "Yellow", 125700, 5 },
        { "Car1001", "Perodua", "MyVi",          "Blue",   48700,  2 },
        { "Car5051", "Mazda",   "X30",           "Black",  115000, 1 }
    };
    int size = sizeof(cars) / sizeof(cars[0]);

    carTree tree;
    for (int i = 0; i < size; i++)
        tree.insert(cars[i]);

    cout << fixed << setprecision(0);

    cout << "===== Preorder =====" << endl;
    tree.preorder();
    cout << endl << "===== Inorder =====" << endl;
    tree.inorder();
    cout << endl << "===== Postorder =====" << endl;
    tree.postorder();

    cout << endl;
    cout << "Height of tree    : " << tree.height() << endl;
    cout << "Number of nodes   : " << tree.nodeCount() << endl;
    cout << "Sum of car prices : RM " << tree.totalPrice() << endl;
    cout << "Sum of car amount : " << tree.totalAmount() << endl;

    return 0;
}
