#include "EventsDisplayerDialog.h"


void EventsDisplayerDialog::showEventsOnData() {
    Date date = mainDialog->getDateInserted();
    auto activities = aRegister->getActivities();
    int numberOfActivities = aRegister->getActualNumberOfActivities();
    int numOfActivitiesShown = 1;
    resetLayout(mainLayout);
    QString title = "Activities for " + QString::number(date.getDay()) + "/" +
            QString::number(date.getMonth()) + "/" + QString::number(date.getYear());
    setWindowTitle(title);
    bool found = false;
    for ( int i=0 ; i<numberOfActivities; i++){
        if (activities[i]->getDate() == date) {
            addNewActivityToShow(*activities[i], numOfActivitiesShown);
            found = true;
            numOfActivitiesShown++;
        }
    }
    if (!found) {
        auto label = new QLabel(tr("No activities in this date, you can add activities from the previous dialog"));
        mainLayout->addWidget(label);
    }
    setLayout(mainLayout);
    this->show();
}

void EventsDisplayerDialog::addNewActivityToShow(const Activity& a, int num) {
    auto box = new QGroupBox;
    auto boxLayout = new QVBoxLayout;
    QString text = "The activity number " + QString::number(num) + " takes place from " + QString::number(a.getStart().getHour()) +
            ":" + QString::number(a.getStart().getMinutes()) + " to " + QString::number(a.getAnEnd().getHour()) + ":" + QString::number(a.getStart().getMinutes());
    auto label1 = new QLabel;
    label1->setText(text);
    QString descriptionText = "Description of the activity: " + a.getDescription();
    auto label2 = new QLabel(descriptionText);
    boxLayout->addWidget(label1);
    boxLayout->addWidget(label2);
    box->setLayout(boxLayout);
    mainLayout->addWidget(box);
}
