#include "include/c/sk_canvas.h"
#include "include/c/sk_data.h"
#include "include/c/sk_image.h"
#include "include/c/sk_imageinfo.h"
#include "include/c/sk_paint.h"
#include "include/c/sk_path.h"
#include "include/c/sk_surface.h"

#include "gui.h"
#include "libnvim.h"

// void   void (*gui_main)(UIBridgeData *bridge, UI *ui);
  // void (*gui_scheduler)(Event, void*);

int main(int argc, char **argv)
{
  start_nvim(&gui_start);
}
