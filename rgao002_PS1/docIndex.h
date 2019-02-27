#ifndef DOCINDEX_H
#define DOCINDEX_H
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

class Posting
{
    public:
    int id;
    int doc_freq;
    void initPosting();
    void insertPosting(int temp_id, int freq);
    void display(Posting a, std::vector<int> temp, int doc_cnt);
    //Posting *prev;
    Posting *next;
    private:
    Posting *head;
    Posting *tail;


};

void Posting::initPosting()
{
    Posting *newPosting;
    newPosting = new Posting;

    newPosting->next = NULL;
    head = newPosting;
    tail = newPosting;
    newPosting->id = 0;
}

void Posting::insertPosting(int temp_id, int freq)
{
    Posting *newPosting;
    newPosting = new Posting;
    newPosting->id = temp_id;
    newPosting->doc_freq = freq;
    //std::cout << newPosting->id << " " << newPosting->doc_freq << std::endl;
    //this->prev = NULL;
    tail->next = newPosting;
    tail = newPosting;
    tail->next = NULL;
}

void Posting::display(Posting a, std::vector<int> temp, int doc_cnt)
{
    
    if (head->id == 0)
    {
        head = head->next;
    }
    
    while (head != NULL)
    {
        
           
         std::cout << "doc_id: " << head->id;
         std::cout << ", weighting: " << head->doc_freq;
         std::cout << ", tf: " << head->doc_freq / 1.0 / temp.at(head->id-1);
         std::cout << ", idf: " << std::log10(20.0 / doc_cnt);
         std::cout << ", tf-idf: " << head->doc_freq / 1.0 / temp.at(head->id-1) * std::log10(20.0 / doc_cnt);
         std::cout << std::endl;
         
         head = head->next;
         
    }
    std::cout << "# of documents the term is contained: " << doc_cnt << std::endl;    
}

#endif





