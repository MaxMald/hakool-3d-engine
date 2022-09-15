#include "hkWindowFactoryQtWidget.h"

#include <QBoxLayout>
#include <QHBoxLayout>

#include "hkWindowQtWidget.h"

namespace hk
{
  WindowFactoryQtWidget::WindowFactoryQtWidget(Hakool& hakool, QWidget* pParent) :
    m_hakool(hakool),
    m_pParent(pParent)
  { }

  WindowFactoryQtWidget::~WindowFactoryQtWidget()
  { }

  Window* 
  WindowFactoryQtWidget::createHakoolWindow()
  {
    WindowQtWidget* pWindow = new WindowQtWidget(m_pParent, m_hakool);
    QHBoxLayout* pHBoxLayout = new QHBoxLayout(m_pParent);
    pHBoxLayout->addWidget(pWindow);
    return pWindow;
  }
}