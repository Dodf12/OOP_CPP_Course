// Test program starter file for CSCI 60 Homework 3; due Friday 10/18/24

#include <iostream>
#include "lexicon.h"

using namespace std;

void yourTestCode();
void foundingDocs();
void annaKarenina();

int main() {
  // use your own txt files and your own test code to test as you go
  //yourTestCode();
  // use these tests and the provided txt files to check your output at the end
  foundingDocs();
  annaKarenina();
  return 0;
}

// Code for you to write while implementing lexicon.cpp
void yourTestCode() {
  // replace this with whatever you want in here!
  Lexicon l("decl.txt");
  Lexicon smallFile("helloworld.txt");

  // cout << "Size: " << smallFile.size() << endl;
  // cout << smallFile << endl;
  // cout << smallFile.remove("bombastic") << endl;
  // cout << smallFile;
  
  cout << "First test: " << l.size() << endl; // check: 1322 total, 632 distinct
  // cout << l << endl;

  //Testing insert
  // cout << l.insert("Sameul") << endl;
  // cout << l << endl;

  //Testing contains
  // cout << l.contains("Sameul") << endl;

  //Testing Remove
  // cout << l.remove("Sameul") << endl;
  // cout << l;

  //Testing | operator
  // smallFile | l;
  // cout << smallFile << endl;
}

// Constructs and uses lexicon objects to do some text analysis.
// Pre: Must have const.txt decl.txt preamble.txt prescramble.txt in directory.
void foundingDocs() {
  
  // construct two lexicons from files and report their sizes
  Lexicon constitution("const.txt");
  Lexicon declaration("decl.txt");
  size_t nConst = constitution.size(), nDecl = declaration.size();
  cout << "\nThe US Constitution contains " << nConst << " distinct words.\n";
  cout << "The Declaration of Independence contains " << nDecl
    << " distinct words.\n";

  // combine lexicons using set operatons
  Lexicon both = constitution & declaration;
  cout << "Size of array after intersect operator " <<both.size() << endl;
  Lexicon either = constitution | declaration;
  cout << "Size of array after union operator " <<either.size() << endl;
  Lexicon exactlyOne = constitution ^ declaration;
  cout << "Size of array after ^ operator " <<exactlyOne.size() << endl;
  
  size_t nCommon=both.size(), nTotal=either.size(), nDiff=exactlyOne.size();
  cout << "The two documents have " << nCommon << " words in common.\n";
  cout << "There are " << nDiff << " words in their symmetric difference.\n";
  if (nTotal!=nCommon+nDiff) {
    cout << "Does it make sense that there are " << nTotal
      << " words in the combined lexicon?\n";
  }
  cout << endl;
  

    
  // check subset relationships
  if (constitution<=declaration) {
    cout << "Are all Constitution words in the Declaration of Independence?\n";
  } 
  else {
    cout << 100.0*nCommon/nConst
      << "% of Constitution words are in the Declaration of Independence.\n";
    string uncommonWord = exactlyOne[0];
    if (constitution.contains(uncommonWord)) {
      cout << "\"" << uncommonWord << "\" is one that is not.\n";
    }
  }
  
  if (constitution>=declaration) {
    cout << "Are all Declaration of Independence words in the Constitution?\n";
  } else {
    cout << 100.0*both.size()/nDecl
      << "% of Declaration of Independence words are in the Constitution.\n";
    string uncommonWord = exactlyOne[nDiff-1];
    if (declaration.contains(uncommonWord)) {
      cout << "\"" << uncommonWord << "\" is one that is not.\n";
    }
  }
  cout << endl;

  // check strict subset relationships
  Lexicon preamble("preamble.txt");
  if (preamble<constitution) {
    cout << "The Constitution's preamble contains " << 100.0*preamble.size()/nConst
      << "% of the distinct words \nin the Constitution and no others.\n";
  } else {
    cout << "How can the preamble contain words not in the full Constitution?\n";
  }
  if (constitution>preamble) {
    cout << "The strict subset relationship remains true if we flip\n"
      << "the operator and args even though it's a different function call.\n";
  } else {
    cout << "Flipping the operator and args shouldn't change the answer.\n";
  }
  cout << endl;

  // check equivalence after changing word order
  Lexicon prescramble("prescramble.txt");
  if (preamble==prescramble) {
    cout << "Scrambling the words of the preamble gives an equivalent lexicon,";
    if ((preamble | prescramble) != preamble) {
      cout << " but why would the union of these things be non equivalent?\n";
    } else {
      cout << "\nwhich is equivalent to the union of the two.\n";
    }
  } else {
    cout << "Whoops, scrambling words shouldn't break equivalence.\n";
  }
  cout << endl;
  
}

// Checks that construction for large text files reaches capacity without error.
// Pre: Must have anna_karenina.txt in directory.
void annaKarenina() {
  ifstream file("anna_karenina.txt");
  string token;
  size_t nRead = 0;
  while (file >> token) nRead++;
  file.close();
  cout << "\nAnna Karenina is " << nRead << " words (with repetition).\n";

  Lexicon akLex("anna_karenina.txt");
  size_t n = akLex.size();
  if (n<Lexicon::CAPACITY) {
    cout << "It contains " << n << " distinct words.\n";
  } else {
    cout << "The number of distinct words reaches our class's capacity.\n\n";
  }
}
