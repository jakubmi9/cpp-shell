// cpp-shell-test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../cpp-shell/cpp-shell.h"

int main()
{
	const std::string greet = "testing program for cpp-shell v0.1";
	const std::string prompt = "test";
	sh::shell *main = new sh::shell(greet, prompt);
	while(true)
	{
		main->prompt();
		if(main->command[0] == "exit")
		{
			delete main;
			std::system("pause");
			return 0;
		}
		if(main->command[0] == "list")
		{
			while(true)
			{
				try
				{
					if(main->command.at(1) == "users")
					{
						if(main->command.at(2) == "nearby")
						{
							if(main->command.size() != 3)
							{
								std::cout << "invalid syntax!" << std::endl;
								break;
							}
							std::cout << "Nearby users:" << std::endl;
							break;
						}
						else
						{
							std::cout << "invalid syntax!" << std::endl;
							break;
						}
					}
					else
					{
						std::cout << "invalid syntax!" << std::endl;
						break;
					}
				}
				catch(const std::out_of_range&)
				{
					main->subprompt();
				}
			}
		}
		main->command.clear();
	}
}

