#include "Athlete.cpp"
class ScoreManager{
public:
    score_type type;

    int score;

    ScoreManager(score_type type, int score) : type(type), score(score) {}

    score_type getType() const {
        return type;
    }

    int getScore() const {
        return score;
    }

    void setType(score_type type) {
        ScoreManager::type = type;
    }

    void setScore(int score) {
        ScoreManager::score = score;
    }
};