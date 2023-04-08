#include <iostream>
using namespace std;

class Node{
public:
    int value;
    Node *next;
    Node();
    Node(int x);
    Node(int x, Node *n);
};

class List{
private:
    Node* head;
public:
    List();
    
    Node* insert_front(int x){
        Node* temp = new Node(x);
        if (head == NULL) {
            head = temp;
            return head;
        }
        temp->next = head;
        head = temp;
        return head;
    }
    
    Node* insert_back(int x){
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

    Node* insert_afterMiddle(int x){
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


    Node* insert_after(int index, int x){
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


    Node* erase_front(){
        if (head == NULL) {
            return NULL;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }


    Node* erase_back(){
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


    int searchValueByIndex(int index) {
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
            cout << "List is empty.\\n";
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

int main(int argc, const char * argv[]) {
    List l;
    
    //test insert_front()
    for(int i=1;i<6;i++){
        l.insert_front(i);
    }
    cout<<"Test insert_front(): ";
    l.displayList();
    cout<<endl;
    
    //test insert_afterMiddle()
    l.insert_afterMiddle(100);
    cout<<"Test insert_afterMiddle(100): ";
    l.displayList();
    cout<<endl;
    
    //test insert_back()
    for(int i=6;i<11;i++){
        l.insert_back(i);
    }
    cout<<"Test insert_back(): ";
    l.displayList();
    cout<<endl;
    
    //test erase_middle()
    l.erase_middle();
    cout<<"Test erase_middle(): ";
    l.displayList();
    cout<<endl;
    
    //test erase_back()
    l.erase_back();
    cout<<"Test erase_back(): ";
    l.displayList();
    cout<<endl;
    
    //test insert_after()
    l.insert_after(4, 999);
    cout<<"Test insert_after(4,999): ";
    l.displayList();
    cout<<endl;
    
    //test erase_after()
    l.erase_after(4);
    cout<<"Test erase_after(4): ";
    l.displayList();
    cout<<endl;
    
    //test erase_front()
    l.erase_front();
    cout<<"Test erase_front(): ";
    l.displayList();
    cout<<endl;
    
    //test searchValueByIndex()
    cout<<"Test searchValueByIndex(3): "<<l.searchValueByIndex(3)<<endl;
    
    //test searchIndexByValue()
    cout<<"Test searchValueByIndex(3): "<<l.searchIndexByValue(3)<<endl;
    return 0;
}
