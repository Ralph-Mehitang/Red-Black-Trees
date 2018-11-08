#include <iostream>
#include "RBTree.h"
using namespace std;
/* Ralph Mehitang
	Joseph Anderson
	Cosc-320
	Red Black Tree lab

*/

void program_menu(){

int input, value;
RBTree tree;
    while (1)
    {
        cout<<"-----------------"<<endl;
        cout<<"Operations on Red Black Tree"<<endl;
        cout<<"-----------------"<<endl;
        cout<<"1.Insert Element "<<endl;
        //cout<<"2.Delete Element "<<endl;
        cout<<"2.Get Minimum "<<endl;
        cout<<"3.get Maximum "<<endl;
        cout<<"4.get Inorder Traversal "<<endl;
        cout<<"5.get successor "<<endl;
        cout<<"6.Display"<<endl;
        cout<<"7.Search "<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>input;
        switch(input)
        {
        case 1:
        int val;
            cout<<"Enter the number to be inserted : ";
            cin>>val;
            tree.insert(val);
            break;
        /*case 2:
            cout<<"Enter the number to be deleted : ";
            cin>>val;
            //test.remove(tmp,tmp->key);
            break;
            */
    
		case 2:
            cout<<"Minimum Value of BST: "<<tree.minimum()<<endl;
            cout<<endl;
            break;
        case 3:
            cout<<"Maximum value of BST: "<<tree.maximum()<<endl;
            cout<<endl;
            break;
        case 4:
            cout<<"Inorder Traversal:"<<endl;
            tree.inorder();
            cout<<endl;
            break;
        case 5:
            cout<<"successor: "<<tree.succesor()<<endl;
            break;
        case 6:
        		cout<<"printing RBTree"<<endl;
        		tree.inorder();
        		cout<<endl;
        break;
        case 7:
        exit(1);
        case 8:
            cout<<"Enter search value:"<<endl;
            cin>>value;
           // tree.search(value); //was leaking a lot decided to take out
            cout<<endl;
            break;
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
}

int main(){

	program_menu();
	return 0;
}