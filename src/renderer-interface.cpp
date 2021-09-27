#include "renderer-interface.h"
#include "renderer.hpp"

extern "C" {
  RendererHandle create_Renderer(int stuff) {
    return new Renderer(stuff);
  }

  void renderer_stop(RendererHandle r) {
    static_cast<Renderer*>(r)->stop();
  }

  void renderer_print_whatever(RendererHandle r) {
    static_cast<Renderer*>(r)->printWhatever();
  }

  void renderer_free(RendererHandle r) {
    delete static_cast<Renderer*>(r);
  }

  void renderer_gridResize(RendererHandle r, int gridId, int width, int height) {
    static_cast<Renderer*>(r)->gridResize(gridId, width, height);
  }

  void renderer_gridClear(RendererHandle r, int gridId) {
    static_cast<Renderer*>(r)->gridClear(gridId);
  }

  void renderer_gridCursorGoto(RendererHandle r, int grid, int row, int col) {
    static_cast<Renderer*>(r)->gridCursorGoto(grid, row, col);
  }

  void renderer_gridScroll(
      RendererHandle r,
      int gridId,
      int startRow,
      int endRow,
      int startCol,
      int endCol, 
      int rows, 
      int cols
  ) {
    static_cast<Renderer*>(r)->gridScroll(gridId, startRow, endRow, startCol, endCol, rows, cols);
  }
  // void mode_info_set(bool guicursor_enabled, Array args)
  void renderer_updateMenu(RendererHandle r) {
    static_cast<Renderer*>(r)->updateMenu();
  }

  void renderer_busyStart(RendererHandle r) {
    static_cast<Renderer*>(r)->busyStart();
  }

  void renderer_busyStop(RendererHandle r) {
    static_cast<Renderer*>(r)->busyStop();
  }

  void renderer_mouseOn(RendererHandle r) {
    static_cast<Renderer*>(r)->mouseOn();
  }

  void renderer_mouseOff(RendererHandle r) {
    static_cast<Renderer*>(r)->mouseOff();
  }

  void renderer_setMode(RendererHandle r, int mode) {
    static_cast<Renderer*>(r)->setMode(mode);
  }

  void renderer_modeChange(RendererHandle r, const char* mode, int modeIdx) {
    static_cast<Renderer*>(r)->modeChange(mode, modeIdx);
  }

  // void hlAttrDefine(int id, HlAttrs attrs, HlAttrs cterm_attrs, Array info)
  void renderer_bell(RendererHandle r) {
    static_cast<Renderer*>(r)->bell();
  }

  void renderer_visualBell(RendererHandle r) {
    static_cast<Renderer*>(r)->visualBell();
  }

  void renderer_defaultColorsSet(RendererHandle r, int rgbFg, int rgbBg, int rgbSp, int ctermFg, int ctermBg) {
    static_cast<Renderer*>(r)->defaultColorsSet(rgbFg, rgbBg, rgbSp, ctermFg, ctermBg);
  }

  void renderer_flush(RendererHandle r) {
    static_cast<Renderer*>(r)->flush();
  }

  void renderer_suspend(RendererHandle r) {
    static_cast<Renderer*>(r)->suspend();
  }

  void renderer_setTitle(RendererHandle r, const char* title) {
    static_cast<Renderer*>(r)->setTitle(title);
  }

  void renderer_setIcon(RendererHandle r, const char* icon) {
    static_cast<Renderer*>(r)->setIcon(icon);
  }

  void renderer_screenshot(RendererHandle r, const char* path) {
    static_cast<Renderer*>(r)->screenshot(path);
  }

  // void optionSet(const char* name, Object value)
  void renderer_rawLine(
      RendererHandle r,
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
    static_cast<Renderer*>(r)->rawLine(gridId, lineRow, startCol, endCol, clearCol, clearAttr, flags, chunk, attrs);
  }
}
