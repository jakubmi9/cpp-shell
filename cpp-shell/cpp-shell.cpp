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
	std::cout << this->_greet << std::endl;
}
//==============================================================================
sh::shell::~shell()
{
}
//==============================================================================
void sh::shell::start()
{
	std::cout << this->_ps1prompt;
	while (this->_c = getchar())
	{
		if (this->_c == '\n' || this->_c == '\r')
		{
			if (this->_arg.empty() == 0)
			{
				this->command.push_back(_arg);
				this->_arg.clear();
			}
			else
				start();
			break;
		}
		else if (this->_c == ' ')
		{
			this->command.push_back(_arg);
			this->_arg.clear();
		}
		else
			this->_arg.append(1, this->_c);
	}
}
//==============================================================================
void sh::shell::substart()
{
	std::cout << this->_ps2prompt;
	while (this->_c = getchar())
	{
		if (this->_c == '\n' || this->_c == '\r')
		{
			if (this->_arg.empty() == 0)
			{
				this->command.push_back(_arg);
				this->_arg.clear();
			}
			else
				substart();
			break;
		}
		else if (this->_c == ' ')
		{
			this->command.push_back(_arg);
			this->_arg.clear();
		}
		else
			this->_arg.append(1, this->_c);
	}
}
//==============================================================================