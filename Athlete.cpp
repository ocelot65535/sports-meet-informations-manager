#include <iostream>
#include "Base.h"

class Athlete {
public:
    std::string name;
    std::string id;
    bool is_male;

    college_type college;
    department_type department;
    grade_type grade;

    int participate_count;

    Athlete(const std::string &name, const std::string &id, bool isMale, college_type college,
            department_type department, grade_type grade, int participateCount) : name(name), id(id), is_male(isMale),
                                                                                  college(college),
                                                                                  department(department), grade(grade),
                                                                                  participate_count(participateCount) {}


    const std::string &getName() const {
        return name;
    }

    const std::string &getId() const {
        return id;
    }

    bool isMale() const {
        return is_male;
    }

    college_type getCollege() const {
        return college;
    }

    department_type getDepartment() const {
        return department;
    }

    grade_type getGrade() const {
        return grade;
    }

    int getParticipateCount() const {
        return participate_count;
    }

    void setName(const std::string &name) {
        Athlete::name = name;
    }

    void setId(const std::string &id) {
        Athlete::id = id;
    }

    void setIsMale(bool isMale) {
        is_male = isMale;
    }

    void setCollege(college_type college) {
        Athlete::college = college;
    }

    void setDepartment(department_type department) {
        Athlete::department = department;
    }

    void setGrade(grade_type grade) {
        Athlete::grade = grade;
    }

    void setParticipateCount(int participateCount) {
        participate_count = participateCount;
    }
};

