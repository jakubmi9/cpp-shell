#include "cpp-shell.h"
#include <iostream>
#include <vector>
//==============================================================================
///<summary>initializes new shell object</summary>
///<param name=_g>greeting message for your program, shows only once upon initialization</param>
///<param name=_p>prompt message for your program, shows at the beginning of every line and it is followed by a $ symbol</param>
sh::shell::shell(std::string _g, std::string _p)
{
	this->_greet = _g;
	this->_ps1prompt = _p;
	this->_ps1prompt.append(1, '$');
	this->_ps1prompt.append(1, ' ');
	this->_ps2prompt = "> ";
	std::cout << this->_greet << std::endl;
}
sh::shell::~shell()
{
}
///<summary>starts primary shell that awaits user input. That input can be found in this->command</summary>
///<remarks>should be run in an endless loop, if user does not provide enough input, substart() should be used to get the additional input</remarks>
void sh::shell::start()
{
	std::cout << this->_ps1prompt;
	while (this->_c = getchar())
	{
		if (this->_c == '\n' || this->_c == '\r')
		{
			this->command.push_back(_arg);
			this->_arg.clear();
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
///<summary>starts secondary shell that awaits user input. Is used for additional input. Input from this shell is appended to this->command, and does not replace its contents</summary>
///<remarks>should be run in an endless loop</remarks>
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