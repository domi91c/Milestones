#include <iostream>
#include "Utilities.h"

namespace MS
{
char Utilities::delimiter;

std::ofstream Utilities::logFile;

Utilities::Utilities()
{
    field_width = 1;
}

void Utilities::setFieldWidth(size_t fw)
{
    field_width = fw;
}

size_t Utilities::getFieldWidth() const
{
    return field_width;
}

const std::string Utilities::trimToken(std::string str)
{
    size_t first_pos = str.find_first_not_of(' '); // first position that is not whitespace.
    size_t last_pos = str.find_last_not_of(' '); // last position that is not whitespace.
    if (first_pos < std::string::npos) {
        // using first and last positions, extract token from whitespace.
        str = str.substr(first_pos, (last_pos - first_pos + 1));
    }
    return str;
}

const std::string Utilities::nextToken(const std::string &str, size_t &next_pos, bool &more)
{
    std::string token;
    size_t pos;

    // if the record is empty, set more to false and throw an error
    if (str.empty()) {
        more = false;
        throw "*** record is empty ***";
    }

    for (pos = next_pos; pos < str.size() + 1; ++pos) {
        // break from loop when delimiter is reached
        if (str[pos] == delimiter) {
            next_pos = pos + 1;
            break;
        }
            // push current character to token
        else {
            token.push_back(str[pos]);
        }
    }
    ///////// Error Checks
    // trim any whitespace from beginning and ends of token
    std::string trimmedToken = trimToken(token);
    if (pos >= str.size()) more = false;
    // if token is empty, throw an error
    if (trimmedToken.empty() || trimmedToken[0] == ' ') {
        throw str + "<--- *** no token found before the delimiter ***";
    }
    // remove null terminator if it is not the only character
    if (trimmedToken[trimmedToken.size() - 1] == '\0' && trimmedToken.size() > 1) {
        trimmedToken.resize(trimmedToken.size() - 1);
    }
    // set static field_width to current token size
    field_width = trimmedToken.size();
    return trimmedToken;
}

void Utilities::setDelimiter(const char delim)
{
    Utilities::delimiter = delim;
}

void Utilities::setLogFile(const char *filename)
{
    logFile.close();
    logFile.open(filename);
}

std::ofstream &Utilities::getLogFile()
{
    return logFile;
}
}
