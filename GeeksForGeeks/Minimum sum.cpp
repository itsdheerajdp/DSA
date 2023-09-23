class Solution{   
public:
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
  
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
  
    return str;
}
    string solve(int arr[], int n) {
        // code here
      sort(arr,arr+n);
      string num1="",num2="";
      for(int i=0;i<n;i++){
          if(i%2==0){
              if(arr[i])num1+=to_string(arr[i]);
          }
          else{
             if(arr[i]) num2+=to_string(arr[i]);
          }
      }
      
      string ans=findSum(num1,num2);
      if(ans=="")return to_string(0);
      else return ans;
    }
};