#include <iostream>
#include "cpp-shell.h"
int main()
{
	const std::string greet = "testing program for cpp-shell v0.1";
	const std::string prompt = "test";
	sh::shell *main = new sh::shell(greet, prompt);
	while(true)
	{
		main->start();
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
							std::cout << "Nearby users:" << std::endl;
							break;
						}
					}
				}
				catch(const std::out_of_range&)
				{
					main->substart();
				}
			}
		}
		main->command.clear();
	}
}