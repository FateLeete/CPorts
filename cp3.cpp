#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

time_t now;
char* dt;

void printTime();

int main()
{
    ifstream file("cports.log");

    int countLines = 0;
    string line;

    if (file.is_open())
    {
	    while (!file.eof())
	    {
            getline(file, line);
            countLines++;
	    }
    }
	
    file.close();

    --countLines;

    cout << " * Lines Count in file : " << countLines << " * ";

    cin.get();

    string skip;

    int j = 0;

    if (countLines > 86668 )
    {
        cout << "You have more than 86668.. Wish to proceed ? ";
                  
        char ch;
                   
        cin >> ch;
        
        if (ch == 'n' || ch == 'N')
        {
            return 1;
        }
                  
        cin.ignore();
        cout << "\n GL ! ";
        cin.get();
    }
    
    char* v = "void";
     
    char* tabProcc[countLines];
    int tabSvc[countLines];
    int tabRem1[countLines];
    int tabRem2[countLines];
    int tabRem3[countLines];
    int tabRem4[countLines];

    string ip1, ip2, ip3, ip4;
    int iip1, iip2, iip3, iip4;

    cout << "\n\nVariables allocated :) ";
    cin.get();

    for (int k = 0; k < countLines; k++)
    {
        tabRem1[k] = 0;
	tabRem2[k] = 0;
	tabRem3[k] = 0;
	tabRem4[k] = 0;
	tabSvc[k] = 0;
	tabProcc[k] = v;
    }

    cout << "\n\n UNSORT IPs\n";
    int szStr;

    ifstream infile("cports.log");
  
    for (int z =0 ; z < countLines; z++)
	{
        for (int i = 0; i < 7; i++)
		{
                infile >> skip;
			
            	if (i == 4)
            	{
                	int diff = skip.size();

                	char* cSStr = new char[35];
                	strcpy(cSStr, skip.c_str());
                  
                	for (int ix = diff; ix < 35 ; ix++)
                	{
                    		cSStr[ix] = ' ';
                    		cout << cSStr[ix];
                	}
            
                cSStr[35] = '\0';

                tabProcc[j] = cSStr;
            	}
        }
        
        infile >> skip;
    	
    	int sz = skip.size();
    
    	char *cstr = new char[skip.length() + 1];
    	strcpy(cstr, skip.c_str());
    
    	cstr[skip.size()] = '\0';
    
    	int m = 0;
    
    	if (cstr[m] != '\0')
    	{
    	    if (isdigit(cstr[m]))
    	    {
    		  if (isdigit(cstr[m + 1]))
    		  {
    		  	if (isdigit(cstr[m + 2]))
			{
                        	ip1 = skip.substr(m, 3);
    				m += 4;
    			}
    			else
    			{
    				ip1 = skip.substr(m, 2);
    				m += 3;
    			}
    		  }
    		  else
    		  {
    		  	ip1 = skip.substr(m, 1);
    			m += 2;
    		  }
            }
        }
    
      	if (cstr[m] != '\0')
        {
             if (isdigit(cstr[m]))
    	     {
                 if (isdigit(cstr[m + 1]))
    		 {
    			if (isdigit(cstr[m + 2]))
    			{
    				ip2 = skip.substr(m, 3);
    				m += 4;
    			}
    			else
    		    	{
    				ip2 = skip.substr(m, 2);
    				m += 3;
    			}
    		 }
             	 else
    		 {
    			ip2 = skip.substr(m, 1);
    			m += +2;
    		 }
    	     }
    	}
    
        if (cstr[m] != '\0')
    	{
    		if (isdigit(cstr[m]))
    		{
    			if (isdigit(cstr[m + 1]))
    			{
    	    			if (isdigit(cstr[m + 2]))
    				{
    					ip3 = skip.substr(m, 3);
    					m += 4;
    				}
    			    	else
    			    	{
    					ip3 = skip.substr(m, 2);
    				    	m += 3;
    			    	}
    		    	}
    		    	else
    			{
    				ip3 = skip.substr(m, 1);
    				m += 2;
    			}
    		}
    	}
    
        if (cstr[m] != '\0')
    	{
    		if (isdigit(cstr[m]))
    		{
    	    		if (isdigit(cstr[m + 1]))
    			{
    				if (isdigit(cstr[m + 2]))
    				{
    					ip4 = skip.substr(m, 3);
    				}
    		    		else
    				{
    					ip4 = skip.substr(m, 2);
    				}
    			}
    	    		else
    			{
    				ip4 = skip.substr(m, 1);
    			}
		}
        }

        iip1 = atoi(ip1.c_str());
    	iip2 = atoi(ip2.c_str());
    	iip3 = atoi(ip3.c_str());
    	iip4 = atoi(ip4.c_str());
            
    	cout << "\n" << j + 1 << "\t" << tabProcc[j] << "\t" << iip1 << "." << iip2 << "." << iip3 << "." << iip4 ;
    
    	tabRem1[j] = iip1;
    	tabRem2[j] = iip2;
    	tabRem3[j] = iip3;
    	tabRem4[j] = iip4;
    
    	delete[] cstr;
    
        ++j;
	}

    infile.close();

    cout << "\n\n****************************************";
    cout << "\nPress ENTER to SORT IPs ";
    cout << "\n****************************************\n\n";

    cin.get();

    printTime();
    
    bool change = true;
    int q;
    int tempo1, tempo2, tempo3, tempo4;
    char* stempo = "void";
    int cpt3 = 0;
	
    cout << " * ";
	
    while (change)
    {
        cpt3++;
 	change = false;
 		
 	if (cpt3 == 88)
 	{
            cout << " * ";
            cpt3 = 0;
        }
	
    	for (int p = 0; p < countLines - 1; p++)
	{
            q = p + 1;
		
	    if (tabRem1[q] <= tabRem1[p] && tabRem2[q] <= tabRem2[p] && tabRem3[q] <= tabRem3[p] && tabRem4[q] < tabRem4[p])
	    { 
                stempo= tabProcc[p]; tempo1 = tabRem1[p]; tempo2 = tabRem2[p]; tempo3 = tabRem3[p]; tempo4 = tabRem4[p];
                tabProcc[p] = tabProcc[q]; tabRem1[p] = tabRem1[q]; tabRem2[p] = tabRem2[q]; tabRem3[p] = tabRem3[q]; tabRem4[p] = tabRem4[q];
                tabProcc[q]= (char*)(stempo); tabRem1[q] = tempo1; tabRem2[q] = tempo2; tabRem3[q] = tempo3; tabRem4[q] = tempo4;
                change = true;
            }
            else if (tabRem1[q] <= tabRem1[p] && tabRem2[q] <= tabRem2[p] && tabRem3[q] < tabRem3[p])
            { 
                stempo= tabProcc[p]; tempo1 = tabRem1[p]; tempo2 = tabRem2[p]; tempo3 = tabRem3[p]; tempo4 = tabRem4[p]; 
                tabProcc[p] = tabProcc[q]; tabRem1[p] = tabRem1[q]; tabRem2[p] = tabRem2[q]; tabRem3[p] = tabRem3[q]; tabRem4[p] = tabRem4[q];
                tabProcc[q]= (char*)(stempo); tabRem1[q] = tempo1; tabRem2[q] = tempo2; tabRem3[q] = tempo3; tabRem4[q] = tempo4;
                change = true;
            }
            else if (tabRem1[q] <= tabRem1[p] && tabRem2[q] < tabRem2[p])
            {
                stempo= tabProcc[p]; tempo1 = tabRem1[p]; tempo2 = tabRem2[p]; tempo3 = tabRem3[p]; tempo4 = tabRem4[p]; 
                tabProcc[p] = tabProcc[q]; tabRem1[p] = tabRem1[q]; tabRem2[p] = tabRem2[q]; tabRem3[p] = tabRem3[q]; tabRem4[p] = tabRem4[q];
                tabProcc[q]= (char*)(stempo); tabRem1[q] = tempo1; tabRem2[q] = tempo2; tabRem3[q] = tempo3; tabRem4[q] = tempo4;
                change = true;
            }
            else 
            {
                if (tabRem1[q] < tabRem1[p])
                {
                    stempo= tabProcc[p]; tempo1 = tabRem1[p]; tempo2 = tabRem2[p]; tempo3 = tabRem3[p]; tempo4 = tabRem4[p]; 
                    tabProcc[p] = tabProcc[q]; tabRem1[p] = tabRem1[q]; tabRem2[p] = tabRem2[q]; tabRem3[p] = tabRem3[q]; tabRem4[p] = tabRem4[q];
                    tabProcc[q]= (char*)(stempo); tabRem1[q] = tempo1; tabRem2[q] = tempo2; tabRem3[q] = tempo3; tabRem4[q] = tempo4;
                    change = true;                  
                }                       
            }         
        }
    }
    
    printTime();

    cout << "\n\n***********************************************************";
    cout << "\nIPs Sorted ! Press ENTER to Show the sorted IPs ";
    cout << "\n***********************************************************";
    
    cin.get(); 
    
    cout << "\n\nSORTED IPs\n";
    
    for (int r = 0; r < countLines; r++)
    {
	cout << "\n" << r + 1 << "\t" << (char*)(tabProcc[r]) << "\t" << tabRem1[r] << "." << tabRem2[r] << "." << tabRem3[r] << "." << tabRem4[r];
    }
    
    cout << "\n\n***********************************************************";
    cout << "\nPress ENTER to get Unique IP";
    cout << "\n***********************************************************\n\n";
    
    int oldi1, oldi2, oldi3, oldi4, cnt, ipCnt;
    cnt = 1;
    ipCnt = 0;
    
    cout << "IP COUNTER    Proccess                     Counter         IP\n";
    cout << "***********************************************************************\n";
    cin.get();

    int biggCnt= 1;
    string biggCntProcc;
    int biggIP1, biggIP2, biggIP3, biggIP4;
    
    for (int xx = 1; xx <= countLines; xx++)
    {
        oldi1 = tabRem1[xx-1];
        oldi02 = tabRem2[xx-1];
        oldi3 = tabRem3[xx-1];
        oldi4 = tabRem4[xx-1];	
      
        if (oldi1 == tabRem1[xx] && oldi2 == tabRem2[xx] && oldi3 == tabRem3[xx] && oldi4 == tabRem4[xx])
        {
            ++cnt;
             
            if ( xx == countLines)
            {
                cout << "\n" << ipCnt << "\t" << tabProcc[xx-1] << "\t" << cnt << "\t" << oldi1 << "." << oldi2 << "." << oldi3 << "." << oldi4;
                 
                if (cnt > biggCnt)
                {
                    biggCnt = cnt;
                    biggCntProcc = tabProcc[xx-1];
                    biggIP1 = oldi1; biggIP2 = oldi2; biggIP3 = oldi3; biggIP4 = oldi4;                              
                }
            }               
        }
        else
        {   
            ++ipCnt;
            cout << "\n" << ipCnt << "\t" << tabProcc[xx-1] << "\t" << cnt << "\t" << oldi1 << "." << oldi2 << "." << oldi3 << "." << oldi4;
	    
            char* svc = "svchost.exe                        ";
            char* Ukn = "Unknown                            ";
                                       
            if (strcmp(tabProcc[xx-1],svc) == 0)
            {
                tabSvc[xx-1] = 1;
            }
             
            if (cnt > biggCnt)
            {
                biggCnt = cnt;
                                  
                if (strcmp(tabProcc[xx-1], Ukn) == 0)
                {
                    biggCntProcc = tabProcc[xx - cnt];
                }
                else
                {
                    biggCntProcc = tabProcc[xx-1];
                }    
                 
                biggIP1 = oldi1; biggIP2 = oldi2; biggIP3 = oldi3; biggIP4 = oldi4;
            }
                
            cnt = 1;
        }
    }

    cout << "\n\n*************************************************************************************";
    cout << "\nThe Most Frequent IP is " << biggIP1 << "." << biggIP2 << "." << biggIP3 << "." << biggIP4; 
    cout << " with the count of " << biggCnt << " from Proccess " << biggCntProcc;  
    cout << "\n*************************************************************************************";
    
    cin.get();                           
    
    cout << "\n\n*************************************************************************************";
    cout << "\nTable of svchost.exe"; 
    cout << "\n*************************************************************************************";   

    cin.get();
   
    int cnt2 = 1; 
     
    for (int r = 0; r < countLines; r++)
	{
        	if ( tabSvc[r] == 1)
        	{
    			cout << "\n" << cnt2 << "\t" << tabProcc[r] << "\t" << tabRem1[r] << "." << tabRem2[r] << "." << tabRem3[r] << "." << tabRem4[r];
      			++cnt2;        
        	}
    	}
  
    cin.get();

    return 0;
}

void printTime()
    {
        now = time(0);
        dt = ctime(&now);
        cout << "\nThe local date and time is: " << dt ;
    }
