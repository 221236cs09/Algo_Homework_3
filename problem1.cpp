
#include<iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
    Node(int x, Node* n) : value(x), next(n) {}
};

class List {
private:
    Node* head;

public:
    List() {
        head = NULL;
    }

    Node* insert_front(int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return head;
        }
        temp->next = head;
        head = temp;
        return head;
    }

    Node* insert_back(int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return head;
        }
        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }

    Node* insert_afterMiddle(int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return head;
        }
        Node* curr = head;
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < count / 2; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        return head;
    }

    Node* insert_after(int index, int x) {
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return head;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        return head;
    }

    Node* erase_front() {
        if (head == NULL) {
            return NULL;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* erase_back() {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return head;
        }
        Node* curr = head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = NULL;
        delete temp;
        return head;
    }

    Node* erase_middle() {
        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        Node* prev = NULL;
        int count = 0;
        while (curr != NULL) {
            count++;
            curr = curr->next;
        }
        curr = head;
        for (int i = 0; i < count / 2; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;
        return head;
    }

    Node* erase_after(int index) {
        if (head == NULL) {
            return NULL;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        Node* temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }

    int searchIndexByValue(int val) {
        if (head == NULL) {
            return -1;
        }
        Node* curr = head;
        int index = 0;
        while (curr != NULL) {
            if (curr->value == val) {
                return index;
            }
            curr = curr->next;
            index++;
        }
        return -1;
    }

    int searchValueByValue(int index) {
        if (head == NULL) {
            return -1;
        }
        Node* curr = head;
        for (int i = 0; i < index; i++) {
            curr = curr->next;
        }
        return curr->value;
    }

    void displayList() {
        if (head == NULL) {
            cout << "List is empty.\\\\n";
            return;
        }
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->value << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    List mylist;
    mylist.insert_front(10);
    mylist.insert_front(20);
    mylist.insert_back(30);
    mylist.insert_afterMiddle(40);
    mylist.insert_after(1, 50);
    mylist.displayList();
    mylist.erase_front();
    mylist.erase_back();
    mylist.erase_middle();
    mylist.erase_after(1);
    mylist.displayList();
    cout << "Index of 40: " << mylist.searchIndexByValue(40) << endl;
    cout << "Value at index 2: " << mylist.searchValueByValue(2) << endl;
    return 0;
}

