#include "Manager.h"

Manager::Manager() {
    list_columns = std::vector<Column>();
    list_athletes = std::vector<Athlete>();
    ATH_UID = 0;
    COL_UID = 0;
}
//-------------------------------------------------
//测试正常
void Manager::build_column(std::string column_name, Type_grade type_grade, Type_score type_score, bool is_male){
    Column newcolumn(get_COL_UID(), column_name, type_grade, type_score, is_male);
    add_column(newcolumn);
    column_map[newcolumn.getName()] = newcolumn.getUID();
}

void Manager::build_athlete(std::string name, std::string id, bool is_male,
                   Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade){
    Athlete newathlete(get_ATH_UID(), name, id, is_male, typeCollege, typeDepartment, typeGrade);
    add_athlete(newathlete);
    athlete_map[newathlete.getId()] = newathlete.getUID();
}
//-------------------------------------------------
void Manager::signup_athlete(std::string ath_id, std::string column_name) {
    Athlete * athlete = find_athlete_byUID(athlete_map[ath_id]);
    Column * column = find_column_byUID(column_map[column_name]);
    if (athlete->getParticipateCount() >= 3)
        return;
    if (athlete != NULL){
        if (column != NULL){
            //注意这里用指针把对象的复制添加到了项目中
            column->addAthlete(*athlete);
            athlete->setParticipateCount(athlete->getParticipateCount() + 1);
        }else{
            std::cout << "signup_athlete failed to exec" << std::endl;
        }
    }
}
void Manager::signup_athlete_remove(std::string ath_id, std::string column_name){
    Athlete * athlete = find_athlete_byUID(athlete_map[ath_id]);
    Column * column = find_column_byUID(column_map[column_name]);
    if (athlete != NULL){
        if (column != NULL){
            column->removeAthlete(*athlete);
            athlete->setParticipateCount(athlete->getParticipateCount() - 1);
        }else{
            std::cout << "signup_athlete_remove failed to exec" << std::endl;
        }
    }

}
//-------------------------------------------------

void Manager::signup_score(std::string ath_id, std::string column_name, double score){
    Athlete * ath = find_athlete_byUID(athlete_map[ath_id]);
    Column * column = find_column_byUID(column_map[column_name]);
    if (ath == NULL){
        std::cout << "signup_score运动员不存在" << std::endl;
        return;
    }
    if (column == NULL){
        std::cout << "signup_score项目不存在" << std::endl;
        return;
    }
    ath->addScore(column->getScoreType(), column->getName(), score);
    column->addScore(ath->getUID(), score);
}

//-------------------------------------------------
//测试正常
void Manager::check_column(std::string column_name){
    Column * column = find_column_byUID(column_map[column_name]);
    if (column != NULL){
        column->show();
    }else{
        std::cout << "check_column项目不存在" << std::endl;
    }

}


//-------------------------------------------------
void Manager::add_athlete(Athlete athlete) {
    list_athletes.push_back(athlete);
}

void Manager::add_column(Column column) {
    list_columns.push_back(column);
}

Athlete Manager::search_athlete_byid(std::string id) {
    for(int i=0; i < list_athletes.size(); i++){
        Athlete athlete = list_athletes[i];
        if(athlete.getId() == id){
            return athlete;
        }
    }
    return Athlete(0,"","",false,Type_college::none_college,Type_department::none_department,Type_grade::none_grade);
}
//-------------------------------------------------

int Manager::get_ATH_UID(){
    ATH_UID++;
    return ATH_UID;
}

int Manager::get_COL_UID(){
    COL_UID++;
    return COL_UID;
}

Athlete * Manager::find_athlete_byUID(int uid){
    for (int i=0;i < list_athletes.size(); i++){
        Athlete * athlete = &list_athletes[i];
        if (athlete->getUID() == uid){
            return athlete;
        }
    }
    return NULL;
}

Column * Manager::find_column_byUID(int uid){
    for (int i=0;i < list_columns.size(); i++){
        Column * column = &list_columns[i];
        if (column->getUID() == uid){
            return column;
        }
    }
    return NULL;
}
