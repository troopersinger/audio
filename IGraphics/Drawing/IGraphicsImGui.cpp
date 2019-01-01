#if defined IGRAPHICS_IMGUI
#include "imgui.cpp"
#include "imgui_widgets.cpp"
#include "imgui_draw.cpp"
#include "imgui_demo.cpp"

#if defined IGRAPHICS_GL
#if defined IGRAPHICS_GL2
#include "imgui_impl_opengl2.cpp"
#elif defined IGRAPHICS_GL3
#include "imgui_impl_opengl3.cpp"
#endif
#endif

#endif //IGRAPHICS_IMGUI
