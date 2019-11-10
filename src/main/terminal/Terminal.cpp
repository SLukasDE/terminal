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

#include <terminal/Terminal.h>
#include <iostream>

#ifdef _WIN32
// Some old MinGW/CYGWIN distributions don't define this:
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING  0x0004
#endif
#endif


namespace terminal {

Terminal::Terminal() {
#ifdef _WIN32
	DWORD outMode = 0;
 	stdoutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

 	if(stdoutHandle == INVALID_HANDLE_VALUE) {
 		exit(GetLastError());
 	}

 	if(!GetConsoleMode(stdoutHandle, &outMode)) {
 		exit(GetLastError());
 	}

 	outModeInit = outMode;

     // Enable ANSI escape codes
 	outMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;

 	if(!SetConsoleMode(stdoutHandle, outMode)) {
 		exit(GetLastError());
 	}
#endif
	std::cout << "\x1b""[?1049h" << std::flush;
}

Terminal::~Terminal() {
    // Reset colors
	std::cout << resetColors() << std::flush;
	std::cout << "\x1b""[?1049l" << std::flush;

#ifdef _WIN32
    // Reset console mode
	if(!SetConsoleMode(stdoutHandle, outModeInit)) {
		exit(GetLastError());
	}
#endif
}

const char* Terminal::saveCursor() {
	return "\x1b""7";
}

const char* Terminal::restoreCursor() {
	return "\x1b""8";
}

const char* Terminal::clearScreen() {
	return "\x1b""[2J";
}

const char* Terminal::clearScreenToCursor() {
	return "\x1b""[1J";
}

const char* Terminal::clearScreenFromCursor() {
	return "\x1b""[0J";
}

const char* Terminal::clearLine() {
	return "\x1b""2dK";
}

const char* Terminal::clearLineToCursor() {
	return "\x1b""1dK";
}

const char* Terminal::clearLineFromCursor() {
	return "\x1b""0dK";
}

const char* Terminal::setTextPlain() {
	return "\x1b""[0m";
}

const char* Terminal::setTextBold(bool b) {
	return b ? "\x1b""[1m" : "\x1b""[21m";
}

const char* Terminal::setTextDim(bool b) {
	return b ? "\x1b""[2m" : "\x1b""[22m";
}

const char* Terminal::setTextItalic(bool b) {
	return b ? "\x1b""[3m" : "\x1b""[23m";
}

const char* Terminal::setTextReverse(bool b) {
	return b ? "\x1b""[7m" : "\x1b""[27m";
}

const char* Terminal::setTextUnderline(bool b) {
	return b ? "\x1b""[4m" : "\x1b""[24m";
}

const char* Terminal::setColorText(Color color) {
	switch(color) {
	case Color::black:
		return "\x1b""[30m";
	case Color::red:
		return "\x1b""[31m";
	case Color::green:
		return "\x1b""[32m";
	case Color::yellow:
		return "\x1b""[33m";
	case Color::blue:
		return "\x1b""[34m";
	case Color::magenta:
		return "\x1b""[35m";
	case Color::cyan:
		return "\x1b""[36m";
	case Color::white:
		return "\x1b""[37m";
	default:
		break;
	}
	return "";
}

const char* Terminal::setColorBackground(Color color) {
	switch(color) {
	case Color::black:
		return "\x1b""[40m";
	case Color::red:
		return "\x1b""[41m";
	case Color::green:
		return "\x1b""[42m";
	case Color::yellow:
		return "\x1b""[43m";
	case Color::blue:
		return "\x1b""[44m";
	case Color::magenta:
		return "\x1b""[45m";
	case Color::cyan:
		return "\x1b""[46m";
	case Color::white:
		return "\x1b""[47m";
	default:
		break;
	}
	return "";
}

const char* Terminal::resetColors() {
	return "\x1b""[0m";
}

} /* namespace terminal */
