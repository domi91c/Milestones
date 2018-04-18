/*! ********************************************************
 * \name OOP345: Milestone 2
 * \file CustomerOrder.h
 * \class CustomerOrder
 * \version Version 1.0
 * \date 2018-03-27
 * \author Dominic Nunes - 016-183-121
***********************************************************/

#ifndef MS_CUSTOMERORDER_H
#define MS_CUSTOMERORDER_H

#include <iostream>
#include <string>
#include "CustomerItem.h"

/*! OOP345 Project namespace */
namespace MS
{

class Item;
class CustomerItem;

/*!
 * \brief A CustomerOrder object manages a customer order throughout the assembly
 * process.  A customer order includes the name of the customer, the name of the
 * product to be assembled, a dynamically allocated array of CustomerItems and
 * the number of these orders.
 *
 * All CustomerOrder objects share the same field delimiter for reading and a
 * common field width for reporting.  The field width holds the maximum number
 * of characters in the name of any customer or product.  Each CustomerOrder
 * object uses this field width to display its information in an aligned
 * tabular format.
 * */
class CustomerOrder
{
    std::string name;          // name of the customer
    std::string product;       // name of the product
    CustomerItem *order;       // address of the customer requests
    unsigned int nOrders;      // number of requests
    static size_t field_width; // current maximum field width

public:

    /*!
     * Upon instantiation, a CustomerOrder object receives a reference to an
     * unmodifiable std::string.  This string contains the information for a
     * single customer order.
     *
     * The constructor initializes the number of customer items to 0 and the
     * pointer to the CustomerItem array to a safe address.  The constructor
     * uses a Utilities object to extract the tokens from the referenced string.
     * The constructor reports appropriate exceptions if the record is missing
     * the customer name field, the product name field, or any item field.
     * The constructor allocates dynamic memory for the CustomerItems identified
     * in the referenced string.  It stores the name of the customer, stores the
     * name of the product and populates the CustomerItem array.  Finally, the
     * constructor extracts the field width from the Utilities object and updates
     * the field_width class variable if that field width is greater than the
     * class variable's current value.  Once all customer orders have been
     * processed, this class variable holds the field width required to display
     * their names in aligned tabular form.
     * */
    explicit CustomerOrder(const std::string &record);

    /*!
     * Since customer orders are not to be duplicated, the copy constructor
     * should never be called.  Your implementation reports an exception if the
     * copy constructor is called.
     */
    CustomerOrder(const CustomerOrder &rhs);
    CustomerOrder &operator=(const CustomerOrder &rhs) = delete;

    /*!
     * Your implementation includes a move constructor, a move assignment
     * operator and a destructor.  Append noexcept to your definitions of the
     * move constructor and move assignment operator for Linux platforms.
     * */
    CustomerOrder(CustomerOrder &&rhs) noexcept;
    CustomerOrder &operator=(CustomerOrder &&rhs) noexcept;

    /*!
     * destructor
     * */
    ~CustomerOrder();

    /*!
     * \returns the number of customer items in the current object
     * */
    unsigned int noOrders() const;

    /*!
     * \returns a reference to the name of customer item i; reports an exception
     * if the index is out of bounds
     *
     * \param index is the index of order to visit
     * */
    const std::string &operator[](unsigned int index) const;

    /*!
     * searches through the customer items and fills those order for the
     * customer items identified by item if any have not been filled.  This
     * function increments item's code for each customer item filled.  This
     * keeps the item code unique for each order.
     *
     * \param item is a reference to the Item to compare the order items against
     * */
    void fill(Item &item);

    /*!
     *  searches through the customer items and removes those items identified
     *  by the name of item if the corresponding part of the order has been
     *  filled.  This function does not alter the item's code
     *
     *  \param item is a reference to the Item to compare the order items against
     * */
    void remove(Item &item);

    /*!
     * \returns true if the current object is in a safe empty state
     * */
    bool empty() const;

    /*!
     *  inserts into os a description of the customer order as shown in the
     *  sample output listed below.  The description consists of
     *  - the name of the customer left-justified in a field of width field_width
     *  - the name of the product left-justified in a field of width field_width
     *  - each customer item on a separate line
     *
     *  \param os is an ostream object
     * */
    void display(std::ostream &os) const;
};
}

#endif // MS_CUSTOMERORDER_H
