#include "GlobalData.h"
#include "graphiceditor.h"
#include <QTextCodec>

GlobalData::GlobalData(){
    
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF8"));
    /*
    QTextCodec *codec = QTextCodec::codecForName("System");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);*/
}

void GlobalData::addGe(graphiceditor *ge){
    m_setGe.insert(ge);
}

void GlobalData::rmGe(graphiceditor *ge){
    m_setGe.erase(ge);
}

void GlobalData::clear(unsigned int handle){
    GeSet::iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return ;
    }
    (*it)->clearSplines();
}

/*
void GlobalData::addSpline(const std::string &name, const std::vector<std::pair<float, float> > &knot){
    for(int i=0; i<m_splines.size(); ++i){
        if(name == m_splines[i].name){
            m_splines[i].setKnots(knot);
            return ;
        }
    }

    aaAaa::aaSpline s;
    s.name = name;
    s.setKnots(knot);
    m_splines.push_back(s);
}*/


void GlobalData::addSpline(unsigned int handle, const aaAaa::aaSpline &knot){
    GeSet::iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return ;
    }
    (*it)->addSpline(knot);
}

bool GlobalData::getSplines(unsigned int handle, std::vector<aaAaa::aaSpline> &splines){
    GeSet::const_iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return false;
    }
    splines = (*it)->getSplines();
    return true;
}

int GlobalData::getCurrentSplineIndex(unsigned int handle){
    GeSet::const_iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return -1;
    }
    return (*it)->getCurrentSplineIndex();
}

void GlobalData::setSplines(unsigned int handle, const std::vector<aaAaa::aaSpline> &splines){
    GeSet::const_iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return ;
    }

    (*it)->setSplines(splines);
}

void GlobalData::addKnot(unsigned int handle, int index, const aaAaa::aaPoint &pt){
    GeSet::const_iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return ;
    }
    
    (*it)->addKnot(index, pt);
}

void GlobalData::addKnot(unsigned int handle, int index, float t){
    GeSet::const_iterator it = m_setGe.find((graphiceditor*)handle);
    if(it == m_setGe.end()){
        return ;
    }

    (*it)->addKnot(index, t);
}

/*
void GlobalData::setSplineLimit(const std::string &name, float left, float top, float right, float bottom){
    for(int i=0; i<m_splines.size(); ++i){
        if(name == m_splines[i].name){
            m_splines[i].setLimit(left, top, right, bottom);
            return ;
        }
    }
}
*/