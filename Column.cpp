#include "Score.cpp"

class Column{
private:
    std::vector<Athlete> list;
    std::string name;
    Type_grade grade;
    Type_score type;
public:
    Column(std::string columnName, Type_grade typeGrade, Type_score typeScore) {
        this->name = columnName;
        this->grade = typeGrade;
        this->type = typeScore;
    }

    std::string getName(){
        return name;
    }

    Type_score getType(){
        return type;
    }

    void setName(std::string columnName) {
        Column::name = columnName;
    }

    void setType(Type_score typeScore) {
        Column::type = typeScore;
    }

    Type_grade getGrade(){
        return grade;
    }

    void setGrade(Type_grade typeGrade) {
        Column::grade = typeGrade;
    }

    void addAthlete(Athlete athlete){
        list.push_back(athlete);
    }

    std::vector<Athlete> getList() const {
        return list;
    }
};