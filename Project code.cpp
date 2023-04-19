#include <bits/stdc++.h>
#include<fstream>
#include <cfloat>
#include <limits>
using namespace std;
//vector<vector<int> > totpath;
double speed=40;
double drainrate=0.15;
double drainrate1= 2;
double mileage=4.34;
double mileage1= 2;
// battery capacity of 65 kwh for vehicle type==0..
// batterycapacity of 400 kwh for vehicle type==1...
// 1 battery percentage= 0.65 kwh= 4.34km for tyoe 0..
// 1 batterypercentage=  4kwh ==2km for type 1...
  vector<vector<double> > minmf(vector<vector<int > > vec,double weight[][16],int vehicletype,double freetime[][3],double time,int batperc);
vector<double>  sorted(vector<vector<int > > vec,double weight[][16],int vehicletype,double freetime[][3],double time,int batperc);


class Graph {
public:
    int V;
    vector<vector<int> > totpath;
    vector<int> *adjList;
    void printAllPathsUtil(int, int, bool[], int[], int&,int &);
    Graph(int);
    void addEdge(int, int);
    void AllPaths(int, int);
    void addweight(double weight[][16],int,int,double);
};

Graph::Graph(int V) {
    this->V = V;
    adjList = new vector<int>[V];
}
void Graph::addweight(double weight[][16],int i,int j,double w)
{
    if(w==80)
     w=w-40;
     if(w==50)
     w=w-30;
     if(w==30)
     w=w-15;
   weight[i][j]=w;
   weight[j][i]=w;
}




void Graph::addEdge(int u, int v) {
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::AllPaths(int s, int d) {
     int jai=0;
    bool *visited = new bool[V];
    int *path = new int[V];
    int pathIndex = 0;
    for (int i = 0; i < V; i++)
        visited[i] = false;
    printAllPathsUtil(s, d, visited, path, pathIndex,jai);
}

void Graph::printAllPathsUtil(int u, int d, bool visited[], int path[], int &pathIndex,int & jai) {
    visited[u] = true;
    path[pathIndex] = u;
    pathIndex++; 
    if (u == d) {
        vector<int> vec(path,path+pathIndex);
        totpath.push_back(vec);
        }
    else {
        for (auto i = adjList[u].begin(); i != adjList[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, pathIndex,jai);
    }
    pathIndex--;
    visited[u] = false;
}

int main() {
    Graph g(16);
    g.addEdge(0, 15);
    g.addEdge(1, 5);
    g.addEdge(1, 2);
    g.addEdge(5, 6);
    g.addEdge(5, 4);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 3);
    g.addEdge(4, 8);
      g.addEdge(4,7);
    g.addEdge(4, 9);
  g.addEdge(9, 14);
    g.addEdge(9, 10);
      g.addEdge(10, 11);
  g.addEdge(6, 12);
  g.addEdge(6,11);
    g.addEdge(6, 13);
  g.addEdge(12, 13);
    g.addEdge(13, 14);
      g.addEdge(14, 7);
        g.addEdge(7, 8);
    double weight[16][16];
  for(int i=0;i<16;i++)
  for(int j=0;j<16;j++)
    weight[i][j]= 0;
    double freetime[16][3]={ {-2,-2,-2},
                        {-1,-1,-2},
						{-1,-1,-1},
						{-1,-1,-2},
						{-1,-1,-1},
						{-1,-1,-1},
						{-1,-1,-1},
						{-1,-1,-1},
						{-1,-2,-2},
                        {-1,-1,-1},
						{-1,-1,-2},
						{-1,-1,-1},
                        {-1,-1,-2},
                        {-1,-1,-1},
                        {-1,-1,-2},
                        {-2,-2,-2}};


  g.addweight(weight,0, 15,INT_MAX);
    g.addweight(weight,1, 5,50);
    g.addweight(weight,1, 2,50);
    g.addweight(weight,5, 6,80);
    g.addweight(weight,5, 4,50);
    g.addweight(weight,2, 3,80);
    g.addweight(weight,2, 4,80);
    g.addweight(weight,4, 3,50);
    g.addweight(weight,4, 8,50);
      g.addweight(weight,4,7,50);
    g.addweight(weight,4, 9,50);
  g.addweight(weight,9, 14,50);
    g.addweight(weight,9, 10,30);
      g.addweight(weight,10, 11,30);
  g.addweight(weight,6, 12,80);
  g.addweight(weight,6,11,30);
    g.addweight(weight,6, 13,50);
  g.addweight(weight,12, 13,50);
    g.addweight(weight,13, 14,50);
      g.addweight(weight,14, 7,50);
        g.addweight(weight,7, 8,50);

     for(int i=0;i<500;i++)
 {   int hours,minutes;
     int vehicletype; int batperc;
         int source,destination;
  cout<<"enter the source-destination pair (source-destinatin)"<<endl;
    cin>>source>>destination;

   cout<<"enter the time in hours from source "<<endl;
       cin>>hours;
      cout<<"enter the time in minutes from source "<<endl;
       cin>>minutes;
        cout<<"enter vehicletype for car (type-0) and for bus (type type-1)"<<endl;
           cin>>vehicletype;
    cout<<"enter the initial battery percentage "<<endl;
         cin>>batperc;
   
      double time= hours +(minutes)/60.0; 
      int cont; 
     g.AllPaths(source,destination);
  vector<double> ans= sorted(g.totpath,weight,0,freetime,2.5,29);
           cout<<" minimum waiting time will be at stations - "<<ans[0]<<endl;
            int energ;
      if(ans[1]==0)
        energ=20;
         if(ans[1]==1)
        energ=40;
         if(ans[1]==2)
        energ=80; 
        cout<<" you have assigned the pump - "<<energ<<" kw"<<endl;

           g.totpath.clear();
         cout<<" if u want to continue press-1 else press-0 "<<endl;
            cin>>cont;
     
   if(cont==1)
    continue;
    else
    break;
          }
    
    


 
return 0;

}


vector<double>  sorted(vector<vector<int > > vec,double weight[][16],int vehicletype,double freetime[][3],double time,int batperc)
{    vector<double> sol;
    vector<double> dista;
    double endemand;
     if(vehicletype==0)
     endemand= (100-batperc)*(0.65);
  else
   endemand= (100-batperc)*4;
     for(int i=0;i<vec.size();i++)
     {   dista.push_back(0);
        for(int j=1;j<vec[i].size();j++)
        dista[i]+=weight[vec[i][j-1]][vec[i][j]];
                                                    }
                                            
   vector<vector<double>> ans = minmf(vec,weight,vehicletype,freetime,time,batperc);
  

    double minmt=DBL_MAX; int count;
    for(int i=0;i<vec.size();i++)
    { double tott= ans[i][2]+ (dista[i]/40);
      if(tott<minmt)
      { minmt=tott;
        count=i;
      }}

       int s1=ans[count][0];
        int s2= ans[count][1];
    if( freetime[s1][s2] != -1 && freetime[s1][s2] != -2 && s2==0)
      freetime[s1][s2]  +=  (endemand+ drainrate*ans[count][3])/20 ; 

    if( freetime[s1][s2] != -1 && freetime[s1][s2] != -2 && s2==1)
      freetime[s1][s2]  +=  (endemand+ drainrate*ans[count][3])/40 ; 
    
    if( freetime[s1][s2] != -1 && freetime[s1][s2] != -2 && s2==2)
      freetime[s1][s2]  +=  (endemand+ drainrate*ans[count][3])/80 ;  
 

    if( freetime[s1][s2]== -1 && s2==0)
      freetime[s1][s2] = time+  (ans[count][3])/40 + (endemand+ drainrate*ans[count][3])/20 ; 
    if( freetime[s1][s2]== -1 && s2==1)
      freetime[s1][s2] = time+  (ans[count][3])/40 + (endemand+ drainrate*ans[count][3])/40 ; 
    if( freetime[s1][s2]== -1 && s2==2)
      freetime[s1][s2] = time+  (ans[count][3])/40 + (endemand+ drainrate*ans[count][3])/80 ; 
   

    sol.push_back(s1);
     sol.push_back(s2);
     sol.push_back(count);
     sol.push_back(ans[count][3]);
     sol.push_back(ans[count][4]);
     sol.push_back(ans[count][5]);


return sol;
                
                }




 vector<vector<double>>  minmf(vector<vector<int > > vec,double weight[][16],int vehicletype,double freetime[][3],double time,int batperc)
 {  vector<vector<double>> jaii;
                
              int count=0;
double endemand;
  if(vehicletype==0)
  endemand= (100-batperc)*(0.65);
  else
   endemand= (100-batperc)*4;
  if(vehicletype==0)
{
    
    for(int i=0;i<vec.size();i++)
    {   double dist=0; 
    double tots=DBL_MAX;
    double station=0;
     double pump=0;
     double distan=0;  
      double waitingtime=0;        
      for(int j=0;j<vec[i].size();j++)
      {
         
          if( j !=0)
        {   
         dist +=weight[vec[i][j-1]][vec[i][j]];   }

          if(dist/mileage >batperc)  
              continue;

          
          double wtime,ctime;
         double traveltime= dist/speed;     
                                 
        if(freetime[vec[i][j]][1] != -2)
        {  wtime= freetime[vec[i][j]][1]-(traveltime+time);
            if(wtime<0)
             wtime=0;  
           ctime= (endemand + dist*drainrate)/40;   
             if((wtime+ctime) < tots) 
            {  tots= wtime+ctime;
                station= vec[i][j];
                pump=1;  
                 distan=dist;   
                 waitingtime= wtime;         
               } }
         if(freetime[vec[i][j]][0] != -2)
        {  wtime= freetime[vec[i][j]][0]-(traveltime+time);
            if(wtime<0)
             wtime=0; 
           ctime= (endemand + dist*drainrate)/20;   
             if((wtime+ctime) < tots) 
            {  tots= wtime+ctime;
                station= vec[i][j];
                pump=0;      
                distan=dist;            waitingtime=wtime;               
            }} 
            
              }
                                                    
            
    
        vector<double> jai;
          jai.push_back(station); //0
         jai.push_back(pump);//1
          jai.push_back(tots); //2
           jai.push_back(waitingtime);//3
          jai.push_back(distan);//4
          jai.push_back(endemand);//5
         jaii.push_back(jai);
    jai.clear();

                
        
    } 
    
   
    }
  else
{  
    
    for(int i=0;i<vec.size();i++)
    {   double dist=0;
     double tots= DBL_MAX;
     double station=0; 
     double pump=0;
     double distan=0; double waitingtime;
      for(int j=0;j<vec[i].size();j++)
   {      if(j !=0)
        { dist +=weight[vec[i][j-1]][vec[i][j]];
                                              }
          
        
        //  if(dist/mileage1 >batperc)  
          //   break;

          double wtime,ctime;
         double traveltime= dist/30;   

        if(freetime[vec[i][j]][1] != -2)
        {  wtime= freetime[vec[i][j]][1]-(traveltime+time);
            if(wtime<0)
             wtime=0;
           ctime= (endemand + dist*drainrate1)/40;   
             if(wtime+ctime<tots) 
            {  tots= wtime+ctime;
                station= vec[i][j];
                pump=1;                          
                 waitingtime=wtime;    
            } }   
         if(freetime[vec[i][j]][2] != -2)
        {  wtime= freetime[vec[i][j]][2]-(traveltime+time);
            if(wtime<0)
             wtime=0;
           ctime= (endemand + dist*drainrate1)/80;   
             if(wtime+ctime < tots) 
            {  tots= wtime+ctime;
                station= vec[i][j];
                pump=2;
                distan=dist;            waitingtime=wtime;                   
            } }
            }
      
        vector<double> jai;
          jai.push_back(station);
          jai.push_back(pump);
          jai.push_back(tots); 
          jai.push_back(waitingtime);
          jai.push_back(distan);
          jai.push_back(endemand);
         jaii.push_back(jai);
    jai.clear();




    }
}




 
   return jaii;        
   
   
    }



 
