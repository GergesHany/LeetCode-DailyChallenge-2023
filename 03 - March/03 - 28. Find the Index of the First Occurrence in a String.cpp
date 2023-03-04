class Solution {
public:
    int strStr(string haystack, string needle) {
       int Idx =  haystack.find(needle); // find the index of the first occurrence of needle in haystack
       return Idx; // return the index
    }
};