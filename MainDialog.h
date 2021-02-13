#ifndef QTHELLOWORLD_MAINDIALOG_H
#define QTHELLOWORLD_MAINDIALOG_H

#include <QDialog>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QIntValidator>

#include "Date.h"


class MainDialog : public QDialog{
    Q_OBJECT
public:
    MainDialog();
    Date getDateInserted() const;
    QLineEdit *const *getInputs() const;
    QPushButton *const *getButtons() const;

private:
    void createButtonGroupBox();
    void createGridInteractionGroupBox();

    enum { NumOfButtons = 2 , NumOfLabels = 3};

    QGroupBox *buttonGroupBox;
    QGroupBox *interactionGroupBox;
    QPushButton *buttons[NumOfButtons];
    QLabel *labels[NumOfLabels];
    QLineEdit *inputs[NumOfLabels];
};


#endif //QTHELLOWORLD_MAINDIALOG_H
