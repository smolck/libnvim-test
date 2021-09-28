#define INCLUDE_GENERATED_DECLARATIONS
#include "ui.h"

#include "ui_to_renderer.h"
#include "nvim/memory.h"
#include "nvim/api/private/defs.h"

#include "nvim/main.h"
#include "nvim/ui.h"

int nvim_main(int argc, char **argv, void (*f)());

static RendererHandle renderer;

void gui_start(void) {
  // renderer_print_whatever(renderer);
  // renderer_free(renderer);
  UI *ui = xcalloc(1, sizeof(UI));  // Not freed by ui_bridge_stop() (yet? TODO(smolck))
  ui->data = renderer;

  ui->stop = stop;
  ui->grid_resize = grid_resize;
  ui->grid_clear = grid_clear;
  ui->grid_cursor_goto = grid_cursor_goto;
  ui->mode_info_set = mode_info_set;
  ui->update_menu = update_menu;
  ui->busy_start = busy_start;
  ui->busy_stop = busy_stop;
  ui->mouse_on = mouse_on;
  ui->mouse_off = mouse_off;
  ui->mode_change = mode_change;
  ui->grid_scroll = grid_scroll;
  ui->hl_attr_define = hl_attr_define;
  ui->bell = bell;
  ui->visual_bell = visual_bell;
  ui->default_colors_set = default_colors_set;
  ui->flush = flush;
  ui->suspend = suspend;
  ui->set_title = set_title;
  ui->set_icon = set_icon;
  ui->screenshot = screenshot;
  ui->option_set= option_set;
  ui->raw_line = raw_line;

  memset(ui->ui_ext, 0, sizeof(ui->ui_ext));
  ui->ui_ext[kUILinegrid] = true;
  ui->ui_ext[kUITermColors] = true;

  ui->width = 80;
  ui->height = 80;

  ui_bridge_attach(ui, gui_main, gui_scheduler);
}

int runNvim(RendererHandle r)
{
  char** stuff = malloc(3 * sizeof(char *));
  stuff[0] = "nvim";
  stuff[1] = "-u";
  stuff[2] = "NONE";
  // stuff[1] = "--headless";
  
  renderer = r;

  return nvim_main(3, stuff, &gui_start);
}
