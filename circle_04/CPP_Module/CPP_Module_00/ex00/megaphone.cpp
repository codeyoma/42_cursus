#include <cctype>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string str;

    if (argc > 1)
    {
		for (int i = 1; i < argc; i++)
		{
			std::string	temp = argv[i];
			for (std::size_t j = 0; j < temp.length(); j++)
				str += std::toupper(temp[j]);
		}
	}
    else
        str = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << str << std::endl;
    return 0;
}
