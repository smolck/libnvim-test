#pragma once

#define INCLUDE_GENERATED_DECLARATIONS
#include "nvim/cursor_shape.h"
#include "nvim/ui.h"
#include "nvim/ui_bridge.h"
#include "renderer-interface.h"

static void stop(UI *ui) {
  // ui->data = NULL;
  renderer_stop(ui->data);
}

static void grid_resize(UI *ui, Integer g, Integer width, Integer height) {
  renderer_gridResize(ui->data, g, width, height);
}

static void grid_clear(UI *ui, Integer g) { renderer_gridClear(ui->data, g); }

static void grid_cursor_goto(UI *ui, Integer grid, Integer row, Integer col) {
  renderer_gridCursorGoto(ui->data, grid, row, col);
}

static void mode_info_set(UI *ui, bool guicursor_enabled, Array args) {
  // TODO(smolck): Probably iterate on the C side here and then send
  // individual key-value stuff to C++?
}

static void update_menu(UI *ui) { renderer_updateMenu(ui->data); }

static void busy_start(UI *ui) { renderer_busyStart(ui->data); }

static void busy_stop(UI *ui) { renderer_busyStop(ui->data); }

static void mouse_on(UI *ui) { renderer_mouseOn(ui->data); }

static void mouse_off(UI *ui) { renderer_mouseOff(ui->data); }

static void set_mode(UI *ui, ModeShape mode) {
  renderer_setMode(ui->data, mode);
}

static void mode_change(UI *ui, String mode, Integer mode_idx) {
  // TODO(smolck): Need to send mode.size as well?
  renderer_modeChange(ui->data, mode.data, mode_idx);
}

static void hl_attr_define(UI *ui, Integer id, HlAttrs attrs,
                           HlAttrs cterm_attrs, Array info) {
  // TODO(smolck): Again, probably iterate this from the C side
  // and send individual attr stuff to C++?
}

static void bell(UI *ui) { renderer_bell(ui->data); }

static void visual_bell(UI *ui) { renderer_visualBell(ui->data); }

static void grid_scroll(UI *ui, Integer g, Integer startrow, // -V751
                        Integer endrow, Integer startcol, Integer endcol,
                        Integer rows, Integer cols) {
  renderer_gridScroll(ui->data, g, startrow, endrow, startcol, endcol, rows,
                      cols);
}

static void default_colors_set(UI *ui, Integer rgb_fg, Integer rgb_bg,
                               Integer rgb_sp, Integer cterm_fg,
                               Integer cterm_bg) {
  renderer_defaultColorsSet(ui->data, rgb_fg, rgb_bg, rgb_sp, cterm_fg,
                            cterm_bg);
}

// Will this function run in reverse in the southern hemisphere?
static void flush(UI *ui) { renderer_flush(ui->data); }

static void suspend(UI *ui) { renderer_suspend(ui->data); }

static void set_title(UI *ui, String title) {
  // TODO(smolck): Need to also send title.size?
  renderer_setTitle(ui->data, title.data);
}

static void set_icon(UI *ui, String icon) {
  // TODO(smolck): Need to also send icon.size?
  renderer_setIcon(ui->data, icon.data);
}

static void screenshot(UI *ui, String path) {
  // TODO(smolck): Need to also send path.size?
  renderer_screenshot(ui->data, path.data);
}

static void option_set(UI *ui, String name, Object value) {
  // TODO(smolck): Yet again, probably deal with `value` on the C
  // side then send it over to C++ somehow . . . or define Object etc.
  // on the C++ side somehow . . .
}

static void raw_line(UI *ui, Integer g, Integer linerow, Integer startcol,
                     Integer endcol, Integer clearcol, Integer clearattr,
                     int flags, const schar_T *chunk, const sattr_T *attrs) {
  renderer_rawLine(ui->data, g, linerow, startcol, endcol, clearcol, clearattr,
                   flags, (const char *)chunk, attrs);
}

static void gui_main(UIBridgeData *bridge, UI *ui) { CONTINUE(bridge); }
static void gui_scheduler(Event event, void *d) {
  event.handler(event.argv);

  /*UI *ui = d;
  TUIData *data = ui->data;
  loop_schedule_fast(data->loop, event);  // `tui_loop` local to tui_main().
  */
}
