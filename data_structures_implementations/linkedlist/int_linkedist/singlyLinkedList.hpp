struct node
{
	int data;
	node* next;
};

class linkedList {
	private:
		node* head;

	public:
		linkedList();
		node* createNode(int num);
		void append(int num);
		void addAsFirst(int num);
		void addAfter(int data_in_node, int data_to_insert);
		void addBefore(int data_in_node, int data_to_insert);
		void addAfterPosition(int position, int num);
		void delNode(int num);
		void delAfter(int num);
		void delBefore(int num);
		bool search(int num);
		void del(int num);
		void display();
		int count();
		void swapTwoAdjacent(int num1, int num2);
		~linkedList();	
};


