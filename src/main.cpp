#include "renderer.hpp"

extern "C" {
#include "ui.h"
}

auto main() -> int {
  auto renderer = std::make_unique<Renderer>();

  std::thread nvimThread(runNvim, renderer.get());
  renderer->glfwLoop();
}
