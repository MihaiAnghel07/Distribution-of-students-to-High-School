Hello!

This is a small project that simulates the software that distributes 
students in high school.The software simulates the method by which in 
Romania, the 8th grade students are distributed to high schools 
according to grades and very importantly the chosen options. 

Admission is by "sliding". What do this means?

Each high school has a certain declared capacity. Each student completes 
a form where he chooses the codes of the high schools where he would like 
to be admitted (of course, the first code represents the favorite high 
school). Thus, the distribution is made according to grades, and if the 
favorite high school places are filled, we move on to option 2, but 
students who have chosen high school 2 as their favorite high school have 
priority, even if they have lower grades and so on. So students must be 
very careful when choosing options, otherwise they may remain 
undistributed in the first stage.

The program uses two structures: one that defines the student and one that 
defines the high school and their data.
The data in the file is read. Then all students are ordered in descending 
order, depending on the grade. With the help of some functions, you go 
through the students' options and as we presented above, the distribution 
is made.

The program uses a database of 200 students (I was a little lazy to generate 
more), who come from 9 middle schools, and can opt for 5 high schools.
Finally, the results are displayed in various files showing the assigned 
students, the non-assigned students and the list of each high school with 
the students admitted to it.


The code was written and run with Codeblocks.
