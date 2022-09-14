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

  virtual void
  paintEvent(QPaintEvent* event) override;

private:

  Hakool& m_hakool;

};