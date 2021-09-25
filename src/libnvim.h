#pragma once
#define INCLUDE_GENERATED_DECLARATIONS

#include "nvim/ui_bridge.h"

int nvim_main(int argc, char **argv, void (*f)());
int start_nvim(void (*f)());

/*typedef struct {
  void (*gui_main)(UIBridgeData *bridge, UI *ui);
  void (*gui_scheduler)(Event, void*);

  void (*stop)(UI*);
  void (*grid_resize)(UI*);
  void (*grid_clear)(UI*);
  void (*grid_cursor_goto)(UI*);
  void (*gui_)(UI*);
  void (*gui_)(UI*);
} GUIData;*/

// UI *gui_start(GUIData *gui_data);
