#include "notepad.h"
#include "ui_notepad.h"



Notepad::Notepad(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Notepad)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}

Notepad::~Notepad()
{
    delete ui;
}


void Notepad::on_actionNew_triggered()
{
    currentFile.clear();
    ui->textEdit->setText(QString()); //to clear the text widget

}

void Notepad::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file"); //opens the dialog box which allows the user to open a file

    QFile file(fileName);

    currentFile = fileName; //to store the file name as current file name

    if(!file.open(QIODevice::ReadOnly | QFile::Text)){
        QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
        return;
    }

    setWindowTitle(fileName);

    //interface for reading text
    QTextStream in(&file);

    QString text = in.readAll();
    // to put the text in our textedit widget

    ui->textEdit->setText(text);

    file.close();
}

void Notepad::on_actionSave_As_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save As");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this,"Warning","Cannot Save File : " + file.errorString());
        return;
    }
    currentFile = fileName;
    //interface for writing text
    setWindowTitle(fileName);
     QTextStream out(&file);
     QString text = ui->textEdit->toPlainText();
     out<<text;
     file.close();
}


void Notepad::on_actionPrint_triggered()
{
    QPrinter printer;
    printer.setPrinterName("Printer Name");
    QPrintDialog pDialog(&printer,this);
    if(pDialog.exec() == QDialog::Rejected)
    {
        QMessageBox::warning(this,"Warning","Cannot Access Printer");
        return;
    }
    ui->textEdit->print(&printer);
}


void Notepad::on_actionExit_triggered()
{
    QApplication::quit();
}


void Notepad::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}


void Notepad::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}


void Notepad::on_actionCut_triggered()
{
    ui->textEdit->cut();
}


void Notepad::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void Notepad::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
