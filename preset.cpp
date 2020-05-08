#define NO_S3D_USING
#include <Siv3D.hpp>

#include "feature.hpp"
#include "preset.hpp"

const Preset& Preset::DEEP_LAVA() {
    static const Preset res {
        {  3, FEAT_DIRT         },
        {  3, FEAT_SHALLOW_LAVA },
        { 10, FEAT_DEEP_LAVA    },
        {  2, FEAT_MOUNTAIN     },
    };
    return res;
}

const Preset& Preset::DEEP_WATER() {
    static const Preset res {
        { 12, FEAT_DEEP_WATER    },
        {  6, FEAT_SHALLOW_WATER },
    };
    return res;
}

const Preset& Preset::DESERT() {
    static const Preset res {
        {  2, FEAT_FLOOR },
        { 13, FEAT_DIRT  },
        {  3, FEAT_GRASS },
    };
    return res;
}

const Preset& Preset::DIRT() {
    static const Preset res {
        {  3, FEAT_FLOOR  },
        { 10, FEAT_DIRT   },
        {  1, FEAT_FLOWER },
        {  1, FEAT_BRAKE  },
        {  1, FEAT_GRASS  },
        {  2, FEAT_TREE   },
    };
    return res;
}

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

const Preset& Preset::MOUNTAIN() {
    static const Preset res {
        {  1, FEAT_FLOOR    },
        {  1, FEAT_BRAKE    },
        {  2, FEAT_GRASS    },
        {  2, FEAT_DIRT     },
        {  2, FEAT_TREE     },
        { 10, FEAT_MOUNTAIN },
    };
    return res;
}

const Preset& Preset::SHALLOW_LAVA() {
    static const Preset res {
        { 14, FEAT_SHALLOW_LAVA },
        {  3, FEAT_DEEP_LAVA    },
        {  1, FEAT_MOUNTAIN     },
    };
    return res;
}

const Preset& Preset::SHALLOW_WATER() {
    static const Preset res {
        {  3, FEAT_DEEP_WATER    },
        { 12, FEAT_SHALLOW_WATER },
        {  1, FEAT_FLOOR         },
        {  1, FEAT_DIRT          },
        {  1, FEAT_GRASS         },
    };
    return res;
}

const Preset& Preset::SWAMP() {
    static const Preset res {
        { 2, FEAT_DIRT          },
        { 3, FEAT_GRASS         },
        { 1, FEAT_TREE          },
        { 1, FEAT_BRAKE         },
        { 4, FEAT_SHALLOW_WATER },
        { 7, FEAT_SWAMP         },
    };
    return res;
}

const Preset& Preset::TREES() {
    static const Preset res {
        {  2, FEAT_FLOOR },
        {  1, FEAT_DIRT  },
        { 11, FEAT_TREE  },
        {  2, FEAT_BRAKE },
        {  2, FEAT_GRASS },
    };
    return res;
}

Preset::Preset(std::initializer_list<std::pair<int,std::reference_wrapper<const Feature>>> dist) {
    for(const auto [k,r] : dist)
        feats_.insert(end(feats_), k, r);
}

int Preset::denom() const { return size(feats_); }

const Feature& Preset::feat(int id) const { return feats_[id]; }
