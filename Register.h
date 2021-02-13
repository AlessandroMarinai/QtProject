#ifndef QTHELLOWORLD_REGISTER_H
#define QTHELLOWORLD_REGISTER_H

#include <QObject>
#include <memory>
#include "Date.h"
#include "Activity.h"
#include "MainDialog.h"
#include "AddNewActivityDialog.h"
#include "SavedOrNotDialog.h"

class Register: public QObject {
    Q_OBJECT
public:
    Register(MainDialog* m, AddNewActivityDialog* s, SavedOrNotDialog* dialog):
    mainDialog(m), secondDialog(s), actualNumberOfActivities(0), savedOrNotDialog(dialog){};

    Activity *const *getActivities() const {
        return activities;
    }

    int getActualNumberOfActivities() const {
        return actualNumberOfActivities;
    }

public slots:
    void addActivityOnADate() {
        Date d = mainDialog->getDateInserted();
        Time start = secondDialog->getStartTime();
        Time end = secondDialog->getEndTime();
        if (!d.isExistingDate()) {
            savedOrNotDialog->setMessageToBeShown(2);
            secondDialog->close();
        }
        else if (!start.isExistingHour() || !end.isExistingHour())
            savedOrNotDialog->setMessageToBeShown(3);
        else if(actualNumberOfActivities<100) {
            activities[actualNumberOfActivities] = new Activity(start , end, secondDialog->getDescription(), d);
            actualNumberOfActivities++;
            savedOrNotDialog->setMessageToBeShown(0);
            secondDialog->clearSlots();
            secondDialog->close();
        } else {
            savedOrNotDialog->setMessageToBeShown(1);
            secondDialog->close();
        }
        savedOrNotDialog->showMessage();
    }//saved = 0, memoryError = 1, wrongDate = 2, wrongTime = 3

private:
    int actualNumberOfActivities;
    Activity* activities[100];
    MainDialog *mainDialog;
    AddNewActivityDialog *secondDialog;
    SavedOrNotDialog *savedOrNotDialog;

};


#endif //QTHELLOWORLD_REGISTER_H
