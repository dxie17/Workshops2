// Workshop: 8
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/28
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "List.h"
#include "Element.h"

namespace sdds {
	List<Product> mergeRaw(const List<Description> &desc, const List<Price>& price);
	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price);
}

#endif