#pragma once

#include <Hakool/Utils/hkIWindowFactory.h>
#include <QWidget>

namespace hk
{
  class Hakool;

  /**
   * Creates a Qt Widget window.
   */
  class WindowFactoryQtWidget : public IWindowFactory
  {
  public:

    /**
     * Create a new Qt Widget window factory.
     * 
     * @param hakool Reference to the hakool engine.
     * @param parent Reference to the parent widget.
     */
    WindowFactoryQtWidget(Hakool& hakool, QWidget* pParent);

    ~WindowFactoryQtWidget();

    virtual Window*
    createHakoolWindow();

  private:

    /**
     * Reference to the Hakool engine.
     */
    Hakool& m_hakool;

    /**
     * Reference to the parent widget.
     */
    QWidget* m_pParent;
  };
}