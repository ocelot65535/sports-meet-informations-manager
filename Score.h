#ifndef DSA_PROJ1_SCORE_H
#define DSA_PROJ1_SCORE_H
#include "Base.h"
class ScoreManager{
private:
    Type_score type;
    std::string column_name;
    double score;
public:
    ScoreManager(Type_score typeScore, std::string column_name,double score);
    //-------------------------------------------------
    Type_score getType();

    std::string getColumnName();

    double getScore();
};
#endif //DSA_PROJ1_SCORE_H
