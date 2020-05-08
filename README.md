# 変愚蛮怒 荒野マップ生成

![Screenshot](https://raw.githubusercontent.com/taotao54321/hengband-wilderness/master/screenshot.gif)

## Prerequisites

[OpenSiv3D](https://github.com/Siv3D/OpenSiv3D) を使っています。Linux の場合、
以下のシンボリックリンクを作成する必要があります:

* `Siv3D/include/`
* `Siv3D/lib/libSiv3D.a`
* `build/resources/`

## Build

```sh
$ cmake -GNinja -Bbuild -S.
$ ninja -C build
```

## Usage

マウス右ドラッグで視点移動、マウスホイールで拡大縮小できます。
