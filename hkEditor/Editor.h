#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Editor.h"

namespace hk
{
  class Scene;
}

class Editor : public QMainWindow
{
    Q_OBJECT

public:

    Editor(QWidget *parent = nullptr);
    
    ~Editor();

    /**
     * @brief Initialize the Editor.
     */
    void 
    init();

private:

    Ui::EditorClass 
    ui;

    hk::Scene*
    _m_pDefaultScene;
};
