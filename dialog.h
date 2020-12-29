#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QFlags>
#include<QPushButton>
#include<QMediaPlayer>
#include<QMediaPlaylist>
#include<QSettings>
#include<QVariant>


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
private slots:

    void cek();

    void pemenang();

    void ulang();

    void on_btnadd_clicked();

    void tampilanDefault();

    void Tanya(QString namaPemenang);

    void on_btnReset_clicked();

    void on_btnpengaturan_clicked();

    void musikLoad();

    void musikSimpan();

private:
    Ui::Dialog *ui;
    int player = 1,poin1=0,poin2=0;
    QString square[10] = {"o","1","2","3","4","5","6","7","8","9"};
};
#endif // DIALOG_H
