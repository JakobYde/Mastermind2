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
    std::unordered_map<Color, int> this_color_count;
    for (auto i = code_.begin(); i < code_.end(); i++) {
        ++this_color_count[*i];
    }

    std::unordered_map<Color, int> other_color_count;
    for (auto i = code.code_.begin(); i < code.code_.end(); i++) {
        ++other_color_count[*i];
    }

    int count = 0;
    for (auto i : this_color_count) {
        count += std::min(i.second, other_color_count[i.first]);
    }

    count -= CountCorrectPlacement(code);
    assert(count >= 0);

    return count;
}

std::vector<Color> Code::GenerateCode()
{
    std::vector<Color> code;
    for (int i = 0; i < 4; ++i)
        code.push_back(GetRandomColor());

    return code;
}

std::vector<Color> Code::code() const
{
    return code_;
}
