#ifndef _PARSER_H
#define _PARSER_H

#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

class RDParser
{
private:
	bool _successful;
	char _currentLetter;
	std::string::iterator i;
	std::string _sentence;
public:
	RDParser(std::string &);
	bool isSuccessful();
	void Match(char);
	void Trace();
	void Prog();
	void Deyimler();
	void Deyim();
	void Exp();
	void Expt();
	void Decompose();
};

#endif //_PARSER_H
