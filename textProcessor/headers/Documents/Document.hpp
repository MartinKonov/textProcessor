#include "../Lines/Line.hpp"
#include <vector>

using namespace std;

/**
 * @brief 
 * 
 */
class Document 
{
 public:
    Document(vector<Line*> lines);
    
    bool getHasChanged();
    size_t getNumSymbols();
    void removeLine();
    void addLine(string line);


    void sort();
    //void sort(Block)
    // TODO while the commands are being made

 private:
    string docName;
    bool hasChanged;
    vector<Line*> lines;

};