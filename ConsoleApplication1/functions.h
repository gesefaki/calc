#pragma once

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

string Binary(const string& IP);
string netAddress(const string& binaryIP, int mask);
string broadAddress(const string& binaryIP, const int mask);
int Hosts(const int mask);

#endif 