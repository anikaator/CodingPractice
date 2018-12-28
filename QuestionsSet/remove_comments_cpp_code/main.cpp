class Solution {
public:
    vector<string> removeComments(vector<string>& source) {

        bool skipnext = false;
        int cnt = 0;
        int len = source.size();
        string input = source[cnt++];
        vector<string> result;
        while(true) {
            if(input.length() <=0 || skipnext) {
              if(cnt < len) {
                input = source[cnt++];
              } else {
                return result;        
              }                
            }

            int pos1 = input.find("/*");
            if( pos1 >=0 && !skipnext) {
              string token;
              istringstream iss(input.substr(0, pos1));
              iss >> token;
              if((token.length() > 0)) {
                result.push_back(input.substr(0, pos1));
              }              
              input = input.substr(pos1+2);
              skipnext = true;
            }
            int pos2 = input.find("*/");
            if( pos2 >=0) {
              input = input.substr(pos2+2);
              skipnext = false;
              continue;
            }
            int pos3 = input.find("//");
            if( pos3 >=0 && !skipnext) {
              input = input.substr(0, pos3);
            }

            if(!skipnext) {
              string token;
              istringstream iss(input.substr(0, pos1));
              iss >> token;
              if((token.length() > 0)) {
                result.push_back(input.substr(0, pos1));                  
              }
              input = "";
            }
        }        
    }
};
