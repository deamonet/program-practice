#include <stdio.h>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void ShowVec(const vector<int>& valList){
    int count = valList.size();
    for (int i = 0; i < count;i++){
        cout << valList[i] << "\t";
    };
    cout<<"\n";
}

void Show2Vec(const vector<vector<int>>& vallist2){
    int count = vallist2.size();
    for(int i=0; i < count;i++){
        cout<<"\n";
        ShowVec(vallist2[i]);
    }
}



class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> zeros;
        zeros.clear();
        if(m==0){return zeros;}
        else if(n==1){return matrix[0];}
        else{
            int x=0, y=0;
            int x_cnt = 0, y_cnt = 0;
            for(int i=0, j=0; i<m/2+1 || j<n/2+1; i++, j++){
                zeros.push_back(matrix[x][y]);
                cout<<"<"<<x<<","<<y<<">"<<"\t"<<"\n";y++;
                while(y<n-j){zeros.push_back(matrix[x][y]);cout<<"<"<<x<<","<<y<<">"<<"\t";y++;};
                y--;x++;cout<<"\n";
                while(x<m-i){zeros.push_back(matrix[x][y]);cout<<"<"<<x<<","<<y<<">"<<"\t";x++;};
                x--;y--;cout<<"\n";
                while(y>=j){zeros.push_back(matrix[x][y]);cout<<"<"<<x<<","<<y<<">"<<"\t";y--;};
                y++;x++;cout<<"\n";
                while(x>=i+1){zeros.push_back(matrix[x][y]);cout<<"<"<<x<<","<<y<<">"<<"\t";x--;};
                x++;cout<<"\n";
                y++;
            };
        };
        return zeros;
    };
};


int main(){
    Solution s;
    vector<int> nums;
    vector<vector<int>> data;
    int rows = 3, cols = 3;
    for(int j=0; j<rows; j++){
        nums.clear();
        for(int i=0;i<cols;i++){
            nums.push_back(i+cols*j);
        };
        data.push_back(nums);
    };
    Show2Vec(data);
    cout<<"\n\n";
    ShowVec(s.spiralOrder(data));
}
    