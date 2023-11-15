//Output a string in N-character format
/*
Input1:s = "PAYPALISHIRING", numRows = 3
Output1:"PAHNAPLSIIGYIR"

Input2:s = "PAYPALISHIRING", numRows = 4
Output2:"PINALSIGYAHRPI"

P     I    N
A   L S  I G
Y A   H R
P     I

Input3:s = "A", numRows = 1
Output3:"A"
*/
char* convert(char *s, int numRows) {
    if(numRows == 1)
        return s;
    else if(numRows>1){
        int n = strlen(s);//get the length of the string;
        int k = 2*numRows-2;
        int index=0;
        int num = n/k;//get the number of the groups;
        char *p = (char*)malloc((n + 1) * sizeof(char)); // +1 for the null terminator
        for (int i = 0;i<numRows;i++){
            //print line by line
            if(i==0||i==numRows-1){
                //print the first line;
                int j=0;
                while(i+j*k<n){
                    p[index++]=s[i+j*k];
                    j++;
                }
            }else{// 0<i<numRows-1
                //print the lines between the first and last line.
                int j=0;
                for(j=0;j<num;j++){
                    p[index++]=s[i+j*k];
                    p[index++]=s[(k-i)+j*k];
                }
                if(i+j*k<n)
                    p[index++]=s[i+j*k];
                if((k-i)+j*k<n)
                    p[index++]=s[(k-i)+j*k];
            }
        }
        p[index]='\0';
        return p;
    }
    return 0;
}
