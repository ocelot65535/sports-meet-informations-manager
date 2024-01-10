#include "Score.h"
ScoreManager::ScoreManager(Type_score typeScore, std::string name, double score) {
    this->type = typeScore;
    this->column_name = name;
    this->score = score;
}
//-------------------------------------------------
Type_score ScoreManager::getType() {
    return type;
}

std::string ScoreManager::getColumnName() {
    return column_name;
}


double ScoreManager::getScore() {
    return score;
}
