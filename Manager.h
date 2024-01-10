#ifndef DSA_PROJ1_MANAGER_H
#define DSA_PROJ1_MANAGER_H

#include "Column.h"


class Manager{
private:
    std::vector<Column> list_columns;
    std::vector<Athlete> list_athletes;

    int ATH_UID;
    int COL_UID;

    //学号到UID映射
    std::unordered_map<std::string, int> athlete_map;
    //项目名到UID映射
    std::unordered_map<std::string, int> column_map;
public:
    Manager();
    //-------------------------------------------------
    //创建新的项目和运动员
    void build_column(std::string column_name, Type_grade type_grade, Type_score type_score, bool is_male);

    void build_athlete(std::string name, std::string id, bool is_male,
                       Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade);

    //-------------------------------------------------
    //项目报名
    void signup_athlete(std::string ath_id, std::string column_name);

    void signup_athlete_remove(std::string ath_id, std::string column_name);
    //-------------------------------------------------
    //成绩录入
    void signup_score(std::string ath_id, std::string column_name, double score);
    //-------------------------------------------------
    //查询
    void check_column(std::string column_name);


    //-------------------------------------------------
    void add_athlete(Athlete athlete);

    void add_column(Column column);

    Athlete search_athlete_byid(std::string id);
    //-------------------------------------------------
    //UID系统，实现运动员和项目的绑定
    int get_ATH_UID();

    int get_COL_UID();

    Athlete * find_athlete_byUID(int uid);

    Column * find_column_byUID(int uid);

};
#endif //DSA_PROJ1_MANAGER_H
