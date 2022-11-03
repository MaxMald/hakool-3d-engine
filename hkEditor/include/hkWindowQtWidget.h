#pragma once

#include <QWidget>

#include <Hakool/hakool.h>
#include <Hakool/Utils/hkWindow.h>

using hk::Hakool;
using hk::Window;
using hk::eRESULT;
using hk::WindowConfiguration;
using hk::uint32;
using hk::Vector2u;
using hk::String;

/**
 * @brief TODO
 */
class WindowQtWidget : public QWidget, public Window
{
public:

  WindowQtWidget(QWidget* pParent, Hakool& hakool);

  virtual ~WindowQtWidget();

  virtual eRESULT
  init(const WindowConfiguration& _config) override;

  virtual HANDLER
  getWindowHandler() override;

  virtual bool
  isOpen() override;

  virtual void
  update() override;

  virtual void
  postUpdate() override;

  virtual void
  destroy() override;

  virtual void
  paintEvent(QPaintEvent* event) override;

  virtual QPaintEngine*
  paintEngine() const;

  virtual void
  resizeEvent(QResizeEvent* event);

private:

  virtual void showEvent(QShowEvent*);

  Hakool& m_hakool;
};