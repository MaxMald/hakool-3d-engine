#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Editor.h"

#include "windowWidget.h"

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

    WId wid;

private:

    Ui::EditorClass 
    ui;

    /**
     * @brief Window widget used to render hakool's graphics.
     */
    WindowWidget
    m_windowWidget;
};
