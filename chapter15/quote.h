#ifndef QUOTE_H
#define QUOTE_H
#include<string>
#include<iostream>
using std::cout;
using std::endl;

class Quote{
public:
	Quote() = default;
	Quote(const Quote &q):
		  bookno(q.bookno), price(q.price){ 
		cout << "This is quote copy " << endl;
	 }
	Quote& operator=(const Quote &);
	Quote(Quote&& q):
		  bookno(std::move(q.bookno)),
		  price(std::move(q.price)){
		cout<< "This is quote move " << endl;	  	
	}
	Quote& operator=(Quote &&);

	Quote(const std::string &book, double p):
					 bookno(book), price(p) {}
	std::string isbn() const{return bookno;}
	virtual Quote* clone() const & { return new Quote(*this); }
	virtual Quote* clone() && { return new Quote(std::move(*this)); }
	virtual double net_price(std::size_t n) const{return n * price;}
	virtual ~Quote() = default;
private:
	std::string bookno;
protected:
	double price = 0.0;
};

//Disc_quote is an abstract base class
class Disc_quote : public Quote{
public:
    Disc_quote() = default;
	Disc_quote(const Disc_quote &q):
			   Quote(q), quantity(q.quantity),
			   discount(q.discount){
		cout << "This is a Disc_quote copy" <<endl;
	}
	Disc_quote& operator=(const Disc_quote &);
	Disc_quote(Disc_quote && rhs):
		       Quote(std::move(rhs)),
			   quantity(std::move(rhs.quantity)),
			   discount(std::move(rhs.discount)){
		cout << "This is a Disc_quote move" <<endl;		  
	 }
	Disc_quote& operator=(Disc_quote &&);
    Disc_quote(const std::string &book, double p,
               std::size_t n, double disc):
               Quote(book, p), 
               quantity(n), discount(disc) {}
	Quote* clone() const & = 0;
	Quote* clone() && = 0;
    double net_price(std::size_t n) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;    
};

//buy > quantity, get a discount
class Bulk_quote: public Disc_quote{
public:
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote & q):
			   Disc_quote(q){
		cout << "This is Bulk_quote copy" << endl;
	}
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote(Bulk_quote && rhs):
			   Disc_quote(std::move(rhs)){
		cout << "This is Bulk_quote move" << endl;
	}
	Bulk_quote& operator=(Bulk_quote &&);
	Bulk_quote(const std::string &book,
			   double p, std::size_t n, double disc):
			   Disc_quote(book, p, n, disc) {}

	Bulk_quote* clone() const &  { return new Bulk_quote(*this); }
	Bulk_quote* clone() &&  { return new Bulk_quote(std::move(*this)); }
	double net_price(std::size_t) const override;
};

//buy > quantity no discount
//buy <= quantity discount
class Tiny_quote: public Disc_quote{
public:
	Tiny_quote() = default;
	using Disc_quote::Disc_quote;
	Tiny_quote* clone() const & override { return new Tiny_quote(*this); }
	Tiny_quote* clone() && override { return new Tiny_quote(std::move(*this)); }

	double net_price(std::size_t) const override;
};

#endif
