#include "SavedOrNotDialog.h"

SavedOrNotDialog::SavedOrNotDialog() {
    messageToBeShown = 0;
    auto layout = new QVBoxLayout;
    text = new QLabel;

    layout->addWidget(text);
    setLayout(layout);
}

void SavedOrNotDialog::showMessage(){
    if (messageToBeShown == 0)
            text->setText(tr("The activity was saved correctly"));
    if (messageToBeShown == 1)
            text->setText(tr("The activity was not saved because the register is full"));
    if (messageToBeShown == 2)
            text->setText(tr("The date inserted is not an existing date, please make sure to insert an existing date"));
    if (messageToBeShown == 3)
            text->setText(tr("One of the times inserted is not a actual time, please make sure to insert an existing time"));
    //saved = 0, memoryError = 1, wrongDate = 2, wrongTime = 3
    //this->setModal(true);
    this->show();
}

void SavedOrNotDialog::setMessageToBeShown(int message) {
    messageToBeShown = message;
}


