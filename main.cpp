//Description: Takes a text file supplied by the user
//             and turns it into a word index, implemented
//             through the use of a BST 

#include <iostream>
#include <fstream>
#include "bst.cpp"
using namespace std;

int main(int argc, char* argv[]) {
	char treechoice; //saves next action
	int choice; 

	// if user does not have correct inputs
	if (argc != 2) {
	    cout << "Incorrect input. Correct format: ./<exectuable.out> <inputtext.txt>\n";
	    return 1;
	}

	cout << "Options: (a) BST, (b) 2-3 Tree, (c) Compare BST and 2-3 Tree\n";
	cin >> treechoice;

	switch(treechoice){
	// BST
	case 'a':
	{
		ifstream input(argv[1]);
		BST newBST;
		if(input.is_open()){
            newBST.buildTree(input);
            input.close();
            while(1){
	        	choice = 0;
	        	cout <<"BST options: (1) display index, (2) search, (3) save index, (4) quit\n";
	        	cin >> choice;
				//Print index
	        	if(choice == 1)
	            	newBST.printTree(cout);
	       
				//Search index for a word
				else if(choice == 2)
	            	newBST.contains();

				//Save index
	    		else if(choice == 3){
		    		string outputFile;
	        		cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
		    		cin >> outputFile;
		   		 	ofstream output(outputFile.c_str());
	        		newBST.printTree(output);
	       		 	output.close();
		    		cout << "Saved\n";
	    		}
	    		// Quit
	    		else
					break;
            } // end-while
        } //end-if
        break;
    } //end case a

    case 'b':
    {/*
    	ifstream input(argv[1]);
		TwoThree newTwoThree;
		if(input.is_open()){
            newTwoThree.buildTree(input);
            input.close();
            while(1){
	        	choice = 0;
	        	cout <<"2-3 Tree options: (1) display index, (2) search, (3) save index, (4) quit\n";
	        	cin >> choice;
				//Print index
	        	if(choice == 1)
	            	newTwoThree.printTree(cout);
	       
				//Search index for a word
				else if(choice == 2)
	            	newTwoThree.contains();

				//Save index
	    		else if(choice == 3){
		    		string outputFile;
	        		cout << "Enter a filename to save your index to (Suggested: <filename>.txt) : ";
		    		cin >> outputFile;
		   		 	ofstream output(outputFile.c_str());
	        		newTwoThree.printTree(output);
	       		 	output.close();
		    		cout << "Saved\n";
	    		}
	    		// Quit
	    		else
					break;
            } // end-while
        } //end-if*/
        break;
    } //end case b

    case 'c':
    {
    	ifstream input(argv[1]);
    	BST newBST;
		//TwoThree newTwoThree;
		if(input.is_open()){
			newBST.timeTree(input);
            //newTwoThree.buildTree(input);
            input.close();
    	break;
    	}
	} //end case c


    default:{
    	cout << "Invalid File Name. Restart Program.\n";
	    return 2;
    	break;
    } //end default

	} //end switch



	return 0;
}
