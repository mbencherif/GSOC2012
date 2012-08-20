#ifndef GRABBABLEBALL_H
#define GRABBABLEBALL_H

#include <string>
#include "grabbableobject.h"

class GrabbableBall: public GrabbableObject
{
public:
    GrabbableBall();

    void setColor(const cv::Scalar &color) {_color = color;}
    void setIniRadius(double R) {_r=_iniR = R;}
    void setIniPosition(const cv::Point &iniPosition) {_pos = iniPosition; }
    void setAlpha(double alpha) {_alpha = alpha;}
    void setGrabbWaitThr(int thr) { _waitThr = thr;}
    void setString(const std::string &text) {_text = text;_ts = cv::getTextSize(_text,cv::FONT_HERSHEY_SIMPLEX,1.5,2,0);}

    void reset();
    void draw(cv::Mat &image); //draw object on the image
    void setCursorPosition(const cv::Point3i &position, bool state); //changes state

private:

    cv::Scalar _color;
    cv::Point _pos;

    double _R0;
    double _alpha;
    double _r;

    double _iniR;
    int _grabbWait;
    int _waitThr;
    int _freeWait;

    std::string  _text;
    cv::Size _ts;

};

#endif // GRABBABLEBALL_H
