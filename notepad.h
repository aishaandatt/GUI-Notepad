#ifndef NOTEPAD_H //this makes sure header files are not loaded more than once
#define NOTEPAD_H

#include <QMainWindow> //this provides the main application window where UI is built.

#include <QFile> //working with files
#include <QFileDialog> //popup dialog to allow the user to select a file
#include <QTextStream> //reading text from files
#include <QMessageBox> //to show a message for e.g: user error
#include <QPrintDialog> //print settings dialog
#include <QPrinter> //to print


QT_BEGIN_NAMESPACE
namespace Ui {
class Notepad;
}
QT_END_NAMESPACE

class Notepad : public QMainWindow
{
    Q_OBJECT

public:
    Notepad(QWidget *parent = nullptr);
    ~Notepad(); //destructor

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

private:
    Ui::Notepad *ui;
    QString currentFile="";
};
#endif // NOTEPAD_H
