using namespace std;
#include "GT.h"
#include<iostream>
void displayMenu()
{
	cout << "Select an action to proceed!" << endl;
	cout << "----------------------------" << endl;
	cout << "[1] New" << endl;
	cout << "[2] Select Folder" << endl;
	cout << "[3] Back to Previous Folder" << endl;
	cout << "[4] Delete Children" << endl;
	cout << "[5] Rename Current" << endl;
	
	
}
void displayOption1Menu()
{
	cout << "Spacing will not be captured." << endl;
	cout << "[1] New Folder" << endl;
	cout << "[2] New Text File" << endl;
}
int main()
{
	GT fileExplorer;
	string directory;
	while (true)
	{
		displayMenu();
		string choice;
		cin >> choice;
		if (choice == "1") //Create a new file or folder 
		{
			displayOption1Menu();
			string choiceOfCreation;
			cin >> choiceOfCreation;
			if (choiceOfCreation == "1") //create a new folder under current node
			{
				string folderName;
				cout << "Enter Folder Name"<<endl;
				cin >> folderName;
				fileExplorer.insertFolder(folderName);
				
			}
			else if (choiceOfCreation == "2") //create a new file under current node
			{
				string fileName;
				cout << "Enter File Name" << endl;
				cin >> fileName;
				fileName = fileName + ".txt";
				fileExplorer.insertFolder(fileName);
			}
			
		}
		if (choice == "2") // Allow to traverse to the next node
		{
			string getItem;
			fileExplorer.showChildrenOfCurrentNode();
			cout << "Back"<<endl;
			cout << "Select an item...";
			cin >> getItem; cout << endl;
			if (getItem == "Back")
			{
				cout << "You are at the original folder." << endl;
			}
			else
			{
				fileExplorer.traverseToChild(getItem);
			}


		}
		if (choice == "3") //Traverse Backwards to the previous node
		{
			fileExplorer.traverseBackwards();
		}
		if (choice == "4")
		{
			string getItem;
			fileExplorer.showChildrenOfCurrentNode();
			cout << "Enter children to delete: " ;
			cin >> getItem;
			cout << endl;
			fileExplorer.deleteChildren(getItem);
		}
		if (choice == "5")
		{
			string updatedName;
			cout << "Enter updated name: ";
			cin >> updatedName;
			cout << endl;
			fileExplorer.updateCurrent(updatedName);
		}
	}


}