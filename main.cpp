#include "Manager.h"
int main() {
    system("chcp 65001");
    Manager * manager = new Manager();

    manager->build_column("100m", Type_grade::grade2, Type_score::time_score, true);

    manager->build_athlete("someone", "2022612001", true, Type_college::engineering, Type_department::data_science, Type_grade::grade2);
    manager->build_athlete("someone2", "2022612002", true, Type_college::engineering, Type_department::data_science, Type_grade::grade2);

    manager->signup_athlete("2022612001", "100m");
    manager->signup_athlete("2022612002", "100m");

    manager->signup_score("2022612001", "100m", 10.0);
    manager->signup_score("2022612002", "100m", 9.8);

    manager->check_college(Type_college::engineering);

    manager->check_athlete("2022612001");

    manager->check_column("100m");
    manager->save(*manager);
    manager->generate();
}
