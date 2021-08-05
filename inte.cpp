#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <sstream>


void only_true(std::vector <std::string> tmp ,int i,int ind);
std::string txt(std::vector <std::string> tmp , int i) ;
bool clarif(std::vector <std::string> tmp , int i)  ;
double maxd(std::vector <std::string> tmp , int i);
int are(std::vector <std::string> tmp , int i);
double foo (std::string tmp,int i,std::string std);
void fishIN(std::vector <std::string> tmp );
void fish(std::vector <std::string> tmp );
void whatif(std::vector <std::string> tmp, int i,int ind);



std::vector <std::string> stringmax;

std::map<std::string,int > intt ;
std::map<std::string,std::string > stringg ;
std::map<std::string,double > doublee ;
std::map<std::string,bool > booll ;



std::vector<std::string> Parse(const std::string& str) //tox@ bareri
{
    std::vector<std::string> temp;
    std::stringstream strr (str);
    for(int i = 0;!strr.eof();i++)
    {
        std::string tmp;
        strr >> tmp;
        temp.push_back(tmp);
        tmp = "";
        
    }

    return temp;
}

template <typename T>
T sum(T a, T b)
{
    return a + b ;
}
template <typename T>
T sub(T a, T b)
{
    return a - b ;
}
template <typename T>
T mul(T a, T b)
{
    return a * b ;
}
template <typename T>
T ddiv(T a, T b)
{
    return a / b ;
}
int d = 0;



void fish(std::vector <std::string> tmp )
{
    if((std::map<std::string,double>::iterator)(doublee.find(tmp[1]))!=doublee.end())
    {
        std::cout<< doublee[tmp[1]];
    }
    else if((std::map<std::string,int>::iterator)(intt.find(tmp[1]))!=intt.end())
    {
        std::cout<< intt[tmp[1]];
    }
    else if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[1]))!=stringg.end())
    {
        std::cout<< stringg[tmp[1]];
    }
    else if((std::map<std::string,bool>::iterator)(booll.find(tmp[1]))!=booll.end())
    {
        std::cout<< booll[tmp[1]];
    }
    else{std::cout<<tmp[1]<<std::endl;}
}


void fishIN(std::vector <std::string> tmp )
{
    bool z;
    std::string c;
    int v;
    double x;
    if((std::map<std::string,double>::iterator)(doublee.find(tmp[1]))!=doublee.end())
    {
        std::cout<<"MUTQAGREL DOUBLE";
        std::cin>>x;
        doublee[tmp[1]] = x;
    }
    else if((std::map<std::string,int>::iterator)(intt.find(tmp[1]))!=intt.end())
    {
        std::cout<<"MUTQAGREL INT";
        std::cin>>v;
        intt[tmp[1]] = v;
    }
    else if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[1]))!=stringg.end())
    {
        std::cout<<"MUTQAGREL STRING";
        getline(std::cin,c);
        stringg[tmp[1]] = c;
    }
    else if((std::map<std::string,bool>::iterator)(booll.find(tmp[1]))!=booll.end())
    {
        std::cout<<"MUTQAGREL BOOL";
        std::cin>>z;
        booll[tmp[1]] = z;
    }
    else{std::cout<<"erorrr";}
}





double foo (std::string tmp,int i,std::string std)
{
    if( std == "double")
    {
        if((std::map<std::string,double>::iterator)(doublee.find(tmp)) != doublee.end())
        {
            return  doublee.find(tmp)->second; 
        }
        else if(std::stoi(tmp)<=INT_MAX  && std::stoi(tmp)>=0)
        {
            return std::stod(tmp);
        }
        else
        {
            std::cout<< i+1 <<"Error:  " ;
            abort();
        }
    }
     else if( std == "are")
     {
        if((std::map<std::string,int>::iterator)(intt.find(tmp)) != intt.end())
        {
            return  intt.find(tmp)->second; 
        }
        else if(std::stoi(tmp)<=INT_MAX  && std::stoi(tmp)>=0)
        {
            return std::stod(tmp);
        }
        else
        {
            std::cout<< i+1 <<"Error:  " ;
            abort();
        }
    }
       throw "error";                     
}



int are(std::vector <std::string> tmp , int i)   ///int
{
    if((std::map<std::string,int>::iterator)(intt.find(tmp[1])) != intt.end())
    {
        std::cout<< i+1 <<"Error: redefinition of 'x' ";
        abort();       
    }

    if(tmp[2] == "=")
    {
        int x ;
        if (tmp[4] == "+"||tmp[4] == "-"||tmp[4] == "*"||tmp[4] == "/" )
        {      
            if(tmp[4] == "+")
            {
                x =  sum( foo(tmp[3], i ,"are"), foo(tmp[5],i,"are"));
                
            }
            else if(tmp[4] == "-")
            {
                x =  sub(  foo(tmp[3], i ,"are"), foo(tmp[5],i,"are"));
            }
            else if(tmp[4] == "*")
            {
                x =  mul(  foo(tmp[3], i ,"are"), foo(tmp[5],i,"are"));
            }
            else if(tmp[4] == "/")
            {
                x =  ddiv( foo(tmp[3], i ,"are"), foo(tmp[5],i,"are"));
            } 
        }
        else if((std::map<std::string,int>::iterator)(intt.find(tmp[3])) != intt.end())
        {
            x = std::stoi(tmp[3]);
            //abort();
        }
        else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
        {
            x = std::stoi(tmp[3]);
        }
        return x;
    }
    throw "error";
}


double maxd(std::vector <std::string> tmp , int i)   ///double
{
    if((std::map<std::string,int>::iterator)(intt.find(tmp[1])) != intt.end())
    {
        std::cout<< i+1 << "  Error: redefinition of 'x' ";
        abort();       
    }

    if(tmp[2] == "=")
    {
        double x ;
        if (tmp[4] == "+"||tmp[4] == "-"||tmp[4] == "*"||tmp[4] == "/" )
        {       
            if(tmp[4] == "+")
            {
                x =  sum(  foo(tmp[3], i ,"double"), foo(tmp[5],i,"double"));
                
            }
            else if(tmp[4] == "-")
            {
                x =  sub(  foo(tmp[3], i ,"double"), foo(tmp[5],i,"double"));
            }
            else if(tmp[4] == "*")
            {
                x =  mul(  foo(tmp[3], i ,"double"), foo(tmp[5],i,"double"));
            }
            else if(tmp[4] == "/")
            {
                x =  ddiv( foo(tmp[3], i ,"double"), foo(tmp[5],i,"double"));
            } 
        }
        else if((std::map<std::string,double>::iterator)(doublee.find(tmp[3])) != doublee.end())
        {
            x = std::stod(tmp[3]);
            //abort();
        }
        else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
        {
            x = std::stod(tmp[3]);
        }
        return x;
    }
    throw "error";
 }
bool clarif(std::vector <std::string> tmp , int i)   ///bool
{
    std::map<std::string,bool>::iterator it = booll.find(tmp[1]);
    if(it != booll.end())
    {
        std::cout<< i+1 <<"  Error: redefinition of "<<tmp[1]<<"     ";
        abort();       
    }

    else if(tmp[2] == "=")
    {
        bool x ;
        if((std::map<std::string,bool>::iterator)(booll.find(tmp[3])) != booll.end())
        {
            if(booll[tmp[3]] == true)
            {
                x = true;
                return x;
            }
            if(booll[tmp[3]] == false)
            {
                x = false;
                return x;
            }     
        }
        else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
        {
            x = true;
            return x;
        }
        else if(std::stoi(tmp[3])==0)
        {
            x = false;
            return x;
        }

    }
    throw "error";
}
            
 

 
std::string txt(std::vector <std::string> tmp , int i)   ///int
{
    if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[1])) != stringg.end())
    {
        std::cout<< i+1 <<"Error: redefinition of '"<<tmp[1]<<"' ";
        abort();       
    }
    if(tmp[2] == "=")
    {
        std::string x ;
        if (tmp[4] == "+"||tmp[4] == "-"||tmp[4] == "*"||tmp[4] == "/" )
        {                           
            if(tmp[4] == "+")
            {
                if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[3])) != stringg.end() && 
                (std::map<std::string,std::string>::iterator)(stringg.find(tmp[5])) != stringg.end())
                { 
                    x =  sum(stringg[tmp[3]],stringg[tmp[5]]);
                    return x;
                }
                else if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[5])) != stringg.end())
                {
                    x =  sum(stringg[tmp[5]],tmp[3]);  
                    return x;
                }
                else
                {
                    x =  sum(stringg[tmp[3]],tmp[5]);
                    return x;
                }
            }
        }
                       
                    
                    

        else if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[3])) == stringg.end())
        {
            x = tmp[3];
            
        }
        return x;
    }
    throw "error";

}
void only_true(std::vector <std::string> tmp ,int i,int ind)
{   
    std::string std = "double";
    if (foo (tmp[1], i,std))
    {    
        whatif(tmp,i+2,ind); 
        d=1;
    }
}

void only_true1(std::vector <std::string> tmp ,int i,int ind,int& s)
{   
    std::string std = "double";
    if (foo (tmp[1], i,std))
    {    
        whatif(tmp,i+2,ind); 
        d=1;
    }
    else{s++;}
   

}


                 
void whatif(std::vector <std::string> tmp, int i,int ind)
{
    for(; i <= ind; i++)
    {
        std::vector <std::string> tmp = Parse(stringmax[i]);
   
        if(tmp[0]=="are")
        {
            intt.insert(std::make_pair(tmp[1],are(tmp,i)));
        }
        else if(tmp[0]=="maxd")
        {
            doublee.insert(std::make_pair(tmp[1],maxd(tmp,i)));
        }
        else if(tmp[0]=="clarif")
        {
            booll.insert(std::make_pair(tmp[1],clarif(tmp,i)));
        }
        else if(tmp[0]=="txt")
        {
            stringg.insert(std::make_pair(tmp[1],txt(tmp,i)));
        }  
        else if(tmp[0]=="Fish*")
        {
            fish(tmp);
        }      
        else if(tmp[0]=="*Fish")
        {
            fishIN(tmp);
        }
            else if(tmp[0]=="Whatif")
        {
            if(stringmax[i+1] == "{")
            {
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind = j;
                        only_true(tmp,i,ind);
                        i=j+1;
                        if(stringmax[i]=="ifnt" && d == 1)
                        {
                            for(; i <= stringmax.size() ; ++i)
                            {
                                if(stringmax[i] == "}")
                                {
                                    i=i+1;
                                    break;
                                }
                            }
                        }
                        
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }
                        
            }
        }
        
       else if(tmp[0]=="ifnt")
        {
            if(stringmax[i+1] == "{")
            {
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind =j;
                        whatif(tmp,i+2,ind);
                        i=i+ind;
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }       
            }
        }
        else if(tmp[0]=="aslongas")
        {
               if(stringmax[i+1] == "{")
            { 
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind = j;
                        int z = 0;
                        int s = 0;
                        while(z==s){
                        only_true1(tmp,i,ind,s);
                        }
                        i=j+1;
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }       
            }
        }
        else
        {
            if((std::map<std::string,int>::iterator)(intt.find(tmp[0])) != intt.end())
            {
                if(tmp[1] == "=")
                {
                    int x ;
                    if (tmp[3] == "+"||tmp[3] == "-"||tmp[3] == "*"||tmp[3] == "/" )
                    {      
                        if(tmp[3] == "+")
                        {
                            x =  sum( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                            
                        }
                        else if(tmp[3] == "-")
                        {
                            x =  sub(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "*")
                        {
                            x =  mul(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "/")
                        {
                            x =  ddiv( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        } 
                    }
                    else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
                    {
                        x = std::stoi(tmp[3]);
                    }
                     intt[tmp[0]]=x;
               }   
            }
            else if((std::map<std::string,double>::iterator)(doublee.find(tmp[0])) != doublee.end())
            {
                if(tmp[1] == "=")
                {
                    double x ;
                    if (tmp[3] == "+"||tmp[3] == "-"||tmp[3] == "*"||tmp[3] == "/" )
                    {      
                        if(tmp[3] == "+")
                        {
                            x =  sum( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                            
                        }
                        else if(tmp[3] == "-")
                        {
                            x =  sub(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "*")
                        {
                            x =  mul(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "/")
                        {
                            x =  ddiv( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        } 
                    }
                    else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
                    {
                        x = std::stoi(tmp[3]);
                    }
                     doublee[tmp[0]]=x;
               }   
            }
            if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[0])) != stringg.end())
            {
                if(tmp[1] == "=")
                {
                 
                     stringg[tmp[0]]=tmp[2];
               }   
            }
            if((std::map<std::string,bool>::iterator)(booll.find(tmp[0])) != booll.end())
            {
                if(tmp[1] == "=")
                {
                    if(tmp[2]=="true"){
                     booll[tmp[0]]=true;
                    }
                    else if(tmp[2]=="false"){
                     booll[tmp[0]]=false;
                    }
                    else{std::cout<<i+1<<"Error : ";}
               }   
            }
        }   
    }  

}



int main(){

    std::ifstream code;
    code.open("WShark.ws");


    if(!(code.is_open()))
    {
        std::cout<<"CHI BACELLLL"<<std::endl;
    }
    else{std::cout<<"tuyna  "<<std::endl;}

    std::string str;

    while(!(code.eof()))//tox tox lcuma
    {     
        str=" ";
        getline(code,str);
        if (str == "")
        {
            continue;
        }
        stringmax.push_back(str);
    }
    code.close();



    for(int i = 0; i < stringmax.size(); ++i)
    {
        std::vector <std::string> tmp = Parse(stringmax[i]);
        if(tmp[0]=="are")
        {
            intt.insert(std::make_pair(tmp[1],are(tmp,i)));
        }
        else if(tmp[0]=="maxd")
        {
            doublee.insert(std::make_pair(tmp[1],maxd(tmp,i)));
        }
        else if(tmp[0]=="clarif")
        {
            booll.insert(std::make_pair(tmp[1],clarif(tmp,i)));
        }
        else if(tmp[0]=="txt")
        {
            stringg.insert(std::make_pair(tmp[1],txt(tmp,i)));
        }  
        else if(tmp[0]=="Fish*")
        {
            fish(tmp);
        }      
        else if(tmp[0]=="*Fish")
        {
            fishIN(tmp);
        }
        else if(tmp[0]=="Whatif")
        {
            if(stringmax[i+1] == "{")
            {
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind = j;
                        only_true(tmp,i,ind);
                        i=j+1;
                        if(stringmax[i]=="ifnt" && d == 1)
                        {
                            for(; i <= stringmax.size() ; ++i)
                            {
                                if(stringmax[i] == "}")
                                {
                                    i=i+1;
                                    break;
                                }
                            }
                        }
                        
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }
                        
            }
        }
        else if(tmp[0]=="ifnt")
        {
            if(stringmax[i+1] == "{")
            {
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind =j;
                        whatif(tmp,i+2,ind);
                        i=i+ind;
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }       
            }
        }
        else if(tmp[0]=="aslongas")
        {
               if(stringmax[i+1] == "{")
            { 
                int ind = 0;
                for(int j = i + 3  ; j <= stringmax.size() ; j++)
                {
                    if(stringmax[j] == "}")
                    {
                        ind = j;
                        int z = 0;
                        int s = 0;
                        while(z==s){
                        only_true1(tmp,i,ind,s);
                        }
                        i=j+1;
                        break;
                    }
                    else if (j == stringmax.size())
                    { 
                        std::cout<<"Error   '}' ";
                        abort();
                    }
                }       
            }
        }
        else
        {
            if((std::map<std::string,int>::iterator)(intt.find(tmp[0])) != intt.end())
            {
                if(tmp[1] == "=")
                {
                    int x ;
                    if (tmp[3] == "+"||tmp[3] == "-"||tmp[3] == "*"||tmp[3] == "/" )
                    {      
                        if(tmp[3] == "+")
                        {
                            x =  sum( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                            
                        }
                        else if(tmp[3] == "-")
                        {
                            x =  sub(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "*")
                        {
                            x =  mul(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "/")
                        {
                            x =  ddiv( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        } 
                    }
                    else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
                    {
                        x = std::stoi(tmp[3]);
                    }
                     intt[tmp[0]]=x;
               }   
            }
            else if((std::map<std::string,double>::iterator)(doublee.find(tmp[0])) != doublee.end())
            {
                if(tmp[1] == "=")
                {
                    double x ;
                    if (tmp[3] == "+"||tmp[3] == "-"||tmp[3] == "*"||tmp[3] == "/" )
                    {      
                        if(tmp[3] == "+")
                        {
                            x =  sum( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                            
                        }
                        else if(tmp[3] == "-")
                        {
                            x =  sub(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "*")
                        {
                            x =  mul(  foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        }
                        else if(tmp[3] == "/")
                        {
                            x =  ddiv( foo(tmp[2], i ,"are"), foo(tmp[4],i,"are"));
                        } 
                    }
                    else if(std::stoi(tmp[3])<=2000000000 && std::stoi(tmp[3])>=0)
                    {
                        x = std::stoi(tmp[3]);
                    }
                     doublee[tmp[0]]=x;
               }   
            }
            if((std::map<std::string,std::string>::iterator)(stringg.find(tmp[0])) != stringg.end())
            {
                if(tmp[1] == "=")
                {
                 
                     stringg[tmp[0]]=tmp[2];
               }   
            }
            if((std::map<std::string,bool>::iterator)(booll.find(tmp[0])) != booll.end())
            {
                if(tmp[1] == "=")
                {
                    if(tmp[2]=="true"){
                     booll[tmp[0]]=true;
                    }
                    else if(tmp[2]=="false"){
                     booll[tmp[0]]=false;
                    }
                    else{std::cout<<i+1<<"Error : ";}
               }   
            }
        }
    }
    return 0;
}