#pragma once

#include "IPlugEditorDelegate.h"
#include "IPlugTimer.h"
#include "pugl/pugl.hpp"

/**
 * @file
 * @copydoc PUGLEditorDelegate
 */

class IPlugPUGLView : public pugl::View
{
public:
  IPlugPUGLView();
  ~IPlugPUGLView();
  
  virtual void OnReshape(int w, int h) {};
  virtual void OnDisplay() {};
  virtual void OnInit() {};
  
  void Init(int w, int h, void* pHandle);
  
  //ITimerCallback
  void OnTimer(Timer& t) override;
  
  //pugl::View
  void onEvent(const PuglEvent* event) override;

private:
  Timer* mTimer = nullptr;
};

/** An IDelgate base class for a SOMETHING that uses PUGL for it's UI */
class PUGLEditorDelegate : public IEditorDelegate
{
public:
  PUGLEditorDelegate(int nParams);
  ~PUGLEditorDelegate();

// IEditorDelegate
  void* OpenWindow(void* pHandle) override;
  void CloseWindow() override;
  
  virtual IPlugPUGLView* CreateView() = 0;
  
private:
  IPlugPUGLView* mView = nullptr;
};
