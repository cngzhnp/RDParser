#include "Parser.h"

int main(int argc,char *argv[])
{
	std::string sentence;
	std::cout << "Ornek cumle giriniz: ";
	std::getline(std::cin,sentence);
	RDParser *example = new RDParser(sentence);
	example->Prog();
	if ( example->isSuccessful() == false )
		std::cout << "\nAyrıştırma başarısız" << std::endl;
	else
		std::cout << "\nAyrıştırma başarılı " << std::endl;
	delete example; 
	return 0;
}
