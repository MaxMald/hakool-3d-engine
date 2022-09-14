#include "Editor.h"

#include <QHBoxLayout>

#include <Hakool\hakool.h>
#include <Hakool/Core/hkCoreUtilities.h>

#include "plainTextWidgetLogger.h"
#include "viewWidget.h"

using hk::Hakool;
using hk::Color;
using hk::PlainTextWidgetLogger;

Editor::Editor(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Editor::~Editor()
{}

void 
Editor::init()
{
  Hakool::Start();
  Hakool* pEngine = Hakool::GetEngine();

  ViewWidget* pViewWidget = new ViewWidget(ui.viewGroup, *pEngine);
  QHBoxLayout* pHBoxLayout = new QHBoxLayout(ui.viewGroup);
  pHBoxLayout->addWidget(pViewWidget);

  m_windowWidget.SetWId(pViewWidget->winId());

  hk::HakoolConfiguration engineConfig;
  engineConfig.windowConfiguration.pWindow = &m_windowWidget;
  engineConfig.graphicsConfiguration.graphicInterface = hk::eGRAPHIC_INTERFACE::kOpenGL;
  engineConfig.graphicsConfiguration.backgroundColor = hk::Color::RED;

  pEngine->init(engineConfig, new PlainTextWidgetLogger());
}
