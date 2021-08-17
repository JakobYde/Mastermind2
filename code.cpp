#include "code.h"


int Code::CountCorrectPlacement(const Code& code) const
{
    std::vector<bool> comparison(code_.size());

    std::transform(code_.begin(), code_.end(), code.code_.begin(), 
        comparison.begin(), std::equal_to<Color>());

    int count = std::count(comparison.begin(), comparison.end(), true);
    assert(count >= 0);

    return count;
}

int Code::CountCorrectColor(const Code& code) const
{
    std::vector<Color> colors(code_);

    auto last = std::unique(colors.begin(), colors.end());
    colors.resize(last - colors.begin());

    int count = 0;
    for (Color c : colors) {
        int count_this = std::count(code_.begin(), code_.end(), c);
        int count_other = std::count(code.code_.begin(), code.code_.end(), c);
        count += std::min(count_this, count_other);
    }

    count -= CountCorrectPlacement(code);
    assert(count >= 0);

    return count;
}

Code Code::GenerateCode()
{
    std::vector<Color> code;
    for (int i = 0; i < 4; ++i)
        code.push_back(GetRandomColor());

    return Code(code);
}

std::vector<Color> Code::code() const
{
    return code_;
}
