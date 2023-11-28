#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

string optionNames[] = {"Nhap Vat Tu", "In Danh Sach", "Nhap Nhan Vien", "Lap Hoa Don"};

void setConsoleColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor + (bgColor << 4));
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 100;     // Set the cursor size to zero
    cursorInfo.bVisible = FALSE; // Set cursor visibility to false
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void displayMenu(int selectedOption, int consoleWidth)
{
    system("cls");

    int menuStartX = (consoleWidth - 10) / 2; // Center the "___MENU___" bar
    COORD menuCoords[] = {
        {menuStartX, 3},
        {menuStartX, 4},
        {menuStartX, 5},
        {menuStartX, 6},
        {menuStartX, 7}};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[0]);
    setConsoleColor(7, 0);
    cout << "_____MENU_____";

    for (int i = 1; i < 5; i++)
    {
        if (i == selectedOption)
        {
            setConsoleColor(0, 15);
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[i]);
            cout << optionNames[i - 1];
            setConsoleColor(7, 0);
        }
        else
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[i]);
            cout << optionNames[i - 1];
        }
    }
}

void openNewPage(int option)
{
    system("cls");
    cout << "Page for option " << option << endl;
    // Add your code for each menu option here
    cout << "Press any key to return to the menu...";
    _getch(); // Wait for a key press before returning to the menu
}

int main()
{
    const int numOptions = 5;
    int selectedOption = 0;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    hideCursor(); // Call hideCursor to hide the cursor

    while (true)
    {
        displayMenu(selectedOption, consoleWidth);

        char key = _getch();

        switch (key)
        {
        case 13: // Enter key
            cout << "\nOption " << selectedOption << " selected!\n";
            openNewPage(selectedOption); // Pass selected option
            // Add your code for each menu option here
            break;

        case 27: // Escape key
            return 0;

        case 72: // Up arrow key
            selectedOption = (selectedOption - 1 + numOptions) % numOptions;
            break;

        case 80: // Down arrow key
            selectedOption = (selectedOption + 1) % numOptions;
            break;
        }
    }

    return 0;
}
