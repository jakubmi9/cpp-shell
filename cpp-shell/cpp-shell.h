#pragma once
#include <string>
#include <vector>
//==============================================================================
namespace sh
{
	///<summary>shell class provides a complete user interface resembling a unix bash. object of this class should be created at the start of your program, it will provide a starting message.</summary>
	class shell
	{
	private:
		std::string _greet;
		std::string _ps1prompt;
		std::string _ps2prompt;
		std::string _arg;
		char _c;
	protected:
	public:
		///<summary>initializes new shell object with a greeting message and a prompt symbol</summary>
		///<param name="greet">greeting message for your program, shows only once upon initialization</param>
		///<param name="prompt">prompt message for your program, shows at the beginning of every line and it is followed by a $ symbol</param>
		shell(std::string greet, std::string prompt);
		///<summary>initializes new shell object with only a prompt symbol</summary>
		///<param name="prompt">prompt message for your program, shows at the beginning of every line and it is followed by a $ symbol</param>
		shell(std::string prompt);
		~shell();
		///<summary>starts primary shell that takes user input. that input can be found in the [std::vector &lt;string&gt; command] property. should be run in an endless loop, if user does not provide enough input, subprompt() should be used to get the additional input</summary>
		void prompt();
		///<summary>starts secondary shell that awaits user input. it is used for additional input. input from this shell is supposed to be appended to the [std::vector &lt;string&gt; command] property. should be run in an endless loop</summary>
		void subprompt();
		///<summary>contains all the arguments that the user typed in.</summary>
		std::vector<std::string> command;
	};
}
//==============================================================================