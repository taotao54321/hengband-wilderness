#define NO_S3D_USING
#include <Siv3D.hpp>

#include "gen.hpp"
#include "util.hpp"

namespace {

using Grid = std::vector<std::vector<int>>;

/**
 * FIXME: 横長マップを仮定している
 *
 * @param x1 左上x座標 (inclusive)
 * @param y1 左上y座標 (inclusive)
 * @param x2 右下x座標 (inclusive)
 * @param y2 右下y座標 (inclusive)
 * @param denom 各地勢の確率の分母(=重みの総和)
 * @param rough ランダム幅
 */
void plasma_recursive_heng(
    Grid& grid,
    const int x1, const int y1, const int x2, const int y2,
    const int denom, const int rough)
{
    // 中央の点 (本家の perturb_point_mid())
    const auto f_mid = [denom,rough](const int sum4) {
        const int avg = div_ceil(sum4, 4);
        const int rnd = s3d::Random(-rough, rough);
        return std::clamp(avg+rnd, 0, denom-1);
    };

    // 4辺の中点 (本家の perturb_point_end())
    const auto f_end = [denom,rough](const int sum3) {
        const int avg = div_ceil(sum3, 3);
        const int rnd = s3d::Random(-rough, rough);
        return std::clamp(avg+rnd, 0, denom-1);
    };

    assert(x1 < x2);

    // 横幅が2になったら終了(2より小さくなることはありえない)
    if(x1+1 == x2) return;

    const int xmid = x1 + (x2-x1)/2;
    const int ymid = y1 + (y2-y1)/2;

    // 中央の点
    grid[ymid][xmid] = f_mid(grid[y1][x1] + grid[y1][x2] + grid[y2][x1] + grid[y2][x2]);

    // 4辺の中点
    grid[y1  ][xmid] = f_end(grid[y1  ][x1  ] + grid[y1  ][x2  ] + grid[ymid][xmid]);  // 上
    grid[ymid][x1  ] = f_end(grid[y1  ][x1  ] + grid[ymid][xmid] + grid[y2  ][x1  ]);  // 左
    grid[ymid][x2  ] = f_end(grid[y1  ][x2  ] + grid[ymid][xmid] + grid[y2  ][x2  ]);  // 右
    grid[y2  ][xmid] = f_end(grid[ymid][xmid] + grid[y2  ][x1  ] + grid[y2  ][x2  ]);  // 下

    // 4領域に対して再帰
    plasma_recursive_heng(grid, x1,   y1,   xmid, ymid, denom, rough);  // 左上
    plasma_recursive_heng(grid, xmid, y1,   x2,   ymid, denom, rough);  // 右上
    plasma_recursive_heng(grid, x1,   ymid, xmid, y2,   denom, rough);  // 左下
    plasma_recursive_heng(grid, xmid, ymid, x2,   y2,   denom, rough);  // 右下
}

}  // anonymous namespace

Grid gen_wild_heng(int w, int h, int denom, int rough) {
    Grid grid(h, std::vector<int>(w));

    grid[0  ][0  ] = s3d::Random(0, denom-1);
    grid[0  ][w-1] = s3d::Random(0, denom-1);
    grid[h-1][0  ] = s3d::Random(0, denom-1);
    grid[h-1][w-1] = s3d::Random(0, denom-1);

    plasma_recursive_heng(grid, 0, 0, w-1, h-1, denom, rough);

    return grid;
}
