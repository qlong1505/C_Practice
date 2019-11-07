# C_Practice

copy from 

# [PROGRAMMING INTERVIEWS](http://tech-queries.blogspot.com/)


## [Find if given pattern is present in given grid](http://tech-queries.blogspot.com/2011/07/find-if-given-pattern-is-present-in.html)

Posted by Unknown in Monday, July 4, 2011

[Tweet](http://twitter.com/share)

**Question:** You are given a 2D array of characters and a character pattern. WAP to find if pattern is present in 2D array. Pattern can be in any way (all 8 neighbors to be considered) but you can’t use same character twice while matching. Return 1 if match is found, 0 if not.  
  
**Example:** Find “microsoft” in below matrix.  
  
![](http://2.bp.blogspot.com/-NqdoFzZ_-5U/ThHsG7NTtqI/AAAAAAAAEDM/9W450BexWoE/s320/string%2Bin%2B2D%2Barray.png)  
We can see the read color character, which form “Microsoft” in above 2D array.  
  
**Answer:** I was asked this question in a [Microsoft interview](http://tech-queries.blogspot.com/2010/08/microsoft-interview-questions.html) almost a year ago. A reader [asked me](http://tech-queries.blogspot.com/2010/08/microsoft-interview-questions.html?showComment=1308119091681#c6938255790358817909) to post the solution for this.  
  
Manually finding the solution of this problem is relatively intuitive, we just need to describe an algorithm for it. Ironically, describing the algorithm is not the easy part.  
  
**How do we do it manually?** First we match the first element; if it matched we matched the 2nd element in the 8 neighbors of first match; do this process recursively; when last character of input pattern matches, return true.  
  
During above process, you take care not to use any cell in 2D array twice. For this purpose, you mark every visited cell with some sign. If your pattern matching fails at some place, you start matching from the beginning (of pattern) in remaining cells. While returning, you unmark visited cells.  
  
Lets convert above intuitive method in algorithm. Since we are doing similar checks every time for pattern matching, a recursive solution is what we need here.  
  
In recursive solution, we need to check if the substring passed is matched in the given matrix or not. The condition is not to use the already used cell. For finding already used cell, we need to have another 2D array to the function (or we can use an unused bit in input array itself.) Also, we need the current position of input matrix, from where we need to start. Since we need to pass a lot more information than actually given, we should be having a wrapper function to initialize that extra information to be passed.  
  
**Algorithm:**  

If you are past the last character in pattern
    Return true

If you got an used cell again
    Return falseIf you got past the 2D matrix  
    Return false

If searching for first element and cell doesn’t match
    findmatch with next cell in row-first order (or column first order)

otherwise if character matches
    mark this cell as used
    res = findmatch with next position of pattern in 8 neighbors
    mark this cell as unused
    Return res

Otherwise
    Return false

  

**Code:**  
  
***

 
#define MAX 100
//level: index till which pattern is matched
//x, y: current position in 2D array
bool findmatch(char mat[MAX][MAX], char *pat, int x, int y, int nrow, int ncol, int level)
{

    if (level == strlen(pat)) //pattern matched
        return true;
                
    if (x<0 || y<0 || x>=nrow || y>=ncol)
     return false; 
    
    if (mat[x][y] == pat[level])
    {
     // printf("{%d, %d}\n",x,y);
        bool res;

        //marking this cell as used
        char temp = mat[x][y];
        mat[x][y] = '#';       
             
        //finding subpattern in 8 neighbours     
        res = findmatch(mat, pat, x-1, y, nrow, ncol, level+1)   ||
              findmatch(mat, pat, x+1, y, nrow, ncol, level+1)   ||
              findmatch(mat, pat, x, y-1, nrow, ncol, level+1)   ||
              findmatch(mat, pat, x, y+1, nrow, ncol, level+1)   ||
              findmatch(mat, pat, x+1, y+1, nrow, ncol, level+1) ||
              findmatch(mat, pat, x+1, y-1, nrow, ncol, level+1) ||
              findmatch(mat, pat, x-1, y+1, nrow, ncol, level+1) ||
              findmatch(mat, pat, x-1, y-1, nrow, ncol, level+1);

        //marking this cell as unused
        mat[x][y] = temp;
        return res;
    }
    else
        return false;
}

bool findmatch_wrapper(char mat[MAX][MAX], char *pat, int nrow, int ncol)
{

 // if total characters in matrix is less then pattern lenghth 

    if (strlen(pat) > nrow*ncol)
        return false;

    for (int i=0; i<nrow; i++)
     for (int j=0; j<ncol; j++){

      if (mat[i][j] == pat[0])
                    if(findmatch(mat, pat, i, j, nrow, ncol, 0)) 
                          return true;
     }
    return false;
}

  ***
  
Please note the use of OR operator while calculating res. This confirms me that I don’t evaluate next condition as soon as one of the conditions evaluates to true.  
  
**Complexity:**  
Best case complexity is obviously O(1), if pattern is NULL.  
  
**Worst case:** What will be worst case for this problem. The matrix (lets say N*N) is filled with ‘A’ in all the cells and pattern is “AAAA…….AAAAB” of length N^2. Then it will match with every cell, search in 8 neighbors recursively and fails at last element every time.  
  
I'm leaving it to readers to find the complexity of this approach.
