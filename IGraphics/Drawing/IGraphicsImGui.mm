#include "IPlugPlatform.h"

#if defined IGRAPHICS_IMGUI

#import "IGraphicsImGui.h"

#if defined IGRAPHICS_METAL
#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>

ImGuiRenderer::ImGuiRenderer(IGraphics* pGraphics)
: mGraphics(pGraphics)
{
  id<MTLDevice> device = MTLCreateSystemDefaultDevice();

  mCommandQueue = [device newCommandQueue];

  IMGUI_CHECKVERSION();
  ImGui::CreateContext();

  //TODO lamda init
  ImGui::StyleColorsDark();

  ImGui_ImplMetal_Init(device);
}

void ImGuiRenderer::Render()
{
  NSView* pView = (NSView*) mGraphics->GetWindow();
  CAMetalLayer* pLayer = (CAMetalLayer*) [pView layer];

  ImGuiIO &io = ImGui::GetIO();
  io.DisplaySize.x = mGraphics->WindowWidth();
  io.DisplaySize.y = mGraphics->WindowHeight();
  io.DisplayFramebufferScale = ImVec2(mGraphics->GetScreenScale(), mGraphics->GetScreenScale());
  io.DeltaTime = 1.f / mGraphics->FPS();

  id<MTLCommandBuffer> commandBuffer = [(id) mCommandQueue commandBuffer];
  static bool show_demo_window = true;

  id<CAMetalDrawable> drawable = [pLayer nextDrawable];

  MTLRenderPassDescriptor* descriptor = [MTLRenderPassDescriptor renderPassDescriptor];
  descriptor.colorAttachments[0].texture = [drawable texture];
  descriptor.colorAttachments[0].clearColor = MTLClearColorMake(1.f, 1.f, 1.f, 1.f);
  descriptor.colorAttachments[0].loadAction = MTLLoadActionLoad; //
  descriptor.colorAttachments[0].storeAction = MTLStoreActionStore;

  if (descriptor != nil)
  {
    id <MTLRenderCommandEncoder> renderEncoder = [commandBuffer renderCommandEncoderWithDescriptor:descriptor];
    [renderEncoder pushDebugGroup:@"ImGui"];

    // Start the Dear ImGui frame
    ImGui_ImplMetal_NewFrame(descriptor);
//      ImGui_ImplOSX_NewFrame(view);
    ImGui::NewFrame();

    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (show_demo_window)
      ImGui::ShowDemoWindow(&show_demo_window);

    // Rendering
    ImGui::Render();
    ImDrawData *drawData = ImGui::GetDrawData();
    ImGui_ImplMetal_RenderDrawData(drawData, commandBuffer, renderEncoder);

    [renderEncoder popDebugGroup];
    [renderEncoder endEncoding];

    [commandBuffer presentDrawable:drawable];
  }

  [commandBuffer commit];
}

#endif

#endif
