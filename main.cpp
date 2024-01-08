#include "Column.cpp"

int main() {
    std::list<Column> all_columns;
    std::string name = "100m";
    Type_grade gradeType = Type_grade::grade2;
    Type_score scoreType = Type_score::time_score;

    Column * race_100m =  new Column(name, gradeType, scoreType);

    std::string ath_name = "songyunxiao";
    std::string id = "2022612001";
    bool isMale = true;

    Type_college college = Type_college::engineering;
    Type_department department = Type_department::data_science;
    Type_grade ath_grade = Type_grade::grade2;


    Athlete * athlete1 = new Athlete(ath_name, id, isMale, college, department, ath_grade);


    race_100m->addAthlete(*athlete1);

    std::vector<Athlete> list_ath_100m = race_100m->getList();

    for(int i=0; i < list_ath_100m.size();i++){
        Athlete ath = list_ath_100m[i];
        std::cout << ath.getName() << std::endl;
    }
}
