#include "IPlugPlatform.h"

#if defined IGRAPHICS_IMGUI

#include "imgui.h"
#include "IGraphics.h"

#if defined IGRAPHICS_GL
  #if defined IGRAPHICS_GL2
    #include "imgui_impl_opengl2.h"
  #elif defined IGRAPHICS_GL3
    #include "imgui_impl_opengl3.h"
  #endif
#elif defined IGRAPHICS_METAL
  #include "imgui_impl_metal.h"
#endif

class ImGuiRenderer
{
public:
  ImGuiRenderer(IGraphics* pGraphics);
  
  void Render();
private:
  IGraphics* mGraphics;
  void* mCommandQueue;
};
#endif
