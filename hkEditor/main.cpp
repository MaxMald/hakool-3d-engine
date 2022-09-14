#include "Editor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication editorApp(argc, argv);

    editorApp.setOrganizationName("HummingFlight");
    editorApp.setOrganizationDomain("https://hummingflight.com");
    editorApp.setApplicationName("Hakool Editor");
    editorApp.setApplicationDisplayName("Hakool Editor");
    editorApp.setApplicationVersion("0.0.0");
    
    Editor editor;
    editor.init();
    editor.show();
    return editorApp.exec();
}
