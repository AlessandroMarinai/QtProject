#ifndef QTHELLOWORLD_ADDNEWACTIVITYDIALOG_H
#define QTHELLOWORLD_ADDNEWACTIVITYDIALOG_H

#include <QDialog>
#include <QApplication>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QValidator>
#include <QPushButton>
#include "Activity.h"

class AddNewActivityDialog : public QDialog{
    Q_OBJECT

public:
    QLineEdit *const *getInputs() const;
    QPushButton *getButton() const;
    AddNewActivityDialog();
    Time getStartTime();
    Time getEndTime();
    QString getDescription();
    void clearSlots();

public slots:
    void onClickedAddActivity();

private:
    void createInputGroupBox();
    void createInputDescription();

    enum {NumOfLabels = 7, NumOfInputs = 4};

    QGroupBox *interactionBox, *descriptionBox;
    QPushButton *button;
    QLabel *labels[NumOfLabels];
    QLineEdit *inputs[NumOfInputs];
    QTextEdit *description;
};


#endif //QTHELLOWORLD_ADDNEWACTIVITYDIALOG_H
