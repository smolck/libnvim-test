#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef void* RendererHandle;
RendererHandle create_Renderer(int stuff);
void renderer_print_whatever(RendererHandle r);
void renderer_free(RendererHandle r);
void renderer_stop(RendererHandle r);
void renderer_gridResize(RendererHandle r, int gridId, int width, int height);
void renderer_gridClear(RendererHandle r, int gridId);
void renderer_gridCursorGoto(RendererHandle r, int grid, int row, int col);
void renderer_gridScroll(
    RendererHandle r,
    int gridId,
    int startRow,
    int endRow,
    int startCol,
    int endCol, 
    int rows, 
    int cols
);
// void mode_info_set(bool guicursor_enabled, Array args)
void renderer_updateMenu(RendererHandle r);
void renderer_busyStart(RendererHandle r);
void renderer_busyStop(RendererHandle r);
void renderer_mouseOn(RendererHandle r);
void renderer_mouseOff(RendererHandle r);
void renderer_setMode(RendererHandle r, int mode);
void renderer_modeChange(RendererHandle r, const char* mode, int modeIdx);
// void hlAttrDefine(int id, HlAttrs attrs, HlAttrs cterm_attrs, Array info)
void renderer_bell(RendererHandle r);
void renderer_visualBell(RendererHandle r);
void renderer_defaultColorsSet(RendererHandle r, int rgbFg, int rgbBg, int rgbSp, int ctermFg, int ctermBg);
void renderer_flush(RendererHandle r);
void renderer_suspend(RendererHandle r);
void renderer_setTitle(RendererHandle r, const char* title);
void renderer_setIcon(RendererHandle r, const char* icon);
void renderer_screenshot(RendererHandle r, const char* path);
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
);


#ifdef __cplusplus
}
#endif
