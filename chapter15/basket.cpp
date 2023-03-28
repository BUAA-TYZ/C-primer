#include"basket.h"

double print_total(std::ostream&, const Quote&, std::size_t);
double Basket::total_receipt(std::ostream &os) const{
	double sum = 0.0;
	for(auto iter = items.cbegin();
			 iter != items.cend();
			 iter = items.upper_bound(*iter))
		sum += print_total(os, **iter, items.count(*iter));
	os << "Total_Sale: " << sum << endl;
	return sum;
}
