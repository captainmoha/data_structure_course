template <class T>

struct node
{
	T data;
	node<T> *next;
};

class stack {
	private:
		int top;
		node<T> *head;

	public:
		stack();
		void push(T data);
		T pop();
		void display();
		~stack();
};

stack<T>::stack() {
	head = NULL;
	top = -1;
}

stack<T>::push(T data) {
	
}


stack<T>::~stack() {

}