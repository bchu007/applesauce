//Name: Chu, Brian
//Assignment 4: map 
//student ID: 861174197
//Date: 5/4/15

#ifndef MYMAP_H
#define MYMAP_H


#include <set>


using namespace std;

template <typename Key, typename T>
class map_pair {
    public:
        const Key first;
        mutable T second;
        map_pair(Key s, T t): first(s), second(t) {};
};

template <typename Key, typename T>
struct classcomp {
    typedef map_pair<const Key, T> Pair;
    bool operator() (const Pair& lhs, const Pair& rhs) const {
        return lhs.first < rhs.first;
    }
}; //end classcomp


template <typename Key, typename T>
class mymap : public set<map_pair<const Key, T>, classcomp<const Key, T> > {
    public:

        typedef map_pair< const Key, T > Pair;                  // short name
        typedef set< Pair, classcomp< const Key, T> > PairSet;  // short name
        
        PairSet theSet;
        
        mymap() {};
        
        mymap(const mymap &temp) {
            theSet = temp.theSet;
        }
        
        mymap& operator=(const mymap &rhs) {
            theSet = rhs.theSet;
        }
        
        ~mymap() {
            theSet.clear();
        }
        
        pair<typename PairSet::iterator, bool> insert(Pair p) {
            return theSet.insert(p);
        }
        
        T& operator[]( const Key x ) {
            pair<typename PairSet::iterator,bool> i = insert( Pair(x,T()) );
            return i.first->second;
        }
        
        
        typename PairSet::iterator find(const Key& x) const {
            return theSet.find(Pair(x, T()) );
            //return iterator to equivalent entry, in any, else end()
        }
        
        
        typename PairSet::iterator end() const {
            return theSet.end();
        }
        
};

#endif 