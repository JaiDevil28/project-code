
#include<bits/stdc++.h>
using namespace std;
 
 double Trd=1.3125; // travelling time taken by ev between adjacent stations from roorkee to delhi and vice versa --(210/4)/40.. 
double Trs= (45/4)/40;// travelling time taken by ev between adjacent stations from roorkee to shahrhanpur and vice versa.. 
double drs=45/4;    // distance between adjacent stations from roorkee to shahrhanpur and vice versa--
double dt=0.15;    // draining power per km of ev.. i.e. 0.15kwh per km
double drd=52.5;      // distance between adjacent stations from roorkee to delhi and vice versa--
double Trh= 12/40;  // travelling time taken by ev between adjacent stations from roorkee to haridwar and vice versa..--(36/3)/40--  
double drh=12;       // distance between adjacent stations from roorkee to haridwar and vice versa--
class customer{
	public:
    string ordest;
    double edemand;
    double time;
    
    
};
char beststation_rode(customer cus,double  freetime[]);
char beststation_dero(customer cus,double  freetime[]);
string beststation_rosh(customer cus,double  freetime_rs[]);
string beststation_shro(customer cus,double  freetime_rs[]);
string beststation_roha(customer cus,double  freetime_rh[]);
string beststation_haro(customer cus,double  freetime_rh[]);
void filldata(customer &cust);

// Function to find the minimum of three numbers------- 
double min(double a,double b,double c)
{  if(a>b)
   { if(b>c)
   	 return c;
    else
    return b;
   }
  	else
  	{ if(a>c)
   	 return c;
    else
    return a;
  		}}

// main program
int main()
{  double freetime[3]={-1,-1,-1};
double freetime_rs[3]={-1,-1,-1};
double freetime_rh[2]={-1,-1};
  // let's say we have approximately 600 evs on an average that passes to roorkee........... 
    customer cust[600];
  for(int i=0;  ;i++)
   {
	
	     cout<<"press '1' to enter the system and '0'  to leave "<<endl;
	       int num;
	        cin>>num;
	        if(num==0)
	        break;
	  else if(num==1)        
{
	filldata(cust[i]);cout<<endl;
      if(cust[i].ordest=="rode")
  	cout<<"the minimum waiting time will be at the station "<<beststation_rode(cust[i],freetime)<<endl;
	  if(cust[i].ordest=="dero")
	  	 	cout<<"the minimum waiting time will be at the station "<<beststation_dero(cust[i],freetime)<<endl;  
		 if(cust[i].ordest=="rosh")
		 	cout<<"the minimum waiting time will be at the station "<<beststation_rosh(cust[i],freetime_rs)<<endl;  
		 if(cust[i].ordest=="shro")
		 	cout<<"the minimum waiting time will be at the station "<<beststation_shro(cust[i],freetime_rs)<<endl;  
		 if(cust[i].ordest=="roha")
		 	cout<<"the minimum waiting time will be at the station "<<beststation_roha(cust[i],freetime_rh)<<endl;  
		   if(cust[i].ordest=="haro")
		 	cout<<"the minimum waiting time will be at the station "<<beststation_haro(cust[i],freetime_rh)<<endl;  
}
  else
  cout<<" you have entered the wrong key please enter  it correctly "<<endl;
   cout<<endl;}		 
		 
		 cout<<"THANK U WE ARE HAPPY TO SERVE YOU "<<endl; 
	return 0;
	                                  }
	
// CUSTOMER'S INPUT------	
			 
void filldata(customer &cust) 
{ double hours; double minutes;
 string pair;
   cout<<"enter the origin destination pair for delhi press-de"<<endl<<"for roorkee press-ro"<<endl<<"for sharhanpur press- sh"<<endl<<"for haridwar press- ha"<<endl<<"like u want to from roorkee to delhi press 'rode' and likewise"<<endl;
    cin>>pair;
   
cout<<"enter the time of starting from your origin  (hours)"<<endl;
      cin>>hours;
    cout<<"enter the time of starting from origin (minutes)"<<endl;
      cin>>minutes;
  double ened;
  cout<<"enter the energydemand in kwh"<<endl;
         cin>>ened;
  double time= hours+ (minutes/60);
  cust.ordest=pair;
  cust.edemand=ened;
  cust.time=time;
}

	
 	                              //  ROORKEE TO DELHI-------	


char beststation_rode(customer cus,double  freetime[])
{ 
   double T=Trd;
   double d=drd;
 double t0=T+cus.time;      // time of arrival at station A
  double chart0= (cus.edemand+dt*d)/20;  // charging time at station A
  double t1=2*T+cus.time;  // time of arrival at station B
  double chart1= (cus.edemand+dt*2*d)/20;	  // charging time at station B
  double t2=3*T+cus.time;   // time of arrival at station B
  double chart2= (cus.edemand+dt*3*d)/20;	 // charging time at station C	 
double w0= freetime[0]-t0;		 // waiting time at station A
double w1= freetime[1]-t1;			 // waiting time at station B 
double w2= freetime[2]-t2;        // waiting time at station C
 if(w0<=0)
{  freetime[0]=t0+chart0+cus.time;  // time updation for station A
   return 'A';	
}
  if(w1<=0)
{  freetime[1]=t1+chart1+cus.time;  // time updation for station B
   return 'B';	
}
  if(w2<=0)
{  freetime[2]=t2+chart2+cus.time;  // time updation for station C
   return 'C';	
}
double minim=min(w0,w1,w2);		 
 if(minim==w0)
 { freetime[0]+=chart0;   // time updation for station A
 	return 'A';
 	}		 
if(minim==w1)
 { freetime[1]+=chart1;  // time updation for station B
 	return 'B';
 	}		 
if(minim==w2)
 { freetime[2]+=chart2;  // time updation for station C
 	return 'C';
 	}		 }
 	
 	
                                           // DELHI TO ROORKEE------- 	

char beststation_dero(customer cus,double  freetime[])
{   double T=Trd;
   double d=drd;

 double t2=T+cus.time;
  double chart2= (cus.edemand+dt*d)/20;
  double t1=2*T+cus.time;
  double chart1= (cus.edemand+dt*2*d)/20;	 
  double t0=3*T+cus.time;
  double chart0= (cus.edemand+dt*3*d)/20;		 
double w2= freetime[2]-t2;		 
double w1= freetime[1]-t1;			 
double w0= freetime[0]-t0;	
 if(w2<=0)
{  freetime[2]=t2+chart2+cus.time;
   return 'C';	
}
  if(w1<=0)
{  freetime[1]=t1+chart1+cus.time;
   return 'B';	
}
  if(w0<=0)
{  freetime[0]=t0+chart0+cus.time;
   return 'A';	
}
double minim=min(w0,w1,w2);		 
 if(minim==w0)
 { freetime[0]+=chart0;
 	return 'A';
 	}		 
if(minim==w1)
 { freetime[1]+=chart1;
 	return 'B';
 	}		 
if(minim==w2)
 { freetime[2]+=chart2;
 	return 'C';
 	}		 }

                                             // ROORKEE TO SHARHANPUR...................


string beststation_rosh(customer cus,double  freetime_rs[])
{ 
   double T=Trs;
   double d=drs;
 double t0=T+cus.time;
  double chart0= (cus.edemand+dt*d)/20;
  double t1=2*T+cus.time;
  double chart1= (cus.edemand+dt*2*d)/20;	 
  double t2=3*T+cus.time;
  double chart2= (cus.edemand+dt*3*d)/20;		 
double w0= freetime_rs[0]-t0;		 
double w1= freetime_rs[1]-t1;			 
double w2= freetime_rs[2]-t2;	
 if(w0<=0)
{  freetime_rs[0]=t0+chart0+cus.time;
   return "A1";	
}
  if(w1<=0)
{  freetime_rs[1]=t1+chart1+cus.time;
   return "B1";	
}
  if(w2<=0)
{  freetime_rs[2]=t2+chart2+cus.time;
   return "C1";	
}
double minim=min(w0,w1,w2);		 
 if(minim==w0)
 { freetime_rs[0]+=chart0;
 	return "A1";
 	}		 
if(minim==w1)
 { freetime_rs[1]+=chart1;
 	return "B1";
 	}		 
if(minim==w2)
 { freetime_rs[2]+=chart2;
 	return "C1";
 	}}
		 		 
		 
                                                 // SHAHRHANPUR TO ROORKEE-------
		 
string beststation_shro(customer cus,double  freetime_rs[])		 
{   double T=Trs;
   double d=drs;

 double t2=T+cus.time;
  double chart2= (cus.edemand+dt*d)/20;
  double t1=2*T+cus.time;
  double chart1= (cus.edemand+dt*2*d)/20;	 
  double t0=3*T+cus.time;
  double chart0= (cus.edemand+dt*3*d)/20;		 
double w2= freetime_rs[2]-t2;		 
double w1= freetime_rs[1]-t1;			 
double w0= freetime_rs[0]-t0;	
 if(w2<=0)
{  freetime_rs[2]=t2+chart2+cus.time;
   return "C1";	
}
  if(w1<=0)
{  freetime_rs[1]=t1+chart1+cus.time;
   return "B1";	
}
  if(w0<=0)
{  freetime_rs[0]=t0+chart0+cus.time;
   return "A1";	
}
double minim=min(w0,w1,w2);		 
 if(minim==w0)
 { freetime_rs[0]+=chart0;
 	return "A1";
 	}		 
if(minim==w1)
 { freetime_rs[1]+=chart1;
 	return "B1";
 	}		 
if(minim==w2)
 { freetime_rs[2]+=chart2;
 	return "C1";
 	}		 
		 
		 
}		 
		 

                                            //  ROORKEE  TO HARIDWAR ----


string beststation_roha(customer cus,double  freetime_rh[])
{ 
   double T=Trh;
   double d=drh;
 double t0=T+cus.time;
  double chart0= (cus.edemand+dt*d)/20;
  double t1=2*T+cus.time;
  double chart1= (cus.edemand+dt*2*d)/20;	 
		 
double w0= freetime_rh[0]-t0;		 
double w1= freetime_rh[1]-t1;			 	
 if(w0<=0)
{  freetime_rh[0]=t0+chart0+cus.time;
   return "A2";	
}
  if(w1<=0)
{  freetime_rh[1]=t1+chart1+cus.time;
   return "B2";	
}

 if(w0<w1)		 
 { freetime_rh[0]+=chart0;
 	return "A2";
 	}
	 else		 
 { freetime_rh[1]+=chart1;
 	return "B2";
 	}		 

}
	
                                           //  HARIDWAR TO ROORKEE  -------------------

string beststation_haro(customer cus,double  freetime_rh[])		 
{   double T=Trh;
   double d=drh;

 
  double t1=2*T+cus.time;
  double chart1= (cus.edemand+dt*d)/20;	 
  double t0=3*T+cus.time;
  double chart0= (cus.edemand+dt*2*d)/20;		 		 
double w1= freetime_rh[1]-t1;			 
double w0= freetime_rh[0]-t0;	
  if(w1<=0)
{  freetime_rh[1]=t1+chart1+cus.time;
   return "B2";	
}
  if(w0<=0)
{  freetime_rh[0]=t0+chart0+cus.time;
   return "A2";	
}
 if(w1>w0)		 
 { freetime_rh[0]+=chart0;
 	return "A2";
 	}	
	else 	 
 { freetime_rh[1]+=chart1;
 	return "B2";
 	}		 
	 
	}		 
	
                   /*************** END OF THE PROGRAM  ********************/





		 
