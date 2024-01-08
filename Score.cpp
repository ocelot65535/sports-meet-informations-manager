#include "Athlete.cpp"
class ScoreManager{
private:
    Type_score type;
    int score;
public:
    ScoreManager(Type_score typeScore, int score) {
        this->type = typeScore;
        this->score = score;
    }

    Type_score getType() {
        return type;
    }

    int getScore() {
        return score;
    }

    void setType(Type_score typeScore) {
        ScoreManager::type = typeScore;
    }

    void setScore(int ath_score) {
        ScoreManager::score = ath_score;
    }
};