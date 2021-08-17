#ifndef DETAILSWINDOW_H
#define DETAILSWINDOW_H

#include <QDialog>
#include "helpers.h"

namespace Ui {
class DetailsWindow;
}

class DetailsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DetailsWindow(QWidget *parent = nullptr);
    ~DetailsWindow();

    void DisplayKanjis(std::vector<QStringList> Kanjis);

private slots:
    void on_returnButton_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::DetailsWindow *ui;
    QWidget *parent;
};



#endif // DETAILSWINDOW_H
