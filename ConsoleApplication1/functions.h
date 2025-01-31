#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

string Binary(const string& IP);
string netAddress(const string& binaryIP, const int mask);
string broadAddress(const string& binaryIP, const int mask);
string firstAddress(const string& netIP);
string lastAddress(const string& broadIP);
int Hosts(const int mask);


#endif 