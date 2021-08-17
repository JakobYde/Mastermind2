#include "color.h"

Color GetRandomColor() {
    Color color = Color(rand() % static_cast<int>(Color::kMax));
    return color;
}