#include <string>
struct date{
	int day,month,year,hour,min;
};

class Post{
	public :
		//Post();
		Post(std::string, std::string, std::string);
		~Post();
				
		int get_id();
		std::string get_author();
		void print();
		
	private :
		int id;
		std::string title;
		std::string author;
		date creation_date;
		std::string text;

		static int ID_COUNTER;
};

class Thread{
	public:
		Thread();
		Thread(std::string, std::string);
		~Thread();
		
		void print();
		std::string get_subject();
		Post* getPosts();
		
		
	private:
		std::string subject;
		std::string author;
		date creation_date;
		Post posts[5];   //5 posts per thread 

		
};

class Forum{
	public:
		Forum(std::string);
		~Forum();
		void print();
		void select(std::string);  
		void select(int);

		#ifdef USE_BT
		void print_sorted();
		#endif
		
	private:
		std::string title;
		Thread threads[5] = {Thread("Rules and useful information","system")};  //5 threads per forum
};																				//also threads[0] is always 'Rules and useful information'   


