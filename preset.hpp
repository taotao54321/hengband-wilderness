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
    static const Preset& DEEP_LAVA();
    static const Preset& DEEP_WATER();
    static const Preset& DESERT();
    static const Preset& DIRT();
    static const Preset& GRASS();
    static const Preset& MOUNTAIN();
    static const Preset& SHALLOW_LAVA();
    static const Preset& SHALLOW_WATER();
    static const Preset& SWAMP();
    static const Preset& TREES();

    Preset(std::initializer_list<std::pair<int,std::reference_wrapper<const Feature>>> dist);

    [[nodiscard]] int denom() const;

    [[nodiscard]] const Feature& feat(int id) const;
};
