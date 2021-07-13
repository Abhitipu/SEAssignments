/*
Name: Abhinandan De
Roll No: 19CS10069
*/
#include<iostream>
#include<string>    // for string functions
#include<string.h>  // for strlen
#include<algorithm> // for std :: transform
#include<fstream>   // file stream
#include<vector>
#include<dirent.h>  // dealing with directories
#include<set>
#include<map>
#include<cstdio>
#include<cstdlib>

using namespace std;

// utility function to convert strings to lower case
void lower(string& s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
}

class Book {
    protected:
        string title, author, releaseDate, language, fileName;

    public:
        Book(string title = "Unknown", string author = "Unknown",
             string releaseDate = "Unknown", string language = "Unknown", string filename = "Unknown"):
             title(title), author(author), releaseDate(releaseDate), language(language), fileName(filename){}
        Book(const Book& b) {
            title = b.title;
            author = b.author;
            releaseDate = b.releaseDate;
            language = b.language;
            fileName = b.fileName;
        }
        ~Book() {}
        bool match(char attr, string value) {
            string temp;
            if(attr == 't')  // title
                temp = title;
            else            // author name
                temp = author;

            lower(temp);
            if(temp.length() < value.length())
                return false;
            else {
                int last_pos = temp.length() - value.length();
                int sz = value.length();
                for(int i = 0; i <= last_pos; i++)
                    if(temp.substr(i, sz) == value)
                        return true;

                return false;
            }
        }
        string getfileName() {
            return fileName;
        }
        void displayb() {
            ifstream infile;
            infile.open(fileName);

            int ctr = 0;
            string input;

            while(ctr < 50) {
                ctr++;
                getline(infile, input);
                cout << input << '\n';
            }
        }
        friend ostream& operator<< (ostream& os, const Book& b);
};

ostream& operator<< (ostream& os, const Book& b) {
    os << "Title: " << b.title << '\n';
    os << "Author: " << b.author << '\n';
    os << "Release Date: " << b.releaseDate << '\n';
    os << "Language: " << b.language << "\n\n";
    return os;
}

class Paragraph {
    string content;
    public:
        Paragraph(string _content = ""):content(_content) {}
        ~Paragraph() {
            content.clear();
        }
        void parse(ifstream& infile, string& input) {
            if(input.size() != 0)
                content += input;

            while(getline(infile, input)) {
                if(input.size() == 0)   // new paragraph
                    return;
                content += (' ' + input);
            }
        }
        int search(string word) {     // utility function to search for a word in the paragraphs!
            int end_pt = content.length() - word.length();
            int occ = 0;
            for(int i = 0; i <= end_pt; i++) {
                string check = content.substr(i, word.length());
                lower(check);
                if(check == word)
                    occ++;
            }
            return occ;
        }
        void display() {
            cout << content << '\n';
        }
};

class Chapter {
    protected:
        string chapTitle;
        vector<Paragraph> paras;    // Chapter HAS paragraphs
    public:
        Chapter(string _title = "Unknown"):chapTitle(_title) {}
        ~Chapter() {
            paras.clear();
        }
        string parse(ifstream& infile, string title) {
            chapTitle = title;
            string input;
            string cmp = "CHAPTER";

            int ctr = 1;
            while(getline(infile, input)) {

                if(input.length() == 0)
                    continue;

                ctr++;
                if(input.length() >= cmp.length())
                    if(input.substr(0, cmp.length()) == cmp)  // next chapter name
                        return input;

                Paragraph p;
                p.parse(infile, input);
                paras.push_back(p);
            }

            string emp = "";    // empty string
            return emp;
        }

        int search_Chapterwise(string word) {
            int occ = 0;
            for(Paragraph p: paras)      // for the chapters
                occ += p.search(word);
            return occ;
        }
        void search_Parawise(string word, vector<pair<int, int>>& v) {
            for(int i = 0; i < paras.size(); i++)
                v.push_back({paras[i].search(word), i});
            return;
        }
        void display_name() {
            cout << chapTitle << '\n';
        }
        void display_para(int paraNo) {
            paras[paraNo].display();
        }
};

class Novel: public Book {       // Novel IS-A book
    vector<Chapter> chapters;    // Novel HAS chapters
    vector<pair<int, pair<int, int>>> paradetails;     // intention : store the no of occurences, chapter no and then paragraph no
    vector<pair<int, int>> chapdetails;
    public:
        Novel(string title = "Unknown", string author = "Unknown",
             string releaseDate = "Unknown", string language = "Unknown", string fileName = "Unknown"):
             Book(title, author, releaseDate, language, fileName) {}
        ~Novel(){
            chapters.clear();
            paradetails.clear();
            chapdetails.clear();
        }
        Novel(const Book& b): Book(b) {}

        void parse() {
            string input;
            ifstream infile;
            infile.open(fileName);

            if(infile.fail()) {
                cout << "Failed to open file!\n";
            }

            string cmp  = "CHAPTER";
            string temp = "";
            int ctr = 0;
            while(temp.length() != 0 || getline(infile, input)) {
                if(temp.length() != 0)
                    input = temp;

                ctr++;
                if(ctr >= 200)
                    break;

                if((input.length() >= cmp.length()) && (input.substr(0, cmp.length()) == cmp)) {
                    // cout << input << '\n';
                    Chapter ch(input);
                    temp = ch.parse(infile, input);
                    chapters.push_back(ch);
                }
            }

            infile.close();
        }

        void updateOcc(string word) {

            for(int i = 0; i < chapters.size(); i++) {
                vector<pair<int, int>> temp;
                chapters[i].search_Parawise(word, temp);
                int occ_in_chapter = 0;
                for(pair<int, int> p: temp) {
                    paradetails.push_back({p.first, {i, p.second}});
                    occ_in_chapter += p.first;
                }
                chapdetails.push_back({occ_in_chapter, i});
            }
        }

        void displayTop_k_paras(int k) {
            sort(paradetails.begin(), paradetails.end());
            reverse(paradetails.begin(), paradetails.end());
            for(int i = 0; i < min(k, (int)paradetails.size()); i++) {
                int chapNo = paradetails[i].second.first;
                int paraNo = paradetails[i].second.second;
                cout << i+1 << ". ";
                chapters[chapNo].display_para(paraNo);
                cout << "Occurences: " << paradetails[i].first << "\n\n";
            }
        }

        void displayTop_k_chapters(int k) {
            sort(chapdetails.begin(), chapdetails.end());
            reverse(chapdetails.begin(), chapdetails.end());
            for(int i = 0; i < min(k, (int)chapters.size()); i++) {
                int chapNo = chapdetails[i].second;
                cout << i+1 << ". ";
                chapters[chapNo].display_name();
                cout << "Occurences: " << chapdetails[i].first << "\n\n";
            }
        }

        void display() {
            displayb();
        }
};

class Scene {
    set<string> characters;      // speakers involved in the scene
    string scTitle;
    public:
        Scene(string _title = "Unknown"): scTitle(_title) {}
        ~Scene() {
            characters.clear();
        }
        string parse(ifstream& infile, string& input) {
            string cmp = "SCENE";
            string cmp2 = "ACT";

            if(input.length() >= cmp.length() && input.substr(0, cmp.length()) == cmp) {
                scTitle = input;
            }


            while(getline(infile, input)) {
                if(input.length() >= cmp.length() && input.substr(0, cmp.length()) == cmp) {
                    return input;
                }
                else if(input.length() >= cmp2.length() && input.substr(0, cmp2.length()) == cmp2) {
                    return input;
                }
                else if(validCharName(input) == "-1")
                    continue;
                else {
                    string newChar = validCharName(input);
                    characters.insert(newChar);
                }
            }

            string tmp = "";
            return tmp;
        }

        string validCharName(string& s) {
            int n = s.size();

            string unsuccessful = "-1";
            string temp = "";

            for(char c: s) {
                if((c <= 'Z' && c >= 'A') || (c == ' '))
                    temp += c;
                else if(c == '.')
                    return temp;
                else
                    return unsuccessful;
            }
            return unsuccessful;
        }
        void getAll(set<string>& allActors) {
            for(string s: characters)
                allActors.insert(s);
        }
        void getCoActors(set<string>& coActors, string& charName) {
            if(characters.find(charName) == characters.end())
                return;

            for(string s: characters) {
                if(s == charName)
                    continue;
                else
                    coActors.insert(s);
            }
        }
};

class Act {
    private:
        string title;
        vector<Scene> scenes;
    public:
        Act(string _title = "Unknown"): title(_title) { }
        ~Act() {
            scenes.clear();
        }
        string parse(ifstream& infile, string input) {
            string cmp = "ACT";
            if(input.length() >= cmp.length() && input.substr(0, cmp.length()) == cmp) {
                title = input;
            }

            string temp = "";
            string cmp2 = "SCENE";
            while(temp.length() != 0 || getline(infile, input)) {
                if(temp.length() != 0)
                    input = temp;

                if(input.length() >= cmp2.length() && input.substr(0, cmp2.length()) == cmp2) {
                    Scene sc(input);
                    temp = sc.parse(infile, input);
                    scenes.push_back(sc);

                    if(temp.length() >= cmp.length() && temp.substr(0, cmp.length()) == cmp)
                        return temp;
                }
            }
            return temp;
        }

        void getAll(set<string>& allActors) {
            for(Scene s: scenes)
                s.getAll(allActors);
        }

        void getCoActors(set<string>& coActors, string& charName) {
            for(Scene s: scenes)
                s.getCoActors(coActors, charName);
        }
};

class Play: public Book {
    protected:
        vector<Act> acts;
        set<string> coActors;
        set<string> allActors;
    public:
        Play(string title = "Unknown", string author = "Unknown",
             string releaseDate = "Unknown", string language = "Unknown", string fileName = "Unknown"):
             Book(title, author, releaseDate, language, fileName){}

        Play(const Book& b): Book(b) { }
        ~Play() {
            acts.clear();
            coActors.clear();
            allActors.clear();
        }
        void parse() {
            string input;
            ifstream infile;
            infile.open(fileName);

            if(infile.fail()) {
                cout << "Error! Couldn't open file!\n";
            }

            string cmp = "ACT";
            string temp = "";

            while(temp.length() != 0 || getline(infile, input)) {
                if(temp.length() != 0)
                    input = temp;
                if(input.substr(0, cmp.length()) == cmp) {
                    Act a(input);
                    temp = a.parse(infile, input);
                    acts.push_back(a);
                }
            }

            infile.close();
        }

        void getAll() {
            for(Act a: acts)
                a.getAll(allActors);

            for(string s: allActors)
                cout << s << '\n';
        }

        void updateCoActors(string& charName) {
            for(int i = 0; i < charName.size(); i++) {
                charName[i] = toupper(charName[i]);
            }

            if(allActors.find(charName) == allActors.end())
                cout << "This character " << charName << " doesn't exist in the play\n";

            for(Act a: acts)
                a.getCoActors(coActors, charName);
        }

        void displayCoActors(string charName) {

            if(coActors.size() == 0)
                return;

            cout << "*************There are " << coActors.size() << " actors who did at least one scene with " << charName << ":*************\n\n";
            int ctr = 1;
            for(string s: coActors) {
                cout << ctr << ". " << s << '\n';
                ctr++;
            }
        }
        void display() {
            displayb();
        }
};

// A generic function for getting all the details!
template<typename T>
void getDetails(string fileName, T& b) {
    string input;
    vector<string> details(4);
    vector<string> req = {"title: ", "author: ", "release date: ", "language: "};
    int i = 0;

    ifstream infile;
    infile.open(fileName);
    if(infile.fail())
        cout << "Couldn't open file\n";

    while(i < req.size()) {
        getline(infile, input);
        int sz = input.length();
        int reqSz = req[i].length();

        if(sz < reqSz)
            continue;

        string check = input.substr(0, reqSz);
        lower(check);

        if(check == req[i])
            details[i] = input.substr(reqSz), i++;
    }

    infile.close();
    b = T(details[0], details[1], details[2], details[3], fileName);
}

void solveCase3(vector<Novel>& novels, vector<Play>& plays) {

    bool done = false;

    while(!done) {
        if(!plays.empty())
            cout << "Enter 1 to search for a matching play.\n";
        if(!novels.empty())
            cout << "Enter 2 to search for a matching novel.\n";
        cout << "Enter 3 to return to use case 2.\n";

        cout << "\n";

        int n;
        cin >> n;

        if(n == 2) {
            cout << "\nEnter the serial no. of the novel to display: ";
            cin >> n;
            n--;
            if(n >= 0 && n < novels.size()) {
                done = true;
                cout << "\n*************Displaying first 50 lines of the novel.*************\n\n";
                novels[n].display();
                novels[n].parse();

                string input;
                cout << "\nEnter a word to get the statistics: ";
                cin >> input;
                lower(input);

                novels[n].updateOcc(input);  // check

                int k;
                cout << "\nEnter k for displaying top k statistics: ";
                cin >> k;

                cout << "\nIf " << k << " chapters/paragraphs are not available, only the available data will be shown.\n\n";

                cout << "\n*************Displaying top k paragraphs containing the word " << input << " as a substring:*************\n\n";
                novels[n].displayTop_k_paras(k);

                cout << "\n*************Displaying top k chapters containing the word*************\n\n";
                novels[n].displayTop_k_chapters(k);

                done = true;
            } else {
                cout << "\nInvalid input\n";
            }
        }
        else if(n == 1) {
            cout << "\nEnter the serial no. of the play to search: ";
            cin >> n;
            n--;
            if(n >= 0 && n < plays.size()) {
                done = true;
                cout << "\n*************Displaying first 50 lines of the play*************\n\n";
                plays[n].display();
                plays[n].parse();

                cout << "\n*************The characters involved in this play are*************\n\n";
                plays[n].getAll();   // creates a set of all actors!

                string name;
                cin.ignore();
                cout << "\nEnter the name of a valid character from the play: ";
                getline(cin, name);

                plays[n].updateCoActors(name);
                plays[n].displayCoActors(name);

            } else {
                cout << "\nInvalid input\n";
            }
        } else if(n == 3) {
            return;
        } else {
            cout << "\nInvalid input\n";
        }
    }
}

// Take input from command line

int main(int argc, char* argv[]) {
    string dirname;
    if(argc > 2) {
        cout << "Too many arguments given\n";
        exit(1);
    }
    else
        dirname = argv[1];

    cout << "\nWelcome to Library Management System\n\n";

    // this contains the list of files!
    ifstream indexfile;
    indexfile.open("index.txt");

    multiset<pair<string, string>> files;   // temporary storage of files and for faster search

    string nameOfFile;
    string typeOfFile;
    while(getline(indexfile, nameOfFile)) {
        getline(indexfile, typeOfFile);
        files.insert({nameOfFile.substr(strlen("Name: ")), typeOfFile.substr(strlen("Type: "))});
    }
    indexfile.close();


    ifstream infile;    // this is for storing/opening the books

    DIR *dir = NULL;  // pointer to directory
    struct dirent *entry = NULL;   // for using operndir and readdir

    dir = opendir(dirname.c_str());

    if(!dir) {
        cout << "This directory doesn't exist!\n";
        exit(-1);
    }

    vector<Novel> novels;    // this will just be used for traversal in part 2
    vector<Play> plays;      // "" "" "" "" "" ""

    ofstream tempfile;          // a temporary file that stores all final contents
    tempfile.open("temp.txt");

    while((entry = readdir(dir)) != NULL) {
        string fileName = entry->d_name;
        if (fileName == "Assn1.cpp" || fileName == "index.txt" || fileName == "temp.txt" || fileName == "a.exe")
            continue;


        infile.open(fileName.c_str());  // for . and .. and other misc files
        if(infile.fail())
            continue;
        infile.close();

        string check = fileName;
        string Type;

        if(files.find({check, "novel"}) != files.end()) {
            Type = "novel";
            Novel n;
            getDetails(fileName, n);
            novels.push_back(n);
        }
        else if(files.find({check, "play"}) != files.end()) {
            Type = "play";
            Play p;
            getDetails(fileName, p);
            plays.push_back(p);
        }
        else {
            cout << "Enter the type of the book with filename " << check << ": ";
            cin >> Type;
            lower(Type);

            if(Type == "novel") {
                Novel n;
                getDetails(fileName, n);
                novels.push_back(n);
            } else {
                Play p;
                getDetails(fileName, p);
                plays.push_back(p);
            }
            infile.close();
            files.insert({fileName, Type});
        }
        tempfile << "Name: " << fileName << '\n';
        tempfile << "Type: " << Type << '\n';
    }
    tempfile.close();

    ifstream tempfile2;
    tempfile2.open("temp.txt");

    ofstream outfile;
    outfile.open("index.txt");
    string input;
    while(getline(tempfile2, input))
        outfile << input << '\n';
    outfile.close();

    tempfile2.close();

    if(remove("temp.txt")) {
        cout << "Error!\n";
        exit(-1);
    }

    cout << "\nRead and synced all files from current working directory. Solved USE CASE 1\n\n";

    int n;
    bool done = false;
    while(!done) {
        cout << "\nEnter: \n";
        cout << "1 for displaying the whole_list\n";
        cout << "2 for searching using title\n";
        cout << "3 for searching using author name\n";
        cout << "4 for ending the program\n\n";

        cin >> n;
        string input;
        bool found = false;
        vector<Play> okPlays;
        vector<Novel> okNovels;   // to push_back the filenames and then use for parsing!
        int ctr = 1;

        switch(n) {
            case 1: if(!plays.empty()) {
                    cout << "\nDisplaying all plays:\n\n";
                        for(Book b: plays) {
                            cout << ctr << ". " << b;
                            okPlays.push_back(b);
                            ctr++;
                        }
                    }
                    if(!novels.empty()) {
                        ctr = 1;
                        cout << "\nDisplaying all novels:\n\n";
                        for(Book b: novels) {
                            cout << ctr << ". " << b;
                            okNovels.push_back(b);
                            ctr++;
                        }
                    }
                    if(novels.empty() && plays.empty())
                        cout << "No records found!\n";
                    else
                        solveCase3(okNovels, okPlays);
                    break;
            case 2: cout << "Enter the title:\n";
                    cin.ignore();
                    getline(cin, input);
                    lower(input);
                    cout << "\nSearching for records:\n\n";
                    if(!plays.empty()) {
                        for(Book b: plays) {
                            if(b.match('t', input)) {
                                if(!found) {
                                    cout << "Matching play(s) found:\n\n";
                                    found = true;
                                }
                                okPlays.push_back(b);
                                cout << ctr << ". " << b;
                                ctr++;
                            }
                        }
                    }
                    if(!novels.empty()) {
                        ctr = 1;
                        bool found2 = false;
                        for(Book b: novels){
                            if(b.match('t', input)) {
                                if(!found2) {
                                    cout << "Matching novel(s) found:\n\n";
                                    found2 = true;
                                }
                                okNovels.push_back(b);
                                cout << ctr << ". " << b;
                                ctr++;
                            }
                        }
                        if(found2)
                            found = true;
                    }
                    if(!found)
                        cout << "No matching records found\n\n";
                    else
                        solveCase3(okNovels, okPlays);
                    break;
            case 3: cout << "Enter the name of the author:\n";
                    cin.ignore();
                    getline(cin, input);
                    lower(input);
                    cout << "\nSearching for records:\n\n";
                    if(!plays.empty()) {
                        for(Book b: plays) {
                            if(b.match('a', input)) {
                                if(!found) {
                                    cout << "Matching play(s) found:\n\n";
                                    found = true;
                                }
                                okPlays.push_back(b);
                                cout << ctr << ". " << b;
                                ctr++;
                            }
                        }
                    }
                    if(!novels.empty()) {
                        ctr = 1;
                        bool found2 = false;
                        for(Book b: novels){
                            if(b.match('a', input)) {
                                if(!found2) {
                                    cout << "Matching novel(s) found:\n\n";
                                    found2 = true;
                                }
                                okNovels.push_back(b);
                                cout << ctr << ". " << b;
                                ctr++;
                            }
                        }
                        if(found2)
                            found = true;
                    }
                    if(!found)
                        cout << "No matching records found\n\n";
                    else
                        solveCase3(okNovels, okPlays);
                    break;
            case 4: cout << "Thanks for testing the program!\n";
                    done = true;
                    break;
            default: cout << "Invalid input\n\n";
        }

        okNovels.clear();
        okPlays.clear();
    }

    files.clear();  // clearing all memory
    novels.clear();
    plays.clear();
    closedir(dir);
    return 0;
}

/*
run code (windows powershell/cmd... format: <./outfile.exe>SPACE<current_working_directory>): ./a.exe C:\Users\Abhinandan\Desktop\Assignment1
Hamlet.txt : play
Heretics: novel
Julius Caesar: play
Moby Dick: novel
Romeo Juliet: play
Uncle tom: novel
*/
