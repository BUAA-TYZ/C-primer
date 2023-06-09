#ifndef BASKET_H
#define BASKET_H

#include"quote.h"
#include<utility>
#include<set>
#include<memory>

class Basket{
public:
	void add_item(const Quote& sale)
	{ items.insert(std::shared_ptr<Quote>(sale.clone())); }
	void add_item(Quote&& sale)
	{ items.insert(std::shared_ptr<Quote>(std::move(sale).clone())); }
	double total_receipt(std::ostream&) const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote> &rhs)
	{ return lhs->isbn() < rhs->isbn(); }
	std::multiset<std::shared_ptr<Quote>, decltype(compare) *>
				  items{compare};
};

#endif
