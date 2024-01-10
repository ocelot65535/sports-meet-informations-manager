#ifndef DSA_PROJ1_COLUMN_H
#define DSA_PROJ1_COLUMN_H
#include "Athlete.h"
class Column{
private:
    int UID;

    std::vector<int> list;
    std::string name;
    bool ismale;
    Type_grade grade;
    Type_score type;
    //UID到分数映射
    std::unordered_map<int, double> score_map;
public:
    Column(int UID, std::string columnName, Type_grade typeGrade, Type_score typeScore, bool isMale);
    //-------------------------------------------------
    void addAthlete(Athlete athlete);

    void removeAthlete(Athlete athlete);

    //-------------------------------------------------

    void show();

    int getUID();

    std::string getName();

    Type_score getScoreType();

    Type_grade getGrade();

    std::vector<int> getATHList();
    //成绩管理
    void addScore(int ath_uid, double score);
};
#endif //DSA_PROJ1_COLUMN_H
