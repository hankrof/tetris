#ifndef __MODEL_DEFAULT_SCORE_H__
#define __MODEL_DEFAULT_SCORE_H__
#include "model/score/score.h"
class DefaultScore : public Score
{
public:
    DefaultScore();
    int point() const override;
    void accumulate(int lines) override;
    void reset() override;
private:
    int _points;
};
#endif
