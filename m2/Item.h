/*! ********************************************************
 * \name OOP345: Milestone 2
 * \file Item.h
 * \class Item
 * \version Version 1.0
 * \date 2018-03-27
 * \author Dominic Nunes - 016-183-121
***********************************************************/

#ifndef MS_ITEM_H
#define MS_ITEM_H

#include <iostream>
#include <string>

/*! OOP345 Project namespace */
namespace MS
{

const unsigned int CODE_WIDTH = 5;

/*!
 * \brief An Item object manages a single item available in the assembly line for
 * filling a customer item request in a customer order.  Each Item object holds
 * the name of the item, the name of the task that inserts the item into a
 * product, the name of the task that removes the item from a product, a
 * detailed description of the item and the current code to be printed on the
 * next Item that fills an CustomerItem's request.
 *
 * All Item objects share the same field delimiter and a common field width.
 * The field width holds the maximum number of characters in the name of any
 * object.  Each Item object uses this field width to display its information
 * in an aligned tabular format.
 */
class Item
{
    std::string name;          // name of the component
    std::string filler;        // name of the filler task
    std::string remover;       // name of the remover task
    std::string description;   // detailed description
    unsigned int code;         // next shipping label
    static size_t field_width; // current maximum field width

public:

    /*!
     * Upon instantiation, an Item object receives either nothing or a reference
     * to an unmodifiable std::string.  This string contains all of the
     * information for a single item.
     *
     * The constructor initializes the description string to "no detailed
     * description" and code to the default initial code (1).  The constructor
     * extracts tokens from the string received using a Utilities object,
     * accepting the first token as the name of the item and reporting an
     * exception if no name has been specified.  The constructor accepts the
     * second token as the name of the filler task that inserts the item into a
     * product and reports an exception if no task has been specified.  The
     * constructor accepts the third token as the naem of the remover task that
     * extracts the item from a product and reports an exception if no task has
     * been specified.  The fourth token is the integer holding the code to be
     * printed on the item's first insertion into a product.  The fifth token
     * is a detailed description of the item.
     *
     * The constructor resets the field_width of the Item class to the size of
     * the name of the current object if the size of its name exceeds the
     * current value of field_width.
     * */
    explicit Item(const std::string &record = std::string());

    /*!
     * \returns true if the current object is in a safe empty state.
     * */
    bool empty() const;

    /*!
     * increments the code to be printed on the next insertion and returns the
     * value before incrementation.
     *
     * \returns a reference to the Item
     * */
    Item &operator++(int);

    /*!
     * \returns a copy of the code to be printed on the next insertion into a
     * product.
     * */
    unsigned int getCode() const;

    /*!
     * \returns an unmodifiable reference to the string that contains the name of the item.
     * */
    const std::string &getName() const;

    /*!
     * \returns an unmodifiable reference to the string that contains the name
     * of the task that inserts the item into a product.
     * */
    const std::string &getFiller() const;

    /*!
     * \returns an unmodifiable reference to the string that contains the name
     * of the task that extracts the item from a product.
     * */
    const std::string &getRemover() const;

    /*!
     * const - inserts into os the name of the item and its current code as
     * shown in the sample output listed below:
     * - the name of the item left-justified in a field of field_width
     * - the code right-justified and 0 filled in a field of CODE_WIDTH and
     *   enclosed within brackets. If the full flag is true, this function
     *   includes a complete description of the item.
     * - the name of the filler task left-justified in a field of width
     *   field_width and preceded by "From "
     * - the name of the remover task left-justified in a field of width
     *   field_width and preceded by "To "
     * - the detailed description of the item left-justified and starting
     *   directly below From and preceded by ": "
     *
     *   \param os is a reference to an ostream object
     *   \param more is a boolean value
     * */
    void display(std::ostream &os, bool more = false) const;
};
}

#endif // MS_ITEM_H