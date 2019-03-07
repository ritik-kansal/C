/*The students of college are getting jealous of the students of college . managed to beat in all the sports and games events. The main strength of the students of is their unity. The students of decide to destroy this unity. The geeks of prepared a special kind of perfume. Anyone who inhales this perfume becomes extremely violent. The students of somehow manage to spread this perfume throughout

's campus atmosphere.

There are N boys
and N girls in college. Each boy has a crush on a single girl and each girl has a crush on a single boy. Since the perfume has been inhaled by each and every student of

college, every student decides to beat up his/her crush's crush, ie. , if boy x has a crush on girl y and girl y has a crush on boy z, x will beat z up, provided, of course, if x and z is not the same person.

The doctor of

college foresees this situation. He cannot stop so many people from beating each other up, however, he can be prepared for the worst-case patient(s). The worst-case patient(s) will be the patient(s) who get(s) beaten up by the maximum number of students. The doctor comes to you for help. He has 2 questions for you :

1. What is the number of beatings received by the worst-case patient(s) ?

2. What is the total number of pairs of students who ended up beating up each other ?

Input :

The first line comprises of T, the number of test cases. Each test case comprises of 3 lines. The first line consists of N.

The next line consists of N space separated natural numbers between 1 and N inclusive such that the

number denotes the the crush of boy i.

The next line consists of N space separated natural numbers between 1 and N inclusive such that the

number denotes the the crush of girl i.

Output :

For every test case, on a new line, print two space separated integers, the answer to doctor's question 1 followed by answer to doctor's question 2.

Constraints :

SAMPLE INPUT

2
3
2 2 1
3 2 1
4
2 3 4 1
2 3 4 1

SAMPLE OUTPUT

1 0
1 4

Explanation

Test Case 1 :

Boy 1 likes Girl 2 and Girl 2 likes Boy 2. So, Boy 1 beats up Boy 2. Boy 2 likes Girl 2 and Girl 2 likes Boy 2. Boy 2 is happy and will obviously not beat himself up. Boy 3 likes Girl 1 and Girl 1 likes Boy 3. Boy 3 is happy and will obviously not beat himself up. Girl 3 likes Boy 1 and Boy 1 likes Girl 2. So, Girl 3 beats up Girl 2.

Finally number of beatings received by : Boy
Boy Boy Girl Girl Girl

Moreover, there are no such pairs of students who beat each other up. ie. there are no two students (boys or girls) i and j such that i beats up j and j beats up i. Hence the answer to test case 1 is '1 0'.
Time Limit: 2.0 sec(s) for each input file.
Memory Limit: 256 MB
Source Limit: 1024 KB
Marking Scheme: Marks are awarded if any testcase passes.
Allowed Languages: Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), TypeScript, Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, Visual Basic
*/
#include<stdio.h>
int main()
    {
        int n,max=0;
        scanf("%d",&n);
        int b[n+1],g[n+1],beat[n+1],beatg[n+1];
        int i,j;
        for(i=1;i<n+1;i++)
        {
            scanf("%d",&b[i]);
        }
        for(i=1;i<n+1;i++)
        {
            scanf("%d",&g[i]);
            beat[i]=0;
            beatg[i]=0;
        }
        for(i=1;i<n+1;i++)
        {

            if(g[b[i]]!=i)
            {
                beat[g[b[i]]]++;
            }
            if(b[g[i]]!=i)
            {
                beatg[b[g[i]]]++;
            }
        }
        max=beat[1];
        for(i=1;i<n+1;i++)
        {
            printf("%d  %d\n",beat[i],beatg[i]);
            if(max<beat[i])
            {
                max=beat[i];
            }
        }
        for(i=1;i<n+1;i++)
        {
            if(max<beatg[i])
            {
                max=beatg[i];
            }
        }
        printf("Worst case is %d ",max);
    }
