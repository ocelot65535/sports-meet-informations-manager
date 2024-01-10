#include "Athlete.h"

Athlete::Athlete(int UID, std::string name, std::string id, bool is_male,
        Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade){
    this->UID = UID;
    this->name = name;
    this->id = id;
    this->is_male = is_male;
    this->college = typeCollege;
    this->department = typeDepartment;
    this->grade = typeGrade;
    this->participate_count = 0;
}
//-------------------------------------------------
int Athlete::getUID(){
    return UID;
}
//-------------------------------------------------
void Athlete::addScore(Type_score typeScore, std::string column_name, double score){
    ScoreManager newscore(typeScore, column_name, score);
    this->score_list.push_back(newscore);
}

std::vector<ScoreManager> Athlete::getScoreList(){
    return score_list;
}

//-------------------------------------------------
std::string Athlete::getName(){
    return name;
}

std::string Athlete::getId(){
    return id;
}

bool Athlete::isMale(){
    return is_male;
}

Type_college Athlete::getCollege(){
    return college;
}

Type_department Athlete::getDepartment(){
    return department;
}

Type_grade Athlete::getGrade(){
    return grade;
}

int Athlete::getParticipateCount(){
    return participate_count;
}
//-------------------------------------------------

void Athlete::setParticipateCount(int participateCount) {
    participate_count = participateCount;
}
