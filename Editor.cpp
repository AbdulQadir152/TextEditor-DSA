#include "Editor.h"
#include <iostream>

Editor::Editor() : undoStack(100), redoStack(100) {}

void Editor::performCommand(Command* cmd)
{
    cmd->execute();
    undoStack.push(cmd);
    while(!redoStack.isEmpty())
        redoStack.pop();
}

void Editor::undo()
{
    if(!undoStack.isEmpty())
    {
        Command* cmd = undoStack.pop();
        cmd->undo();
        redoStack.push(cmd);
    }
    else
    {
        cout << "Nothing to undo!\n";
    }
}

void Editor::redo()
{
    if(!redoStack.isEmpty())
    {
        Command* cmd = redoStack.pop();
        cmd->execute();
        undoStack.push(cmd);
    }
    else
    {
        cout << "Nothing to redo!\n";
    }
}

void Editor::saveToFile(const string& fileName)
{
    buffer.saveToFile(fileName);
}

void Editor::loadFromFile(const string& fileName)
{
    buffer.loadFromFile(fileName);
    while(!undoStack.isEmpty()) undoStack.pop();
    while(!redoStack.isEmpty()) redoStack.pop();
}

void Editor::displayBuffer()
{
    buffer.display();
}

TextBuffer* Editor::getBuffer()
{
    return &buffer;
}
