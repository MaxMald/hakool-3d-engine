#include "hkWindowQtWidget.h"

#include <QResizeEvent>

WindowQtWidget::WindowQtWidget(QWidget* pParent, Hakool& hakool):
  QWidget(pParent),
  m_hakool(hakool)
{ 
 
}

WindowQtWidget::~WindowQtWidget()
{
}

eRESULT 
WindowQtWidget::init(const WindowConfiguration& _config)
{
  Window::init(_config); 

  resize(_config.width, _config.height);
  return eRESULT::kSuccess;
}

HANDLER 
WindowQtWidget::getWindowHandler()
{
    return (HANDLER)winId();
}

bool 
WindowQtWidget::isOpen()
{
    return true;
}

void 
WindowQtWidget::update()
{
}

void 
WindowQtWidget::postUpdate()
{
}

void 
WindowQtWidget::destroy()
{
}

void 
WindowQtWidget::paintEvent(QPaintEvent* event)
{
  m_hakool.update();
  m_hakool.draw();
}

QPaintEngine* 
WindowQtWidget::paintEngine() const
{
  return 0;
}

void
WindowQtWidget::resizeEvent(QResizeEvent* evt)
{
  setSize((hk::uint32)evt->size().width(), (hk::uint32)evt->size().height());
}

void 
WindowQtWidget::showEvent(QShowEvent*)
{
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);
}
