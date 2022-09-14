#pragma once

#include <QWidget>

#include <Hakool/hakool.h>

using hk::Hakool;

/**
 * @brief TODO
 */
class ViewWidget : public QWidget
{
public:

  ViewWidget(QWidget* pParent, Hakool& hakool);

  virtual ~ViewWidget();

private:

  Hakool& m_hakool;

};