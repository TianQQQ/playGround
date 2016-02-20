//
//  main.cpp
//  RapidxmlTest1
//
//  Created by Tian Qiu on 11/29/15.
//  Copyright © 2015 Tian Qiu. All rights reserved.
//
#include "../rapidxml/rapidxml.hpp"
#include "../rapidxml/rapidxml_utils.hpp"
#include "../rapidxml/rapidxml_print.hpp"

#include<iostream>
using namespace rapidxml;

int main()
{
    file<> fdoc("config.xml");
    std::cout<<fdoc.data()<<std::endl;
    xml_document<> doc;
    doc.parse<0>(fdoc.data());
    
    std::cout<<doc.name()<<std::endl;
    
    //! 获取根节点
    xml_node<>* root = doc.first_node();
    xml_node<>* delnode = root->first_node("color");
    root->remove_node(delnode);//先删除address节点
    //
    xml_node<>* lnode = root->first_node("size");//找到post节点
    xml_node<>* mynode=doc.allocate_node(node_element,"address","河北");
    root->insert_node(lnode,mynode);
    
    std::string text;
    rapidxml::print(std::back_inserter(text),doc,0);
    
    
    std::cout<<text<<std::endl;
    
    std::ofstream out("version.xml");
    out << doc;
    system("pause");
    return 0;
}