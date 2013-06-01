#ifndef __GLOBALDATA_H__
#define __GLOBALDATA_H__

#include "../libspline/aaCurve.h"
#include <set>


class graphiceditor;

class GlobalData{
private:
    GlobalData();
    GlobalData(const GlobalData &gd);

public:
    typedef std::set<graphiceditor*> GeSet;
    GeSet m_setGe;

public:
    ~GlobalData(){}

    static GlobalData &instance(void){
        static GlobalData gd;
        return gd;
    }

    void addGe(graphiceditor *ge);
    void rmGe(graphiceditor *ge);

    void clear(unsigned int handle);

   // void addSpline(unsigned int handle, const std::string &name, const std::vector<std::pair<float, float> > &knot);
    void addSpline(unsigned int handle, const aaAaa::aaSpline &knot);
//    void setSplineLimit(const std::string &name, float left, float top, float right, float bottom);
    bool getSplines(unsigned int handle, std::vector<aaAaa::aaSpline> &splines);
    void setSplines(unsigned int handle, const std::vector<aaAaa::aaSpline> &splines);

    int getCurrentSplineIndex(unsigned int handle);

    void addKnot(unsigned int handle, int index, const aaAaa::aaPoint &pt);
    void addKnot(unsigned int handle, int index, float t);

};

#endif // __GLOBALDATA_H__

