#include <iostream>
#include <map>
#include <iterator>
#include "colors.h"

#define NEXTSTEP {\
    cout << endl << endl;\
    cin.get();\
}

#define INSERT_MACRO( func ) { \
    for (int i = 1; i <= TRY_LEN; i++) { \
        int idx = rand()%TRY_LEN; \
        int rand_num = rand()%TRY_LEN; \
        func; \
        printf("Inserted %d:%d into hashmap\n", idx, rand_num); \
    } \
}

#define TRY_LEN 10

using namespace std;

class HashMap {
    public:
        map <int, int> int_map;

    //functions
        void insert_number_into_hashmap(int, int);
        void insert_number_into_hashmap_nodup(int, int);
        //delete_number_from_hashmap()
        void display_hashmap();
        void autodisplay_hashmap();
        void erase_all();
        void emplace_number_into_hashmap(int, int);
        void find_and_erase();
        int hashmap_size();
        int hashmap_max_size();
};

void HashMap::display_hashmap() {
    map <int, int> :: iterator it;
    cout << YEL("Current state of map:") << endl;
    cout << "KEY" << "    " << "VALUE"<<endl;
    for (it = int_map.begin(); it != int_map.end(); it++) {
       cout << it->first << "    " << it->second << endl;  
    }
    cout << endl;
}

void HashMap::autodisplay_hashmap() {
    cout << "KEY" << "    " << "VALUE"<<endl;
    for (auto& x : int_map) {
       cout << x.first << "    " << x.second << endl;  
    }
}


void HashMap::insert_number_into_hashmap_nodup(int index, int rand_num) {
    pair <map<int, int>::iterator, bool> ret;
    ret = int_map.insert(pair<int, int> (index, rand_num));
    if (ret.second == false) {
        printf(RED("Key already present %d:%d\n"), ret.first->first, ret.first->second);
    }
}
void HashMap::insert_number_into_hashmap(int index, int rand_num) {
    int_map[index] = rand_num;
}

void HashMap::erase_all() {
    int_map.clear();
}

void HashMap::emplace_number_into_hashmap(int index, int rand_num) {
    auto ret = int_map.emplace(index, rand_num); 
    if (ret.second == false) {
        printf(RED("Key already present %d:%d\n"), ret.first->first, ret.first->second);
    }
}


void HashMap::find_and_erase() {
    int num;
    cout << "Enter key to delete : ";
    cin >> num;
    auto it = int_map.find(num);
    int_map.erase(it);
    autodisplay_hashmap();
    cout << YEL("If you use iterator to delete its a constant time map.erase(it)") << endl;
    cout << "Enter key to delete : ";
    cin >> num;
    int_map.erase(num);
    autodisplay_hashmap();
    cout << YEL("If you use key to delete its a logarithmic time map.erase(key)") << endl;
    cout << "Enter key to delete whole range till end: ";
    cin >> num;
    it = int_map.find(num);
    int_map.erase(it, int_map.end());
    autodisplay_hashmap();
    cout << YEL("You can use range to erase map.erase(it, map.end())") << endl;
}


int HashMap::hashmap_size() {
    return int_map.size();
}

int HashMap::hashmap_max_size() {
    cout << YEL("max_size is potential size the container can reach due to known system or library implementation limitations") << endl;
    return int_map.max_size();
}

int main() {

    HashMap hashmap;

    cout << GRN(">>> Insert map[key]=value \n");
    INSERT_MACRO(hashmap.insert_number_into_hashmap(idx, rand_num))
    hashmap.display_hashmap();
    cout << YEL("Note : Insert allows duplicate key insert and overwrite value") << endl;
    hashmap.erase_all();
   
    NEXTSTEP

    cout << GRN("Insert using map.insert(<pair<int, int> (key, value))"\
                " and detect duplicates") << endl;
    INSERT_MACRO(hashmap.insert_number_into_hashmap_nodup(idx, rand_num))
    hashmap.display_hashmap();
    cout << YEL("Note : Insert allows duplicate key detection in ret value") << endl;
    hashmap.erase_all();

    NEXTSTEP

    cout << GRN("Emplace: Inserts a new element in the map if its key is unique") << endl;
    INSERT_MACRO(hashmap.emplace_number_into_hashmap(idx, rand_num))
    hashmap.display_hashmap();
    cout << YEL("Complexity logarithmic in the container size.") << endl;
    cout << YEL("Complexity is constant if the insertion point for the "\
                "element is position. Using emplace hint "\
                "mymap.emplace_hint(mymap.end(),'c',14)") << endl;
    
    NEXTSTEP

    printf(GRN("Current size is %d and max size is %d\n"), hashmap.hashmap_size(), hashmap.hashmap_max_size());

    NEXTSTEP

    cout << GRN ("Find and erase") <<endl;
    hashmap.find_and_erase();

    NEXTSTEP 

    cout << "==== Note ====" << endl;
    cout << KYEL;
    cout << "* Using mymap.at(\"key\") = value you can overwrite element" << endl;
    cout << "* You can use map.clear() to flush all contents" << endl;
    cout << RST;
    return 0;
}

