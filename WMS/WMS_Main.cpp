using namespace std;
#include "GT.h"
#include "Dictionary.h"
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
	cout << "[6] Search for Folder/File (Global)" << endl;
	cout << endl;
	
}
void displayOption1Menu()
{
	cout << "\nSpacing will not be captured.\n" << endl;
	cout << "[1] New Folder" << endl;
	cout << "[2] New Text File" << endl;
	cout << endl;
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
				cout << "\nEnter Folder Name: ";
				cin >> folderName;
				cout << endl;
				fileExplorer.insertFolder(folderName);
				
			}
			else if (choiceOfCreation == "2") //create a new file under current node
			{
				string fileName;
				cout << "\nEnter File Name: ";
				cin >> fileName;
				cout << endl;
				fileName = fileName + ".txt";
				fileExplorer.insertFolder(fileName);
			}
			
		}
		if (choice == "2") // Allow to traverse to the next node
		{
			string getItem;
			fileExplorer.showChildrenOfCurrentNode();
			cout << "Back"<<endl;
			cout << "\nSelect an item...";
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
			cout << "\nEnter children to delete: " ;
			cin >> getItem;
			cout << endl;
			fileExplorer.deleteChildren(getItem);
		}
		if (choice == "5")
		{
			string updatedName;
			cout << "\nEnter updated name: ";
			cin >> updatedName;
			cout << endl;
			fileExplorer.updateCurrent(updatedName);
		}
		if (choice == "6")	//Search and display paths of file/folder 
		{
			string name;
			cout << "\nEnter file/folder name: ";
			cin >> name;
			cout << endl;
			fileExplorer.searchFile(name);
		}
	}
}




//int main()
//{
//	Dictionary d;
//	string array[4] = { "john1.txt", "john1.txt", "john5.txt", "john5.txt" };
//	for (string s : array)
//	{
//		d.add(s, "root/" + s);
//	}
//
//	d.print();
//	cout << endl;
//
//	//
//	//string array[5] = { "john1.txt", "john2.txt", "john3.txt", "john4.txt", "john5.txt" };
//
//	//for (string s : array)
//	//{
//	//	d.add(s, "root/" + s);
//	//}
//	//d.add("john5.txt", "root/testPath");
//	//d.add("john5.txt", "root/testPath2");
//	//cout << "Test Case 1: Showing of all items" << endl;
//	//d.print();
//	//cout << endl;
//	////cout << d.get("john5.txt");
//	//cout << "Test Case 2: Showing of all paths in selected filename" << endl;
//	//for (auto x : d.getList("john5.txt"))
//	//{
//	//	cout << x << endl;
//	//}
//	//cout << endl;
//
//	///*d.remove("john5.txt", "root/john5.txt");
//	//cout << "Test Case 3: Deletion of john5.txt with path value of root/john5.txt" << endl;
//	//d.print();
//	//cout << endl;*/
//	//d.rehash();
//	//cout << "Test Case 4: Showing of all items after rehash" << endl;
//	//d.print();
//	//cout << endl;
//	//d.update("john3.txt", "root/john3.txt", "john5.txt", "root/john5.txt");
//	//d.print();
//
//
//
//	return 0;
//}