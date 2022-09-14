#include "viewWidget.h"

ViewWidget::ViewWidget(QWidget* pParent, Hakool& hakool):
  QWidget(pParent),
  m_hakool(hakool)
{ }

ViewWidget::~ViewWidget()
{
  setAttribute(Qt::WA_PaintOnScreen);
  setAttribute(Qt::WA_OpaquePaintEvent);
  setAttribute(Qt::WA_NoSystemBackground);

}
