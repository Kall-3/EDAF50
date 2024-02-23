#include "bitreference.h"
#include "bitset.h"

BitReference& BitReference::operator=(bool b) {
	// *** IMPLEMENT ***
	// This corresponds to the set() function in SimpleBitset.

	if (b) {
		*this->p_bits |= (1L << this->pos);
	} else {
		*this->p_bits &= ~ (1L << this->pos);
	}
    
	return *this;
}

BitReference& BitReference::operator=(const BitReference& rhs) {
	// *** IMPLEMENT ***
	// Same as operator=(bool), but the bit is picked from rhs

    *this = static_cast<bool>(rhs); // operator=(rhs);

	return *this;
}

BitReference::operator bool() const {
	// *** IMPLEMENT ***
	// This corresponds to the get() function in SimpleBitset.

    return (*this->p_bits & (1L << this->pos));
}
