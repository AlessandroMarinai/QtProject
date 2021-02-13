#ifndef QTHELLOWORLD_SAVEDORNOTDIALOG_H
#define QTHELLOWORLD_SAVEDORNOTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>

class SavedOrNotDialog : public QDialog {
Q_OBJECT

public:
    SavedOrNotDialog();
    void setMessageToBeShown(int message);

    enum {saved = 0, memoryError = 1, wrongDate = 2, wrongTime = 3};
    void showMessage();

private:
    QLabel *text;
    int messageToBeShown = 0;
};

#endif //QTHELLOWORLD_SAVEDORNOTDIALOG_H
