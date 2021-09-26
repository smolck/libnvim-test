#include "libnvim.h"
#include "nvim/cursor_shape.h"
#include "gui.h"

static void stop(UI* ui)
{
  // ui->data = NULL;
}

static void grid_resize(UI *ui, Integer g, Integer width, Integer height)
{
  printf("grid: %lld, width: %lld, height: %lld, ", g, width, height);
}

static void grid_clear(UI *ui, Integer g)
{
}

static void grid_cursor_goto(UI *ui, Integer grid, Integer row, Integer col)
{
}

static void mode_info_set(UI *ui, bool guicursor_enabled, Array args)
{
}

static void update_menu(UI *ui)
{
}

static void busy_start(UI *ui)
{
  // ((TUIData *)ui->data)->busy = true;
}

static void busy_stop(UI *ui)
{
  // ((TUIData *)ui->data)->busy = false;
}

static void mouse_on(UI *ui)
{
}

static void mouse_off(UI *ui)
{
}

static void set_mode(UI *ui, ModeShape mode)
{
}

static void mode_change(UI *ui, String mode, Integer mode_idx)
{
}

static void hl_attr_define(UI *ui, Integer id, HlAttrs attrs, HlAttrs cterm_attrs, Array info)
{}

static void bell(UI *ui)
{
}

static void visual_bell(UI *ui)
{
}

static void grid_scroll(UI *ui, Integer g, Integer startrow,  // -V751
                            Integer endrow, Integer startcol, Integer endcol, Integer rows,
                            Integer cols FUNC_ATTR_UNUSED)
{
}

static void default_colors_set(UI *ui, Integer rgb_fg, Integer rgb_bg, Integer rgb_sp,
                                   Integer cterm_fg, Integer cterm_bg)
{}

// Will this function run in reverse in the southern hemisphere?
static void flush(UI *ui)
{
}

static void suspend(UI *ui)
{
}

static void set_title(UI *ui, String title)
{}

static void set_icon(UI *ui, String icon)
{
}

static void screenshot(UI *ui, String path)
{}

static void option_set(UI *ui, String name, Object value)
{}

static void raw_line(UI *ui, Integer g, Integer linerow, Integer startcol, Integer endcol,
                         Integer clearcol, Integer clearattr, LineFlags flags, const schar_T *chunk,
                         const sattr_T *attrs)

{
  // printf("raw line: %s\n", (char *)chunk);
  for (Integer c = startcol; c < endcol; c++) {
    // const char* stuff;
    // memcpy((void *)stuff, chunk[c-startcol], sizeof(schar_T));
    printf("%s", (char *)chunk[c-startcol]);

    // assert((size_t)attrs[c-startcol] < kv_size(data->attrs));
    // grid->cells[linerow][c].attr = attrs[c-startcol];
  }
  printf("\n");
}


/// Main function of the GUI thread
static void gui_main(UIBridgeData *bridge, UI *ui)
{
  printf("main wassup\n");

  CONTINUE(bridge);
}

/// Handoff point between the main (ui_bridge) thread and the GUI thread.
static void gui_scheduler(Event event, void *d)
{
  // printf("wassup\n");

  event.handler(event.argv);
  // event.handler(d);

  /*UI *ui = d;
  TUIData *data = ui->data;
  loop_schedule_fast(data->loop, event);  // `tui_loop` local to tui_main().
  */
}

void gui_start(void) {
  UI *ui = xcalloc(1, sizeof(UI));  // Not freed by ui_bridge_stop() (yet? TODO(smolck))
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
