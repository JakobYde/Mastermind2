#ifndef CODE_
#define CODE_

#include <vector>
#include <assert.h>
#include <algorithm>

#include "color.h"

class Code {
public:
	// Make the class copyable and movable.
	Code(const Code& other) = default;
	Code& operator=(const Code& other) = default;

	Code(const std::vector<Color>& code) : code_(code) {};
	Code() {};
	~Code() {};

	// Counts number of pegs with both correct color and placement.
	int CountCorrectPlacement(const Code& code) const;

	// Counts number of pegs with correct color but incorrect placement. 
	//   Example: [R, R, G, Y], [B, B, R, B] returns 1.
	int CountCorrectColor(const Code& code) const;

	// Generates a random code.
	static Code GenerateCode();

	// Returns code_
	std::vector<Color> code() const;

protected: // This class could likely be inherited.
	std::vector<Color> code_;
};
#endif CODE_
