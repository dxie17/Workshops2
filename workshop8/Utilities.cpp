// Workshop: 8
// Full Name: Deyang Xie
// Student ID: 150162204
// Email Address: dxie17@myseneca.ca
// Date: 2021/11/28
// Description: I have done all the coding by myself and only copied the code
// that my professor provided to complete my workshops and assignments.
///////////////////////////////////////////////////
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (auto i = 0u; i < desc.size() ; i++) {
			for (auto m = 0u; m < price.size(); m++) {
				if (desc[i].code == price[m].code) {
					Product* newProduct = new Product(desc[i].desc, price[m].price);
					newProduct->validate();
					priceList += move(newProduct);
					delete newProduct;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		for (auto i = 0u; i < desc.size(); i++) {
			for (auto m = 0u; m < price.size(); m++) {
				if (desc[i].code == price[m].code) {
					std::shared_ptr<Product> newProduct(new Product(desc[i].desc, price[m].price));
					newProduct->validate();
					priceList += move(newProduct);

				}
			}
		}
		return priceList;
	}
}