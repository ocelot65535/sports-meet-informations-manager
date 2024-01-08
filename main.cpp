#include "Manager.cpp"

int main() {
    system("chcp 65001");
    Manager * manager = new Manager();

    std::string name = "100m";
    Type_grade gradeType = Type_grade::grade2;
    Type_score scoreType = Type_score::time_score;

    Column * race_100m =  new Column(name, gradeType, scoreType);

    std::string ath_name = "某同学";
    std::string id = "2022612001";
    bool isMale = true;

    Type_college college = Type_college::engineering;
    Type_department department = Type_department::data_science;
    Type_grade ath_grade = Type_grade::grade2;


    Athlete * athlete1 = new Athlete(ath_name, id, isMale, college, department, ath_grade);


    race_100m->addAthlete(*athlete1);

    manager->add_column(*race_100m);
    manager->add_athlete(*athlete1);
    manager->check_column();
    manager->check_athlete();

    manager->search_incolumn(ath_name);


}
