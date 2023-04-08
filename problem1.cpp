Node::Node() {
    value = 0;
    next = NULL;
}

Node::Node(int x, Node* n) {
    value = x;
    next = n;
}

List::List() {
    head = NULL;
}

Node* List::insert_front(int x) {
    Node* temp = new Node(x);
    if (head == NULL) {
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
    return head;
}

Node* List::insert_back(int x) {
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

Node* List::insert_afterMiddle(int x) {
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

Node* List::insert_after(int index, int x) {
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

Node* List::erase_front() {
    if (head == NULL) {
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* List::erase_back() {
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

Node* List::erase_middle() {
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

Node* List::erase_after(int index) {
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

int List::searchIndexByValue(int val) {
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

int List::searchValueByValue(int index) {
    if (head == NULL) {
        return -1;
    }
    Node* curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->value;
}

void List::displayList() {
    if (head == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->value << " ";
        curr = curr->next;
    }
    cout << endl;
}
