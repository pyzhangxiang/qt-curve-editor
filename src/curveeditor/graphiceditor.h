#ifndef GRAPHICEDITOR_H
#define GRAPHICEDITOR_H

#include <QDialog>
#include "ui_graphiceditor.h"

#include "../libspline/aaCurve.h"
#include <vector>

class SplineDisplayerWidget;

typedef std::vector<aaAaa::aaSpline> SplineVec;

class graphiceditor : public QDialog
{
    Q_OBJECT

public:
    graphiceditor(QWidget *parent = 0);
    ~graphiceditor();

    void clearSplines();
    void addSpline(const aaAaa::aaSpline &knot);
    void setSplines(const std::vector<aaAaa::aaSpline> &splines);
    void addKnot(int index, const aaAaa::aaPoint &pt);
    void addKnot(int index, float t);

    int getCurrentSplineIndex();

    const std::vector<aaAaa::aaSpline> &getSplines(void) const{
        return m_splines;
    }

private:
    Ui::graphiceditorClass ui;

    SplineDisplayerWidget *m_viewer;

    int m_curve_type;
    SplineVec m_splines;

private:
    void setupSplines();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void onCurveSelectChanged(int index);
    void onCurveTypeChanged(int index);
    void onSelectPosChanged(float t, float v);
};

#endif // GRAPHICEDITOR_H
