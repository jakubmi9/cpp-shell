#include "cpp-shell.h"
#include <iostream>
#include <vector>
//==============================================================================
sh::shell::shell(std::string _g, std::string _p)
{
	this->_greet = _g;
	this->_ps1prompt = _p;
	this->_ps1prompt.append(1, '$');
	this->_ps1prompt.append(1, ' ');
	this->_ps2prompt = "> ";
	#ifdef __linux__
	system("clear");
	#endif // __linux__
	#ifdef __APPLE__
	system("clear");
	#endif // __APPLE__
	#ifdef _WIN32
	system("cls");
	#endif // _WIN32
	std::cout << this->_greet << std::endl << std::endl;
}
//==============================================================================
sh::shell::shell(std::string _p)
{
	this->_ps1prompt = _p;
	this->_ps1prompt.append(1, '$');
	this->_ps1prompt.append(1, ' ');
	this->_ps2prompt = "> ";
}
//==============================================================================
sh::shell::~shell()
{
}
//==============================================================================
void sh::shell::prompt()
{
	std::cout << this->_ps1prompt;
	while(this->_c = getchar())
	{
		if(this->_c == '\n' || this->_c == '\r')
		{
			if(this->_arg.empty() == 0)
			{
				this->command.push_back(_arg);
				this->_arg.clear();
			}
			else
				prompt();
			break;
		}
		else if(this->_c == ' ')
		{
			this->command.push_back(_arg);
			this->_arg.clear();
		}
		else
			this->_arg.append(1, this->_c);
	}
}
//==============================================================================
void sh::shell::subprompt()
{
	std::cout << this->_ps2prompt;
	while(this->_c = getchar())
	{
		if(this->_c == '\n' || this->_c == '\r')
		{
			if(this->_arg.empty() == 0)
			{
				this->command.push_back(_arg);
				this->_arg.clear();
			}
			else
				subprompt();
			break;
		}
		else if(this->_c == ' ')
		{
			this->command.push_back(_arg);
			this->_arg.clear();
		}
		else
			this->_arg.append(1, this->_c);
	}
}
//==============================================================================