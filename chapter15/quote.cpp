#include "quote.h"

double print_total(std::ostream &os,    
                   const Quote &item, std::size_t n){    
    double ret = item.net_price(n);    
    os << "ISBN: " << item.isbn()    
       << " # sold: " << n << " total due :" << ret << endl;;    
    return ret;    
}    

Quote& Quote::operator=(const Quote &rhs){
	if(&rhs != this){
		bookno = rhs.bookno;
		price = rhs.price;
	}
	cout << "This is quote copy =" <<endl;
	return *this;
}

Quote& Quote::operator=(Quote&& rhs){
	if(this != &rhs){
		bookno = std::move(rhs.bookno);
		price = std::move(rhs.price);
	}
	cout << "This is quote move =" << endl;
	return *this;
}

Disc_quote& Disc_quote::operator=(const Disc_quote &rhs){
	if(this !=&rhs){
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
	}
	cout << "This is Disc_quote copy =" << endl;
	return *this;
}

Disc_quote& Disc_quote::operator=(Disc_quote &&rhs){
	if(this != &rhs){
		Quote::operator=(std::move(rhs));
		quantity = std::move(rhs.quantity);
		discount = std::move(rhs.discount);
	}
	cout << "This is Disc_quote move =" << endl;
	return *this;
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote &rhs){
	if(this != &rhs){
		Disc_quote::operator=(rhs);
	}
	cout << "This is Bulk_quote copy =" << endl;
	return *this;
}

Bulk_quote& Bulk_quote::operator=(Bulk_quote &&rhs){
	if(this != &rhs){
		Disc_quote::operator=(std::move(rhs));
	}
	cout << "This is Bulk_quote move =" << endl;
	return *this;
}
double Bulk_quote::net_price(std::size_t n) const{
	if(n >= quantity)
		return price * (1 - discount) * n;
	else
		return price * n;
}

double Tiny_quote::net_price(std::size_t n) const{
	if(n >= quantity)
		return quantity * (1 - discount) * price +
			   (n - quantity) * price;
	else
		return n * (1 - discount) * price;
}
