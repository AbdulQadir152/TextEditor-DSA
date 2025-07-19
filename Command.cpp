#include "Command.h"
#include <iostream>

InsertCommand::InsertCommand(TextBuffer *buffer, int index, string sentence)
{
    this->buffer = buffer;
    this->index = index;
    this->sentence = sentence;
}

void InsertCommand::execute()
{
    if(sentence.empty())
    {
        cout << "Warning: Empty insert command.\n";
        return;
    }
    buffer->insertAtGivenPos(sentence, index);
}

void InsertCommand::undo()
{
    buffer->deleteFromIndex(index);
}

DeleteCommand::DeleteCommand(TextBuffer *buffer, int index)
{
    this->buffer = buffer;
    this->index = index;
    deletedText = "";
}

void DeleteCommand::execute()
{
    if(index < 0 || index >= buffer->getCount()) return;
    deletedText = buffer->getLineAt(index);
    buffer->deleteFromIndex(index);
}

void DeleteCommand::undo()
{
    buffer->insertAtGivenPos(deletedText, index);
}

UpdateCommand::UpdateCommand(TextBuffer *buffer, int index, string newText)
{
    this->buffer = buffer;
    this->index = index;
    this->newText = newText;
    oldText = buffer->getLineAt(index);
}

void UpdateCommand::execute()
{
    buffer->updateLineAt(index, newText);
}

void UpdateCommand::undo()
{
    buffer->updateLineAt(index, oldText);
}
