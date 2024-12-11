#include <iostream>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <tuple>

using namespace std;

class Deck{
    private:
        string key;
        string brand;
        string name;
        string size; //Setting the size as a string rather than int makes it easier for user input.

    public:
        Deck(){ //Default Constructor

        }

        Deck(string key, string brand, string name, string size){
            this->key = key;
            this->brand = brand;
            this->name = name;
            this->size = size;
        }

        string getKey() const{
            return key;
        }

        string getBrand() const{
            return brand;
        }

        string getName() const{
            return name;
        }

        string getSize() const{
            return size;
        }

        void print(){ //Used for testing
            cout << "Brand: " << brand << endl;
            cout << "Name: " << name << endl;
            cout << "Size: " << size << endl;
            cout << endl;
        }

};

class DeckHashTable{
        private:
            unordered_map<string, Deck> deckMap;

        public:
            DeckHashTable(){
                //Fill Hashtable
                deckMap = {
                    //AlienWorkshop
                    {"AlienWorkshop_Rob", Deck("AlienWorkshop_Rob", "AlienWorkshop", "Rob Dyrdek", "8.25")},
                    {"AlienWorkshop_Spectrum", Deck("AlienWorkshop_Spectrum", "AlienWorkshop", "Spectrum", "7.75")},
                    {"AlienWorkshop_Abduction", Deck("AlienWorkshop_Abduction", "AlienWorkshop", "Abduction-33", "8.0")},
                    //April
                    {"April_Shane", Deck("April_Shane", "April", "Shane O'Neill", "8.125")},
                    {"April_Yuto", Deck("April_Yuto", "April", "Yuto Horigome", "8.25")},
                    {"April_Guy", Deck("April_Guy", "April", "Guy Mariano", "8.5")},
                    {"April_Logo", Deck("April_Logo", "April", "Logo", "8.3")},
                    //Baker
                    {"Baker_Reynolds", Deck("Baker_Reynolds", "Baker", "Andrew Reynolds", "8.3")},
                    {"Baker_Logo", Deck("Baker_Logo", "Baker", "Logo", "8.5")},
                    //Girl
                    {"Girl_PacMan", Deck("Girl_PacMan", "Girl", "PacMan/Sean Malto", "8.5")},
                    {"Girl_Koston", Deck("Girl_Koston", "Girl", "Eric Koston", "8.3")},
                    //Plan-B
                    {"Plan-B_Sheckler", Deck("Plan-B_Sheckler", "Plan-B", "Ryan Sheckler", "8.125")},
                    {"Plan-B_Joslin", Deck("Plan-B_Joslin", "Plan-B", "Chris Joslin", "8.3")},
                    //Primitive
                    {"Primitive_Akatsuki", Deck("Primitive_Akatsuki", "Primitive", "Akatsuki", "8.3")},
                    {"Primitive_Gohan", Deck("Primitive_Gohan", "Primitive", "Gohan", "8.125")},
                    {"Primitive_Goku", Deck("Primitive_Goku", "Primitive", "Goku", "8.25")},
                    //DGK
                    {"DGK_SourPatch", Deck("DGK_SourPatch", "DGK", "SourPatch", "7.75")},
                    {"DGK_Overlord", Deck("DGK_Overlord", "DGK", "Overlord", "8.0")},
                    {"DGK_Billions", Deck("DGK_Billions", "DGK", "Billions", "8.25")}
                };

            }

            Deck getDeck(string key){
                return deckMap.at(key);
            }
            
            void display(){
                cout << "Deck Inventory: " << "\n\n";
                for(const auto& [key, deck] : deckMap){
                    cout << "Deck key: " << key << endl;
                    cout << "Info: " << deck.getBrand() << ", " << deck.getName() << ", " << deck.getSize() << "\n\n";
                }
                cout << "Deck Inventory Link: file:///Users/kevintownsend/SkateWebsite/Deck_Inventory.html" << endl;
            }

            void displayBrands(){
                unordered_set<string> brands;
                for(const auto& pair : deckMap){
                    brands.insert(pair.second.getBrand());
                }
                cout << "Available brands: " << endl;
                for(const string& brand : brands){
                    cout << brand << endl;
                }
                cout << "\n";
            }

            void displaySizes(){
                cout << "7.75" << endl;
                cout << "8.0" << endl;
                cout << "8.125" << endl;
                cout << "8.25" << endl;
                cout << "8.3" << endl;
                cout << "8.5" << endl;
                cout << "\n";
            }

            bool inTable(string input){
                for(const auto& [key, deck] : deckMap){
                    if(input == key){
                        return true;
                    }
                }
                return false;
            }

            bool hasBrand(string brand){
                for(const auto& [key, deck] : deckMap){
                    if(brand == deck.getBrand()){
                        return true;
                    }
                }
                return false;
            }

            bool hasSize(string size){
                for(const auto& [key, deck] : deckMap){
                    if(size == deck.getSize()){
                        return true;
                    }
                }
                return false;
            }

            void filterBrand(const string& brand){
                list<Deck> filteredList;
                for(const auto& [key, deck] : deckMap){
                    if(deck.getBrand() == brand){
                        filteredList.push_back(deck);
                    }
                }

                //Display results
                cout << "Filter: " << brand << "\n\n";
                for(const auto& deck : filteredList){
                    cout << "Deck Key: " << deck.getKey() << endl;
                    cout << "Info: " << deck.getBrand() << ", " << deck.getName() << ", " << deck.getSize() << "\n\n";
                }
                
            }

            void filterSize(string size){
                list<Deck> filteredList;
                for(const auto& [key, deck] : deckMap){
                    if(deck.getSize() == size){
                        filteredList.push_back(deck);
                    }
                }

                //Display results
                cout << "Filter: Size " << size << "\n\n";
                for(const auto& deck : filteredList){
                    cout << "Deck Key: " << deck.getKey() << endl;
                    cout << "Info: " << deck.getBrand() << ", " << deck.getName() << ", " << deck.getSize() << "\n\n";
                }
            }
            
            
};

class Trucks{
    private:
        string key;
        string brand;
        string name;
        string size; //Setting the size as a string rather than int makes it easier for user input.

    public:
        Trucks(){ //Default Constructor

        }

        Trucks(string key, string brand, string name, string size){
            this->key = key;
            this->brand = brand;
            this->name = name;
            this->size = size;
        }

        string getKey() const{
            return key;
        }

        string getBrand() const{
            return brand;
        }

        string getName() const{
            return name;
        }

        string getSize() const{
            return size;
        }

        void print(){ //Used for testing
            cout << "Brand: " << brand << endl;
            cout << "Name: " << name << endl;
            cout << "Size: " << size << endl;
            cout << endl;
        }
};

class TrucksHashTable{
        private:
            unordered_map<string, Trucks> trucksMap;

        public:
            TrucksHashTable(){
                //Fill Hashtable
                trucksMap = {
                    {"Independent_BlackStandard", Trucks("Independent_BlackStandard", "Independent", "Black Standard", "144")},
                    {"Independent_BTG", Trucks("Independent_BTG", "Independent", "BTG", "139")},
                    {"Independent_HollowChain", Trucks("Independent_HollowChain", "Independent", "Hollow Chain", "149")},
                    {"Thunder_Cromer", Trucks("Thunder_Cromer", "Thunder", "Brad Cromer", "149")},
                    {"Thunder_Medieval", Trucks("Thunder_Medieval", "Thunder", "Medieval", "148")},
                    {"Thunder_Silvas", Trucks("Thunder_Silvas", "Thunder", "Miles Silvas", "144")},
                    {"Venture_Koston", Trucks("Venture_Koston", "Venture", "Eric Koston", "149")},
                    {"Venture_Gipson", Trucks("Venture_Gipson", "Venture", "Troy Gipson", "139")},
                    {"Venture_Paid", Trucks("Venture_Paid", "Venture", "Paid V-Hollow", "148")}
                };
            }
            
            Trucks getTrucks(string key){
                return trucksMap.at(key);
            }

            void display(){
                cout << "Trucks Inventory: " << "\n\n";
                for(const auto& [key, trucks] : trucksMap){
                    cout << "Trucks key: " << key << endl;
                    cout << "Info: " << trucks.getBrand() << ", " << trucks.getName() << ", " << trucks.getSize() << "\n\n";
                }
                cout << "Trucks Inventory Link: file:///Users/kevintownsend/SkateWebsite/Trucks_Inventory.html" << endl;
            }

            void displayBrands(){
                unordered_set<string> brands;
                for(const auto& pair : trucksMap){
                    brands.insert(pair.second.getBrand());
                }
                cout << "Available brands: " << endl;
                for(const string& brand : brands){
                    cout << brand << endl;
                }
                cout << "\n";
            }

            void displaySizes(){
                cout << "139" << endl;
                cout << "144" << endl;
                cout << "148" << endl;
                cout << "149" << endl;
                cout << "\n";
            }

            bool inTable(string input){
                for(const auto& [key, trucks] : trucksMap){
                    if(input == key){
                        return true;
                    }
                }
                return false;
            }

            bool hasBrand(string brand){
                for(const auto& [key, trucks] : trucksMap){
                    if(brand == trucks.getBrand()){
                        return true;
                    }
                }
                return false;
            }

            bool hasSize(string size){
                for(const auto& [key, trucks] : trucksMap){
                    if(size == trucks.getSize()){
                        return true;
                    }
                }
                return false;
            }

            void filterBrand(const string& brand){
                list<Trucks> filteredList;
                for(const auto& [key, trucks] : trucksMap){
                    if(trucks.getBrand() == brand){
                        filteredList.push_back(trucks);
                    }
                }

                //Display results
                cout << "Filter: " << brand << "\n\n";
                for(const auto& trucks : filteredList){
                    cout << "Trucks Key: " << trucks.getKey() << endl;
                    cout << "Info: " << trucks.getBrand() << ", " << trucks.getName() << ", " << trucks.getSize() << "\n\n";
                }
                
            }

            void filterSize(string size){
                list<Trucks> filteredList;
                for(const auto& [key, trucks] : trucksMap){
                    if(trucks.getSize() == size){
                        filteredList.push_back(trucks);
                    }
                }

                //Display results
                cout << "Filter: " << size << "\n\n";
                for(const auto& trucks : filteredList){
                    cout << "Trucks Key: " << trucks.getKey() << endl;
                    cout << "Info: " << trucks.getBrand() << ", " << trucks.getName() << ", " << trucks.getSize() << "\n\n";
                }
            }           
};

class Wheels{
    private:
        string key;
        string brand;
        string name;
        string size; //Setting the size as a string rather than int makes it easier for user input.

    public:
        Wheels(){ //Default Constructor

        }

        Wheels(string key, string brand, string name, string size){
            this->key = key;
            this->brand = brand;
            this->name = name;
            this->size = size;
        }

        string getKey() const{
            return key;
        }

        string getBrand() const{
            return brand;
        }

        string getName() const{
            return name;
        }

        string getSize() const{
            return size;
        }

        void print(){ //Used for testing
            cout << "Brand: " << brand << endl;
            cout << "Name: " << name << endl;
            cout << "Size: " << size << endl;
            cout << endl;
        }
};

class WheelsHashTable{
        private:
            unordered_map<string, Wheels> wheelsMap;

        public:
            WheelsHashTable(){
                //Fill Hashtable
                wheelsMap = {
                    {"Spitfire_Classic", Wheels("Spitfire_Classic", "Spitfire", "Green Classic", "52")},
                    {"Spitfire_Fade", Wheels("Spitfire_Fade", "Spitfire", "Fade", "58")},
                    {"Spitfire_Burners", Wheels("Spitfire_Burners", "Spitfire", "Burners", "55")},
                    {"Spitfire_Grimple", Wheels("Spitfire_Grimple", "Spitfire", "Grimplehead", "54")},
                    {"Pig_Classic", Wheels("Pig_Classic", "Pig", "Blue Classic", "53")},
                    {"Pig_Lewis", Wheels("Pig_Lewis", "Pig", "Julian Lewis", "55")},
                    {"Pig_Combo", Wheels("Pig_Combo", "Pig", "Combo", "54")},
                    {"Bones_STF", Wheels("Bones_STF", "Bones", "Easy Streets", "52")},
                    {"Bones_100s", Wheels("Bones_100s", "Bones", "100s", "54")},
                    {"Bones_P-Rod", Wheels("Bones_P-Rod", "Bones", "P-Rod", "52")},
                    {"OJ_DoubleDuros", Wheels("OJ_DoubleDuros", "OJ", "Double Duros", "58")},
                    {"OJ_Concentrate", Wheels("OJ_Concentrate", "OJ", "From Concentrate", "53")},
                    {"OJ_Koi", Wheels("OJ_Koi", "OJ", "Dressen Koi", "56")}
                };
            }

            Wheels getWheels(string key){
                return wheelsMap.at(key);
            }
            
            void display(){
                cout << "Wheels Inventory: " << "\n\n";
                for(const auto& [key, wheels] : wheelsMap){
                    cout << "Wheels key: " << key << endl;
                    cout << "Info: " << wheels.getBrand() << ", " << wheels.getName() << ", " << wheels.getSize() << "\n\n";
                }
                cout << "Wheels Inventory Link: file:///Users/kevintownsend/SkateWebsite/Wheels_Inventory.html" << endl;
            }

            void displayBrands(){
                unordered_set<string> brands;
                for(const auto& pair : wheelsMap){
                    brands.insert(pair.second.getBrand());
                }
                cout << "Available brands: " << endl;
                for(const string& brand : brands){
                    cout << brand << endl;
                }
                cout << "\n";
            }

            void displaySizes(){
                cout << "52" << endl;
                cout << "53" << endl;
                cout << "54" << endl;
                cout << "55" << endl;
                cout << "56" << endl;
                cout << "58" << endl;
                cout << "\n";
            }

            bool inTable(string input){
                for(const auto& [key, wheels] : wheelsMap){
                    if(input == key){
                        return true;
                    }
                }
                return false;
            }

            bool hasBrand(string brand){
                for(const auto& [key, wheels] : wheelsMap){
                    if(brand == wheels.getBrand()){
                        return true;
                    }
                }
                return false;
            }

            bool hasSize(string size){
                for(const auto& [key, wheels] : wheelsMap){
                    if(size == wheels.getSize()){
                        return true;
                    }
                }
                return false;
            }

            void filterBrand(const string& brand){
                list<Wheels> filteredList;
                for(const auto& [key, wheels] : wheelsMap){
                    if(wheels.getBrand() == brand){
                        filteredList.push_back(wheels);
                    }
                }

                //Display results
                cout << "Filter: " << brand << "\n\n";
                for(const auto& wheels : filteredList){
                    cout << "Wheels Key: " << wheels.getKey() << endl;
                    cout << "Info: " << wheels.getBrand() << ", " << wheels.getName() << ", " << wheels.getSize() << "\n\n";
                }
                
            }

            void filterSize(string size){
                list<Wheels> filteredList;
                for(const auto& [key, wheels] : wheelsMap){
                    if(wheels.getSize() == size){
                        filteredList.push_back(wheels);
                    }
                }

                //Display results
                cout << "Filter: " << size << "\n\n";
                for(const auto& wheels : filteredList){
                    cout << "Wheels Key: " << wheels.getKey() << endl;
                    cout << "Info: " << wheels.getBrand() << ", " << wheels.getName() << ", " << wheels.getSize() << "\n\n";
                }
            }         
};

class Bearings{
    private:
        string name;

    public:
        Bearings(){ //Default Constructor

        }

        Bearings(string name){
            this->name = name;
        }

        string getName() const{
            return name;
        }

        void print(){ //Used for testing
            cout << "Name: " << name << endl;
            cout << endl;
        }
};

class BearingsHashTable{
    private:
        unordered_map<string, Bearings> bearingsMap;

    public:
        BearingsHashTable(){
            //Fill HashTable
            bearingsMap = {
                {"Bones_Reds", Bearings("Bones REDS")},
                {"Bones_Swiss", Bearings("Bones Swiss")},
                {"ShakeJunt", Bearings("Shake Junt")},
                {"DGK", Bearings("DGK")}
            };
        }

        Bearings getBearings(string key){
            return bearingsMap.at(key);
        }

        void display(){
            cout << "Bearings Inventory: file:///Users/kevintownsend/SkateWebsite/Bearings_Inventory.html" << "\n\n";
            for(const auto&[key, bearings] : bearingsMap){
                cout << "Key: " << key << ", ";
                cout << "Info: " << bearings.getName() << "\n\n";
            }
        }

        bool inTable(string input){
                for(const auto& [key, bearings] : bearingsMap){
                    if(input == key){
                        return true;
                    }
                }
                return false;
            }
};

class Griptape{
    private:
        string name;

    public:
        Griptape(){ //Default Constructor

        }

        Griptape(string name){
            this->name = name;
        }

        string getName() const{
            return name;
        }

        void print(){
            cout << "Name: " << name << endl;
            cout << endl;
        }
};

class GriptapeHashTable{
    private:
        unordered_map<string, Griptape> griptapeMap;

    public:
        GriptapeHashTable(){
            //Fill HashTable
            griptapeMap = {
                {"Grizzly", Griptape("Grizzly")},
                {"Mob", Griptape("Mob")},
                {"Primitive", Griptape("Primitive")},
                {"Thrasher", Griptape("Thrasher")}
            };
        }
        
        Griptape getGriptape(string key){
            return griptapeMap.at(key);
        }

        void display(){
            cout << "Griptape Inventory: file:///Users/kevintownsend/SkateWebsite/Griptape_Inventory.html" << "\n\n";
            for(const auto&[key, griptape] : griptapeMap){
                cout << "Key: " << key << ", ";
                cout << "Info: " << griptape.getName() << "\n\n";
            }
        }

        bool inTable(string input){
                for(const auto& [key, griptape] : griptapeMap){
                    if(input == key){
                        return true;
                    }
                }
                return false;
            }
};

class AssemblyLine{
    private:
    
    public:
        Deck chooseDeck(){
            DeckHashTable deckTable;
            string input;

            while(true){
                //Main Menu that displays all the decks
                cout << "\n";
                deckTable.display();
                cout << "Type the deck key or select a filter" << endl;
                cout << "Type '1' to filter by brand" << endl;
                cout << "Type '2' to filter by size" << endl;
                cin >> input;
                cout << "\n";

                //Checks for valid input
                while(!deckTable.inTable(input) && input != "1" && input != "2"){
                    cout << "Invalid Input!" << endl;
                    cout << "Type the deck key or select a filter" << endl;
                    cout << "Type '1' to filter by brand" << endl << "Type '2' to filter by size" << endl;
                    cin >> input;
                    cout << "\n";
                }

                //Returns Deck
                if(deckTable.inTable(input)){
                    
                    return deckTable.getDeck(input);
                }

                //Brand Filter Option
                else if(input == "1"){
                    while(true){
                        cout << "Enter the brand name: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string brand;
                        cin >> brand;
                        cout << "\n";
                        
                        if(brand == "0"){ //Returns to display of all decks
                            break;
                        }
                        else if(!deckTable.hasBrand(brand)){ //Checks if brand exists in hashtable
                            cout << "Brand not recognizable, try again" << endl;
                            deckTable.displayBrands();
                            continue;
                        }
                        else{
                            deckTable.filterBrand(brand); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Deck (type deck key): " << endl;
                            cout << "Enter '0' to select a different brand" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different brand
                                break;
                            }
                            else if(!deckTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{ 
                                
                                return deckTable.getDeck(input);
                            }
                        }
                    }
                }

                //Size Filter Option
                else if(input == "2"){
                    while(true){
                        cout << "Enter Size: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string size;
                        cin >> size;
                        cout << "\n";
                        
                        if(size == "0"){ //Returns to display of all decks
                            break;
                        }
                        else if(!deckTable.hasSize(size)){ //Checks if brand exists in hashtable
                            cout << "Size not recognizable, try again" << endl;
                            deckTable.displaySizes();
                            continue;
                        }
                        else{
                            deckTable.filterSize(size); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Deck (type deck key): " << endl;
                            cout << "Enter '0' to select a different size" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different brand
                                break;
                            }
                            else if(!deckTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{ 
                                
                                return deckTable.getDeck(input);
                            }
                        }
                    }
                }
            }
        }

        Trucks chooseTrucks(){
            TrucksHashTable trucksTable;
            string input;

            while(true){
                //Main Menu that displays all the trucks
                cout << "\n";
                trucksTable.display();
                cout << "Type the trucks key or select a filter" << endl;
                cout << "Type '1' to filter by brand" << endl;
                cout << "Type '2' to filter by size" << endl;
                cin >> input;
                cout << "\n";

                //Checks for valid input
                while(!trucksTable.inTable(input) && input != "1" && input != "2"){
                    cout << "Invalid Input!" << endl;
                    cout << "Type the trucks key or select a filter" << endl;
                    cout << "Type '1' to filter by brand" << endl << "Type '2' to filter by size" << endl;
                    cin >> input;
                    cout << "\n";
                }

                //Returns Trucks
                if(trucksTable.inTable(input)){
                    return trucksTable.getTrucks(input);
                }

                //Brand Filter Option
                else if(input == "1"){
                    while(true){
                        cout << "Enter the brand name: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string brand;
                        cin >> brand;
                        cout << "\n";
                        
                        if(brand == "0"){ //Returns to display of all trucks
                            break;
                        }
                        else if(!trucksTable.hasBrand(brand)){ //Checks if brand exists in hashtable
                            cout << "Brand not recognizable, try again" << endl;
                            trucksTable.displayBrands();
                            continue;
                        }
                        else{
                            trucksTable.filterBrand(brand); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Trucks (type trucks key): " << endl;
                            cout << "Enter '0' to select a different brand" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different brand
                                break;
                            }
                            else if(!trucksTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{ 
                                return trucksTable.getTrucks(input);
                            }
                        }
                    }
                }

                //Size Filter Option
                else if(input == "2"){
                    while(true){
                        cout << "Enter Size: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string size;
                        cin >> size;
                        cout << "\n";
                        
                        if(size == "0"){ //Returns to display of all trucks
                            break;
                        }
                        else if(!trucksTable.hasSize(size)){ //Checks if size exists in hashtable
                            cout << "Size not recognizable, try again" << endl;
                            trucksTable.displaySizes();
                            continue;
                        }
                        else{
                            trucksTable.filterSize(size); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Trucks (type trucks key): " << endl;
                            cout << "Enter '0' to select a different brand" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different size
                                break;
                            }
                            else if(!trucksTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{                         
                                return trucksTable.getTrucks(input);
                            }
                        }
                    }
                }
            }
        }

        Wheels chooseWheels(){
            WheelsHashTable wheelsTable;
            string input;

            while(true){
                //Main Menu that displays all the Wheels
                cout << "\n";
                wheelsTable.display();
                cout << "Type the wheels key or select a filter" << endl;
                cout << "Type '1' to filter by brand" << endl;
                cout << "Type '2' to filter by size" << endl;
                cin >> input;
                cout << "\n";

                //Checks for valid input
                while(!wheelsTable.inTable(input) && input != "1" && input != "2"){
                    cout << "Invalid Input!" << endl;
                    cout << "Type the wheels key or select a filter" << endl;
                    cout << "Type '1' to filter by brand" << endl << "Type '2' to filter by size" << endl;
                    cin >> input;
                    cout << "\n";
                }

                //Returns Wheels
                if(wheelsTable.inTable(input)){                   
                    return wheelsTable.getWheels(input);
                }

                //Brand Filter Option
                else if(input == "1"){
                    while(true){
                        cout << "Enter the brand name: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string brand;
                        cin >> brand;
                        cout << "\n";
                        
                        if(brand == "0"){ //Returns to display of all Wheels
                            break;
                        }
                        else if(!wheelsTable.hasBrand(brand)){ //Checks if brand exists in hashtable
                            cout << "Brand not recognizable, try again" << endl;
                            wheelsTable.displayBrands();
                            continue;
                        }
                        else{
                            wheelsTable.filterBrand(brand); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Wheels (type wheels key): " << endl;
                            cout << "Enter '0' to select a different brand" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different brand
                                break;
                            }
                            else if(!wheelsTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{                                 
                                return wheelsTable.getWheels(input);
                            }
                        }
                    }
                }

                //Size Filter Option
                else if(input == "2"){
                    while(true){
                        cout << "Enter Size: " << endl;
                        cout << "(Type '0' to go back)" << endl;
                        string size;
                        cin >> size;
                        cout << "\n";
                        
                        if(size == "0"){ //Returns to display of all Wheels
                            break;
                        }
                        else if(!wheelsTable.hasSize(size)){ //Checks if size exists in hashtable
                            cout << "Size not recognizable, try again" << endl;
                            wheelsTable.displaySizes();
                            continue;
                        }
                        else{
                            wheelsTable.filterSize(size); //Applies the filter
                        }
                        
                        while(true){
                            cout << "Select Wheels (type wheels key): " << endl;
                            cout << "Enter '0' to select a different size" << endl;
                            cin >> input;
                            cout << "\n";
                            
                            if(input == "0"){ //Takes user back to choose a different size
                                break;
                            }
                            else if(!wheelsTable.inTable(input)){ //Checks if the input is correct
                                cout << "Invalid input, try again" << endl;
                                continue;   
                            }
                            else{                                 
                                return wheelsTable.getWheels(input);
                            }
                        }
                    }
                }
            }
        }

        Bearings chooseBearings(){
            BearingsHashTable bearingsTable;
            string input;

            //Main Menu that displays all the Bearings
                cout << "Choose your Bearings: " << "\n\n";
                bearingsTable.display();
                cout << "Type the bearings key" << endl;
                cin >> input;
                cout << "\n";

                //Checks for valid input
                while(!bearingsTable.inTable(input)){
                    cout << "Invalid Input, try again" << endl;
                    bearingsTable.display();
                    cin >> input;
                    cout << "\n";
                }

                //Returns Bearings            
                return bearingsTable.getBearings(input);
                
        }

        Griptape chooseGriptape(){
            GriptapeHashTable griptapeTable;
            string input;

            //Main Menu that displays all the Griptape
                cout << "Choose your Griptape: " << "\n\n";
                griptapeTable.display();
                cout << "Type the griptape key" << endl;
                cin >> input;
                cout << "\n";

                //Checks for valid input
                while(!griptapeTable.inTable(input)){
                    cout << "Invalid Input, try again" << endl;
                    griptapeTable.display();
                    cin >> input;
                    cout << "\n";
                }

                //Returns Bearings               
                return griptapeTable.getGriptape(input);       
        }
};


class Board{
    private:
        Deck deck;
        Trucks trucks;
        Wheels wheels;
        Bearings bearings;
        Griptape griptape;

    public:
      
        void build() {
            AssemblyLine line;
            

            while (true) {
                int currentStep;
                currentSetup();
                cout << "Current Step: " << currentStep << endl;

                cout << "Choose a step to continue:" << endl;
                cout << "1. Choose Deck" << endl;
                cout << "2. Choose Trucks" << endl;
                cout << "3. Choose Wheels" << endl;
                cout << "4. Choose Bearings" << endl;
                cout << "5. Choose Griptape" << endl;
                cout << "Enter the step number or '0' to exit: ";
                cin >> currentStep;

                if (currentStep == 0) {
                    cout << "Exiting assembly." << endl;
                    break;
                }

                switch (currentStep) {
                    case 1:
                        cout << "Step 1: Choose your Deck." << "\n\n";
                        deck = line.chooseDeck();
                        cout << "Selected Deck: " << deck.getKey() << endl;
                        break;

                    case 2:
                        cout << "Step 2: Choose your Trucks." << "\n\n";
                        trucks = line.chooseTrucks();
                        cout << "Selected Trucks: " << trucks.getKey() << endl;;
                        break;

                    case 3:
                        cout << "Step 3: Choose your Wheels." << "\n\n";
                        wheels = line.chooseWheels();
                        cout << "Selected Wheels: " << wheels.getKey() << endl;
                        break;

                    case 4:
                        cout << "Step 4: Choose your Bearings." << "\n\n";
                        bearings = line.chooseBearings();
                        cout << "Selected Bearings: " << bearings.getName() << endl;
                        break;

                    case 5:
                        cout << "Step 5: Choose your Griptape." << "\n\n";
                        griptape = line.chooseGriptape();
                        cout << "Selected Griptape: " << griptape.getName() << endl;
                        break;

                    default:
                        cout << "Invalid step number. Try again." << endl;
                }

                cout << "Would you like to jump to another step? (y/n): ";
                char choice;
                cin >> choice;
                while(choice != 'y' && choice != 'n'){
                    cout << "Invalid input, try again" << endl;
                    cin >> choice;
                }
                cout << "\n";
                if (choice == 'n' || choice == 'N') {
                    break;
                }
            }

            cout << "Assembly Complete!" << "\n\n";
        }

        void currentSetup(){
            cout << "Current Setup" << endl;
            cout << "Deck: " << deck.getKey() << endl;
            cout << "Trucks: " << trucks.getKey() << endl;
            cout << "Wheels: " << wheels.getKey() << endl;
            cout << "Bearings: " << bearings.getName() << endl;
            cout << "Griptape: " << griptape.getName() << "\n\n";
        }

        void display(){
            cout << "Here's your complete!" << endl;
            cout << "Deck: " << deck.getBrand() << ", " << deck.getName() << ", " << deck.getSize() << endl;
            cout << "Trucks: " << trucks.getBrand() << ", " << trucks.getName() << ", " << trucks.getSize() << endl;
            cout << "Wheels: " << wheels.getBrand() << ", " << wheels.getName() << ", " << wheels.getSize() << endl;
            cout << "Bearings: " << bearings.getName() << endl;
            cout << "Griptape: " << griptape.getName() << endl;
        }

        void info(){
            cout << "Deck: " << deck.getBrand() << ", " << deck.getName() << ", " << deck.getSize() << endl;
            cout << "Trucks: " << trucks.getBrand() << ", " << trucks.getName() << ", " << trucks.getSize() << endl;
            cout << "Wheels: " << wheels.getBrand() << ", " << wheels.getName() << ", " << wheels.getSize() << endl;
            cout << "Bearings: " << bearings.getName() << endl;
            cout << "Griptape: " << griptape.getName() << endl;
        }    
};


int main(){
    stack<Board> boardHistory;
    
    cout << "Welcome to Build-A-Board" << endl;
    cout << "- - - - - - - - - - - - -" << endl;
    while(true){
        cout << "Main Menu" << endl;
        cout << "1. Build a Skateboard" << endl;
        cout << "2. Recent Builds" << "\n\n";
        cout << "Insert Key: ";
        int num;
        cin >> num;
        cout << "\n";

        if(num == 1){
            Board board;
            board.build();
            boardHistory.push(board);
            board.display();
            cout << "\n";
            cout << "1 - Return to Main Menu" << endl;
            cout << "2 - End session " << endl;
            cout << "Insert Key: ";
            int input;
            cin >> input;
            cout << "\n";
            if(input == 1){
                continue;
            }
            else{
                cout << "See you next time!" << endl;
                break;
            }   
        }
        else if(num == 2){
            int input;
            while(input != 2){
                if(boardHistory.empty()){
                    cout << "No previous builds" << endl;
                    cout << "Returning to Main Menu" << "\n\n";
                    break;
                }
                else{
                    cout << "Previous Build: " << endl;
                    boardHistory.top().info();
                    cout << "\n"; 
                    cout << "1 - Remove this build and view another" << endl;
                    cout << "2 - Return to Main Menu" << endl;
                    cout << "Insert Key: ";
                    cin >> input;
                    cout << "\n";
                    if(input == 1){
                        boardHistory.pop();
                    }
                    else{
                        break;
                    }
                }   
            }
        }
    }
    return 0;
}