#include "dialog.h"
#include "ui_dialog.h"
#include<QSoundEffect>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    tampilanDefault();

    musikLoad();

    Qt::WindowFlags flags=0;
    flags |= Qt::WindowContextHelpButtonHint;
    setWindowFlags(flags);

    //pengaturan disabled btn
    ui->btn1->setDisabled(true);
    ui->btn2->setDisabled(true);
    ui->btn3->setDisabled(true);
    ui->btn4->setDisabled(true);
    ui->btn5->setDisabled(true);
    ui->btn6->setDisabled(true);
    ui->btn7->setDisabled(true);
    ui->btn8->setDisabled(true);
    ui->btn9->setDisabled(true);

   //membuat koneksi(signal)untuk di terima oleh fungsi cek
   connect(ui->btn1,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn2,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn3,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn4,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn5,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn6,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn7,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn8,&QPushButton::clicked,this,&Dialog::cek);
   connect(ui->btn9,&QPushButton::clicked,this,&Dialog::cek);


   ui->p1->setReadOnly(true);
   ui->p2->setReadOnly(true);
   ui->volume->hide();
   ui->lblVolume->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::tampilanDefault()
{

    ui->btn1->setText("1");
    ui->btn2->setText("2");
    ui->btn3->setText("3");
    ui->btn4->setText("4");
    ui->btn5->setText("5");
    ui->btn6->setText("6");
    ui->btn7->setText("7");
    ui->btn8->setText("8");
    ui->btn9->setText("9");

}

void Dialog::ulang()
{
    ui->btn1->setChecked(false);
    ui->btn2->setChecked(false);
    ui->btn3->setChecked(false);
    ui->btn4->setChecked(false);
    ui->btn5->setChecked(false);
    ui->btn6->setChecked(false);
    ui->btn7->setChecked(false);
    ui->btn8->setChecked(false);
    ui->btn9->setChecked(false);
    tampilanDefault();
    cek();
}

void Dialog::Tanya(QString namaPemenang)
{
    QMessageBox msg;
    msg.setText("PemenangNya " + namaPemenang);
    msg.setInformativeText("Mau Main Lagi?!");
    msg.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msg.setDefaultButton(QMessageBox::Yes);
    int nilai = msg.exec();

    if(nilai == QMessageBox::Yes){
        if(namaPemenang == "X"){
            poin1++;
            ui->p1->setValue(poin1);
        }else if(namaPemenang=="O"){
            poin2++;
            ui->p2->setValue(poin2);
        }
        ulang();
    }else{
        reject();
    }
}

void Dialog::cek()
{
    QString mark;
    player=(player%2)?1:2;
    mark=(player == 1) ? "X" : "O";


    QMediaPlayer *play = new QMediaPlayer();
    play->setMedia(QUrl::fromLocalFile("/home/gideon/Desktop/Qt/BAB 5/TicTacToc/klik.mp3"));
    play->setVolume(100);
    play->play();

    if(ui->btn1->isChecked() && square[1] == ui->btn1->text()){
        ui->btn1->setText(mark);
    }else if(ui->btn2->isChecked() && square[2] == ui->btn2->text()){
        ui->btn2->setText(mark);
    }else if(ui->btn3->isChecked() && square[3] == ui->btn3->text()){
        ui->btn3->setText(mark);
    }else if(ui->btn4->isChecked() && square[4] == ui->btn4->text()){
        ui->btn4->setText(mark);
    }else if(ui->btn5->isChecked() && square[5] == ui->btn5->text()){
        ui->btn5->setText(mark);
    }else if(ui->btn6->isChecked() && square[6] == ui->btn6->text()){
        ui->btn6->setText(mark);
    }else if(ui->btn7->isChecked() && square[7] == ui->btn7->text()){
        ui->btn7->setText(mark);
    }else if(ui->btn8->isChecked() && square[8] == ui->btn8->text()){
        ui->btn8->setText(mark);
    }else if(ui->btn9->isChecked() && square[9] == ui->btn9->text()){
        ui->btn9->setText(mark);
    }
    pemenang();
    player++;
}

void Dialog::pemenang()
{
    if(ui->btn1->text() == ui->btn5->text() && ui->btn5->text() == ui->btn9->text()){
       Tanya(ui->btn5->text());
    }else if(ui->btn3->text() == ui->btn5->text() && ui->btn5->text() == ui->btn7->text()){
       Tanya(ui->btn5->text());
    }else if(ui->btn1->text() == ui->btn4->text() && ui->btn4->text() == ui->btn7->text()){
       Tanya(ui->btn4->text());
    }else if(ui->btn2->text() == ui->btn5->text() && ui->btn5->text() == ui->btn8->text()){
       Tanya(ui->btn5->text());
    }else if(ui->btn3->text() == ui->btn6->text() && ui->btn6->text() == ui->btn9->text()){
       Tanya(ui->btn6->text());
    }else if(ui->btn1->text() == ui->btn2->text() && ui->btn2->text() == ui->btn3->text()){
       Tanya(ui->btn2->text());
    }else if(ui->btn4->text() == ui->btn5->text() && ui->btn5->text() == ui->btn6->text()){
       Tanya(ui->btn5->text());
    }else if(ui->btn7->text() == ui->btn8->text() && ui->btn8->text() == ui->btn9->text()){
       Tanya(ui->btn8->text());
    }
}

void Dialog::on_btnadd_clicked()
{
    if(ui->player1->text().isEmpty()){
      ui->player1->setText(ui->lineEdit->text());
    }else{
      ui->player2->setText(ui->lineEdit->text());
      if(!ui->player1->text().isEmpty() && !ui->player2->text().isEmpty()){

          ui->btn1->setDisabled(false);
          ui->btn2->setDisabled(false);
          ui->btn3->setDisabled(false);
          ui->btn4->setDisabled(false);
          ui->btn5->setDisabled(false);
          ui->btn6->setDisabled(false);
          ui->btn7->setDisabled(false);
          ui->btn8->setDisabled(false);
          ui->btn9->setDisabled(false);
      }

    }
    ui->btn1->setDefault(true);
}


void Dialog::on_btnReset_clicked()
{
    ui->p1->setValue(0);
    ui->p2->setValue(0);
    ulang();
}

void Dialog::on_btnpengaturan_clicked()
{
    if(ui->btnpengaturan->text() == "Pengaturan"){
        ui->volume->show();
        ui->lblVolume->show();
        ui->btnpengaturan->setText("Simpan");
        ui->btn1->setDisabled(false);
        ui->btn2->setDisabled(false);
        ui->btn3->setDisabled(false);
        ui->btn4->setDisabled(false);
        ui->btn5->setDisabled(false);
        ui->btn6->setDisabled(false);
        ui->btn7->setDisabled(false);
        ui->btn8->setDisabled(false);
        ui->btn9->setDisabled(false);
    }else if(ui->btnpengaturan->text() == "Simpan"){
        musikSimpan();
        ui->volume->hide();
        ui->lblVolume->hide();
        ui->btnpengaturan->setText("Pengaturan");
        musikLoad();
    }
}

void Dialog::musikLoad()
{
    QSettings setting;
    QVariant var = setting.value("setting",0);
    bool oke;
    int nilai = var.toInt(&oke);

    if(!oke){ return; }

    QMediaPlaylist *list    =   new QMediaPlaylist();
    list->addMedia(QUrl::fromLocalFile("/home/gideon/Desktop/Qt/BAB 5/TicTacToc/lagu.wav"));
    list->setPlaybackMode(QMediaPlaylist::Loop);

    QMediaPlayer *play = new QMediaPlayer();
    play->setPlaylist(list);
    play->setVolume(nilai);
    play->play();
}

void Dialog::musikSimpan()
{
    QSettings setting;
    setting.setValue("setting",ui->volume->value());
}
