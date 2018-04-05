/*! ********************************************************
 * OOP345: Milestone 1
 * \file Utilities.h
 * \class Utilities
 * \version Version 1.0
 * \date 2018-03-25
 * \author Dominic Nunes - 016-183-121
***********************************************************/

#ifndef MS_UTILITIES_H
#define MS_UTILITIES_H

#include <string>
#include <fstream>

/*! OOP345 Project namespace */
namespace MS
{
/*!
 * \brief Utility functions with general usages throughout the application
 * */
class Utilities
{
    size_t field_width;           // maximum field width needed
    static char delimiter;        // field delimiter character
    static std::ofstream logFile; // log file

public:

    /*!
     * Upon instantiation, a Utilities object initializes the value of its
     * field_width instance variable to 1.
     * */
    Utilities();

    /*!
     * resets the field width of the current object to fw
     *
     * \param fw is the size of field width to set
     * */
    void setFieldWidth(size_t fw);

    /*!
     * returns the field width of the current object
     * */
    size_t getFieldWidth() const;

    /*!
     *
     * removes whitespace from the beginning and end of a string
     *
     * \param str is the string to be trimmed
     *
     * \returns a token with leading and trailing whitespace removed
     * */
    const std::string trimToken(std::string str);

    /*!
     * receives a reference to string str, a reference to the position (next_pos)
     * in this string at which to start extraction, and a reference to a boolean
     * flag (more).  This function returns the next token found and sets more to
     * true if the record contains more tokens after the extracted token; false
     * otherwise.  This function updates the current object's field_width data member
     * if its current value is less than the size of the token extracted.  This
     * function reports an exception if there are two delimiters with no token
     * between them.
     *
     * \param str is a reference to the string to be parsed
     * \param next_pos is a reference to the position in str
     * \param more is a reference flag used to continue or end parsing
     *
     * \returns the next token from the record
     * */
    const std::string nextToken(const std::string &str, size_t &next_pos, bool &more);

    /*!
     * resets the delimiter for this class to the character received
     *
     * \param delim is the delimiter for Utilities::delimiter to be set to
     * */
    static void setDelimiter(const char delim);

    /*!
     * receives the address of an unmodifiable C-style string containing the name
     * of the log file for the project.  This function opens a file of this name
     * for writing and truncation.
     *
     * \param filename is a C-style string which Utilities::logFile is set to
     * */
    static void setLogFile(const char *filename);

    /*!
     * \returns a modifiable reference to the log file
     * */
    static std::ofstream &getLogFile();
};
}

#endif // MS_UTILITIES_H