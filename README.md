# KNN PROJECT
The purpose of the KNN algorithm is to make a feature determination for a point 
by checking the k nearest neighbors. So, this program designed for this purpose. It is 
aimed to run all processes with the help of a menu. An object of each class is created for 
this menu object and these objects are used throughout the program. Since the switch 
key structure is used with the loop in the menu, an object from each class is created and 
kept in order to prevent the objects from disappearing and getting error every time.
Since these generated points can be large, references are used to use these points 
throughout the program. Otherwise, there may be a situation that may slow down the 
program with unnecessary copy formations. Points are kept with pairs. First pair is 
formed by the index of the point and the category id. Second pair is formed with the x 
and y coordinates of the point. These two pairs are stored as pairs again. In order to be 
more pleasing to the eye, these points are then printed on the coordinate plane with the 
help of the graph class.

The program gives the following output at the end (for k=5):
![image](https://github.com/gfbpae/KNN/assets/94529874/5f70dff6-e364-4730-aeae-e919ca934ba4)
