#include "aaCurve.h"
#include "spline.h"


namespace aaAaa{

    std::string aaSpline::spline_name[aaSpline::SPLINE_COUNT] = {"Cubic Spline"};

 /*   aaCurve::aaCurve(const std::string &name, int knum, double *t, double *knot)
    : m_name(name), m_knum(knum), m_t(0), m_knot(0){
    
        if(m_knum <= 0)
            return ;

        m_t = new double[m_knum];
        m_knot = new double[m_knum];

        for(int i=0; i<m_knum; ++i){
            m_t[i]  = t[i];
            m_knot[i] = knot[i];
        }

    }
*/
    aaCurve::aaCurve(const aaSpline &spline_data)
    : m_name(spline_data.name), m_knum(spline_data.size()), m_t(0), m_knot(0){
        if(m_knum <= 0)
            return ;

        m_t = new double[m_knum];
        m_knot = new double[m_knum];

        for(int i=0; i<m_knum; ++i){
            m_t[i]  = spline_data.knots[i].t;
            m_knot[i] = spline_data.knots[i].y;
        }

    }

    aaCurve::~aaCurve(void){
        if(m_t)
            delete []m_t;
        if(m_knot)
            delete []m_knot;
    }

    bool aaCurve::getValue(double t, double &value){
        if(!m_t)
            return false;

        return true;
    }


    //////////////////////////////////////////////////////////////////////////
        
    aaCubicSpline::aaCubicSpline(const aaSpline &spline_data)
    : aaCurve(spline_data), m_ddp(0){

        if(m_knum > 3)
            m_ddp = spline_cubic_set(m_knum, m_t, m_knot, 2, 0, 2, 0);
    }

    aaCubicSpline::~aaCubicSpline(void){
        if(m_ddp)
            delete []m_ddp;
    }

    bool aaCubicSpline::getValue(double t, double &value){
        if(!m_t)
            return false;

        if(m_knum > 3){
             if(!m_ddp)
                 return false;

            double dp, ddp;
            value = spline_cubic_val(m_knum, m_t, t, m_knot, m_ddp, &dp, &ddp);

            return true;
        }else if(m_knum > 2){
            double dp;
            spline_quadratic_val(m_knum, m_t, m_knot, t, &value, &dp);

            return true;
        }else if(m_knum > 1){
            double dp;
            spline_linear_val(m_knum, m_t, m_knot, t, &value, &dp);

            return true;
        }else{
            return false;
        }
    }


    //////////////////////////////////////////////////////////////////////////
    aaQuadraticSpline::aaQuadraticSpline(const aaSpline &spline_data)
        : aaCurve(spline_data){

    }

    aaQuadraticSpline::~aaQuadraticSpline(void){
        
    }

    bool aaQuadraticSpline::getValue(double t, double &value){
        if(!m_t)
            return false;

        if(m_knum > 2){
            double dp;
            spline_quadratic_val(m_knum, m_t, m_knot, t, &value, &dp);

            return true;
        }else if(m_knum > 1){
            double dp;
            spline_linear_val(m_knum, m_t, m_knot, t, &value, &dp);

            return true;
        }else{
            return false;
        }
    }


    //////////////////////////////////////////////////////////////////////////
    aaLinearSpline::aaLinearSpline(const aaSpline &spline_data)
        : aaCurve(spline_data){

    }

    aaLinearSpline::~aaLinearSpline(void){

    }

    bool aaLinearSpline::getValue(double t, double &value){
        if(!m_t || m_knum < 2)
            return false;

        double rate = (t - m_t[0]) / (m_t[1] - m_t[0]);
        if(rate < 0)
            value = m_knot[0];
        if(rate > 1)
            value = m_knot[1];
        value = (1 - rate) * m_knot[0] + rate * m_knot[1];
        
        return true;
    }

}
