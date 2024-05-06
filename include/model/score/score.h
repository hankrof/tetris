#ifndef __MODEL_SCORE_H__
#define __MODEL_SCORE_H__
class Score
{
public:
    virtual ~Score() {}
    virtual int point() const = 0;
    virtual void accumulate(int lines) = 0;
    virtual void reset() = 0;
};
#endif

