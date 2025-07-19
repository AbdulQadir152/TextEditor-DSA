#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include "TextBuffer.h"
using namespace std;

class Command
{
    public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual ~Command() {}
};

class InsertCommand : public Command 
{
    private:
    TextBuffer *buffer;
    int index;
    string sentence;

    public:
    InsertCommand(TextBuffer *buffer, int index, string sentence);
    void execute() override;
    void undo() override;
};

class DeleteCommand : public Command 
{
    private:
    TextBuffer *buffer;
    int index;
    string deletedText;

    public:
    DeleteCommand(TextBuffer *buffer, int index);
    void execute() override;
    void undo() override;
};

class UpdateCommand : public Command 
{
    private:
    TextBuffer *buffer;
    int index;
    string newText;
    string oldText;

    public:
    UpdateCommand(TextBuffer *buffer, int index, string newText);
    void execute() override;
    void undo() override;
};

#endif
