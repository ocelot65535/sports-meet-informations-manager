#include "Column.cpp"

class Manager{
private:
    std::vector<Column> list_columns;
    std::vector<Athlete> list_athletes;
public:
    Manager() {
        list_columns = std::vector<Column>();
        list_athletes = std::vector<Athlete>();
    }

    void add_column(Column column){
        list_columns.push_back(column);
    }

    void delete_column(std::string column_name){
        for(int i=0; i < list_columns.size(); i++){
            Column column = list_columns[i];
            if(column.getName() == column_name){
                list_columns.erase(list_columns.begin() + i);
            }
        }
    }

    void check_column(){
        for(int i=0; i < list_columns.size(); i++){
            Column column = list_columns[i];
            std::cout << column.getName() << std::endl;
        }
    }

    void search_incolumn(std::string ath_name){
        for(int i=0; i < list_columns.size(); i++){
            Column column = list_columns[i];
            std::vector<Athlete> list = column.getList();
            for(int j=0; j < list.size(); j++){
                Athlete athlete = list[j];
                if(athlete.getName() == ath_name){
                    std::cout << "Found: "+ ath_name + " in: " + column.getName() + " index: " + std::to_string(j) << std::endl;
                }
            }
        }
    }


    void add_athlete(Athlete athlete){
        list_athletes.push_back(athlete);
    }

    void delete_athlete(std::string athlete_name){
        for(int i=0; i < list_athletes.size(); i++){
            Athlete athlete = list_athletes[i];
            if(athlete.getName() == athlete_name){
                list_athletes.erase(list_athletes.begin() + i);
            }
        }
    }

    void check_athlete(){
        for(int i=0; i < list_athletes.size(); i++){
            Athlete athlete = list_athletes[i];
            std::cout << athlete.getName() << std::endl;
        }
    }
};
