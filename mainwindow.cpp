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
#include <QTextFrame>
#include <QStyle>

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

    connect(ui->actionZoomIn, &QAction::triggered, [=](){ ui->textEdit->zoomIn(); });
    connect(ui->actionZoomOut, &QAction::triggered, [=](){ ui->textEdit->zoomOut(); });
    connect(ui->actionZoomReset, &QAction::triggered, this, &MainWindow::resetujZoom);


    connect(ui->actionUndo, &QAction::triggered, this, [=](){
        if(ui->textEdit->document()->isUndoAvailable()) ui->textEdit->undo();
    });
    connect(ui->actionRedo, &QAction::triggered, this, [=](){
        if(ui->textEdit->document()->isRedoAvailable()) ui->textEdit->redo();
    });


    ui->textEdit->setStyleSheet("background-color: white; color: black; padding: 10px; border-radius: 5px;");
    setWindowTitle("Notepad");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::noviDokument() {
    ui->textEdit->clear();

    QTextFrameFormat format = ui->textEdit->document()->rootFrame()->frameFormat();
    format.setBackground(Qt::white);
    ui->textEdit->document()->rootFrame()->setFrameFormat(format);

    ui->textEdit->setStyleSheet("background-color: white; color: black; padding: 10px;");
    setWindowTitle("Novi dokument - Notepad");
}

void MainWindow::otvoriDatoteku() {
    QString filter = "Sve podržano (*.txt *.html);;Text Files (*.txt);;HTML Files (*.html);;All Files (*.*)";
    QString fileName = QFileDialog::getOpenFileName(this, "Otvori datoteku", "", filter);

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QFile::Text)) return;

    QTextStream in(&file);
    QString sadrzaj = in.readAll();
    file.close();

    if (fileName.endsWith(".html")) {
        ui->textEdit->setHtml(sadrzaj);


        QColor bgColor = ui->textEdit->document()->rootFrame()->frameFormat().background().color();
        if (bgColor.isValid()) {
            ui->textEdit->setStyleSheet(QString("background-color: %1; padding: 10px;").arg(bgColor.name()));
        }
    } else {
        ui->textEdit->setPlainText(sadrzaj);
    }

    setWindowTitle(fileName + " - Notepad");
}

void MainWindow::spremiDatoteku() {
    QString fileName = QFileDialog::getSaveFileName(this, "Spremi kao", "", "HTML Files (*.html);;Text Files (*.txt)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QFile::Text)) return;

    QTextStream out(&file);
    if (fileName.endsWith(".html")) {

        out << ui->textEdit->toHtml();
    } else {
        out << ui->textEdit->toPlainText();
    }
    file.close();
    setWindowTitle(fileName + " - Notepad");
}

void MainWindow::promijeniFont() {
    bool ok;
    QFont currentFont = ui->textEdit->currentCharFormat().font();
    QFont font = QFontDialog::getFont(&ok, currentFont, this);
    if (ok) {
        QTextCharFormat format;
        format.setFont(font);
        ui->textEdit->mergeCurrentCharFormat(format);
    }
}

void MainWindow::promijeniBoju() {
    QColor boja = QColorDialog::getColor(ui->textEdit->textColor(), this, "Boja teksta");
    if (boja.isValid()) {
        QTextCharFormat format;
        format.setForeground(boja);
        ui->textEdit->mergeCurrentCharFormat(format);
    }
}


void MainWindow::promijeniBojuPozadine() {
    QColor boja = QColorDialog::getColor(Qt::white, this, "Boja pozadine");
    if (boja.isValid()) {

        ui->textEdit->setStyleSheet(QString("background-color: %1; padding: 10px; border-radius: 5px;").arg(boja.name()));


        QTextDocument *doc = ui->textEdit->document();
        QTextFrame *root = doc->rootFrame();
        QTextFrameFormat format = root->frameFormat();
        format.setBackground(boja);
        root->setFrameFormat(format);
    }
}

void MainWindow::pronadjiTekst() {
    bool ok;
    QString text = QInputDialog::getText(this, "Traži", "Pojam:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        QList<QTextEdit::ExtraSelection> selections;
        QTextCharFormat format;
        format.setBackground(Qt::yellow);
        QTextCursor cursor(ui->textEdit->document());
        while (!cursor.isNull() && !cursor.atEnd()) {
            cursor = ui->textEdit->document()->find(text, cursor);
            if (!cursor.isNull()) {
                QTextEdit::ExtraSelection s;
                s.format = format;
                s.cursor = cursor;
                selections.append(s);
            }
        }
        ui->textEdit->setExtraSelections(selections);
    }
}

void MainWindow::promijeniTemu(bool dark) {
    if (dark) {
        this->setStyleSheet(
            "QMainWindow { background-color: #121212; }"
            "QMenuBar { background-color: #1a1a1a; color: white; }"
            "QStatusBar { background-color: #1a1a1a; color: #888; }"
            "QToolBar { background-color: #1a1a1a; border: none; }"
            );
        ui->textEdit->setStyleSheet("background-color: #1e1e1e; color: #dcdcdc; padding: 15px; border-radius: 10px;");
    } else {
        this->setStyleSheet("");
        ui->textEdit->setStyleSheet("background-color: white; color: black; padding: 10px; border: 1px solid #ccc;");
    }
}

void MainWindow::resetujZoom() {
    QFont font = ui->textEdit->font();
    font.setPointSize(12);
    ui->textEdit->setFont(font);
}