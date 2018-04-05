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
    // first position that is not whitespace.
    size_t first_pos = str.find_first_not_of(' ');
    // last position that is not whitespace.
    size_t last_pos = str.find_last_not_of(' ');

    if (first_pos < std::string::npos) {
        // using first and last positions, extract token from whitespace.
        str = str.substr(first_pos, (last_pos - first_pos + 1));
    }
    return str;
}

const std::string Utilities::nextToken(const std::string &str, size_t &next_pos, bool &more)
{
    std::string token;
    // if str starts with a delimiter, throw an error.
    if (str[0] == delimiter) {
        throw str + "<--  *** no token found before the delimiter ***";
    }

    for (size_t i = next_pos; i < 1000; ++i) {
        // find occurence of delimiter.
        if (str[i] == delimiter) {
            // if a delimeter is found right after another (missing token in between),
            // throw an error.
            if (str[i + 1] == delimiter) {
                throw str + "<--  *** no token found before the delimiter ***";
            }
            // increment next_pos so nextToken starts after this point on next run.
            next_pos = i + 1;
            break;
        }
        else if (i == str.size()) {
            // stop checking for tokens and return current token.
            more = false;
            return token;
        }
        else {
            // if current str character is not a delimiter or the end of the string, add
            // str character to current token.
            token.push_back(str[i]);
        }
    }
    field_width = token.size();
    return token;
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
