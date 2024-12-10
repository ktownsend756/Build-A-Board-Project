#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <map>

using namespace std;

class TrickTree{
    public:
        struct Node{
            string trick;
            vector<Node*> children;

            Node(string trick){
                this->trick = trick;
            }
        };

        //Constructor
        Node *ollie;
        TrickTree(){
            ollie = nullptr;
        }

        //Destructor
        ~TrickTree(){
            deleteTree(ollie);
        }

        void display(){
            cout << "Trick Tree" << "\n\n";
            displayNode(ollie, 0); 
        }

        void initializeTree(){
            ollie = new Node("Ollie");

            // Add children to the root
            Node* shuvit = addChild(ollie, "Shuvit");
            Node* fs_shuvit = addChild(ollie, "Frontside Shuvit");
            Node* bs_180 = addChild(ollie, "Backside 180");
            Node* fs_180 = addChild(ollie, "Frontside 180");
            Node* kickflip = addChild(ollie, "Kickflip");
            Node* heelflip = addChild(ollie, "Heelflip");


            //Adds tricks to child tricks
            //Basic branches
            //Shuvit Branch
            Node* three_shuv = addChild(shuvit, "360 Shuvit");
            Node* bs_bigspin = addChild(shuvit, "Backside Bigspin");
            addChild(shuvit, "Varial Kickflip");
            addChild(shuvit, "Inward Heelflip");
            //Frontside Shuvit Branch
            Node* fs_three_shuv = addChild(fs_shuvit, "Frontside 360 Shuvit");
            Node* fs_bigspin = addChild(fs_shuvit, "Frontside Bigspin");
            addChild(fs_shuvit, "Hardflip");
            addChild(fs_shuvit, "Varial Heelflip");
            //Backside 180 Branch
            addChild(bs_180, "Backside Flip");
            addChild(bs_180, "Backside Heel");
            Node* bs_360 =  addChild(bs_180, "Backside 360");
            addChild(bs_180, "Backside Bigspin");
            //Frontside 180 Branch
            addChild(fs_180, "Frontside Flip");
            addChild(fs_180, "Frontside Heel");
            Node* fs_360 =  addChild(fs_180, "Frontside 360");
            addChild(fs_180, "Frontside Bigspin");
            //Kickflip Branch
            Node* varial_kickflip = addChild(kickflip, "Varial Kickflip");
            Node* hardflip = addChild(kickflip, "Hardflip");
            Node* bs_flip = addChild(kickflip, "Backside Flip");
            Node* fs_flip = addChild(kickflip, "Frontside Flip");
            //Heelflip Branch
            Node* varial_heelflip = addChild(heelflip, "Varial Heelflip");
            Node* inward_heelflip = addChild(heelflip, "Inward HeelFlip");
            Node* bs_heel = addChild(heelflip, "Backside Heel");
            Node* fs_heel = addChild(heelflip, "Frontside Heel");

            //Advanced Branches
            //Three Shuv Branch
            Node* treflip = addChild(three_shuv, "Treflip");
            //BackSide Bigspin Branch
            Node* bs_biggerspin = addChild(bs_bigspin, "Backside Biggerspin");
            Node* bigflip = addChild(bs_bigspin, "Big Flip");
            //FS Three Shuv Branch
            Node* laserflip = addChild(fs_three_shuv, "Laserflip");
            //Frontside Bigspin Branch
            Node* fs_biggerspin = addChild(fs_bigspin, "Frontside Biggerspin");
            Node* bigheel= addChild(fs_bigspin, "Big Heel");
            //Backside 360 Branch
            Node* bs_360flip = addChild(bs_360, "Backside 360Flip");
            Node* bs_360heel = addChild(bs_360, "Backside 360Heel");
            //Frontside 360 Branch
            Node* fs_360flip = addChild(fs_360, "Frontside 360Flip");
            Node* fs_360heel = addChild(fs_360, "Frontside 360Heel");
            //Varial Kickflip Branch
            addChild(varial_kickflip, "Treflip");
            //Hardflip Branch
            Node* threesixty_hardflip = addChild(hardflip, "360 Hardflip");
            //Backsideflip Branch
            addChild(bs_flip, "Backside 360Flip");
            //FrontsideFlip Branch
            addChild(fs_flip, "Frontside 360Flip");
            //Varial Heelflip Branch
            addChild(varial_heelflip, "Laserflip");
            //Inward Heelflip Branch
            Node* threesixty_inward_heel = addChild(inward_heelflip, "360 Inward Heelflip");
            //BacksideHeel Branch
            addChild(bs_heel, "Backside 360Heel");
            //FrontsideHeel Branch
            addChild(fs_heel, "Frontside 360Heel");
        }

        
    
    private:
        Node* addChild(Node* parent, const string& trick) {
            Node* child = new Node(trick);
            parent->children.push_back(child);
            return child;
        }

        void displayNode(Node* node, int level) {
            if(!node){ //Checks if tree is empty
                return;
            } 

            for (int i = 0; i < level; ++i){ //Loop to make the display look better
                cout << "       "; 
            }

            cout << node->trick;
            if(!node->children.empty()){
                cout << " -->";
            }
            cout << "\n";

            // Display children
            for (Node* child : node->children) {
                displayNode(child, level + 1);
            }
        }

        void deleteTree(Node* node) {
            if (!node){ //Checks if tree is empty
                return;
            } 

            for (Node* child : node->children) {
                deleteTree(child);
            }
            delete node;
        }
};

class TrickGraph{
    map<string, list<string> > adjList;

    public:
       void addEdge(string trick_type, string trick){
            adjList[trick_type].push_back(trick);
       }

       void print(){
            cout << "Trick Types: " << "\n\n";
            
            for (auto i : adjList) {
                
                cout << i.first << " -> ";
                
                for (auto j : i.second) {
                    
                    cout << j << ", ";
                }
                cout << "\n\n";
            }
        }

        void initializeGraph(){
            //Trick Types:
            //Spins
            addEdge("Spins", "Shuv-it");
            addEdge("Spins", "Frontside Shuv-it");
            addEdge("Spins", "360 Shuv-it");
            addEdge("Spins", "360 Frontside Shuv-it");

            //Body Varial
            addEdge("Body Varial", "Backside 180");
            addEdge("Body Varial", "Frontside 180");
            addEdge("Body Varial", "Backside 360");
            addEdge("Body Varial", "Frontside 360");

            //Flips
            addEdge("Flips", "KickFlip");
            addEdge("Flips", "Double KickFlip");
            addEdge("Flips", "HeelFlip");
            addEdge("Flips", "Double HeelFlip");

            //Spins & Flips
            addEdge("Flips w/ Spins", "Varial Kickflip");
            addEdge("Flips w/ Spins", "Varial Heelflip");
            addEdge("Flips w/ Spins", "Treflip");
            addEdge("Flips w/ Spins", "Laserflip");
            addEdge("Flips w/ Spins", "HardFlip");
            addEdge("Flips w/ Spins", "Inward Heelflip");
            addEdge("Flips w/ Spins", "360 Hardflip");
            addEdge("Flips w/ Spins", "360 Inward Heelflip");

            //Body Varial & Spins
            addEdge("Spins w/ Body Varial", "Backside Bigspin");
            addEdge("Spins w/ Body Varial", "Frontside Bigspin");
            addEdge("Spins w/ Body Varial", "Backside Biggerspin");
            addEdge("Spins w/ Body Varial", "Frontside Biggerspin");
            
            //Body Varial & Flips
            addEdge("Body Varial w/ Flip", "Backside Flip");
            addEdge("Body Varial w/ Flip", "Frontside Flip");
            addEdge("Body Varial w/ Flip", "360 Backside Flip");
            addEdge("Body Varial w/ Flip", "360 Frontside Flip");

            //Body Varial & Flips & Spins
            addEdge("Body Varial w/ Flip w/ Spin", "Big Flip");
            addEdge("Body Varial w/ Flip w/ Spin", "Big Heel");
            addEdge("Body Varial w/ Flip w/ Spin", "Bigger Flip");
            addEdge("Body Varial w/ Flip w/ Spin", "Bigger Heel");
            


            
        }

};

int main(){
    TrickGraph tricks;
    tricks.initializeGraph();
    tricks.print();
    
    
    /*
    TrickTree trickTree;
    trickTree.addEdge("Ollie", "Shuv-it");
    trickTree.addEdge("Ollie", "Fs 180");
    trickTree.addEdge("Ollie", "BS 180");
    trickTree.addEdge("Ollie", "Kickflip");
    trickTree.addEdge("Kickflip", "Varial Kickflip");
    trickTree.addEdge("Shuv-it", "Varial Kickflip");
    */

   /*
    trickTree.print();
    */
    return 0;
}