#include "detailswindow.h"
#include "ui_detailswindow.h"
#include <QLabel>

DetailsWindow::DetailsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DetailsWindow),
    parent(parent)
{
    ui->setupUi(this);

    QPalette palette;
    palette.setColor(QPalette::WindowText, Qt::white);

    QPixmap bkgnd("C:/Users/brahm/PROJETS_TRAVAIL_PDF/PROJETS/C++/Kanji_Quiz/Kanji_Study/bkg.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);

}

DetailsWindow::~DetailsWindow()
{
    parent->show();
    delete ui;
}

void DetailsWindow::closeEvent(QCloseEvent *event)
{
     parent->show();
}

void DetailsWindow::on_returnButton_clicked()
{
    parent->show();
    this->close();
    this->destroy();
}

void DetailsWindow::DisplayKanjis(std::vector<QStringList> Kanjis)
{
    int n_kanji = Kanjis.size();

    if (n_kanji < 1)
        return;


    int frame_width = ui->frame->width();
    int n_space = n_kanji - 1;
    int space = 25;

    int fonts[4]{32,75,30,30};

    int l = (frame_width - n_space*space) / n_kanji;
    int h = 130;

    int cursor_x = ui->frame->frameGeometry().topLeft().x();

    for (int i = 0; i < n_kanji ; i++)
    {
        QStringList KanjiDetail = Kanjis[i];
        int cursor_y = ui->frame->frameGeometry().topLeft().y();

        for (int j = 0 ; j < KanjiDetail.size(); j++)
        {
            QLabel *label = new QLabel(this);
            label->setFrameStyle(QFrame::Panel | QFrame::Sunken);
            label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
            QFont font = label->font(); font. setPointSize(fonts[j]); label->setFont(font);
            label->setText(KanjiDetail[j]);
            label->setGeometry(cursor_x,cursor_y,l,h);
            label->setWordWrap(true);

            cursor_y += h + space;
        }

        cursor_x += l + space;

    }

}
