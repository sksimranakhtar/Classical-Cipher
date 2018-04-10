#include<bits/stdc++.h>
using namespace std;
map<int,int> keyMap; 
void setPermutationOrder(string key)
{               
    for(int i=0; i < key.length(); i++)
    {
        keyMap[key[i]] = i;
    }
} 
string encryptMessage(string msg,string key)
{
    int row,col,j;
    string cipher = "";
    col = key.length(); 
    row = msg.length()/col; 
    if (msg.length() % col)
        row += 1;
    char matrix[row][col];
    for (int i=0,k=0; i < row; i++)
    {
        for (int j=0; j<col; )
        { 
            if( isalpha(msg[k]))
            { 
                matrix[i][j] = msg[k];
                j++;
            }
            k++;
        }
    }
 
    for (map<int,int>::iterator ii = keyMap.begin(); ii!=keyMap.end(); ++ii)
    {
        j=ii->second;
        for (int i=0; i<row; i++)
        {
            if( isalpha(matrix[i][j]))
                cipher += matrix[i][j];
        }
    }
 
    return cipher;
}
 
string decryptMessage(string cipher,string key)
{
    int col = key.length();
    int row = cipher.length()/col;
    char cipherMat[row][col];
 
    for (int j=0,k=0; j<col; j++)
        for (int i=0; i<row; i++)
            cipherMat[i][j] = cipher[k++];
 
   
    int index = 0;
    for( map<int,int>::iterator ii=keyMap.begin(); ii!=keyMap.end(); ++ii)
        ii->second = index++;
 
    char decCipher[row][col];
    map<int,int>::iterator ii=keyMap.begin();
    int k = 0;
    for (int l=0,j; key[l]!='\0'; k++)
    {
        j = keyMap[key[l++]];
        for (int i=0; i<row; i++)
        {
            decCipher[i][k]=cipherMat[i][j];
        }
    }
 
    string msg ="";
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            if(decCipher[i][j] != '_')
                msg += decCipher[i][j];
        }
    }
    return msg;
}
 
int main(void)
{   
    // key input
    cout << "Enter the KEY" << endl;
    string key;
    cin>>key;
    // Plain text input
    cout << "Enter the PlainText"<< endl;
    string msg;
    cin>>msg;
    int len=msg.length();
    int col = key.length();
    //int row = msg.length()/col;
    if (msg.length() % col!=0){
    	int left=col-msg.length() % col;
	for(int k=0;k<left;k++) msg=msg+"X";
    }
        

    // Mapping of key in order
    setPermutationOrder(key);

    // first encyption
    string cipher1 = encryptMessage(msg,key);
    // Second Encryption
    string cipher2 = encryptMessage(cipher1,key);
   
    // First Decryption 
    string cipher = decryptMessage(cipher2,key);
    // Second Decryption
    string message = decryptMessage(cipher,key);

    // OUTPUT
    // conversion into uppercase decrypted message
    for(int i=0;i<cipher1.length();i++){
        if(cipher1[i]<='z' && cipher1[i]>='a'){

         cipher1[i]-=32;
        }
    }
    
    // conversion into uppercase of decrypted message
    for(int i=0;i<cipher2.length();i++){
        if(cipher2[i]<='z' && cipher2[i]>='a'){

         cipher2[i]-=32;
        }
    }

    cout << "After 1st Transposition, Encrypted Message: " << cipher1 << endl;
    cout << "After 2nd Transposition, Encrypted Message: " << cipher2 << endl;
    
    cout << "Final Decrypted Message: " << message << endl;
 
    return 0;
}

