# 📝 Mini Text Editor in C++

A **Data Structures & Algorithms-based** text editor built in C++ that supports insertion, deletion, updating, and file operations on a line-by-line text buffer — along with **undo** and **redo** functionality using the Command design pattern.

## 🚀 Features

- Add, update, or delete lines at any position
- Save buffer to a text file
- Load buffer from a text file
- Undo and redo any modification (via Command Pattern)
- Displays all lines with line numbers
- Command-line interface for interaction

## 💡 Concepts Used

- **Doubly Linked List** – Core data structure to manage the text buffer
- **Command Design Pattern** – For implementing undo/redo functionality
- **Stacks (Custom Template)** – Used for managing undo and redo history
- **File I/O** – Load from and save to external `.txt` files

## 📁 Project Structure

```
DSA-TextEditor/
├── Command.h            # Command interface and Insert/Delete/Update command classes
├── Command.cpp          # Implementation of command classes
├── Editor.h             # Editor class to manage buffer and undo/redo
├── Editor.cpp           # Editor method implementations
├── Stack.h              # Template stack class for undo/redo
├── Stack.cpp            # (optional, if separated implementation is used)
├── TextBuffer.h         # Doubly linked list for text line storage
├── TextBuffer.cpp       # Implementation of text buffer methods
├── main.cpp             # Entry point, handles menu and user interaction
├── FAST                 # (optional) any config or custom file you added
└── README.md            # Project documentation (this file)
```

## 🛠️ How It Works

- Text lines are stored in a doubly linked list.
- Insert, delete, and update actions are encapsulated as commands.
- Each command supports both execution and undoing.
- Two custom stacks manage the undo and redo history.
- File operations allow saving/loading buffer contents persistently.