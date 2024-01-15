#ifndef DSA_PROJ1_MANAGER_H
#define DSA_PROJ1_MANAGER_H

#include "Column.h"


class Manager{
private:
    std::vector<Column> list_columns;
    std::vector<Athlete> list_athletes;

    int ATH_UID;
    int COL_UID;


public:
    Manager();
    //学号到UID映射
    std::unordered_map<std::string, int> athlete_map;
    //项目名到UID映射
    std::unordered_map<std::string, int> column_map;
    //-------------------------------------------------
    //录入新的项目
    void build_column(std::string column_name, Type_grade type_grade, Type_score type_score, bool is_male);
    //录入新运动员
    void build_athlete(std::string name, std::string id, bool is_male,
                       Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade);
    //-------------------------------------------------
    //外部接口
    //项目报名接口
    void signup_athlete(std::string ath_id, std::string column_name);
    //项目退赛接口
    void signup_athlete_remove(std::string ath_id, std::string column_name);
    //成绩录入
    void signup_score(std::string ath_id, std::string column_name, double score);
    //查询(按照项目名称)
    void check_column(std::string column_name);

    void check_college(Type_college typeCollege);

    void check_athlete(std::string ath_id);

    void check_totalscore();

    void generate();
    //-------------------------------------------------
    //内部接口
    void add_athlete(Athlete athlete);

    void add_column(Column column);

    std::vector<Column> getColumnList();

    std::vector<Athlete> getAthleteList();
    //-------------------------------------------------
    //UID系统，实现运动员和项目的绑定
    int get_ATH_UID();

    int get_COL_UID();

    Athlete * find_athlete_byUID(int uid);

    Column * find_column_byUID(int uid);

    void save(Manager manager);

    void addupScore(int uid);
};
#endif //DSA_PROJ1_MANAGER_H
