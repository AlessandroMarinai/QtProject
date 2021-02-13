#include <QApplication>
#include <QMainWindow>
#include <QPlainTextEdit>
#include "Register.h"
#include "SavedOrNotDialog.h"
#include "EventsDisplayerDialog.h"

int main( int argc, char **argv ) {
    QApplication app( argc, argv );

    AddNewActivityDialog firstDialog;
    MainDialog mainWindow;
    mainWindow.setWindowTitle(QApplication::translate("","Events"));
    mainWindow.show();
    SavedOrNotDialog savedDialog;
    Register aRegister(&mainWindow, &firstDialog, &savedDialog);
    EventsDisplayerDialog secondDialog(&mainWindow, &aRegister);


    QObject::connect(mainWindow.getButtons()[0], SIGNAL(clicked() ), &firstDialog, SLOT(onClickedAddActivity()), Qt::AutoConnection);

    QObject::connect(firstDialog.getButton(),SIGNAL(clicked() ), &aRegister,SLOT(addActivityOnADate()));

    QObject::connect(mainWindow.getButtons()[1], SIGNAL(clicked() ), &secondDialog, SLOT(showEventsOnData()));

    return app.exec();
}