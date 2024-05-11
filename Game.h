#pragma once

#include <vector>
#include <string>

class Game {
private:
    std::vector<std::string> countries;
    std::string m_country;
    int m_points {0};

public:
    int getPoints() {return m_points;}

    void Clear();
    std::string ConvertToLowercase(std::string& s);
    void SearchCountries(void);
    void PopulateCountries(void);
    void setCountry(std::string s);
    void ConvertToFullName(void);
    void ReplaceElement(void);
    std::string GenerateRandomString(void);
    bool WinGame(void);
    void Timer(void);
};