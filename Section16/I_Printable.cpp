#include "I_Printable.h"


std::ostream& operator<<(std::ostream& out, const I_Printable& obj) {
	obj.print(out);
	return out;
}