#pragma once

#include <cstdint>

struct Color { std::uint8_t r, g, b; };

constexpr Color COLOR_DARK       { 0x00, 0x00, 0x00 };
constexpr Color COLOR_WHITE      { 0xff, 0xff, 0xff };
constexpr Color COLOR_SLATE      { 0x8c, 0x8c, 0x8c };
constexpr Color COLOR_ORANGE     { 0xff, 0x77, 0x00 };
constexpr Color COLOR_RED        { 0xc9, 0x00, 0x00 };
constexpr Color COLOR_GREEN      { 0x00, 0x86, 0x45 };
constexpr Color COLOR_BLUE       { 0x00, 0x00, 0xe3 };
constexpr Color COLOR_UMBER      { 0x8e, 0x45, 0x00 };
constexpr Color COLOR_LIGHTDARK  { 0x50, 0x50, 0x50 };
constexpr Color COLOR_LIGHTSLATE { 0xd1, 0xd1, 0xd1 };
constexpr Color COLOR_VIOLET     { 0xc0, 0x00, 0xaf };
constexpr Color COLOR_YELLOW     { 0xff, 0xff, 0x00 };
constexpr Color COLOR_LIGHTRED   { 0xff, 0x00, 0x68 };
constexpr Color COLOR_LIGHTGREEN { 0x00, 0xff, 0x00 };
constexpr Color COLOR_LIGHTBLUE  { 0x51, 0xdd, 0xff };
constexpr Color COLOR_LIGHTUMBER { 0xd7, 0x8e, 0x45 };

struct Feature {
    char symbol;
    Color color;
};

constexpr Feature FEAT_BRAKE         { ':', COLOR_GREEN      };
constexpr Feature FEAT_DEEP_LAVA     { '~', COLOR_RED        };
constexpr Feature FEAT_DEEP_WATER    { '~', COLOR_BLUE       };
constexpr Feature FEAT_DIRT          { '.', COLOR_UMBER      };
constexpr Feature FEAT_FLOOR         { '.', COLOR_WHITE      };
constexpr Feature FEAT_FLOWER        { ':', COLOR_LIGHTGREEN };
constexpr Feature FEAT_GRASS         { '.', COLOR_GREEN      };
constexpr Feature FEAT_MOUNTAIN      { '^', COLOR_ORANGE     };
constexpr Feature FEAT_SHALLOW_LAVA  { '~', COLOR_LIGHTUMBER };
constexpr Feature FEAT_SHALLOW_WATER { '~', COLOR_LIGHTBLUE  };
constexpr Feature FEAT_SWAMP         { '.', COLOR_LIGHTBLUE  };
constexpr Feature FEAT_TREE          { '#', COLOR_LIGHTGREEN };
