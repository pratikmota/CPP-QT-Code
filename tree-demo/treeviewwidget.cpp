#include "treeviewwidget.h"

TreeViewWidget::TreeViewWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create the model
    model = new QFileSystemModel(this);
    model->setRootPath("/"); // Set the root path to display

    // Create the tree view
    treeView = new QTreeView(this);
    treeView->setModel(model);

    // Enable checkboxes for items
    //treeView->setHeaderHidden(true); // Hide the header
    // Make the header visible
    treeView->setHeaderHidden(false);

    // Set column titles
    QStandardItemModel *headerModel = new QStandardItemModel(treeView);
    headerModel->setHorizontalHeaderLabels({"File Name", "Size", "Type", "Modified"});
    treeView->header()->setModel(headerModel);

    treeView->setItemDelegate(new QStyledItemDelegate());
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    /*
    // Set checkboxes for the first column (index 0)
    for (int i = 0; i < model->columnCount(); ++i) {
        treeView->setItemDelegateForColumn(i, new QStyledItemDelegate());
    }
*/

    // Enable multi-selection and checkboxes for all items
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    for (int i = 0; i < model->columnCount(); ++i) {
        treeView->setItemDelegateForColumn(i, new QStyledItemDelegate());
    }

    //treeView->resizeColumnToContents(0);
    treeView->setColumnWidth(0, 250);

    // Allow user to check/uncheck items
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(treeView);

    // Connect to the double-clicked signal
    connect(treeView, &QTreeView::doubleClicked, this, &TreeViewWidget::onItemDoubleClicked);
}

void TreeViewWidget::onItemDoubleClicked(const QModelIndex &index)
{
    QString filePath = model->filePath(index);
    QDesktopServices::openUrl(QUrl::fromLocalFile(filePath));
}

/*
QModelIndexList selectedIndexes = treeView->selectionModel()->selectedIndexes();

QStringList selectedFiles;
foreach (const QModelIndex &index, selectedIndexes) {
    if (model->isDir(index)) {
        // Handle directories if needed (e.g., add them to a list)
    } else {
        QString filePath = model->filePath(index);
        selectedFiles.append(filePath); // Or use file names: QString fileName = model->fileName(index);
    }
}
// ... (after obtaining selectedFiles)

qDebug() << "Selected files:";
foreach (const QString &filePath, selectedFiles) {
    qDebug() << filePath;
}

// You can now use the selectedFiles list for further processing or actions
//==============

void TreeViewWidget::onButtonClicked() // Example function
{
    // Get selected files
    QModelIndexList selectedIndexes = treeView->selectionModel()->selectedIndexes();
    QStringList selectedFiles;
    foreach (const QModelIndex &index, selectedIndexes) {
        // ... (code to handle files and directories)
    }

    // Use the selectedFiles list for further processing
}

*/
