#include "Score.cpp"
#include <list>
class Column{
private:
    std::list<Athlete> list;
    std::string name;
    grade_type grade;
    score_type type;
public:
    Column(const std::string &name, score_type type) : name(name), type(type) {}

    const std::string &getName() const {
        return name;
    }

    score_type getType() const {
        return type;
    }

    void setName(const std::string &name) {
        Column::name = name;
    }

    void setType(score_type type) {
        Column::type = type;
    }

    grade_type getGrade() const {
        return grade;
    }

    void setGrade(grade_type grade) {
        Column::grade = grade;
    }

    void addAthlete(Athlete athlete){
        list.push_back(athlete);
    }

    const std::list<Athlete> &getList() const {
        return list;
    }
};