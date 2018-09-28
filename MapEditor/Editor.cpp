#include <iostream>
#include <tchar.h>
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <string>
#include "Editor.h"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Main.hpp"

std::string GetFileFromUser() {
	char filename[MAX_PATH];

	OPENFILENAME ofn;
	ZeroMemory(&filename, sizeof(filename));
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;  // If you have a window to center over, put its HANDLE here
	ofn.lpstrFilter = (LPCWSTR)"Text Files\0*.txt\0Any File\0*.*\0";
	ofn.lpstrFile = (LPWSTR)filename;
	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrTitle = (LPCWSTR)"Select a File, yo!";
	ofn.Flags = OFN_DONTADDTORECENT | OFN_FILEMUSTEXIST;

	if (GetOpenFileNameA((LPOPENFILENAMEA)&ofn))
	{
		return std::string(filename, MAX_PATH);
	}
	else
	{
		// All this stuff below is to tell you exactly how you messed up above. 
		// Once you've got that fixed, you can often (not always!) reduce it to a 'user cancelled' assumption.
		switch (CommDlgExtendedError())
		{
		case 1:
		default: std::cout << "You cancelled.\n";
		}
	}
	return NULL;
}

int main() {
	std::string pathToTileset = GetFileFromUser();

	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

	window.setPosition(sf::Vector2i(10, 50));

	window.setTitle("SFML Window");

	sf::Vector2u size = window.getSize();
	unsigned int width = size.x;
	unsigned int height = size.y;

	while (window.isOpen()) {

		sf::Texture texture;
		if (!texture.loadFromFile(pathToTileset)) {
			//error
		}

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		//Clear the window
		window.clear(sf::Color::Black);

		//Draw everything here
		window.draw(sf::Sprite(texture));

		//end the current frame
		window.display();

	}

	return 0;
}