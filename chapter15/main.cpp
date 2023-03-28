#include"quote.h"
#include"basket.h"
  
double print_total(std::ostream&, const Quote&, std::size_t);
int main(){
	Quote q1("123-123", 50);
	Bulk_quote q2("123-111", 50, 10, 0.2);

	//Disc_quote q3("111", 50, 10, 0.2);
	Tiny_quote q4("123-234", 50, 10, 0.3);

	print_total(std::cout, q1, 10);
	print_total(std::cout, q2, 10);
		
	print_total(std::cout, q4, 15);
	print_total(std::cout, q4, 5);

	Quote q5(q1);
	print_total(std::cout, q5, 5);
	Quote q6(std::move(q5));
	print_total(std::cout, q6, 5);

	Bulk_quote q7(q2);
	print_total(std::cout, q7, 15);
	Bulk_quote q8(std::move(q7));
	print_total(cout, q8, 20);
	Bulk_quote q9;
	q9 = q8;
	print_total(cout, q9, 15);
	Bulk_quote q10;
	q10 = std::move(q9);
	print_total(cout, q10, 20);

	Basket bk;
	bk.add_item(q1);
	for(int i=0; i<15; ++i)
		bk.add_item(q2);
	bk.add_item(q6);
	bk.add_item(q8);
	bk.add_item(q10);
	bk.total_receipt(cout);
}
