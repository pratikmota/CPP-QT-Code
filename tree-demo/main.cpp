#include <QApplication>
#include "treeviewwidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TreeViewWidget widget;
    widget.show();

    return app.exec();
}
