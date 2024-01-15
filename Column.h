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

    Type_space location;
public:
    Column(int UID, std::string columnName, Type_grade typeGrade, Type_score typeScore, bool isMale);
    //-------------------------------------------------
    void addAthlete(Athlete athlete);

    void removeAthlete(Athlete athlete);

    //-------------------------------------------------

    void show();

    int getUID();

    std::string getName();

    bool isMale();

    Type_score getScoreType();

    Type_grade getGrade();

    std::vector<int> getATHList();

    Type_space getLocation();

    void setLocation(Type_space location);
    //成绩管理
    void addScore(int ath_uid, double score);

    std::unordered_map<int, double> getScoreMap();

    std::vector<std::pair<int, double>> sort_bigger();
    std::vector<std::pair<int, double>> sort_smaller();
};
#endif //DSA_PROJ1_COLUMN_H
