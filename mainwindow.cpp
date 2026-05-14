#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QFontDialog>
#include <QColorDialog>
#include <QInputDialog>
#include <QLineEdit>
#include <QTextCharFormat>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->textEdit->setUndoRedoEnabled(true);




    connect(ui->actionNew, &QAction::triggered, this, &MainWindow::noviDokument);
    connect(ui->actionOpen, &QAction::triggered, this, &MainWindow::otvoriDatoteku);
    connect(ui->actionSave, &QAction::triggered, this, &MainWindow::spremiDatoteku);
    connect(ui->actionExit, &QAction::triggered, this, &QWidget::close);


    connect(ui->actionFont, &QAction::triggered, this, &MainWindow::promijeniFont);
    connect(ui->actionColor, &QAction::triggered, this, &MainWindow::promijeniBoju);
    connect(ui->actionBackground_color, &QAction::triggered, this, &MainWindow::promijeniBojuPozadine);


    connect(ui->actionFind, &QAction::triggered, this, &MainWindow::pronadjiTekst);


    connect(ui->actionDark_Mode, &QAction::toggled, this, &MainWindow::promijeniTemu);


    connect(ui->actionZoomIn, &QAction::triggered, [=](){
        ui->textEdit->zoomIn();
    });
    connect(ui->actionZoomOut, &QAction::triggered, [=](){
        ui->textEdit->zoomOut();
    });


    connect(ui->actionZoomReset, &QAction::triggered, this, &MainWindow::resetujZoom);


    connect(ui->actionUndo, &QAction::triggered, this, [=](){
        if(ui->textEdit->document()->isUndoAvailable()) ui->textEdit->undo();
    });
    connect(ui->actionRedo, &QAction::triggered, this, [=](){
        if(ui->textEdit->document()->isRedoAvailable()) ui->textEdit->redo();
    });


    connect(ui->textEdit, &QTextEdit::textChanged, [=](){
        int count = ui->textEdit->toPlainText().length();
        ui->statusbar->showMessage("Characters: " + QString::number(count));
    });

    setWindowTitle("Moj Notepad");
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::noviDokument() {
    ui->textEdit->clear();
    setWindowTitle("New Document - Notepad");
}

void MainWindow::otvoriDatoteku() {
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "HTML Files (*.html);;Text Files (*.txt);;All Files (*.*)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) return;

    QTextStream in(&file);
    QString sadrzaj = in.readAll();
    file.close();


    if (fileName.endsWith(".html")) {
        ui->textEdit->setHtml(sadrzaj);
    } else {
        ui->textEdit->setPlainText(sadrzaj);
    }

    ui->textEdit->document()->setModified(false);
    setWindowTitle(fileName + " - Notepad");
}

void MainWindow::spremiDatoteku() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "HTML Files (*.html);;Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) return;

    QTextStream out(&file);


    out << ui->textEdit->toHtml();

    file.close();
    setWindowTitle(fileName + " - Notepad");
}

void MainWindow::promijeniFont() {
    bool ok;
    QFont font = QFontDialog::getFont(&ok, ui->textEdit->font(), this);
    if (ok) ui->textEdit->setFont(font);
}

void MainWindow::promijeniBoju() {
    QColor boja = QColorDialog::getColor(Qt::black, this, "Izaberi boju teksta");
    if (boja.isValid()) {
        ui->textEdit->setTextColor(boja);
    }
}

void MainWindow::promijeniBojuPozadine() {
    QColor boja = QColorDialog::getColor(Qt::white, this, "Izaberi boju pozadine");
    if (boja.isValid()) {
        QPalette p = ui->textEdit->palette();
        p.setColor(QPalette::Base, boja);
        ui->textEdit->setPalette(p);
    }
}

void MainWindow::pronadjiTekst() {
    bool ok;
    QString text = QInputDialog::getText(this, "Find All", "Search for (highlight all):", QLineEdit::Normal, "", &ok);

    if (ok && !text.isEmpty()) {
        QList<QTextEdit::ExtraSelection> extraSelections;
        QTextCharFormat format;
        format.setBackground(Qt::yellow);
        format.setForeground(Qt::black);

        QTextDocument *doc = ui->textEdit->document();
        QTextCursor cursor(doc);

        while (!cursor.isNull() && !cursor.atEnd()) {
            cursor = doc->find(text, cursor);
            if (!cursor.isNull()) {
                QTextEdit::ExtraSelection selection;
                selection.format = format;
                selection.cursor = cursor;
                extraSelections.append(selection);
            }
        }
        ui->textEdit->setExtraSelections(extraSelections);
    }
}

void MainWindow::promijeniTemu(bool dark) {
    if (dark) {
        this->setStyleSheet(
            "QMainWindow { background-color: #2b2b2b; }"
            "QTextEdit { background-color: #1e1e1e; color: #dcdcdc; border: none; font-size: 14px; }"
            "QMenuBar { background-color: #2b2b2b; color: white; }"
            "QMenuBar::item:selected { background-color: #3d3d3d; }"
            "QStatusBar { background-color: #2b2b2b; color: gray; }"
            );
    } else {
        this->setStyleSheet("");
    }
}

void MainWindow::resetujZoom() {
    QFont font = ui->textEdit->font();
    font.setPointSize(12); // Vraća na standardnu veličinu
    ui->textEdit->setFont(font);

    // Resetira i kursor (za novi tekst)
    QTextCharFormat format;
    format.setFont(font);
    ui->textEdit->setCurrentCharFormat(format);

    ui->statusbar->showMessage("Zoom resetiran na 12", 2000);
}