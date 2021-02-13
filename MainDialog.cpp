#include "MainDialog.h"

MainDialog::MainDialog() {

    createButtonGroupBox();
    createGridInteractionGroupBox();

    auto mainLayout = new QVBoxLayout;
    mainLayout->addWidget(interactionGroupBox);
    mainLayout->addWidget(buttonGroupBox);

    setLayout(mainLayout);
}

void MainDialog::createButtonGroupBox() {
    buttonGroupBox = new QGroupBox (tr("Choose action"));
    auto *layout = new QHBoxLayout;

    buttons[0] = new QPushButton(tr("Add Activity in this date"));
    buttons[1] = new QPushButton(tr("Show Activities on a date"));
    for (auto & button : buttons)
        layout->addWidget(button);

    buttonGroupBox->setLayout(layout);
}

void MainDialog::createGridInteractionGroupBox() {
    interactionGroupBox = new QGroupBox (tr("Choose date"));
    auto *layout = new QGridLayout;

    labels[0] = new QLabel(tr("Day"));
    labels[1] = new QLabel(tr("Month"));
    labels[2] = new QLabel(tr("Year"));
    auto validator = new QIntValidator();

    for(int i = 0; i < NumOfLabels ; i++) {
        inputs[i] = new QLineEdit;
        inputs[i]->setValidator(validator);
        layout->addWidget(labels[i], i + 1, 0);
        layout->addWidget(inputs[i], i + 1, 1);
    }
    interactionGroupBox->setLayout(layout);
}

QPushButton *const *MainDialog::getButtons() const {
    return buttons;
}

QLineEdit *const *MainDialog::getInputs() const {
    return inputs;
}

Date MainDialog::getDateInserted() const {
    int day = inputs[0]->text().toInt();
    int month = inputs[1]->text().toInt();
    int year = inputs[2]->text().toInt();
    return {day, month, year};
}
