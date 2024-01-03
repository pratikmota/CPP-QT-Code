#ifndef TREEVIEWWIDGET_H
#define TREEVIEWWIDGET_H

#include <QWidget>
#include <QTreeView>
#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QStyledItemDelegate>
#include <QHeaderView>
#include <QStandardItemModel>  // For column headers
#include <QDesktopServices>   // For opening files
#include <QUrl>


class TreeViewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeViewWidget(QWidget *parent = nullptr);

private slots:
    void onItemDoubleClicked(const QModelIndex &index);

private:
    QTreeView *treeView;
    QFileSystemModel *model;
};

#endif // TREEVIEWWIDGET_H
