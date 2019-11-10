#include <terminal/Terminal.h>
#include <iostream>
#include <chrono>
#include <thread>

void test() {
	terminal::Terminal terminal;
	std::cout << terminal.clearScreen() << std::flush;
	std::cout << terminal.saveCursor() << std::flush;
	std::cout << "Foo 1" << std::endl;
	std::cout << terminal.setColorText(terminal::Terminal::Color::green) << "Foo 2" << terminal.setColorText(terminal::Terminal::Color::white) << std::endl;
	std::cout << terminal.setTextBold() << "Bold" << terminal.setTextBold(false) << std::endl;
	std::cout << terminal.setTextItalic() << "Italic" << terminal.setTextPlain() << "plain" << std::endl;
	std::cout << terminal.setTextDim() << "Dim" << terminal.setTextDim(false) << std::endl;
	std::cout << terminal.setTextReverse() << "Reverse" << terminal.setTextReverse(false) << std::endl;
	std::cout << terminal.setTextUnderline() << "Underline" << terminal.setTextUnderline(false) << std::endl;

	std::this_thread::sleep_for(std::chrono::seconds(2));

//	std::cout << setColorText(red) << setColorBackground(blue) << "Hello, " << saveCursor() << "World" << resetColors() << "This is normal Color" << restoreCursor() << setColorBackground(white) << saveCursor() << "BLA\n" << restoreCursor() << " " << std::endl;
}

int main(int argc, const char *argv[]) {
	test();

	return 0;
}
