#include <QApplication>
#include "view/View.h"
#include "controller/Controller.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    View view;
    Controller controller(&view);
    view.show();

    return app.exec();
}
