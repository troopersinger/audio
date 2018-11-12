#include "PUGLEditorDelegate.h"

#include "gl.h"
#include "pugl.h"

IPlugPUGLView::IPlugPUGLView()
: pugl::View(nullptr, nullptr)
{
}

IPlugPUGLView::~IPlugPUGLView()
{
  if(mTimer) {
    mTimer->Stop();
    DELETE_NULL(mTimer);
  }
}

void IPlugPUGLView::Init(int w, int h, void* pParent)
{
  initWindowSize(w, h);
  initWindowMinSize(100, 100);
  initResizable(true);
  initContextType(PUGL_GL);
  initWindowParent((PuglNativeWindow) pParent);
  initTransientFor((uintptr_t) pParent);
  
  createWindow("IPlugPUGL");
  
  OnInit();
  
  mTimer = Timer::Create(std::bind(&IPlugPUGLView::OnTimer, this, std::placeholders::_1), 16.);
}

void IPlugPUGLView::OnTimer(Timer& t)
{
  waitForEvent();
  postRedisplay();
}

void IPlugPUGLView::onEvent(const PuglEvent* event)
{
  auto printModifiers = [](unsigned mods)
  {
    fprintf(stderr, "Modifiers:%s%s%s%s\n",
            (mods & PUGL_MOD_SHIFT) ? " Shift"   : "",
            (mods & PUGL_MOD_CTRL)  ? " Ctrl"    : "",
            (mods & PUGL_MOD_ALT)   ? " Alt"     : "",
            (mods & PUGL_MOD_SUPER) ? " Super" : "");
  };
  
  switch (event->type) {
    case PUGL_NOTHING:
      break;
    case PUGL_CONFIGURE:
      OnReshape(event->configure.width, event->configure.height);
      break;
    case PUGL_EXPOSE:
      OnDisplay();
      break;
    case PUGL_CLOSE:
      break;
    case PUGL_KEY_PRESS:
      fprintf(stderr, "Key %u (char U+%04X special U+%04X) press (%s)%s\n",
              event->key.keycode, event->key.character, event->key.special,
              event->key.utf8, event->key.filter ? " (filtered)" : "");
      break;
    case PUGL_KEY_RELEASE:
      fprintf(stderr, "Key %u (char U+%04X special U+%04X) release (%s)%s\n",
              event->key.keycode, event->key.character, event->key.special,
              event->key.utf8, event->key.filter ? " (filtered)" : "");
      break;
    case PUGL_MOTION_NOTIFY:
      break;
    case PUGL_BUTTON_PRESS:
    case PUGL_BUTTON_RELEASE:
      fprintf(stderr, "Mouse %d %s at %f,%f ",
              event->button.button,
              (event->type == PUGL_BUTTON_PRESS) ? "down" : "up",
              event->button.x,
              event->button.y);
      printModifiers(event->scroll.state);
      break;
    case PUGL_SCROLL:
      fprintf(stderr, "Scroll %f %f %f %f ",
              event->scroll.x, event->scroll.y, event->scroll.dx, event->scroll.dy);
      printModifiers(event->scroll.state);
      break;
    case PUGL_ENTER_NOTIFY:
      fprintf(stderr, "Entered\n");
      break;
    case PUGL_LEAVE_NOTIFY:
      fprintf(stderr, "Exited\n");
      break;
    case PUGL_FOCUS_IN:
      fprintf(stderr, "Focus in\n");
      break;
    case PUGL_FOCUS_OUT:
      fprintf(stderr, "Focus out\n");
      break;
  }
};

PUGLEditorDelegate::PUGLEditorDelegate(int nParams)
: IEditorDelegate(nParams)
{  
}

PUGLEditorDelegate::~PUGLEditorDelegate()
{
  CloseWindow();
}

void* PUGLEditorDelegate::OpenWindow(void* pParent)
{
  if(mView) {
    mView->hideWindow();
    DELETE_NULL(mView);
  }
  
  mView = CreateView();
  
  if(mView)
  {
    mView->Init(GetEditorWidth(), GetEditorHeight(), pParent);
    return (void*) mView->getNativeWindow();
  }
  else
    return nullptr;
}

void PUGLEditorDelegate::CloseWindow()
{
  if(mView) {
    mView->hideWindow();
    DELETE_NULL(mView);
  }
}
