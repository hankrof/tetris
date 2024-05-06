#include "model/score/default_score.h"
DefaultScore::DefaultScore()
    : _points(0)
{

}

int DefaultScore::point() const
{
    return _points;
}

void DefaultScore::accumulate(int lines)
{
    switch (lines)
    {
    case 1:
        _points += 50;
        break;
    case 2:
        _points += 200;
        break;
    case 3:
        _points += 300;
        break;
    case 4:
        _points += 500;
        break;
    default:
        break;
    };
}

void DefaultScore::reset()
{
    _points = 0;
}

