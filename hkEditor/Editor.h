#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Editor.h"

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
};
