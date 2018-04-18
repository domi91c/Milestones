/*! ********************************************************
 * \name OOP345: Milestone 2
 * \file CustomerItem.h
 * \class CustomerItem
 * \version Version 1.0
 * \date 2018-03-27
 * \author Dominic Nunes - 016-183-121
***********************************************************/

#ifndef MS_CUSTOMERITEM_H
#define MS_CUSTOMERITEM_H

#include <iostream>
#include <string>

namespace MS
{

class Item;

/*!
 * \brief A CustomerItem object manages a single item requested within a
 * customer order throughout the assembly process.  A customer item request
 * includes the name of the item requested, the state of the request, and the
 * unique code printed on the item label.
 * */
class CustomerItem
{
    std::string name;  // name of the requested component
    bool filled;       // status of the request
    unsigned int code; // unique shipping label

public:

    /*!
     * Upon instantiation, an CustomerItem object either receives nothing or a
     * reference to an unmodifiable std::string.  This string contains the name
     * of the customer item requested.
     *
     * The constructor initializes the name identifying the item requested to
     * the name received or to an empty state if no name was specified,
     * initializes filled to false and initializes the item code to 0.
     *
     * \param _name is an unmodifiable string
     * */
    explicit CustomerItem(const std::string &_name = std::string());

    /*!
     * \param item is a reference to an Item
     *
     * \returns true if the current object asks for item; false otherwise
     * */
    bool asksFor(const Item &item) const;

    /*!
     * \returns true if the current object's request has been filled
     * */
    bool isFilled() const;

    /*!
     * sets the item code for the current object to the value received and
     * switches the status of the current object to filled
     *
     * \param _code is an unsigned integer
     * */
    void fill(const unsigned int _code);

    /*!
     * resets the item code for the current object to 0 and resets the status
     * of the current object to not filled
     * */
    void clear();

    const std::string &getName() const;

    /*!
     * inserts into os a description of the customer item as shown in the sample
     * output listed below.  The description consists of
     * - the symbol + or - identifying the fill status of the item request
     * - the code printed on the item if filled or 0 if not filled in a field
     *   width of CODE_WIDTH padded with 0s and enclosed within brackets
     * - the name of the customer item
     *
     * \param os is an ostream object
     * */
    void display(std::ostream &os) const;
};
}

#endif // MS_CUSTOMERITEM_H