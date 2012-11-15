#include "ren-general/inputoutput.h"

#include <limits>
#include <iostream>

int main(int, char **)
{
	MemoryStream Test;

	struct 
	{
		char Data[8];
	} Raw{"0123456"};

	Test << OutputStream::Raw(Raw) << "\n";
	Test << 'c' << "\n";
	Test << true << " " << false << "\n";
	Test << std::numeric_limits<int>::max() << "\n";
	Test << std::numeric_limits<unsigned int>::max() << "\n";
	Test << std::numeric_limits<long int>::max() << "\n";
	Test << std::numeric_limits<long unsigned int>::max() << "\n";
	Test << std::numeric_limits<float>::max() << "\n";
	Test << std::numeric_limits<double>::max() << "\n";
	Test << String("Hey") << "\n";
	Test << OutputStream::Hex(Raw) << "\n";
	std::cout << (String)Test << std::flush;
	return 0;
}

