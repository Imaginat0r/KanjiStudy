#include "helpers.h"

std::string string_Hashing(std::string s){

    std::hash<std::string> hash_string;
    return std::to_string(hash_string(s));
}

int findInVector(const std::vector<QString>  &vecOfElements, const QString& element)
{
    int result;

    // Find given element in vector
    auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
    if (it != vecOfElements.end())
    {
        result = distance(vecOfElements.begin(), it);
    }
    else
    {
        result = -1;
    }
    return result;
}

struct KanjiDetail {
    QString Kanji;
    QString Kanji_LVL;
    QString Kanji_Translation;
    QString Kanji_Reading;
};


