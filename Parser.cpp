#include "Parser.h"

RDParser::RDParser(std::string &sentence)
{
	this->_sentence = sentence;
	_sentence += '\0';
	_sentence.erase(std::remove(_sentence.begin(),_sentence.end(),' '),_sentence.end());
	while ( _sentence.find("if") != ULONG_MAX )
		_sentence.replace(_sentence.find("if"),std::string("if").length(),"$");
	this->i = _sentence.begin();
	this->_currentLetter = *i;
	this->_successful = true;
}

void RDParser::Trace()
{
	std::string::iterator j = i;
	for( ; j != _sentence.end() ; j++ )
	{
		if( *j == '$' )
			std::cout << "if";
		else if( *j == '\0' )
			std::cout << "EOF";		
		else
			std::cout << *j;
	}
	std::cout << std::endl;
}

void RDParser::Match(char token)
{
	if( this->_currentLetter == token )
	{
		i++;
		_currentLetter = *i;
		this->Trace();		
	}
	else
	{
		this->Decompose();
		return;
	}
}

bool RDParser::isSuccessful()
{
	return this->_successful;
}

void RDParser::Decompose()
{
	this->_successful = false;
}

void RDParser::Prog()
{
	std::cout << "Prog()        ";
	this->Match('{');
	Deyimler();
	std::cout << "Prog()        ";
	this->Match('}');
	std::cout << "Prog()        ";
	this->Match('\0');
}

void RDParser::Deyimler()
{
	if( isalpha(_currentLetter) || _currentLetter == '$' )
	{
		this->Deyim();
		this->Deyimler();
	}
	else
		return;
}

void RDParser::Deyim()
{
	if( isalpha(_currentLetter) )
	{
		std::cout << "Deyim()       ";
		this->Match(_currentLetter);
		std::cout << "Deyim()       ";
		this->Match('=');
		this->Exp();
		std::cout << "Deyim()       ";
		this->Match(';');
	}
	else if( _currentLetter == '$' )
	{
		std::cout << "Deyim()       ";
		this->Match('$');
		std::cout << "Deyim()       ";
		this->Match('(');
		this->Exp();
		std::cout << "Deyim()       ";
		this->Match(')');
		this->Deyim();
	}
}

void RDParser::Exp()
{
	std::cout << "Exp()         ";
	this->Match(_currentLetter);
	this->Expt();
}

void RDParser::Expt()
{
	if( _currentLetter == '+' )
	{
		std::cout << "Expt()        ";
		this->Match('+');
		this->Exp();
	}
	else if( _currentLetter == '-' )
	{
		std::cout << "Expt()        ";
		this->Match('-');
		this->Exp();
	}
	else
		return;		
}
