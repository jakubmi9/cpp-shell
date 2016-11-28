#include "cpp-shell.h"
#include <iostream>
#include <vector>
//==============================================================================
sh::shell::shell(std::string _g, std::string _p)
{
	this->_oriG = _g;
	this->_oriP = _p;
	this->_G = _g;
	this->_PS1 = _p;
	this->_PS1.append("$ ");
	this->_PS2 = "> ";
	#ifdef __linux__
	system("clear");
	#endif
	#ifdef __APPLE__
	system("clear");
	#endif
	#ifdef _WIN32
	system("cls");
	#endif
	std::cout << this->_G << std::endl << std::endl;
}
//==============================================================================
sh::shell::shell(std::string _p)
{
	this->_oriP = _p;
	this->_PS1 = _p;
	this->_PS1.append("$ ");
	this->_PS2 = "> ";
}
//==============================================================================
sh::shell::~shell()
{
}
//==============================================================================
void sh::shell::prompt()
{
	std::cout << this->_PS1;
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
	std::cout << this->_PS2;
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
void sh::shell::submodule(std::string _n)
{
	this->_PS1 = this->_oriP;
	this->_PS1.append(":");
	this->_PS1.append(_n);
	this->_PS1.append("$ ");
}
//==============================================================================
void sh::shell::submodule()
{
	this->_PS1 = this->_oriP;
	this->_PS1.append("$ ");
}