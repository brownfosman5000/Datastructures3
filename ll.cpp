#include <iostream>
#include <fstream>
using namespace std;

struct Node{
	Node *next;
	int quantity;
	double price;
	
	Node(){next=NULL;}
	
};

struct LinkedList{

	Node *front;
	Node *rear;
	
	LinkedList(){front = NULL; rear = NULL;}
	void push(Node*);
	bool empty();

};
bool LinkedList::empty(){
	if(front == NULL )
		return true;
	return false;

}
void LinkedList::push(Node *newnode){

	if(empty()){
		front = newnode;
		rear = newnode;
		cout<<"Added to list just started"<<endl;
	}

	else{
		rear->next = newnode; 
		rear = newnode;
		cout<<"Added to List"<<endl;
	}	

}

ifstream fin;
void widgetProcessing(LinkedList*);
void receiptProcessing(LinkedList*);
void SalesProcessing(int&);
void promotionProcessing();


int main(){
	LinkedList *list = new LinkedList;

	fin.open("data.txt");
	widgetProcessing(list);
	
	return 0;
}


void widgetProcessing(LinkedList *list){
	int counter = 0;
	string recordtype;

	while(fin){
		fin >> recordtype;
		if(recordtype == "R")
			receiptProcessing(list);

		else if(recordtype == "S")
			//salesProcessing(counter);
			break;
		else if(recordtype == "P")
			break;
			//promotionProcessing();
	}
}



void receiptProcessing(LinkedList *list){
	Node *node = new Node;
	
	fin>>node->quantity;
	fin>>node->price;
	list->push(node);
	cout<<"Receipt Read in: Received: "<<node->quantity<<" Cost: "<<node->price<<endl;
}
