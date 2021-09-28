#pragma once
#include "GLFW/glfw3.h"
#define SK_GL

#include "include/core/SkSurface.h"
#include "include/gpu/GrDirectContext.h"

#include <thread>

/// struct to store values from 'guicursor' and 'mouseshape'
/// Indexes in shape_table[]
/*typedef enum {
SHAPE_IDX_N      = 0,       ///< Normal mode
SHAPE_IDX_V      = 1,       ///< Visual mode
SHAPE_IDX_I      = 2,       ///< Insert mode
SHAPE_IDX_R      = 3,       ///< Replace mode
SHAPE_IDX_C      = 4,       ///< Command line Normal mode
SHAPE_IDX_CI     = 5,       ///< Command line Insert mode
SHAPE_IDX_CR     = 6,       ///< Command line Replace mode
SHAPE_IDX_O      = 7,       ///< Operator-pending mode
SHAPE_IDX_VE     = 8,       ///< Visual mode with 'selection' exclusive
SHAPE_IDX_CLINE  = 9,       ///< On command line
SHAPE_IDX_STATUS = 10,      ///< On status line
SHAPE_IDX_SDRAG  = 11,      ///< dragging a status line
SHAPE_IDX_VSEP   = 12,      ///< On vertical separator line
SHAPE_IDX_VDRAG  = 13,      ///< dragging a vertical separator line
SHAPE_IDX_MORE   = 14,      ///< Hit-return or More
SHAPE_IDX_MOREL  = 15,      ///< Hit-return or More in last line
SHAPE_IDX_SM     = 16,      ///< showing matching paren
SHAPE_IDX_COUNT  = 17
} ModeShape;*/

struct GLFWDestructor {
  void operator()(GLFWwindow *ptr) { glfwDestroyWindow(ptr); }
};

class Renderer {
private:
  std::unique_ptr<SkSurface> m_surface;
  std::unique_ptr<GLFWwindow, GLFWDestructor> m_window;
  std::unique_ptr<GrDirectContext> m_context;

  void initGlfwAndSkia();

public:
  Renderer();

  void glfwLoop();

  void stop();

  void gridResize(int gridId, int width, int height);
  void gridClear(int gridId);
  void gridCursorGoto(int grid, int row, int col);
  void gridScroll(int gridId, int startRow, int endRow, int startCol,
                  int endCol, int rows, int cols);
  // void mode_info_set(bool guicursor_enabled, Array args)
  void updateMenu();
  void busyStart();
  void busyStop();
  void mouseOn();
  void mouseOff();
  void setMode(int mode); // See above, TODO(smolck)
  void modeChange(const char *mode, int modeIdx);
  // void hlAttrDefine(int id, HlAttrs attrs, HlAttrs cterm_attrs, Array info)
  void bell();
  void visualBell();
  void defaultColorsSet(int rgbFg, int rgbBg, int rgbSp, int ctermFg,
                        int ctermBg);
  void flush();
  void suspend();
  void setTitle(const char *title);
  void setIcon(const char *icon);
  void screenshot(const char *path);
  // void optionSet(const char* name, Object value)
  void rawLine(int gridId, int lineRow, int startCol, int endCol, int clearCol,
               int clearAttr, int flags, const char *chunk, const int *attrs);
};
