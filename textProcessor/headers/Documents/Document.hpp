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
    Document(string name, vector<Line*> lines);
    ~Document();

    bool getHasChanged();
    void setHasChanged(bool changed);
    size_t getNumSymbols();
    void removeLine();
    void addLine(string line);
    string getDocName();
    void setDocName(string name);
    string getContents();


    void sort();
    //void sort(Block)
    // TODO while the commands are being made

 private:
    string docName;
    bool hasChanged;
    vector<Line*> lines;

};