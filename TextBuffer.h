#ifndef TEXTBUFFER_H
#define TEXTBUFFER_H

#include <string>
using namespace std;

class Node
{
    private:
    string text;
    Node* next;
    Node* prev;

    public:
    Node();
    Node(const string& text);
    friend class TextBuffer;
};

class TextBuffer
{
    private:
    Node* head;
    Node* tail;
    int count;

    public:
    TextBuffer();
    void insertAtBegin(string sentence);
    void insertAtGivenPos(string sentence, int index);
    void insertAtEnd(string sentence);
    void updateLineAt(int index, const string& newText);
    bool deleteAtBegin();
    bool deleteFromIndex(int index);
    bool deleteAtEnd();
    void saveToFile(const string& fileName) const;
    void loadFromFile(const string& fileName);
    int getCount() const;
    string getLineAt(int index) const;
    bool isEmpty() const;
    void display();
    ~TextBuffer();
};

#endif
