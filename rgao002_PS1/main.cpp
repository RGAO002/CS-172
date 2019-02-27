#include "docIndex.h"
#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <set>
#include <boost/algorithm/string.hpp>


    


bool stopword(std::string word)
{
    std::ifstream in("stoplist.txt");
    std::ostringstream tmp; 
    tmp << in.rdbuf(); 
    std::string stuff = tmp.str();
    std::stringstream ss(stuff);
    while (ss >> stuff)
    {
        if (boost::iequals(word, stuff))
        {
           return true;
        }
        
    }
    return false;
}

void wordCount(std::vector<int> &wordcnt, std::string stuff, int file_id)
{
    int cnt = 0;
    std::stringstream ss(stuff);
    while (ss >> stuff)
    {
        //std:: cout << stuff << std::endl;
        if (!stopword(stuff))
        {
           cnt++;
        }
        
    }
    wordcnt.at(file_id-1) = cnt;
    
}



int main()
{
     
     
     
     std::string userInput;
     std::cout << "Enter term: ";
     std::cin >> userInput;
     
     while (userInput != "QUIT")
     {
         std::vector<int> wordcnt(20);
         
         Posting term;
         term.initPosting();
         int doc_cnt = 0;
         /*if (userInput.empty())
         {
            std::cout << "Enter term: ";
            std::cin >> userInput;
         }*/
         while (stopword(userInput))
         {
            std::cout << "Stop Word, invalid." << std::endl;
            std::cout << "Enter term: ";
            std::cin >> userInput;
         }
     
    
     

         for (int i = 1; i <= 20; ++i)
         {
            std::string filename;
            
            if (i < 10)
            {
                filename = "./data/file0" + std::to_string(i) + ".txt"; //read file
                //std::cout << "./data/file0" + std::to_string(i) + ".txt";
    
            }
            else
            {
                filename = "./data/file" + std::to_string(i) + ".txt"; //read file
    
            }
            std::ifstream in(filename);
            if(!in)
            {
                std::cout << "File reading unsuccessful." << std::endl;
            }
                
            std::ostringstream tmp; 
            tmp << in.rdbuf(); 
            std::string stuff = tmp.str();
            

            
            std::stringstream ss(stuff);
            wordCount(wordcnt, stuff, i);
           // std::cout << wordcnt.at(i-1) << " ";
            int cnt = 0;
            while (ss >> stuff)
            {
                if (userInput == stuff)
                {
                    cnt++;
                }
            }
           // std::cout << cnt << " ";
           if (cnt != 0)
           {
              doc_cnt++;
              term.insertPosting(i, cnt);
           }
           
        }
        if (doc_cnt != 0)
        {
            term.display(term, wordcnt, doc_cnt);
        }
        else
        {
            std::cout << "'" << userInput << "'" << " is not found within any documents." << std::endl;
        }
        std::cout << "Enter term: ";
        std::cin >> userInput;
    }
     
}