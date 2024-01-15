#include "Column.h"

Column::Column(int UID, std::string columnName, Type_grade typeGrade, Type_score typeScore, bool isMale) {
    this->UID = UID;
    this->name = columnName;
    this->grade = typeGrade;
    this->type = typeScore;
    this->ismale = isMale;
}
//-------------------------------------------------
void Column::addAthlete(Athlete athlete){
    if (athlete.isMale() == this->ismale){
        list.push_back(athlete.getUID());
        score_map[athlete.getUID()] = 0;
    }else{
        std::cout << "性别不符合" << std::endl;
    }
}

void Column::removeAthlete(Athlete athlete) {
    for (int i = 0; i < list.size(); i++){
        if (list[i] == athlete.getUID()){
            list.erase(list.begin() + i);
            //将运动员在这个项目中删除时，同样把成绩也删除掉
            score_map.erase(athlete.getUID());
            return;
        }else{
            std::cout << "运动员不存在" << std::endl;
        }
    }
}

//-------------------------------------------------
void Column::show() {
    std::cout << "项目名称：" << name << std::endl;
    std::cout << "项目性别：" << (ismale ? "男" : "女") << std::endl;
    std::cout << "项目年级：" << grade << std::endl;
    std::cout << "项目类型：" << type << std::endl;
    std::cout << "参赛人数：" << list.size() << std::endl;
    std::cout << "参赛人员(UID)   成绩：" << std::endl;
    for (int i = 0; i < list.size(); i++){
        std::cout << list[i] << "\t" << score_map[list[i]] << std::endl;
    }
}

int Column::getUID(){
    return UID;
}

std::string Column::getName(){
    return name;
}

bool Column::isMale(){
    return ismale;
}

Type_score Column::getScoreType(){
    return type;
}


Type_grade Column::getGrade(){
    return grade;
}

std::vector<int> Column::getATHList(){
    return list;
}
//-------------------------------------------------

void Column::addScore(int ath_uid, double score) {
    score_map[ath_uid] = score;
}

std::unordered_map<int, double> Column::getScoreMap(){
    return score_map;
}

std::vector<std::pair<int, double>> Column::sort_bigger() {
    std::vector<std::pair<int, double>> pairs(score_map.begin(), score_map.end());
    // 冒泡排序
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs.size() - 1 - i; ++j) {
            if (pairs[j].second < pairs[j + 1].second) {
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
    return pairs;
}

std::vector<std::pair<int, double>> Column::sort_smaller() {
    std::vector<std::pair<int, double>> pairs(score_map.begin(), score_map.end());
    // 冒泡排序
    for (size_t i = 0; i < pairs.size(); ++i) {
        for (size_t j = 0; j < pairs.size() - 1 - i; ++j) {
            if (pairs[j].second > pairs[j + 1].second) {
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
    return pairs;
}


Type_space Column::getLocation(){
    return location;
}

void Column::setLocation(Type_space location){
    this->location = location;
}