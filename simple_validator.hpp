#include <iostream>
#include <string>
#include <stack>

bool DetermineXml(const std::string &input)
{
    std::stack<std::string> tags;
    std::string currentTag;
    bool inTag = false;

    for (char ch: input)
    {
        if (ch == '<'){
            if(inTag){
                //malformed xml: '<' inside a tag(double '<')
                return false;
            }
            inTag = true;
            currentTag.clear();
        }
        else if (ch =='>'){
            if(!inTag){
                //malformed xml: '>' without a corresponding 
                return false;
            }
            inTag = false;
            
            if(currentTag.empty()){
                //malformed xml: empty tag 
                return false;
            } 

            if(currentTag[0] == '/'){
                //closing tag
                currentTag = currentTag.substr(1);//remove '/'
                if(tags.empty() || tags.top() != currentTag){
                    //malformed xml: closing tag without a corresponding opening tag
                    return false;
                }
                tags.pop();
            }
            else{
                //opening tag
                tags.push(currentTag);
            }
        }
        else if(inTag){
            currentTag += ch;
        }
    }
    return tags.empty();
}
