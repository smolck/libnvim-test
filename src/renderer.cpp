#include <iostream>
#include "renderer.hpp"
#include "include/core/SkCanvas.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/core/SkData.h"
#include "include/core/SkStream.h"

constexpr int INITIAL_WIDTH = 900;
constexpr int INITIAL_HEIGHT = 900;

void error_callback(int error, const char* description) {
  fputs(description, stderr);
}

void Renderer::initGlfwAndSkia() {
  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    exit(EXIT_FAILURE);
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  //(uncomment to enable correct color spaces) glfwWindowHint(GLFW_SRGB_CAPABLE, GL_TRUE);
  glfwWindowHint(GLFW_STENCIL_BITS, 0);
  //glfwWindowHint(GLFW_ALPHA_BITS, 0);
  glfwWindowHint(GLFW_DEPTH_BITS, 0);

  std::unique_ptr<GLFWwindow, GLFWDestructor> win(glfwCreateWindow(INITIAL_WIDTH, INITIAL_HEIGHT, "Simple example", NULL, NULL));
  this->m_window = std::move(win);

  if (!this->m_window) {
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  glfwMakeContextCurrent(this->m_window.get());
  //(uncomment to enable correct color spaces) glEnable(GL_FRAMEBUFFER_SRGB);

  // init skia
  auto interface = GrGLMakeNativeInterface();

  std::unique_ptr<GrDirectContext> context(GrDirectContext::MakeGL(interface).release());
  this->m_context = std::move(context);

  GrGLFramebufferInfo framebufferInfo;
  framebufferInfo.fFBOID = 0; // assume default framebuffer
  // We are always using OpenGL and we use RGBA8 internal format for both RGBA and BGRA configs in OpenGL.
  //(replace line below with this one to enable correct color spaces) framebufferInfo.fFormat = GL_SRGB8_ALPHA8;
  framebufferInfo.fFormat = GL_RGBA8;

  SkColorType colorType = kRGBA_8888_SkColorType;
  GrBackendRenderTarget backendRenderTarget(INITIAL_WIDTH, INITIAL_HEIGHT,
    0, // sample count
    0, // stencil bits
    framebufferInfo);

  //(replace line below with this one to enable correct color spaces) sSurface = SkSurface::MakeFromBackendRenderTarget(sContext, backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, SkColorSpace::MakeSRGB(), nullptr).release();
  std::unique_ptr<SkSurface> surface(SkSurface::MakeFromBackendRenderTarget(
      this->m_context.get(),
      backendRenderTarget,
      kBottomLeft_GrSurfaceOrigin,
      colorType,
      nullptr,
      nullptr
    ).release());
  if (surface == nullptr) abort();

  this->m_surface = std::move(surface);
  // (replace sSurface creation with this one to enable correct color spaces):
  // sSurface = SkSurface::MakeFromBackendRenderTarget(sContext, backendRenderTarget, kBottomLeft_GrSurfaceOrigin, colorType, SkColorSpace::MakeSRGB(), nullptr).release();

  glfwSwapInterval(1);
  // glfwSetKeyCallback(window, key_callback);
}

Renderer::Renderer() {
  this->initGlfwAndSkia();
}

void Renderer::glfwLoop() {
  auto canvas = this->m_surface->getCanvas();
  auto win = this->m_window.get();

  while (!glfwWindowShouldClose(win)) {
    glfwWaitEvents();
    SkPaint paint;
    paint.setColor(SK_ColorWHITE);
    canvas->drawPaint(paint);
    paint.setColor(SK_ColorBLUE);
    canvas->drawRect({100, 200, 300, 500}, paint);
    this->m_context->flush();

    glfwSwapBuffers(win);
  }

  glfwDestroyWindow(win);
  glfwTerminate();
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
