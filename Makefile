all:
# is this necessary?
	cmake -S . -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	cmake --build build

prepare-skia:
	# git pull --recurse-submodules
	# ../depot_tools/gn gen out/Shared --args='is_official_build=true is_component_build=true'
	# See https://github.com/acmlira/mimicry#preparing-skia
	cd third_party/skia && python tools/git-sync-deps && ../depot_tools/gn gen cmake --ide=json --json-ide-script=../../gn/gn_to_cmake.py --args='is_official_build=true is_component_build=true skia_use_icu=false skia_use_system_libjpeg_turbo=false skia_use_system_libwebp=false skia_use_system_expat=false skia_use_system_libpng=false'
