#ifndef DSA_PROJ1_BASE_H
#define DSA_PROJ1_BASE_H
#include <vector>
#include <list>
#include <iostream>
#include <unordered_map>

#define MAX_PARTICIPATE_COUNT 3

enum Type_space {
    none,
    track1,
    track2,
    track3,
    field1,
    field2
};

enum Type_college{
    none_college,
    engineering,
    literature,
    science,
    management,
    art,
    foreign_language,
    law,
    medicine
};

enum Type_department {
    none_department,
    computer_science,
    data_science
};

enum Type_grade {
    none_grade,
    grade1,
    grade2,
    grade3,
    grade4,
    master,
    doctor
};

enum Type_score{
    none_score,
    time_score,
    distance_score,
    number_score
};


#endif //DSA_PROJ1_BASE_H
