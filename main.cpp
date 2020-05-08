#define NO_S3D_USING
#include <Siv3D.hpp>

#include "feature.hpp"
#include "gen.hpp"
#include "preset.hpp"

using namespace s3d::Literals;

constexpr s3d::char32 FONT_PATH[] = U"mplus-1m-regular.ttf";  // 等幅フォント
constexpr int         FONT_SIZE   = 16;

class Term {
private:
    s3d::Font font_;
    s3d::Size ch_size_;

    static s3d::Size font_char_size(const s3d::Font& font, s3d::char32 ch) {
        return font(s3d::String(1,ch)).region(s3d::Point(0,0)).size;
    }

public:
    Term(const s3d::FilePath& font_path, int font_size) :
        font_(font_size,font_path), ch_size_(font_char_size(font_,U'a'))
    {
        if(!font_) throw s3d::Error(U"cannot load font '{}'"_fmt(font_path));
    }

    [[nodiscard]] const s3d::Size& ch_size() const { return ch_size_; }

    void draw_char(const s3d::Point& colrow, char ch, const s3d::ColorF& color) const {
        font_(s3d::char32(ch)).draw(ch_size_*colrow, color);
    }

    void draw_char(int col, int row, char ch, const s3d::ColorF& color) const {
        draw_char(s3d::Point(col,row), ch, color);
    }
};

s3d::Color feat_color(const Feature& feat) {
    const auto& color = feat.color;
    return { color.r, color.g, color.b };
}

void Main() {
    constexpr int GRID_W = 198;
    constexpr int GRID_H =  66;

    constexpr int WIN_W = 1000;
    constexpr int WIN_H =  800;

    s3d::Scene::SetScaleMode(s3d::ScaleMode::ResizeFill);
    s3d::Window::SetStyle(s3d::WindowStyle::Sizable);

    const Term term(FONT_PATH, FONT_SIZE);

    const auto FLOOR_SIZE = s3d::Size{GRID_W,GRID_H} * term.ch_size();

    // Linux では centering=false にしないとウィンドウが画面外へ飛ぶバグがある (Siv3D 0.4.3)
    // https://github.com/Siv3D/OpenSiv3D/issues/506
    s3d::Window::Resize(WIN_W, WIN_H, s3d::WindowResizeOption::ResizeSceneSize, false);

    s3d::Camera2D camera(FLOOR_SIZE/2, 0.5);

    auto preset = Preset::GRASS();
    auto grid = gen_wild_heng(GRID_W, GRID_H, preset.denom(), 1);

    while(s3d::System::Update()) {
        camera.update();
        {
            const auto trans = camera.createTransformer();

            for(int r = 0; r < GRID_H; ++r) {
                for(int c = 0; c < GRID_W; ++c) {
                    const auto& feat = preset.feat(grid[r][c]);
                    term.draw_char(c, r, feat.symbol, feat_color(feat));
                }
            }
        }

        if(s3d::SimpleGUI::Button(U"Generate", {850,50})) {
            grid = gen_wild_heng(GRID_W, GRID_H, preset.denom(), 1);
        }

        camera.draw();
    }
}
