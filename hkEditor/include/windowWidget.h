#pragma once

#include <QtWidgets/QMainWindow>

#include <Hakool/Utils/hkWindow.h>

using hk::Window;

class WindowWidget : public Window
{
public:

  /**
   * @brief Create a new window widget with an invalid WId.
   */
  WindowWidget();

  /**
   * @brief Create a new window widget with a WId.
   */
  WindowWidget(WId wid);

  virtual ~WindowWidget();

  /// <summary>
  /// Set the WId of this Window Widget.
  /// </summary>
  /// 
  /// <param name="wid">WId.</param>
  void
  SetWId(WId wid);

  /**
  * Get the window system handler.
  *
  * @return Handler.
  */
  virtual HANDLER
  getWindowHandler() override;

  /**
  * Indicates if the window is open.
  *
  * @return True if the window is open.
  */
  virtual bool
  isOpen();

protected:

  /**
   * @brief Widget window id.
   */
  WId 
  m_windowHandler;
};