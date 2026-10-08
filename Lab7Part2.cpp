/*
Lab 7: Structure in C++ and Singly Linked Lists (Part 2 – Deletion & Searching)
Part A: Learn how to delete node from the linked list
1.
In Lab 6, you wrote codes for the following scenario:
Write a struct declaration for a linked list. Your structure should contain the following data members: an integer data containing a student id and a next pointer variable which points to the structure. In the main function, you will need to assign a value to student id, assign next to NULL (or 0), and finally display the contents of the data members.
In previous Lab 6 Exercise, you wrote the following functions:
•an insert function that inserts a new student at the beginning of the linked list
•a display function that displays the values in the linked list
•an insert function that inserts a new student at the end of the linked list; and
•an insert function that inserts a new student into a sorted linked list
 
Now, using the same question, write the following delete functions:
•a delete function that deletes a student from the beginning of the linked list
•a delete function that deletes a student from the end of the linked list; and
•a delete function that deletes a student from the linked list based on the student id.
[Estimate Finish Time: 60 minutes]
*/
 
#include <iostream>
using namespace std;
struct node_type {
	int id;
	struct node_type *prev, * next;
 
	node_type(int new_id) {
		id = new_id;
		prev = next = nullptr;
	}
};
class LIST {
private:
	struct node_type* head;
	struct node_type* tail;
	int size;
public:
	LIST();
	void display();
	void displayReversed();
	bool is_empty();
	void insertFront(int new_id);
	void insertRear(int new_id);
	struct node_type* deleteFront();
	struct node_type* deleteRear();
	struct node_type* insertSorted(int id);
	struct node_type* deleteId(int id);
};
 
LIST::LIST() {
	head = tail = nullptr;
	size = 0;
}
void LIST::display() {
	struct node_type* trav = head;
	cout << "head -> ";
	while (trav != nullptr) {
		cout << trav->id << " -> ";
		trav = trav->next;
	}
	cout << "null" << endl;
}
void LIST::displayReversed() {
	struct node_type* trav = tail;
	cout << "null <- ";
	while (trav != nullptr) {
		cout << trav->id << " <- ";
		trav = trav->prev;
	}
	cout << "head" << endl;
}
bool LIST::is_empty() {
	if (head == nullptr)
		return true;
	else
		return false;
}
void LIST::insertFront(int new_id) {
	struct node_type* new_node = new node_type(new_id);
 
	if (is_empty())
		head = tail = new_node;
	else {
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
	}
	size++;
	new_node = nullptr;
}
void LIST::insertRear(int new_id) {
	struct node_type* new_node = new node_type(new_id);
 
	if (is_empty())
		head = tail = new_node;
	else {
		tail->next = new_node;
		new_node->prev = tail;
		tail = tail->next;//tail = new_node;
	}
	size++;
	new_node = nullptr;
}
 
struct node_type* LIST::deleteFront() {
	struct node_type* delete_node = nullptr;
	if (is_empty())
		cout << "List is empty" << endl;
	else {
		delete_node = head;
		if (head->next == nullptr) {
			head = tail = nullptr;
		}
		else {
			head = head->next;
			delete_node->next = head->prev = nullptr;
		}
	}
	return delete_node;
}
 
struct node_type* LIST::deleteRear() {
	struct node_type* delete_node = nullptr;
	if (is_empty())
		cout << "List is empty" << endl;
	else {
		delete_node = tail;
		if (head->next == nullptr) {//singleton
			head = tail = nullptr;
		}
		else {
			tail = tail->prev;
			tail->next = delete_node->prev = nullptr;
		}
	}
	return delete_node;
}
struct node_type* LIST::insertSorted(int id) {
	struct node_type* new_node = new node_type(id);
 
	if (is_empty())
		head = tail = new_node;
	else {
		struct node_type* trav = head;
		while (trav->id < new_node->id)
			trav = trav->next;
		if (trav == head) {
			//insert front
			new_node->next = head;
			head->prev = new_node;
			head = new_node;
		}
		else if (trav == nullptr) {
			//insert rear
			tail->next = new_node;
			new_node->prev = tail;
			tail = tail->next;//tail = new_node;
		}
		else {
			//insert between nodes
			new_node->next = trav;
			new_node->prev = trav->prev;
			trav->prev->next = trav->prev = new_node;
		}
		size++;
	}
}
 
struct node_type* LIST::deleteId(int id) {
	struct node_type* trav = head, *delete_node = nullptr;
 
	while (trav != nullptr) {
		if (trav->id == id)
			break;
		trav = trav->next;
	}
 
	if (trav == nullptr)
		cout << "Id is NOT found." << endl;
	else {
		delete_node = trav;
		if (trav == head) {//delete front
			delete_node = head;
			if (head->next == nullptr) {
				head = tail = nullptr;
			}
			else {
				head = head->next;
				delete_node->next = head->prev = nullptr;
			}
		}
		else {
			if (trav == tail) {//delete rear
				delete_node = tail;
				if (head->next == nullptr) {//singleton
					head = tail = nullptr;
				}
				else {
					tail = tail->prev;
					tail->next = delete_node->prev = nullptr;
				}
			}
			else { // delete between nodes
				delete_node->prev->next = delete_node->next;
				delete_node->next->prev = delete_node->prev;
				delete_node->next = delete_node->prev = nullptr;
			}
		}
		size--;
	}
	trav = nullptr;
	return delete_node;
}
int menu();
int main() {
	LIST dstr_lab33, dstr_lab31;//sorted list
	bool stop = false;
	int choice;
	int new_id, id;
	do {
		choice = menu();
		switch (choice) {
		case 1:
		case 2:
			cout << "Enter new student\'s id: ";
			cin >> new_id;
			if (choice == 1)
				dstr_lab33.insertFront(new_id);
			else
				dstr_lab33.insertRear(new_id);
			break;
		case 3:
			cout << "3. display list" << endl;
			dstr_lab33.display();
			break;
			cout << "4. exit program" << endl;
		case 4:
			dstr_lab33.deleteFront();
			break;
		case 5:
			dstr_lab33.deleteRear();
			break;
		case 6:
			cout << "Enter id to delete: ";
			cin >> id;
			dstr_lab33.deleteId(id);
			break;
		case 7:
			cout << "7. display list in reversed" << endl;
			dstr_lab33.displayReversed();
			break;
		case 8:
			cout << "Enter new id: ";
			cin >> id;
			dstr_lab31.insertSorted(id);
		case 9:
			stop = true;
			break;
		default:
			cout << "Invalid input!" << endl;
		}
	} while (!stop);
}
 
int menu() {
	int choice;
	cout << "Welcome to dstr_lab33" << endl;
	cout << "1. insert to front of list" << endl;
	cout << "2. insert to rear of list" << endl;
	cout << "3. display list" << endl;
	cout << "4. delete at front" << endl;
	cout << "5. delete at rear" << endl;
	cout << "6. delete id" << endl;
	cout << "7. display list in reversed" << endl;
	cout << "8. insert to sorted list" << endl;
	cout << "9. exit program" << endl;
	cout << "Enter choice: ";
	cin >> choice;
	return choice;
}