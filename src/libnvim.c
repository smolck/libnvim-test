#include "libnvim.h"

#include "nvim/memory.h"
#include "nvim/api/private/defs.h"

#include "nvim/main.h"

int start_nvim(void (*f)())
{
  char** stuff = malloc(3 * sizeof(char *));
  stuff[0] = "nvim";
  stuff[1] = "-u";
  stuff[2] = "NONE";
  // stuff[1] = "--headless";

  return nvim_main(1, stuff, f);
}

/*UI *gui_start(GUIData *gui_data)
{

}*/
