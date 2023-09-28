#include <iostream>
#include <string>
#include <fstream>
#include <SFML/Audio.hpp>
using namespace std;



int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	sf::SoundBuffer correctBuffer;
	if (!correctBuffer.loadFromFile("win.ogg")) {
		return -1; // Ошибка при загрузке файла
	}
	sf::Sound correctSound;
	correctSound.setBuffer(correctBuffer);

	sf::SoundBuffer correctBuffer2;
	if (!correctBuffer2.loadFromFile("fail.ogg")) {
		return -1; // Ошибка при загрузке файла
	}
	sf::Sound correctSound2;
	correctSound2.setBuffer(correctBuffer2);

	int user;
	do {


		int rnd = 1 + rand() % 1;
		cout << "Введите число: ";
		cin >> user;
		if (rnd == user) {
			cout << "Вы угадали!" << endl;
			correctSound.play();
		}
		else {
			cout << "Вы не угадали. Загаданное число - " << rnd << endl;
			correctSound2.play();
		}
	}
		while (user != 0);


	return 0;
}