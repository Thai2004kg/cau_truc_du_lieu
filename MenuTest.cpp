#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

string optionNames[] = {"Nhap Vat Tu", "In Danh Sach Vat Tu", "Nhap Nhan Vien", "In Danh Sach Nhan Vien", "Lap Hoa Don", "Exit"};

void setConsoleColor(int textColor, int bgColor)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), textColor + (bgColor << 4));
}

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.dwSize = 10; // Set the cursor size
    // have to set to "10" due to console emulator errors.

    cursorInfo.bVisible = FALSE; // Set cursor visibility to false
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void displayMenu(int selectedOption, int consoleWidth)
{
    system("cls");

    int menuStartX = (consoleWidth - 20) / 2; // Centered "_____MENU_____" bar
    // assume x (coordinate) = 20, divided by 2 --> center
    COORD menuCoords[] = {
        {menuStartX, 3}, // index = 0
        {menuStartX, 5},
        {menuStartX, 7},
        {menuStartX, 9},
        {menuStartX, 11},
        {menuStartX, 13},
        {menuStartX, 15}};

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[0]);
    setConsoleColor(7, 0);
    cout << "_____MENU_____";

    for (int i = 1; i < 7; i++) // the range is: 1-2-3-4-5-6
    {
        if (i == selectedOption) // show ONLY the current selected option
        {
            setConsoleColor(0, 15); // text color to black and background color to white
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[i]);
            cout << "   " << optionNames[i - 1] << "   "; // Added spaces around the option
            setConsoleColor(7, 0);                        // text color to white and background color to black
        }
        else // show the rest of the options
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), menuCoords[i]);
            cout << "   " << optionNames[i - 1] << "   "; // Added spaces around the option
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
    const int numOptions = 7;
    int selectedOption = 1;

    // Get the console size information
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
        case 13:                         // Enter key
            openNewPage(selectedOption); // Pass selected option
            // Add your code for each menu option here
            break;
               }
    }

    return 0;
}
