#ifndef EASYHANDTRACKER_H
#define EASYHANDTRACKER_H

#include "handtracker.h"
#include "handsegmentation.h"

#include "rect3d.hpp"

class EasyHandTracker: public HandTracker
{

public:
    EasyHandTracker();
    ~EasyHandTracker();

    void init();
    void init(cv::Mat &mask);
    bool track(cv::Mat &mask, const cv::Mat &depth, const cv::Mat &rgb);

    void setDistanceThreashold(int delta)
    {
        _delta = delta;
    }

private:
    cv::Rect3D _position;
    HandSegmentation *_segmentator;

    int _delta;
    bool _isLost;
};

#endif // EASYHANDTRACKER_H
