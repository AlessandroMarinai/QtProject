#ifndef QTHELLOWORLD_EVENTSDISPLAYERDIALOG_H
#define QTHELLOWORLD_EVENTSDISPLAYERDIALOG_H

#include "Register.h"
#include <QString>

class EventsDisplayerDialog : public QDialog {
Q_OBJECT

public:
    EventsDisplayerDialog(MainDialog* dialog, Register *r): mainLayout(new QVBoxLayout) ,aRegister(r), mainDialog(dialog){};

    void addNewActivityToShow(const Activity& a, int num);

public slots:
    void showEventsOnData();

private:
    QVBoxLayout *mainLayout;
    Register *aRegister;
    MainDialog *mainDialog;
    void resetLayout(QLayout* apLayout) //this function in used to delete all widgets added
    {
        QLayoutItem *vpItem;
        while ((vpItem = apLayout->takeAt(0)) != 0)  {
            if (vpItem->layout()) {
                resetLayout(vpItem->layout());
                vpItem->layout()->deleteLater();
            }
            if (vpItem->widget()) {
                vpItem->widget()->deleteLater();
            }
            delete vpItem;
        }
    }
};





#endif //QTHELLOWORLD_EVENTSDISPLAYERDIALOG_H
