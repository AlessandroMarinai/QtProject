#include "AddNewActivityDialog.h"

AddNewActivityDialog::AddNewActivityDialog() {
    createInputGroupBox();
    createInputDescription();

    auto mainLayout = new QVBoxLayout;
    button = new QPushButton(tr("Add Event"));


    mainLayout->addWidget(interactionBox);
    mainLayout->addWidget(descriptionBox);
    mainLayout->addWidget(button);

    setLayout(mainLayout);
}

void AddNewActivityDialog::createInputGroupBox() {
        interactionBox = new QGroupBox (tr("Add the details here"));
        auto *layout = new QGridLayout;

        labels[0] = new QLabel(tr("Starting time"));
        labels[1] = new QLabel(tr("Ending time"));
        layout->addWidget(labels[0], 1, 1);
        layout->addWidget(labels[1], 1, 3);

        labels[2] = new QLabel(tr("Hours"));
        labels[3] = new QLabel(tr("Minutes"));
        labels[4] = new QLabel(tr("Hours"));
        labels[5] = new QLabel(tr("Minutes"));

        auto validator = new QIntValidator();
        for (int j=0; j<=2 ; j=j+2){
            for (int i = 0; i < 2; i++) {
                inputs[i+j] = new QLineEdit;
                inputs[i+j]->setValidator(validator);
                layout->addWidget(labels[i+j+2], i + 2, 1+j);
                layout->addWidget(inputs[i+j], i + 2, 2+j);
            }
        }
        interactionBox->setLayout(layout);
}

void AddNewActivityDialog::onClickedAddActivity() {
    this->setModal(true);
    this->show();
}

void AddNewActivityDialog::createInputDescription() {
    descriptionBox = new QGroupBox;
    auto layout = new QVBoxLayout;
    auto label = new QLabel(tr("Add the description of the activity below"));
    description = new QTextEdit();
    layout->addWidget(label);
    layout->addWidget(description);
    descriptionBox->setLayout(layout);
}

QPushButton *AddNewActivityDialog::getButton() const {
    return button;
}

QLineEdit *const *AddNewActivityDialog::getInputs() const {
    return inputs;
}

Time AddNewActivityDialog::getStartTime() {
    int hour = inputs[0]->text().toInt();
    int minutes = inputs[1]->text().toInt();
    return {hour, minutes};
}

Time AddNewActivityDialog::getEndTime() {
    int hour = inputs[2]->text().toInt();
    int minutes = inputs[3]->text().toInt();
    return {hour, minutes};
}

QString AddNewActivityDialog::getDescription() {
    auto cursor = description->textCursor();
    description->setTextCursor(cursor);
    description->selectAll();
    return description->textCursor().selectedText(); //for this widget we need textCursor method
}

void AddNewActivityDialog::clearSlots() {
    for (auto & input : inputs)
        input->clear();
    description->clear();
}
