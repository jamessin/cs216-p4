cs216-p4
========

Porgram 4 Unsorted List


#include "UnsortedType.h"

int main()
{
  ifstream inFile;
  ofstream outFile;

  inFile.open("in.data");
  outFile.open("out.data");

  ItemType item;
  UnsortedType itemList;
  char command;

  itemList.MakeEmpty();
  outFile << "Student Report" << endl;
  outFile << "--------------" << endl;

  inFile >> command;

  while(command)
  {
   switch(command)
   {
    case 'A':
     item.GetItemFromFile(inFile);
     if(item.ValidItem())
     {
      if(!itemList.IsFull())
       itemList.InsertItem(item);
      else
       outFile << "List is full! No Insert!" << endl;
     }
    else
     item.WriteInvalidItemToFile(outFile);
   break;
    case 'D':
     if(!itemList.LengthIs() == 0)
      itemList.DeleteItem(item);
     else
      outFile << "List is empty! No Delete!" << endl;
    break;
    case 'P':
     if(!itemList.LengthIs() == 0)
      itemList.PrintList(outFile);
     else
      outFile << "List is empty! No Print!" << endl;
   break;
    case 'C':
     outFile << "Reached" << endl;
   break;
    case 'I':
     outFile << "Reached also" << endl;
   break;
    case 'G':
     outFile << "Reached again" << endl;
   break;
   }
    inFile >> command;
  }

outFile << "End of report" << endl;

return 0;
}


Input Sample
============
A 444 Zoom,Joe 3.33 CS M
A 777 Green,Rose 2.75 IS F
A 1000 Loop,Sue 3.21 CS F
A 222 Hoow,David 2.88 IS M
D 222
A 666 Daryaa,Sam 3.54 IS M
A 999 Rumi,Naz 3.25 CS F
A 123 Lee,Jon 2.22 IS F
A 888 Sharp,Mike 3.33 CS M
P
C
I
G
