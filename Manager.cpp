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

void Manager::check_college(Type_college typeCollege){
    std::cout << "学院：" << typeCollege << std::endl;
    for (int i = 0; i < list_athletes.size(); i++){
        Athlete * athlete = &list_athletes[i];
        if (athlete->getCollege() == typeCollege){
            std::cout << athlete->getName() << std::endl;
        }
    }
}

void Manager::check_athlete(std::string ath_id) {
    Athlete * athlete = find_athlete_byUID(athlete_map[ath_id]);
    if (athlete != NULL){
        std::cout << "姓名：" << athlete->getName() << std::endl;
        std::cout << "学号：" << athlete->getId() << std::endl;
        std::cout << "参赛项目：" << std::endl;
        std::vector<ScoreManager> score_list = athlete->getScoreList();
        for (int i = 0; i < score_list.size(); i++){
            std::cout << score_list[i].getColumnName() << "\t" << score_list[i].getScore() << std::endl;
        }
    }else{
        std::cout << "check_athlete运动员不存在" << std::endl;
    }
}

void Manager::check_totalscore() {
    return;
}
//-------------------------------------------------
void Manager::add_athlete(Athlete athlete) {
    list_athletes.push_back(athlete);
}

void Manager::add_column(Column column) {
    list_columns.push_back(column);
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

//-------------------------------------------------
std::vector<Column> Manager::getColumnList() {
    return list_columns;
}

std::vector<Athlete> Manager::getAthleteList(){
    return list_athletes;
}


void Manager::save(Manager manager){
    std::ofstream file("backup.txt",std::ios::out | std::ios::binary);
    if (file.is_open()) {
        file << "运动员" << std::endl;
        file << list_athletes.size() << std::endl;
        for (int i=0;i<list_athletes.size();i++){
            Athlete * ath = &list_athletes[i];
            file << ath->getName() << std::endl;
            file << ath->getId() << std::endl;
            if (ath->isMale()){
                file << "男" << std::endl;
            }else{
                file << "女" << std::endl;
            }
            file << ath->getCollege() << std::endl;
            file << ath->getDepartment() << std::endl;
            file << ath->getGrade() << std::endl;
            file << ath->getParticipateCount() << std::endl;
            for (int j=0;j<ath->getScoreList().size();j++){
                ScoreManager scoreManager = ath->getScoreList()[j];
                file << scoreManager.getType() << std::endl;
                file << scoreManager.getColumnName() << std::endl;
                file << scoreManager.getScore() << std::endl;
            }
        }

        file << "运动项目" << std::endl;
        file << list_columns.size() << std::endl;
        for (int m=0;m<list_columns.size();m++){
            Column * col = &list_columns[m];
            file << col->getName() << std::endl;
            if (col->isMale()){
                file << "男" << std::endl;
            }else{
                file << "女" << std::endl;
            }
            file << col->getGrade() << std::endl;
            file << col->getScoreType() << std::endl;
            file << col->getATHList().size() << std::endl;
            for (int n=0;n<col->getATHList().size();n++){
                file << col->getATHList()[n] << std::endl;
                file << col->getScoreMap()[col->getATHList()[n]] << std::endl;
            }
        }
        std::cout << "成功写入文件！" << std::endl;
        file.close();
    } else {
        std::cerr << "无法打开文件" << std::endl;
    }
}

void Manager::addupScore(int uid) {
    Column * column = find_column_byUID(uid);
    if (column->getATHList().size()<4){
        std::cout << "没有足够的成员！" << std::endl;
        return;
    }
    if (column->getATHList().size()>6){
        int index = 5;
        std::vector<std::pair<int, double>> pairs;
        pairs = Type_score::time_score == column->getScoreType() ? column->sort_smaller() : column->sort_bigger();
        for (int i=0; i< index; i++) {
            Athlete * ath = find_athlete_byUID(pairs[i].first);
            switch (i+1) {
                case 1:
                    ath->setPoints(ath->getPoints() + 7);
                    break;
                case 2:
                    ath->setPoints(ath->getPoints() + 5);
                    break;
                case 3:
                    ath->setPoints(ath->getPoints() + 3);
                    break;
                case 4:
                    ath->setPoints(ath->getPoints() + 2);
                    break;
                case 5:
                    ath->setPoints(ath->getPoints() + 1);
                    break;
            }
        }
        return;
    }
    if (column->getATHList().size()>4){
        int index = 3;
        std::vector<std::pair<int, double>> pairs;
        pairs = Type_score::time_score == column->getScoreType() ? column->sort_smaller() : column->sort_bigger();
        for (int i=0; i< index; i++) {
            Athlete * ath = find_athlete_byUID(pairs[i].first);
            switch (i+1) {
                case 1:
                    ath->setPoints(ath->getPoints() + 5);
                    break;
                case 2:
                    ath->setPoints(ath->getPoints() + 3);
                    break;
                case 3:
                    ath->setPoints(ath->getPoints() + 2);
                    break;
            }
        }
        return;
    }
}

void Manager::generate() {
    std::ofstream file("result.txt",std::ios::out | std::ios::binary);
    if (file.is_open()){
        // 假设每个场地每天有一个时间段可以安排项目
        const int timeSlotsPerDay = 1;
        // 运动员在每个时间段是否已经安排了项目
        std::unordered_map<int, std::unordered_set<int>> athleteTimeSlotMap;
        // 日程表，每个场地的每个时间段对应一个项目UID
        std::vector<std::vector<int>> schedule(3, std::vector<int>(list_columns.size(), -1));

        for (auto& column : list_columns) {
            std::vector<int> athletes = column.getATHList();

            bool scheduled = false;
            for (int timeSlot = 0; timeSlot < schedule[0].size() && !scheduled; ++timeSlot) {
                // 检查所有参与该项目的运动员在当前时间段是否空闲
                bool allAthletesAvailable = true;
                for (int athleteUID : athletes) {
                    if (athleteTimeSlotMap[athleteUID].count(timeSlot) > 0) {
                        allAthletesAvailable = false;
                        break;
                    }
                }

                if (allAthletesAvailable) {
                    for (int spaceIndex = 0; spaceIndex < 3; ++spaceIndex) {
                        if (schedule[spaceIndex][timeSlot] == -1) {
                            schedule[spaceIndex][timeSlot] = column.getUID();
                            column.setLocation(static_cast<Type_space>(spaceIndex + 1));
                            // 标记参与运动员的时间段已被占用
                            for (int athleteUID : athletes) {
                                athleteTimeSlotMap[athleteUID].insert(timeSlot);
                            }
                            scheduled = true;
                            break;
                        }
                    }
                }
            }
            if (!scheduled) {
                std::cout << "无法为项目 " << column.getName() << " 安排时间和场地" << std::endl;
            }
        }

        // 打印日程表
        for (int spaceIndex = 0; spaceIndex < 3; ++spaceIndex) {
            file << "场地 " << spaceIndex + 1 << ":" << std::endl;
            for (int timeSlot = 0; timeSlot < schedule[spaceIndex].size(); ++timeSlot) {
                int columnUID = schedule[spaceIndex][timeSlot];
                if (columnUID != -1) {
                    Column *column = find_column_byUID(columnUID);
                    file << "时间段 " << timeSlot << ": " << column->getName() << std::endl;
                } else {
                    file << "时间段 " << timeSlot << ": 空闲" << std::endl;
                }
            }
        }
    }else{
        std::cerr << "无法打开文件" << std::endl;
    }
}