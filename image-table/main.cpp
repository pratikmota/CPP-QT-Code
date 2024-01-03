#include "mainwindow.h"

#include <QApplication>
#include <QStandardItemModel>
#include <QTableView>
#include <QPixmap>
#include <QDebug>
#include <QBrush>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create a table model
    QStandardItemModel model;

    // Add columns
    model.setColumnCount(2);
    model.setHeaderData(0, Qt::Horizontal, "Image");
    model.setHeaderData(1, Qt::Horizontal, "Description");

    // Add rows with images
    QString imagePath1 = "D:/PROGRAMMING/QT/IMAGES/pratik.jpg"; // Replace with your image path
    QString imagePath2 = "D:/PROGRAMMING/QT/IMAGES/raju.png";

    //QPixmap pixmap1(imagePath1);
    //QPixmap pixmap2(imagePath2);
    QPixmap pixmap1 = QPixmap(imagePath1).scaled(QSize(200, 200), Qt::KeepAspectRatio);
    QPixmap pixmap2 = QPixmap(imagePath2).scaled(QSize(200, 200), Qt::KeepAspectRatio);
    //item->setData(QVariant(pixmap), Qt::DecorationRole);


    for (int i = 0; i < 2; ++i) {
        QStandardItem* item = new QStandardItem();
        item->setData(QVariant(pixmap1), Qt::DecorationRole); // Set image for decoration role
        model.setItem(i, 0, item);

        item = new QStandardItem("Description for image " + QString::number(i+1));
        item->setBackground(Qt::lightGray);
        model.setItem(i, 1, item);
    }

    // Create a table view
    QTableView tableView;
    tableView.setModel(&model);

    // Adjust column width for images
    tableView.setColumnWidth(0, 150); // Adjust as needed

    tableView.resizeRowsToContents(); // For row-based fitting
    tableView.resizeColumnsToContents(); // For column-based fitting

    tableView.setEditTriggers(QAbstractItemView::NoEditTriggers);



    // Show the table
    tableView.show();

    return app.exec();
}

/*
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
*/
