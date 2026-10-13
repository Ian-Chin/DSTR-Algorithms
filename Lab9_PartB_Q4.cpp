// Lab 9 - Part B, Test Yourself 4 : Tower of Hanoi using three array-based stacks
#include <iostream>
using namespace std;

const int MAX_DISKS = 10;

struct Tower {
    int disks[MAX_DISKS];
    int top;
};

void push(Tower &t, int disk);
int pop(Tower &t);
void moveDisk(Tower &from, Tower &to);
void displayTowers(Tower towers[]);
void solveHanoi(int n, Tower towers[], int from, int to, int aux);

int main() {
    int n;

    cout << "enter the number of disks      :";
    cin >> n;

    if (n < 1 || n > MAX_DISKS) {
        cout << "Number of disks must be between 1 and " << MAX_DISKS << endl;
        return 0;
    }

    Tower towers[3];
    for (int i = 0; i < 3; i++)
        towers[i].top = -1;

    // largest disk (n) at the bottom of Tower1, smallest (1) on top
    for (int disk = n; disk >= 1; disk--)
        push(towers[0], disk);

    cout << endl;
    displayTowers(towers);
    solveHanoi(n, towers, 0, 2, 1);

    return 0;
}

void push(Tower &t, int disk) {
    t.disks[++t.top] = disk;
}

int pop(Tower &t) {
    return t.disks[t.top--];
}

void moveDisk(Tower &from, Tower &to) {
    push(to, pop(from));
}

// prints each tower from top disk to bottom disk
void displayTowers(Tower towers[]) {
    for (int i = 0; i < 3; i++) {
        cout << "Tower" << i + 1 << "->\t";
        for (int j = towers[i].top; j >= 0; j--)
            cout << "\t" << towers[i].disks[j];
        cout << endl;
    }
    cout << endl;
}

void solveHanoi(int n, Tower towers[], int from, int to, int aux) {
    if (n == 0)
        return;

    // move n-1 disks out of the way, move the largest, then bring n-1 back on top
    solveHanoi(n - 1, towers, from, aux, to);
    moveDisk(towers[from], towers[to]);
    displayTowers(towers);
    solveHanoi(n - 1, towers, aux, to, from);
}
