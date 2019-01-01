#include "IPlugPlatform.h"

#if defined IGRAPHICS_IMGUI

#import "IGraphicsImGui.h"

#if defined IGRAPHICS_METAL
#import <Metal/Metal.h>

@interface ImGuiRenderer ()
@property (nonatomic, strong) id <MTLCommandQueue> commandQueue;
@end

@implementation ImGuiRenderer

- (id) initWithIGraphics: (IGraphicsMac*) pGraphics
{
  self = [super init];
 
  if(self)
  {
    mGraphics = pGraphics;

    id<MTLDevice> device = MTLCreateSystemDefaultDevice();

    _commandQueue = [device newCommandQueue];

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    //TODO lamda init
    ImGui::StyleColorsDark();

    ImGui_ImplMetal_Init(device);
  }
  
  return self;
}

- (void)render:(NSView*) view;
{
  ImGuiIO &io = ImGui::GetIO();
  io.DisplaySize.x = view.bounds.size.width;
  io.DisplaySize.y = view.bounds.size.height;

#if defined OS_MAC
  CGFloat framebufferScale = view.window.screen.backingScaleFactor ?: NSScreen.mainScreen.backingScaleFactor;
#elif defined OS_IOS
  CGFloat framebufferScale = view.window.screen.scale ?: UIScreen.mainScreen.scale;
#endif
  io.DisplayFramebufferScale = ImVec2(framebufferScale, framebufferScale);

  io.DeltaTime = 1 / 60.;//float(view.preferredFramesPerSecond ?: 60);

  id<MTLCommandBuffer> commandBuffer = [self.commandQueue commandBuffer];

  static bool show_demo_window = true;
  
  MTLRenderPassDescriptor* descriptor = [MTLRenderPassDescriptor renderPassDescriptor];
  
  descriptor.colorAttachments[0].clearColor = MTLClearColorMake(0.f, 0.f, 0.f, 0.f);
  descriptor.colorAttachments[0].loadAction = MTLLoadActionLoad;
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

//        [commandBuffer presentDrawable:view.currentDrawable];
  }

  [commandBuffer commit];
}

@end

#include "imgui_impl_metal.mm"

#endif

#endif
