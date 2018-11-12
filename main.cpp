//Description: Takes a text file supplied by the user
//             and turns it into a word index, implemented
//             through the use of a BST 

#include <iostream>
#include <fstream>
#include "bst.cpp"
#include "23tree.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Choice saves the your next action is
	int choice;
    // Option decides if you'd like to use a 2-3 tree or BST
    char option;
    
	if (argc != 2) {
	    cout << "Incorrect input. Correct format: ./<exectuable.out> <inputtext.txt>\n";
	    return 1;
	}

	ifstream input(argv[1]);
	BST myTree;
    TwoThree newTree;

	if(input.is_open()){
        cout << "Options: (a) BST, (b) 2-3 Tree, (c) Compare BST and 2-3 Tree\n";
        cin >> option;
        // Doing a BST
        if (option == a){
            myTree.buildTree(input);
            input.close();
            while(1){
                choice = 0;
                cout <<"Options: (1) display index, (2) search, (3) save index, (4) quit\n";
                cin >> choice;

                //Print index
                if(choice == 1)
                    myTree.printTree(cout);
	       
                //Search index for a word
                else if(choice == 2)
                    myTree.contains();

                //Save index
                else if(choice == 3){
                string outputFile;
                    cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
                cin >> outputFile;
                ofstream output(outputFile.c_str());
                    myTree.printTree(output);
                    output.close();
                cout << "Saved\n";
                }

                //Quit
                else
                    break;
                }
        }
        // Doing a Two-Three Tree
        else if(option == b)
        {
            newTree.buildTree(input);
            input.close();
            while (1)
            {
                choice = 0;
                cout <<"Options: (1) display index, (2) search, (3) save index, (4) quit\n";
                cin >> choice;
                
                //Print index
                if(choice == 1)
                    newTree.printTree(cout);
                
                //Search index for a word
                else if(choice == 2)
                    newTree.contains();
                
                //Save index
                else if(choice == 3){
                    string outputFile;
                    cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
                    cin >> outputFile;
                    ofstream output(outputFile.c_str());
                    myTree.printTree(output);
                    output.close();
                    cout << "Saved\n";
                }
                //Quit
                else
                    break;
            }
                
        }
        else
        {
            cout << "we aint done" << endl;
        }
        
    }
	else
    {
	    cout << "Invalid File Name. Restart Program.\n";
	    return 2;
    }
	return 0;
}
