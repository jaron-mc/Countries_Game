#include "Game.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unistd.h>
#include <chrono>

void Game::setCountry(std::string s) {
	m_country = s;
}

void Game::Clear(void) {
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

void Game::SearchCountries(void) {
	if (std::find(countries.begin(), countries.end(), m_country) != countries.end()) {
		m_points++;;
		Clear();
		ReplaceElement();
		ConvertToFullName();
		std::cout << '\n' << m_country << " is a country! 1 point added!\n";
		std::cout << "Current Points: " << m_points << '\n';
	} else if (m_country != "q") {
		std::cout << "\nInvalid input: Try again\n";
	}
}

void Game::PopulateCountries(void) {
	std::string country;
	std::string file_object = "countries_list.txt";
	std::ifstream infile(file_object);

	if (!infile) {
		std::cerr << "Error reading from file: Please make sure countries_list.txt is available" << '\n';
		exit(1);
	}

	while (!infile.eof()) {
		getline(infile, country);
		countries.push_back(country);
	}

	infile.close();
	}

void Game::ConvertToFullName(void) {
	m_country[0] -= 32;
	for (int i {0}; i < m_country.size(); i++) {
		if (m_country[i] == ' ') {
			m_country[i+1] -=32;
		}
	}	
}

std::string Game::ConvertToLowercase(std::string& s) {
    for (int i {0}; i < s.size(); i++) {
        if (s[i] > 64 && s[i] < 97) {
            s[i] += 32;
        }
    }
    return s;
}

void Game::Timer(void) {
	// Do something
}

void Game::ReplaceElement(void) {
	std::vector<std::string>::iterator it = std::find(countries.begin(), countries.end(), m_country);
	size_t index = std::distance(countries.begin(), it);
	countries.at(index) = GenerateRandomString();
}

std::string Game::GenerateRandomString(void) {
	const int length = 12;
	static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
	std::string result;
	result.resize(length);

	for (int i {0}; i < length; i++) {
		result[i] = charset[rand() % charset.length()];
	}
	return result;
}

bool Game::WinGame(void) {
	if (m_points >= 197) {
		return true;
	}
	return false;
}