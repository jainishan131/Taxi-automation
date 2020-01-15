#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include<windows.h>
#include<conio.h>
#undef __STRICT_ANSI__
#include<cmath>
#include<bits/stdc++.h>
using namespace std;

template <typename T>
T get_input(const string &strQuery);
string get_username();
string get_password();
string get_gender();
void save_user(const string &username, const string &password,const string &gender);
void login();
void register_user();
void main_menu();
int loggedIn();
template <typename T>
T get_input(const string &strQuery)
{
    cout << strQuery << "\n> ";
    T out = T();
    while (!(cin >> out))
    {
        cin.clear();
        cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        cout << "\t\t\t\t\tError!" "\n";
    }
    return out;
}
/////
string get_password()
{
    string password1 = get_input <string> ("\t\t\tPlease enter your password.");
    string password2 = get_input <string> ("\t\t\tPlease re-enter your password.");

    while (password1 != password2)
    {
        cout << "\t\t\t\t\tError! Passwords do not match." "\n";
        password1 = get_input <string>("\t\t\tPlease enter your password.");
        password2 = get_input <string>("\t\t\tPlease re-enter your password.");
    }
    return password1;
}

/////
string get_username()
{
    string username = get_input <string>("\t\t\tPlease enter a Username.");
    cout << "\t\t\tUsername: " << username << "\t\t";

    while (get_input <int>("\t\t\tIf you wish to confirm your Username please enter 1.") != 1)
    {
        username = get_input <string>("\t\t\tPlease enter a Username.");
        cout << "\t\t\tUsername: " << username << "\t\t";
    }
    return username;
}
/////
string get_gender()
{
    string gender = get_input <string>("\t\t\tPlease enter your gender");
    cout << "\t\t\tGender: " << gender << "\t\t";

    while (get_input <int>("\t\t\tIf you wish to confirm your gender please enter 1.") != 1)
    {
        gender = get_input <string>("\t\t\tPlease enter your gender.");
        cout << "\t\t\tGender: " << gender << "\t\t";
    }
    return gender;
}
struct lgdin{
string user;
string currloc;
string dest;
float x;
float y;
string gen;

}currli;
void login()
{
    string line = " ";
    ifstream readFile("userandpassword.txt");
    string UserName;
    string Password;
    string _UserName;
    string _Password;
    string _gender;
    cout << "\t\t\tEnter UserName: ";
    cin >> UserName;
    cout << "\t\t\tEnter Password: ";
    cin >> Password;

    bool found = false;

    while (getline(readFile,line))
    {
        stringstream iss(line);
        iss >> _UserName >> _Password >> _gender;
        if (UserName == _UserName && Password == _Password)
        {
            cout<<"\t\t\t\t\t\t";

            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout << "\t\t\t\t\tLogin Successful!"<< endl;
            currli.user=_UserName;
            currli.gen=_gender;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\t\t\t\t\tInvalid Username And Password"<< endl;
        cout<<"\t\t\t\tTo Register press 1 and for trying Logging again press 2"<<endl;
        int choice;
        cout<<"\t\t\t\t\t";
        A:
        cin>>choice;
        switch(choice)
        {
            case 1:
                register_user();
                break;
            case 2:
                login();
                break;
            default:
            cout<<"Wrong input. Please choose again.\n> ";
            goto A;
        }
    }
    else { int a;
    system("cls");
    a=loggedIn();}

}
/////
void main_menu()
{
    int choice = get_input <int>("\n\n\n\n\n\n\n"
        "\t\t\t\tHello, Would you like to Log in or Register?" "\n"
        "\t\t\t\t[1] Login" "\n"
        "\t\t\t\t[2] Register" "\n"
        "\t\t\t\t[3] Exit");
    B:
    switch (choice)
    {
        case 1:
            login();
            break;
        case 2:
            register_user();
            cout<<"\t\t\t\t\t\t";
            for(int i=0;i<5;i++)
            {
                cout<<".";
                Sleep(100);
            }
            cout<<endl;
            cout<<endl;
            cout<<endl;
            cout <<"\t\t\t\t\tRegistered Successfully!"<< endl;
            main_menu();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<"Wrong input. Please enter your choice again.\n> ";
            cin>>choice;
            goto B;

       //main_menu();
    }
}
/////
void register_user()
{
    string username = get_username();
    string password = get_password();
    string gender = get_gender();
    save_user(username, password,gender);
}
/////
void save_user(const string &username, const string &password , const string &gender)
{
    ofstream myfile;
    myfile.open ("userandpassword.txt",ios::app);
    myfile << username<< " "<< password<<" "<<gender;
    myfile<<'\n';
    myfile.close();
}/////
void gotoxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}
////
void Welcome_window()
{
    gotoxy(50,2);
    printf(R"(
              .----' `-----.
             //^^^^;;^^^^^^`\
     _______//_____||_____()_\________
    /826    :      : ___              `\
   |>   ____;      ;  |/\><|   ____   _<)
  {____/    \_________________/    \____}
       \ '' /                 \ '' /
        '--'                   '--'  )");
    gotoxy(5,12);
    Sleep(500);
    printf("Taxi Automation Scheduling System using Adaptive Real Time Shortest Path Algorithm involving women safety feature");
    gotoxy(45,15);
    Sleep(500);
    printf("DEVELOPED BY:-");
    gotoxy(45,16);
    Sleep(500);
    printf("(BATCH : B7/B8)");
    gotoxy(45,17);
    Sleep(500);
    printf("Ishan Jain");
    gotoxy(45,18);
    Sleep(500);
    printf("Harshit Singhal");
    gotoxy(45,19);
    Sleep(500);
    printf("Praduman Gupta");
    gotoxy(45,20);
    Sleep(500);
}
////////////////////////////////////////////////////////////////////
int result;
int E;
struct Edge
{
	int src, dest;
	double weight;
	int cond;
	int trafiic;
};

struct Vertex
{
    int Vid;
	double lat, lon;
};
struct driver
{
    string name;
    string gender;
    string cloc;
    string dloc;
    int cab_cond;
    int turns;
    bool running;
};
driver d[4];
// a structure to represent a connected, undirected
// and weighted graph
static double haversine(double lat1, double lon1, double lat2, double lon2)
{
        // distance between latitudes
        // and longitudes
        double dLat = (lat2 - lat1) *
                      M_PI / 180.0;
        double dLon = (lon2 - lon1) *
                      M_PI / 180.0;

        // convert to radians
        lat1 = (lat1) * M_PI / 180.0;
        lat2 = (lat2) * M_PI / 180.0;

        // apply formulae
        double a = pow(sin(dLat / 2), 2) +
                   pow(sin(dLon / 2), 2) *
                   cos(lat1) * cos(lat2);
        double rad = 6371;
        double c = 2 * asin(sqrt(a));
        return rad * c;
}

struct Graph
{
	// V-> Number of vertices, E-> Number of edges
	int V, E;

	// graph is represented as an array of edges.
	// Since the graph is undirected, the edge
	// from src to dest is also edge from dest
	// to src. Both are counted as 1 edge here.
	struct Edge* edge;
	struct Vertex* vert;
};

// Creates a graph with V vertices and E edges
struct Graph* createGraph(int V, int E)
{
	struct Graph* graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];
	graph->vert = new Vertex[V];

	return graph;
}

/*int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}
*/
int printSolution(int dist[], int V)
{
   cout<<"Vertex   Distance from Source\n";
   for (int i = 0; i < V; i++)
      cout<<i <<"tt"<< dist[i];
}


///////////////
class Pair
{
    public:
        string destination;
        float dist;
        int condition;
        Pair(string dest, float weight,int cond)
        {
            destination=dest;
            dist=weight;
            condition=cond;
        }
};
/////
class myComparator
{
    public:
        int operator() (Pair p1, Pair p2)
        {
            return p1.dist > p2.dist;
        }
};
int calculate_cost(map<string,float> distance, map<string,int> c_net)
{
    float mini=INT_MAX;
    float time[4];
    float c[4];
	for(int i=0;i<4;i++)
	{
		c[i]= (((((d[i].turns+1)*10) - c_net[d[i].cloc])*12)*distance[d[i].cloc]);
	}
	for(int i=0;i<4;i++)
	{
		time[i]=((distance[d[i].cloc]/d[i].cab_cond) + (d[i].turns*6) + c[i]);
	}

	int dir;
	for(int i=0;i<4;i++)
	{
		if(time[i] < mini && currli.gen==d[i].gender)
		{
			mini = time[i];
			dir = i;
		}
	}
	cout<<"\t\t\t\tETA of driver 0 is::   "<<time[0]/60<<endl;
	cout<<"\t\t\t\tETA of driver 1 is::   "<<time[1]/60<<endl;
	cout<<"\t\t\t\tETA of driver 2 is::   "<<time[2]/60<<endl;
    cout<<"\t\t\t\tETA of driver 3 is::   "<<time[3]/60<<endl;
    cout<<endl<<endl;
    cout<<"***************************************"<<"Driver will be at your location in: "<<(time[dir]/60)<<"***************************************\n\n\n";

	return dir;
}

class Gmap
{
    int V;
    map<string, list< Pair > > adjList;
    public:
        Gmap(int v)
        {
            V=v;
        }
        void addEdge(string src, string dest,float wt,int condition)
        {
            Pair p (dest,wt,condition);
            Pair k (src,wt,condition);
            adjList[src].push_back(p);
            adjList[dest].push_back(k);
        }
        void Validate_input(string &src,string &des)
        {
            if(( adjList.find(src) == adjList.end() ))
            {
                cout<<"\t\t\t\tSource Could Not be Found, Renter\n";
                string src1;
                cin>>src1;
                src=src1;
            }
            if(( adjList.find(des) == adjList.end() ))
            {
                cout<<"\t\t\t\tDestination Could Not be Found, Renter\n";
                string des1;
                cin>>des1;
                des=des1;
            }
        }
       /* void printAllPaths(string s, string d,int rate)
        {
            map<string,bool> visited;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                visited[it->first]=false;
            }
            string *path = new string[V];
            int path_index = 0;
            printAllPathsUtil(s, d, visited, path, path_index,0,0,rate);
        }*/
        float dijk(string src,string des,int i)
        {
             map<string ,float > distance;
            map<string,bool> visited;
            map<string, int> conditions;
            map<string,string> parent;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                distance[it->first] = INT_MAX;
                visited[it->first] = false;
            }
            distance[src]=0;
            conditions[src]=0;
            priority_queue<Pair,vector<Pair>, myComparator> Q;
            Pair P(src,distance[src],conditions[src]);
            Q.push(P);
            string last;
            while(!Q.empty())
            {
                Pair Temp=Q.top();
                Q.pop();
                string u=Temp.destination;last=Temp.destination;
                for(auto it=adjList[u].begin();it!=adjList[u].end();it++)
                {
                    Pair f = *it;
                    string v = f.destination;
                    float w = f.dist;
                    int cond=f.condition;
                    if(distance[u]+w<distance[v] && u!=des)
                    {
                        parent[v]=u;
                        distance[v]=distance[u]+w;
                        conditions[v]=conditions[u]+cond;
                        Pair L(v,distance[v],conditions[v]);
                        visited[u]=true;
                        Q.push(L);
                    }
                }
            }
            if(distance[des]==INT_MAX)
            {
                distance[des]=0;

            }
            string k=des;
            while(parent[k].compare(src)!=0 && k!=src)
            {
                k=parent[k];
                d[i].turns++;
            }

            return distance[des];
        }
        void Dijkstras(string src,string des)
        {
            /*to print the path having the shortest distance*/
            map<string ,float > distance;
            map<string,bool> visited;
            map<string, int> conditions;
            map<string,string> parent;
            for(auto it=adjList.begin();it!=adjList.end();it++)
            {
                distance[it->first] = INT_MAX;
                visited[it->first] = false;
            }
            distance[src]=0;
            conditions[src]=0;
            priority_queue<Pair,vector<Pair>, myComparator> Q;
            Pair P(src,distance[src],conditions[src]);
            Q.push(P);
            string last;
            while(!Q.empty())
            {
                Pair Temp=Q.top();
                Q.pop();
                string u=Temp.destination;last=Temp.destination;
                for(auto it=adjList[u].begin();it!=adjList[u].end();it++)
                {
                    Pair f = *it;
                    string v = f.destination;
                    float w = f.dist;
                    int cond=f.condition;
                    if(distance[u]+w<distance[v] && u!=des)
                    {
                        parent[v]=u;
                        distance[v]=distance[u]+w;
                        conditions[v]=conditions[u]+cond;
                        Pair L(v,distance[v],conditions[v]);
                        visited[u]=true;
                        Q.push(L);
                    }
                }
            }
            if(distance[des]==INT_MAX)
            {
                cout<<"\n\n\n\n\n\n\n";
                cout<<"\t\t\t\t\tNo Path between the source and the destination Exists, Sorry for the Inconvenience";
                exit(0);
            }
            cout<<"-----------------------------------SHORTEST ROUTE BETWEEN THE SORCE AND DESTINATION-----------------------------------"<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\tThe shortest distance between "<<src<<" and "<<des<< " is : "<<distance[des]<<" KM"<<endl;
            cout<<endl;
            cout<<endl;
           // cout<<"\t\t\tThe cost of Travel Inclusive of Taxes : Rs "<<distance[des]*rate<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\tSHORTEST path for DRIVERS are: "<<endl;
            cout<<endl;
            cout<<endl;
            cout<<"\t\t\t\t";
            string k;
            for(int i=0;i<4;i++)
            {
            k=d[i].cloc;
            if(d[i].running==false)
            {
            cout<<k<<"-->";
            while(parent[k].compare(src)!=0 && k!=src)
            {
                cout<<parent[k]<<" -->";
                k=parent[k];
                d[i].turns++;
            }
            cout<<src<<endl;
            cout<<"\t\t\t\t"<<"And the distance is "<<distance[d[i].cloc];

            cout<<endl;

            cout<<"\t\t\t\t";
            }
            else
            {
            cout<<k<<"<->";
            cout<<d[i].dloc<<"-->";
            k=d[i].dloc;
            while(parent[k].compare(src)!=0 && k!=src)
            {
                cout<<parent[k]<<" -->";
                k=parent[k];
                d[i].turns++;
            }
            d[i].turns++;
            cout<<src<<endl;
            float d2;
            d2=dijk(d[i].cloc,d[i].dloc,i);
            //cout<<distance[d[i].dloc];
            distance[d[i].dloc]+=d2;
            distance[d[i].cloc]=distance[d[i].dloc];
            cout<<"\t\t\t\t"<<"And the distance is "<<distance[d[i].dloc];

            cout<<endl;

            cout<<"\t\t\t\t";

            }
            }
            cout<<endl;
            result = calculate_cost(distance,conditions);
           /* if(conditions[des]<=-1)
                cout<<"\t\t\tThe travel conditions are Bad"<<endl;
            else if(conditions[des]==0)
                cout<<"\t\t\tThe travel conditions are Normal"<<endl;
            else
                cout<<"\t\t\tThe travel conditions are Good"<<endl;*/
           // return distance[des];
            /*for(auto it = distance.begin();it!=distance.end();it++)
            {
                cout<<'\t'<<'\t'<<'\t';
                cout<<it->first<<'\t'<<it->second<<endl;
            }*/
            cout<<endl<<endl;
            cout<<"********************************************"<<"Driver Allocated is: "<<d[result].name<<"***********************************************\n\n\n";

        }
};
int V = 14;
Gmap g(V);


///////////////////////////////////////////////////////////////////
void searchdriver(string c,string des)
{
    system("cls");
    cout<<"Currently drivers are at:"<<endl;
    cout<<d[0].cloc<<'\t'<<d[1].cloc<<'\t'<<d[2].cloc<<'\t'<<d[3].cloc<<endl<<endl;
     g.Dijkstras(c,des);
}
int loggedIn()
{
//    cls(1);

    gotoxy(35,10);
    printf("Enter 1 for ");
    gotoxy(34,11);
    printf("Booking a cab");

    gotoxy(35,14);
    printf("Enter 2 to ");
    gotoxy(30,15);
    printf("Visit Your Own Profile");

    gotoxy(35,18);
    printf("Enter 3 for ");
    gotoxy(37,19);
    printf("LOGOUT");

    gotoxy(67,13);
    printf("Enter Your Choice Here:");
    gotoxy(55,4);
     string c,d;
    //printf("WELCOME %s!",ver.name);
    gotoxy(77,15);
    switch((int)_getch()-(int)'0')
    {
    case 1:
//        cls(1);

//        makeGeneralBox(75,6,33,8,0);
        system("cls");
        gotoxy(45,8);
        printf("Enter your current location:");
        cin>>c;
        currli.currloc=c;

        gotoxy(45,10);
        printf("Enter your destination:");
        cin>>d;
        currli.dest=d;
           gotoxy(45,12);
           printf("Please wait while we are allocating a cab for you...");
        gotoxy(60,10);
        printf("...");
        gotoxy(91,12);
        searchdriver(c,d);
        break;
    case 2:
//        cls(1);
        system("cls");

        cout<<currli.user<<endl;
        break;
    case 3:
//        cls(1);
        //mainPage();
        break;
    default:
//        cls(1);
        gotoxy(55,15);
        printf("Wrong Input");
//        delay(1000);
        exit(1);
    }
    return 0;
}
int main()
{


	int E = 19; // Number of edges in graph
	double w;
	struct Graph* graph = createGraph(V, E);

    graph->vert[0].lat = 28.628999;
	graph->vert[0].lon = 77.374303;

	graph->vert[1].lat = 28.631292;
	graph->vert[1].lon = 77.374119;

	graph->vert[2].lat = 28.631311;
	graph->vert[2].lon = 77.370922;

	graph->vert[3].lat = 28.631450;
	graph->vert[3].lon = 77.364960;

	graph->vert[4].lat = 28.731478;
	graph->vert[4].lon = 77.366572;

	graph->vert[5].lat = 28.784178;
	graph->vert[5].lon = 77.367188;

	graph->vert[6].lat = 28.635425;
	graph->vert[6].lon = 77.369256;

	graph->vert[7].lat = 28.633469;
	graph->vert[7].lon = 77.372867;

	graph->vert[8].lat = 28.633164;
	graph->vert[8].lon = 77.372432;

	graph->vert[9].lat = 28.633245;
	graph->vert[9].lon = 77.389042;

	graph->vert[10].lat = 28.633555;
	graph->vert[10].lon = 77.389177;

	graph->vert[11].lat = 28.633666;
	graph->vert[11].lon = 77.389264;

	graph->vert[12].lat = 28.633777;
	graph->vert[12].lon = 77.389367;

	graph->vert[13].lat = 28.633888;
	graph->vert[13].lon = 77.3898943;
    int c;   //condition of road
	// add edge 0-1
	graph->edge[0].src = 0;
	graph->edge[0].dest = 1;
	w=haversine(graph->vert[0].lat,graph->vert[0].lon,graph->vert[1].lat,graph->vert[1].lon);
	graph->edge[0].weight = w;
	c=1;
	g.addEdge("0","1",w,c);

	// add edge 0-2
	graph->edge[1].src = 1;
	graph->edge[1].dest = 2;
	w=haversine(graph->vert[1].lat,graph->vert[1].lon,graph->vert[2].lat,graph->vert[2].lon);
	graph->edge[1].weight = w;
	c=2;
	g.addEdge("1","2",w,c);
	// add edge 0-3
	graph->edge[2].src = 2;
	graph->edge[2].dest = 8;
	w=haversine(graph->vert[2].lat,graph->vert[2].lon,graph->vert[8].lat,graph->vert[8].lon);
	graph->edge[2].weight = w;
	c=3;
	g.addEdge("2","8",w,c);
	// add edge 1-3
	graph->edge[3].src = 8;
	graph->edge[3].dest = 13;
	w=haversine(graph->vert[8].lat,graph->vert[8].lon,graph->vert[13].lat,graph->vert[13].lon);
	graph->edge[3].weight = w;
	c=5;
	g.addEdge("8","13",w,c);
	// add edge 2-3
	graph->edge[4].src = 13;
	graph->edge[4].dest = 12;
	w=haversine(graph->vert[13].lat,graph->vert[13].lon,graph->vert[12].lat,graph->vert[12].lon);
	graph->edge[4].weight = w;
	c=4;
	g.addEdge("13","12",w,c);

    graph->edge[5].src = 12;
	graph->edge[5].dest = 11;
	w=haversine(graph->vert[12].lat,graph->vert[12].lon,graph->vert[11].lat,graph->vert[11].lon);
	graph->edge[5].weight = w;
	c=6;
	g.addEdge("12","11",w,c);

	// add edge 0-2
	graph->edge[6].src = 11;
	graph->edge[6].dest = 9;
	w=haversine(graph->vert[11].lat,graph->vert[11].lon,graph->vert[9].lat,graph->vert[9].lon);
	graph->edge[6].weight = w;
	c=9;
	g.addEdge("11","9",w,c);

	// add edge 0-3
	graph->edge[7].src = 9;
	graph->edge[7].dest = 3;
	w=haversine(graph->vert[9].lat,graph->vert[9].lon,graph->vert[3].lat,graph->vert[3].lon);
	graph->edge[7].weight = w;
	c=6;
	g.addEdge("9","3",w,c);

	// add edge 1-3
	graph->edge[8].src = 3;
	graph->edge[8].dest = 0;
	w=haversine(graph->vert[3].lat,graph->vert[3].lon,graph->vert[0].lat,graph->vert[0].lon);
	graph->edge[8].weight = w;
	c=4;
	g.addEdge("3","0",w,c);

	// add edge 2-3
	graph->edge[9].src = 3;
	graph->edge[9].dest = 4;
	w=haversine(graph->vert[3].lat,graph->vert[3].lon,graph->vert[4].lat,graph->vert[4].lon);
	graph->edge[9].weight = w;
	c=9;
	g.addEdge("3","4",w,c);

	graph->edge[10].src = 4;
	graph->edge[10].dest = 1;
	w=haversine(graph->vert[4].lat,graph->vert[4].lon,graph->vert[1].lat,graph->vert[1].lon);
	graph->edge[10].weight = w;
	c=10;
	g.addEdge("4","1",w,c);

	// add edge 0-2
	graph->edge[11].src = 4;
	graph->edge[11].dest = 5;
	w=haversine(graph->vert[4].lat,graph->vert[4].lon,graph->vert[5].lat,graph->vert[5].lon);
	graph->edge[11].weight = w;
	c=3;
	g.addEdge("4","5",w,c);

	// add edge 0-3
	graph->edge[12].src = 5;
	graph->edge[12].dest = 7;
	w=haversine(graph->vert[5].lat,graph->vert[5].lon,graph->vert[7].lat,graph->vert[7].lon);
	graph->edge[12].weight = w;
	c=6;
	g.addEdge("5","7",w,c);

	// add edge 1-3
	graph->edge[13].src = 6;
	graph->edge[13].dest = 7;
	w=haversine(graph->vert[6].lat,graph->vert[6].lon,graph->vert[7].lat,graph->vert[7].lon);
	graph->edge[13].weight = w;
	c=9;
	g.addEdge("6","7",w,c);

	// add edge 2-3
	graph->edge[14].src = 6;
	graph->edge[14].dest = 4;
	w=haversine(graph->vert[6].lat,graph->vert[6].lon,graph->vert[4].lat,graph->vert[4].lon);
	graph->edge[14].weight = w;
	c=7;
	g.addEdge("6","4",w,c);

    // add edge 0-2
	graph->edge[15].src = 7;
	graph->edge[15].dest = 8;
	w=haversine(graph->vert[7].lat,graph->vert[7].lon,graph->vert[8].lat,graph->vert[8].lon);
	graph->edge[15].weight = w;
	c=5;
	g.addEdge("7","8",w,c);

	// add edge 0-3
	graph->edge[16].src = 7;
	graph->edge[16].dest = 10;
	w=haversine(graph->vert[7].lat,graph->vert[7].lon,graph->vert[10].lat,graph->vert[10].lon);
	graph->edge[16].weight = w;
	c=7;
	g.addEdge("7","10",w,c);

	// add edge 1-3
	graph->edge[17].src = 9;
	graph->edge[17].dest = 10;
	w=haversine(graph->vert[9].lat,graph->vert[9].lon,graph->vert[10].lat,graph->vert[10].lon);
	graph->edge[17].weight = w;
	c=8;
	g.addEdge("9","10",w,c);

	// add edge 2-3
	graph->edge[18].src = 10;
	graph->edge[18].dest = 12;
	w=haversine(graph->vert[10].lat,graph->vert[10].lon,graph->vert[12].lat,graph->vert[12].lon);
	graph->edge[18].weight = w;
	c=2;
	g.addEdge("10","12",w,c);
	//

	d[0].name = "Mohit Jain";
	d[0].gender = "male";
	d[0].cab_cond = 6;
	d[0].running=false;
	//
	d[1].name = "Harsh Tyagi";
	d[1].gender = "male";
	d[1].cab_cond = 7;
	d[1].running=true;
	d[1].dloc="6";
	//
	d[2].name = "Kaushal Bhansali";
    d[2].gender = "male";
    d[2].cab_cond = 5;
    d[2].running=false;
    d[3].name = "A Sharma";
    d[3].gender = "female";
    d[3].running=false;
    d[3].cab_cond = 8;
    d[0].cloc = "1";
    d[1].cloc = "4";
    d[2].cloc = "9";
    d[3].cloc = "11";
    d[0].turns = 0;
    d[1].turns = 0;
    d[2].turns = 0;
    d[3].turns = 0;
    Welcome_window();
    Sleep(1000);
    system("cls");
    main_menu();


}
