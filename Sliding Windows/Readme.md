## Title: Understanding the Sliding Window Technique
There are two types-
- Variable Size Sliding Window
- Fixed Size Sliding Window

## Identification-Problem wiil be around sub-arrays and substrings 
Always remember 
- It will give you a condition and will ask about the window size and vice versa
- Size can be fixed or variable.
- shortest or longest window
- fixed size window
## Variable size Window
Remember Good Segment Technique (the subarray which statisfies the condition)
- Good Segment Increasing Technique
- It means if a sub array is good then all sub-arrays contained in it is good
- For ex- condition sum<=7 [1,2,3,9] [1,2,3] is good ,then [3],[2,3] is also good
- Good Segement Decreasing
- It means if a sub array is good then all sub-arrays containing it are good
- For ex- condition sum>=7 [1,2,3,9] [1,2,4] is good ,then [1,2,4,9] also good
- Attaching an article 
- [Click here for more information](https://leetcode.com/problems/frequency-of-the-most-frequent-element/solutions/1175088/C++-Maximum-Sliding-Window-Cheatsheet-Template/) 

## Fixed Size Sliding Window
- high=j and low=i j-i+1=k
- for every iteration 
- Add next element to the window
- Remove the previous element from the window
