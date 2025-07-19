#ifndef EDITOR_H
#define EDITOR_H

#include "TextBuffer.h"
#include "Stack.h"
#include "Command.h"

class Editor 
{
    private:
    TextBuffer buffer;
    Stack<Command*> undoStack;
    Stack<Command*> redoStack;

    public:
    Editor();
    void performCommand(Command* cmd);
    void undo();
    void redo();
    void saveToFile(const string& fileName);
    void loadFromFile(const string& fileName);
    void displayBuffer();
    TextBuffer* getBuffer();
};

#endif
