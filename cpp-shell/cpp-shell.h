#pragma once
#include <string>
#include <vector>
namespace sh
{
	class shell
	{
	private:
		std::string _greet;
		std::string _ps1prompt;
		std::string _ps2prompt;
		std::string _arg;
		char _c;
		bool _done = 1;
	protected:
	public:
		shell(std::string greet, std::string prompt);
		~shell();
		void start();
		void substart();
		std::vector<std::string> command;
	};
}