#define NO_S3D_USING
#include <Siv3D.hpp>

#include "feature.hpp"
#include "preset.hpp"

const Preset& Preset::GRASS() {
    static const Preset res {
        { 2, FEAT_FLOOR  },
        { 2, FEAT_DIRT   },
        { 9, FEAT_GRASS  },
        { 1, FEAT_FLOWER },
        { 2, FEAT_BRAKE  },
        { 2, FEAT_TREE   },
    };
    return res;
}

Preset::Preset(std::initializer_list<std::pair<int,std::reference_wrapper<const Feature>>> dist) {
    for(const auto [k,r] : dist)
        feats_.insert(end(feats_), k, r);
}

int Preset::denom() const { return size(feats_); }

const Feature& Preset::feat(int id) const { return feats_[id]; }
