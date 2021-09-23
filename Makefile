all:
# is this necessary?
	cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

prepare:
	# See https://github.com/acmlira/mimicry#preparing-skia
	cd third_party/neovim && make libnvim
	cd third_party/skia && python tools/git-sync-deps && ../depot_tools/gn gen out/Static --args='is_official_build=true skia_use_icu=false skia_use_system_libjpeg_turbo=false skia_use_system_libwebp=false skia_use_system_expat=false skia_use_system_libpng=false' && ninja -C out/Static
