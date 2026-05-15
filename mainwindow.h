#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void noviDokument();
    void otvoriDatoteku();
    void spremiDatoteku();
    void promijeniFont();
    void promijeniBoju();
    void promijeniBojuPozadine();
    void pronadjiTekst();
    void promijeniTemu(bool dark);
    void resetujZoom();



private:
    Ui::MainWindow *ui;
};
#endif