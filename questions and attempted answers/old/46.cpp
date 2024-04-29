#include <vector>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <typeinfo.h>

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
    vector<vector<int>> permute(vector<int>& nums){
        vector<int> remain;
        vector<vector<int>> total;
        vector<vector<int>> data;
        if(nums.size()==0 || nums.size()==1){
            data.resize(1);
            data[0] = nums;
            return data;
        }else if(nums.size()==2){
            data.resize(2);
            data[0] = nums;
            int temp = nums[1];
            nums[1] = nums[0];
            nums[0] = temp;
            data[1] = nums;
            return data;
        }else{
            for(int i=0; i<nums.size(); i++){
                cout<<"i\t"<<i<<"\n";

                remain.clear();
                data.clear();

                for(int j=0; j<nums.size(); j++){
                    if(j != i){remain.push_back(nums[j]);};
                };
                
                ShowVec(remain);
                data = permute(remain);
                cout<<"\n\n";
                cout<<"data begin";
                Show2Vec(data);
                cout<<"data end";

                cout<<"\n\n";

                for(int n=0; n<data.size(); n++){
                    data[n].push_back(nums[i]);
                    total.push_back(data[n]);
                };
            };
            return total;
        };
        return total;
    };
};

int main(){
    Solution s;
    vector<int> nums;
    for(int i=0;i<5;i++){
        nums.push_back(i);
        cout<<nums[i]<<",";
    };
    cout<<"\n\n";

    vector<vector<int>> data = s.permute(nums);
    printf("finally");    
    cout<<"\ndata size\t"<<data.size();
    cout<<"\n\n";
    Show2Vec(data);
}