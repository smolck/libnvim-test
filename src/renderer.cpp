#include <iostream>
#include "renderer.hpp"

void Renderer::printWhatever() {
  std::cout << "Whatever! " << this->m_stuff << "\n";
}

void Renderer::stop() {}

void Renderer::gridResize(int gridId, int width, int height) {}
void Renderer::gridClear(int gridId) {}
void Renderer::gridCursorGoto(int grid, int row, int col) {}
void Renderer::gridScroll(
    int gridId,
    int startRow,
    int endRow,
    int startCol,
    int endCol, 
    int rows, 
    int cols
) {}
// void mode_info_set(bool guicursor_enabled, Array args)
void Renderer::updateMenu() {}
void Renderer::busyStart() {}
void Renderer::busyStop() {}
void Renderer::mouseOn() {}
void Renderer::mouseOff() {}
void Renderer::setMode(int mode) {}
void Renderer::modeChange(const char* mode, int modeIdx) {}
// void hlAttrDefine(int id, HlAttrs attrs, HlAttrs cterm_attrs, Array info)
void Renderer::bell() {}
void Renderer::visualBell() {}
void Renderer::defaultColorsSet(int rgbFg, int rgbBg, int rgbSp, int ctermFg, int ctermBg) {}
void Renderer::flush() {}
void Renderer::suspend() {}
void Renderer::setTitle(const char* title) {}
void Renderer::setIcon(const char* icon) {}
void Renderer::screenshot(const char* path) {}
// void optionSet(const char* name, Object value)
void Renderer::rawLine(
    int gridId,
    int lineRow,
    int startCol,
    int endCol,
    int clearCol,
    int clearAttr,
    int flags,
    const char* chunk,
    const int *attrs
) {
  std::cout << chunk << "\n";
}
