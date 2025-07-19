#include "TextBuffer.h"
#include <iostream>
#include <fstream>

using namespace std;

// Node constructors
Node::Node() {
    text = "";
    next = nullptr;
    prev = nullptr;
}

Node::Node(const string& text) {
    this->text = text;
    next = nullptr;
    prev = nullptr;
}

// TextBuffer constructor
TextBuffer::TextBuffer() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// TextBuffer destructor
TextBuffer::~TextBuffer() {
    Node* temp = head;
    while (temp) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }
}

// Insert at the beginning
void TextBuffer::insertAtBegin(string sentence) {
    Node* newNode = new Node(sentence);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    count++;
}

// Insert at the end
void TextBuffer::insertAtEnd(string sentence) {
    Node* newNode = new Node(sentence);
    if (!tail) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
}

// Insert at a given index
void TextBuffer::insertAtGivenPos(string sentence, int index) {
    if (index < 0 || index > count) {
        cout << "Invalid index\n";
        return;
    }
    if (index == 0) {
        insertAtBegin(sentence);
    } else if (index == count) {
        insertAtEnd(sentence);
    } else {
        Node* temp = head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* newNode = new Node(sentence);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        count++;
    }
}

// Delete from beginning
bool TextBuffer::deleteAtBegin() {
    if (!head)
        return false;

    Node* temp = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete temp;
    count--;
    return true;
}

// Delete from end
bool TextBuffer::deleteAtEnd() {
    if (!tail)
        return false;

    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
    count--;
    return true;
}

// Delete from a given index
bool TextBuffer::deleteFromIndex(int index) {
    if (index < 0 || index >= count)
        return false;

    if (index == 0)
        return deleteAtBegin();
    else if (index == count - 1)
        return deleteAtEnd();

    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete temp;
    count--;
    return true;
}

// Update line at a given index
void TextBuffer::updateLineAt(int index, const string& newText) {
    if (index < 0 || index >= count) {
        cout << "Invalid index\n";
        return;
    }

    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->text = newText;
}

// Save buffer to file
void TextBuffer::saveToFile(const string& fileName) const {
    ofstream outFile(fileName);
    if (!outFile.is_open()) {
        cout << "Failed to open file for writing.\n";
        return;
    }

    Node* temp = head;
    while (temp) {
        outFile << temp->text << endl;
        temp = temp->next;
    }

    outFile.close();
    cout << "File saved successfully.\n";
}

// Load buffer from file
void TextBuffer::loadFromFile(const string& fileName) {
    ifstream inFile(fileName);
    if (!inFile.is_open()) {
        cout << "Failed to open file for reading.\n";
        return;
    }

    // Clear existing buffer
    while (!isEmpty()) {
        deleteAtBegin();
    }

    string line;
    while (getline(inFile, line)) {
        insertAtEnd(line);
    }

    inFile.close();
    cout << "File loaded successfully.\n";
}

// Get line at index
string TextBuffer::getLineAt(int index) const {
    if (index < 0 || index >= count)
        return "";

    Node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->text;
}

// Get total number of lines
int TextBuffer::getCount() const {
    return count;
}

// Check if buffer is empty
bool TextBuffer::isEmpty() const {
    return count == 0;
}

// Display buffer
void TextBuffer::display() {
    if (isEmpty()) {
        cout << "Buffer is empty.\n";
        return;
    }

    Node* temp = head;
    int index = 0;
    while (temp) {
        cout << index + 1 << ": " << temp->text << endl;
        temp = temp->next;
        index++;
    }
}
