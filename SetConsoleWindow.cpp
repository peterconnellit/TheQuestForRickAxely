#include <iostream>

//Program on Windows 2000 or higher
#define _WIN32_WINNT 0x0500
#include <windows.h> 

using std::cout;

//Sets window of your console into values you desire
bool SetWindowBool(int Width, int Height)//http://www.3dbuzz.com/forum/threads/102195-How-do-you-resize-a-console-window-in-C
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	//Get handle of the standard output 
	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (Handle == NULL)
	{
		cout << "Failure in getting the handle\n" << GetLastError();
		return FALSE;
	}

	//Set screen buffer size to that specified in coord 
	if (!SetConsoleScreenBufferSize(Handle, coord))
	{
		cout << "Failure in setting buffer size\n" << GetLastError();
		return FALSE;
	}

	//Set the window size to that specified in Rect 
	if (!SetConsoleWindowInfo(Handle, TRUE, &Rect))
	{
		cout << "Failure in setting window size\n" << GetLastError();
		return FALSE;
	}

	return TRUE;
}

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height + 50; //If you want the scroll bar buffer must be larger than visible area

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE); //Get Handle 
	SetConsoleScreenBufferSize(Handle, coord); //Set Buffer Size 
	SetConsoleWindowInfo(Handle, TRUE, &Rect); //Set Window Size 

}