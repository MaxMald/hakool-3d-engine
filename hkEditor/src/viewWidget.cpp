#include "viewWidget.h"

ViewWidget::ViewWidget(QWidget* pParent, Hakool& hakool):
  QWidget(pParent),
  m_hakool(hakool)
{ 
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);
}

ViewWidget::~ViewWidget()
{
}

void 
ViewWidget::paintEvent(QPaintEvent* event)
{
  m_hakool.update();
  m_hakool.draw();
}
