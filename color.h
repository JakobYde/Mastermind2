#pragma once
#ifndef COLOR_
#define COLOR_

#include <stdlib.h>
#include <unordered_set>

enum class Color {
    kRed, kGreen, kBlue, kYellow,
    kPurple, kOrange, kCyan, kWhite, 
    kMax = 8, kNull
};

const std::vector<char> kColors{ 'r', 'g', 'b', 'y', 'p', 'o', 'c', 'w' };

Color GetRandomColor();

#endif COLOR_