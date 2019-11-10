/*
MIT License

Copyright (c) 2019 Sven Lukas

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef TERMINAL_TERMINAL_H_
#define TERMINAL_TERMINAL_H_

#ifdef _WIN32
#include <windows.h>
#endif

namespace terminal {

class Terminal {
public:
	enum class Color { black, red, green, yellow, blue, magenta, cyan, white };

	Terminal();
	virtual ~Terminal();

	/* save position and color */
	const char* saveCursor();

	/* restore position and color */
	const char* restoreCursor();


	const char* clearScreen();
	const char* clearScreenToCursor();
	const char* clearScreenFromCursor();

	const char* clearLine();
	const char* clearLineToCursor();
	const char* clearLineFromCursor();

	const char* setTextPlain();
	const char* setTextBold(bool b = true);
	const char* setTextDim(bool b = true);
	const char* setTextItalic(bool b = true);
	const char* setTextReverse(bool b = true);
	const char* setTextUnderline(bool b = true);

	const char* setColorText(Color color);
	const char* setColorBackground(Color color);
	const char* resetColors();

private:
#ifdef _WIN32
	HANDLE stdoutHandle;
	DWORD outModeInit;
#endif
};

} /* namespace terminal */

#endif /* TERMINAL_TERMINAL_H_ */
