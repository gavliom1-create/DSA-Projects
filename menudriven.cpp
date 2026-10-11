#include<iostream>
using namespace std;

class song{
	public:
		song *prev;
		song *next;
		string title;
		string artist;
		
		song(string x,string y)
		{
			prev=NULL;
			next=NULL;
			title=x;                     
			artist=y;
		}
};

class playlist{
	private:
		song *head;
	public:
		song *current;
		
		playlist()
		{
		head=NULL;
		current=NULL;
		}
		
		int empty()
		{
			if(head==NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		void insert(string x,string y)
		{
			song *p=new song(x,y);
			if(empty())
			{
				head=p;
				current=head;
			}
			else
			{
				song *q=head;
		    	while(q->next!=NULL)
		    	{
		    		q=q->next;
				}
				q->next=p;
				p->prev=q;
			}
		}
		
		void remove(string x)
		{
			song *q,*p;
			q=head;
			if(q->title==x)
			{
				{
				p=head;
				head=head->next;
				head->prev=NULL;
				delete p;
				return;
			    }
			while(q->next!=NULL)
			{
				if(q->next->title==x)
				{
					p=q->next;
					q->next=p->next;
					p->next=q;
					delete p;
					return;
				}
				q = q->next;
			}
			}
			else
			{
				cout<<"Song"<<" '"<<x<<"'"<<" Not Found in playlist"<<endl;
			}
	   	}
	   	
	   	void play(string x)
	   	{
	   		if(current==NULL)
	   		{
                cout << "Playlist is empty" << endl;
                return;
			}
	   		else
	   		{
			   if(x=="next")
	   		    {
	   			if(current->next==NULL)	
	   			{
	   				cout<<"Last Song (Can not play next)"<<endl;
				}
				else
				{
					current=current->next;
				}
			}
			
			else if(x=="previous")
			{
				if(current->prev==NULL)
				{
					cout<<"First Song (Can not play previous)"<<endl;
				}
				else
				{
					current=current->prev;
				}
			}
			cout<<"Current Song playing:"<<current->title<<endl;        //current song playing/showing..(x==current)..directly
			}
		}
		
		void displayforward()
		{
			song *q=head;
			cout<<"Forward Display: "<<endl;
			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
			    q=q->next;
			}
     	}
		 
		void displaybackward()
		{
			song *q=head;
			cout<<"Backward Display:"<<endl;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
				q=q->prev;
			}
		}
};

int main()
{
    playlist pl;
    int choice;
    string title, artist;

    do
    {
        cout << "===== MUSIC PLAYLIST =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Display Playlist in Forward" << endl;
        cout << "4. Display Playlist in Reverse" << endl;
        cout << "5. Play Current Song" << endl;
        cout << "6. Play Next Song" << endl;
        cout << "7. Play Previous Song" << endl;
        cout << "8. Play Complete Playlist" << endl;
        cout << "9. Repeat All" << endl;
        cout << "10. Show Current Song" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;cout<<endl;
        
        switch(choice)
        {
            case 1:
                cout << "Enter song title: ";cin >> title;
                cout << "Enter artist name: ";cin >> artist;
                pl.insert(title, artist);
                break;

            case 2:
                cout << "Enter song title to delete: ";
                cin >> title;
                pl.remove(title);
                break;

            case 3:
                pl.displayforward();
                break;
                cout<<endl;

            case 4:
                pl.displaybackward();
                break;

            case 5:
                pl.play("current");       // Play current song
                break;

            case 6:
                pl.play("next");     // Play next song
                break;

            case 7:
                pl.play("previous");    // Play previous song
                break;

            case 8:
                // Play complete playlist
                break;

            case 9:
                // Repeat all
                break;

            case 10:
                pl.play("current");     // Show current song
                break;

            case 11:
                cout << "Exiting..." << endl;             //exiting from menu
                break;

            default:
                cout << "Invalid choice!" << endl;
        }
        cout<<endl;

    } while(choice != 11);

    return 0;
}
