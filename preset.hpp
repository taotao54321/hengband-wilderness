#pragma once

#include <functional>
#include <initializer_list>
#include <utility>
#include <vector>

struct Feature;

class Preset {
private:
    std::vector<std::reference_wrapper<const Feature>> feats_;

public:
    static const Preset& GRASS();

    Preset(std::initializer_list<std::pair<int,std::reference_wrapper<const Feature>>> dist);

    [[nodiscard]] int denom() const;

    [[nodiscard]] const Feature& feat(int id) const;
};
