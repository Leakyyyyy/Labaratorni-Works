#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

std::string arabic_to_roman(int arabic) {
    std::map<int, std::string, std::greater<int>> romanNumerals = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    std::string result;
    for (const auto& kvp : romanNumerals) {
        while (arabic >= kvp.first) {
            result += kvp.second;
            arabic -= kvp.first;
        }
    }

    return result;
}

int roman_to_arabic(string roman) {
    map<char, int> romanNumerals = {
        {'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, 
        {'X', 10}, {'V', 5}, {'I', 1}
    };
    int result = 0;
    for (int i = 0; i < roman.length(); i++) {
        if (i + 1 < roman.length() && romanNumerals[roman[i]] < romanNumerals[roman[i + 1]]) {
            result += romanNumerals[roman[i + 1]] - romanNumerals[roman[i]];
            i++;
        } else {
            result += romanNumerals[roman[i]];
        }
    }
    return result;
}

int main() {
    int arabicNumber = 366;
    string romanNumber = arabic_to_roman(arabicNumber);
    cout << "Арабское число " << arabicNumber << " в римской записи: " << romanNumber << endl;

    string romanNumberStr = "CDLV";
    int arabicNumberVal = roman_to_arabic(romanNumberStr);
    cout << "Римское число " << romanNumberStr << " в арабской записи: " << arabicNumberVal << endl;

    return 0;
}
