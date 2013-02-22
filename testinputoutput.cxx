#include "ren-general/inputoutput.h"
#include "ren-general/range.h"

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
	Test << OutputStream::StringHex(49).PadTo(7) << "\n";
	Test << OutputStream::StringHex(49).PadTo(1) << "\n";
	std::cout << (String)Test << std::flush;

	int IntOut;
	MemoryStream("1") >> IntOut;
	assert(IntOut == 1);
	
	unsigned int UnsignedIntOut;
	MemoryStream("1") >> UnsignedIntOut;
	assert(UnsignedIntOut == 1);
	
	unsigned int UnsignedInt2Out;
	MemoryStream("7") >> UnsignedInt2Out;
	assert(UnsignedInt2Out == 7);
	
	float FloatOut;
	MemoryStream("4.3") >> FloatOut;
	assert(RangeF(4.2, 4.4).Contains(FloatOut));

	return 0;
}

