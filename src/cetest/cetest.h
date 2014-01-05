#ifndef CETEST_H
#define CETEST_H

#include <QtWidgets/QMainWindow>
#include "ui_cetest.h"

#include <vector>
#include <string>


class graphiceditor;

class cetest : public QMainWindow
{
    Q_OBJECT

public:
    cetest(QWidget *parent = 0, Qt::WindowFlags flags = 0);
    ~cetest();

private:
    Ui::cetestClass ui;

    graphiceditor *ge;


protected slots:
    void onShowGeClicked(void); 
};

#endif // CETEST_H
