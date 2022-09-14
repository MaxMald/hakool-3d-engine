#include <windowWidget.h>

WindowWidget::WindowWidget():
  Window(),
  m_windowHandler()
{ }

WindowWidget::WindowWidget(WId wid):
  Window(),
  m_windowHandler(wid)
{ }

WindowWidget::~WindowWidget()
{ }

void 
WindowWidget::SetWId(WId wid)
{
  m_windowHandler = wid;
}

HANDLER 
WindowWidget::getWindowHandler()
{
  return (HANDLER)m_windowHandler;
}

bool 
WindowWidget::isOpen()
{
  return true;
}
