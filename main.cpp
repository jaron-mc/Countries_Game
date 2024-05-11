#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include "Game.hpp"
#include <ctime>

int main(void) {

    Game CountriesGame;

    srand(time(NULL));

    int points {0};
    bool activeGame {true};
    std::string country;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "--------------Country Quiz----------------" << "\n";

    CountriesGame.PopulateCountries();
    while (activeGame) {
        std::cout << "\nEnter a country ('q' to end game, 't' for planned features): ";
	    getline(std::cin, country);

        if (country == "q") {
            activeGame = false;
            std::cout << "\nThe game has ended!\n";
            std::cout << "Final score: " << CountriesGame.getPoints() << " / 197 (" <<
            static_cast<double>(CountriesGame.getPoints()) / 197 << "%)\n";
        }

        CountriesGame.ConvertToLowercase(country);
        CountriesGame.setCountry(country);
        CountriesGame.SearchCountries();

        if (CountriesGame.WinGame()) {
            activeGame = false;
            std::cout << "\nYou have correctly named all 197 countries!" << std::endl;
        } 
    }

    return 0;
}
