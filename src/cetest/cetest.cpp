#include "cetest.h"
#include "../curveeditor/graphiceditor.h"
#include "../libspline/aaCurve.h"
#include <QLibrary>
#include <QMessageBox>

cetest::cetest(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags), ge(0)
{
    ui.setupUi(this);

    connect(ui.pushButton_showGe, SIGNAL(clicked()), this, SLOT(onShowGeClicked()));
}

cetest::~cetest()
{
    if(ge)
        delete ge;
}

void cetest::onShowGeClicked(void)
{
    if(!ge)
    {
        std::vector<aaAaa::aaSpline> splines;

        aaAaa::aaSpline spline;
        spline.addKnots(aaAaa::aaPoint(0, 0));
        spline.addKnots(aaAaa::aaPoint(128, 150));
        spline.addKnots(aaAaa::aaPoint(255, 255));

        spline.name = "R";
        splines.push_back(spline);
        
        spline.name = "G";
        spline.setLimit(0, 255, 255, 0);
        splines.push_back(spline);

        ge = new graphiceditor();
        ge->setSplines(splines);
    }
    ge->show();
}