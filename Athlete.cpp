#include "Base.h"

class Athlete {
public:
    std::string name;
    std::string id;
    bool is_male;

    Type_college college;
    Type_department department;
    Type_grade grade;

    int participate_count;

    Athlete(std::string name, std::string id, bool is_male,
            Type_college typeCollege, Type_department typeDepartment, Type_grade typeGrade){
        this->name = name;
        this->id = id;
        this->is_male = is_male;
        this->college = typeCollege;
        this->department = typeDepartment;
        this->grade = typeGrade;
        this->participate_count = 0;
    }


    std::string getName(){
        return name;
    }

    std::string getId(){
        return id;
    }

    bool isMale(){
        return is_male;
    }

    Type_college getCollege(){
        return college;
    }

    Type_department getDepartment(){
        return department;
    }

    Type_grade getGrade(){
        return grade;
    }

    int getParticipateCount(){
        return participate_count;
    }

    void setName(std::string name) {
        Athlete::name = name;
    }

    void setId(std::string id) {
        Athlete::id = id;
    }

    void setIsMale(bool isMale) {
        is_male = isMale;
    }

    void setCollege(Type_college college) {
        Athlete::college = college;
    }

    void setDepartment(Type_department department) {
        Athlete::department = department;
    }

    void setGrade(Type_grade grade) {
        Athlete::grade = grade;
    }

    void setParticipateCount(int participateCount) {
        participate_count = participateCount;
    }
};

