#include <iostream>
#include "Editor.h"

using namespace std;

int main()
{
    Editor editor;
    int choice, index;
    string text, filename;

    do
    {
        cout << "\n----- Mini Text Editor Menu -----\n";
        cout << "1. Insert a line\n";
        cout << "2. Delete a line\n";
        cout << "3. Update a line\n";
        cout << "4. Undo last operation\n";
        cout << "5. Redo last undone operation\n";
        cout << "6. Display text buffer\n";
        cout << "7. Save buffer to file\n";
        cout << "8. Load buffer from file\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice)
        {
            case 1:
                cout << "Enter index to insert at (0-based): ";
                cin >> index;
                cin.ignore();
                cout << "Enter text to insert: ";
                getline(cin, text);
                editor.performCommand(new InsertCommand(editor.getBuffer(), index, text));
                break;

            case 2:
                cout << "Enter index to delete (0-based): ";
                cin >> index;
                cin.ignore();
                editor.performCommand(new DeleteCommand(editor.getBuffer(), index));
                break;

            case 3:
                cout << "Enter index to update (0-based): ";
                cin >> index;
                cin.ignore();
                cout << "Enter new text: ";
                getline(cin, text);
                editor.performCommand(new UpdateCommand(editor.getBuffer(), index, text));
                break;

            case 4:
                editor.undo();
                break;

            case 5:
                editor.redo();
                break;

            case 6:
                editor.displayBuffer();
                break;

            case 7:
                cout << "Enter filename to save to: ";
                cin >> ws;
                getline(cin, filename);
                editor.saveToFile(filename);
                break;

            case 8:
                cout << "Enter filename to load from: ";
                cin >> ws;
                getline(cin, filename);
                editor.loadFromFile(filename);
                break;

            case 0:
                cout << "Exiting editor. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 0);

    return 0;
}
