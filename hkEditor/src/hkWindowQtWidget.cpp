#include "hkWindowQtWidget.h"

WindowQtWidget::WindowQtWidget(QWidget* pParent, Hakool& hakool):
  QWidget(pParent),
  m_hakool(hakool)
{ 
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);
}

WindowQtWidget::~WindowQtWidget()
{
}

eRESULT 
WindowQtWidget::init(const WindowConfiguration& _config)
{
  Window::init(_config);
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
