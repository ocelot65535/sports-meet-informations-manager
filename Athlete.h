#ifndef DSA_PROJ1_ATHLETE_H
#define DSA_PROJ1_ATHLETE_H
#include "Score.h"
class Athlete {
private:
    int UID;

    std::string name;
    std::string id;
    bool is_male;

    Type_college college;
    Type_department department;
    Type_grade grade;

    int participate_count;

    std::vector<ScoreManager> score_list;
public:
    Athlete(int UID, std::string name, std::string id, bool is_male,
            Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade);
    //-------------------------------------------------
    int getUID();

    //-------------------------------------------------
    void addScore(Type_score typeScore, std::string column_name, double score);

    std::vector<ScoreManager> getScoreList();

    //-------------------------------------------------
    std::string getName();

    std::string getId();

    bool isMale();

    Type_college getCollege();

    Type_department getDepartment();

    Type_grade getGrade();

    int getParticipateCount();
    //-------------------------------------------------

    void setParticipateCount(int participateCount);
};
#endif //DSA_PROJ1_ATHLETE_H
