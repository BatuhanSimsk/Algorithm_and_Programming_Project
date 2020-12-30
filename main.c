#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

//WE HAVE LOTS OF COMMENT LINES SUCH AS "Printf()" .THE REASON WE USE THESE COMMENT LINES SO OFTEN IS TO DETECT ERRORS
//BY TRYING COMMENT LINES MANY TIMES TILL OUR PROGRAM IS READY FOR THE USER.

const char matrix_bigram_strings[10][3] ={"th", "he", "in", "er", "an", "en", "ch", "de", "ei", "te"};

const char matrix_trigram_strings[10][4]={"the", "and", "ing", "ent", "ion", "der", "sch", "ich", "nde", "die"};

const char languages[2][8]={"english", "german"};

//Frequency values of english language
 const float frequency_eng[20]={ 2.71, 2.33, 2.03, 1.78, 1.61, 1.13, 0.01, 0.01, 0.01, 0.01, 1.81, 0.73, 0.72, 0.42, 0.42, 0.01, 0.01, 0.01, 0.01, 0.01 };
 //Frequency values of german language
 const float frequency_germ[20]={ 0.01, 0.89, 1.71, 3.90, 1.07, 3.61, 2.36, 2.31, 1.98, 1.98, 0.01, 0.01, 0.01, 0.01, 0.01, 1.04, 0.76, 0.75, 0.72, 0.62 };


float calculated_frequencies[20];
float distances [2]={0,0};

int e = 0;      //These variables are defined global so we do not need to define them in every function..
int g = 0;
int m;
int n;

void get_string(char x[])
{
char c;
  for(int i=0; c!=EOF ;i++)
    {
    c=getchar();
    x[i]=c;
    }

//After write or paste your string,press enter,write EOF character via CTRL+Z combination and press enter again.
}

void filter_str(char y[])
{
    int i = 0;
    for (; i<strlen(y) ; i++)
    {
        if (97<=y[i] && y[i]<=122)     //This part is controlling the letters of the text are lowercase(a-z) or not.
            {
   //        printf("%c",y[i]);
            }

        else if(65<=y[i] && y[i]<=90)  //This part is controlling the letters of the text are uppercase(A-Z) or not.
            {                              //If the letters are uppercase,they converted lowecase.
            y[i] = tolower(y[i]);
     //       printf("%c",y[i]);
            }

        else {                             //This part is convert non-alphanumeric characters to "space character"(ASCII:32)
              y[i]=32;
      //        printf("%c",y[i]);
        }
    }

}

void calculate_frequencies_bi(char z[])
{

    int i;
    int total_bigram_counter=0;
    float counter_th=0;
    float counter_he=0;
    float counter_er=0;
    float counter_in=0;
    float counter_an=0;
    float counter_en=0;
    float counter_ch=0;
    float counter_de=0;
    float counter_ei=0;
    float counter_te=0;


    for(i=0;z[i];i++)
    {
            for(int a=0;a<10;a++)
            {
                if(matrix_bigram_strings[a][0]==z[i])
                     {  if(matrix_bigram_strings[a][1]==z[i+1])
                            {
                                total_bigram_counter++;

                              switch (a)                      //That switch-case structure computes every single bigram -according our bigram list- in text one-by-one
                                {                             //and assign them all to individual variables.
                                    case 0:
                                        counter_th++;

                                    break;


                                    case 1: ;

                                        counter_he++;

                                    break;

                                     case 2: ;
                                        counter_in++;

                                    break;

                                    case 3: ;
                                        counter_er++;

                                    break;

                                    case 4: ;
                                        counter_an++;

                                    break;

                                    case 5: ;
                                        counter_en++;

                                    break;

                                     case 6: ;
                                        counter_ch++;

                                    break;

                                    case 7: ;
                                        counter_de++;

                                    break;

                                    case 8: ;
                                        counter_ei++;

                                    break;

                                    case 9: ;
                                        counter_te++;

                                    break;
                                }
                            }
                    }
            }
    }

printf("\n\n");
printf("Number of 'th' bigram: %.2f\n",counter_th);
printf("Number of 'he' bigram: %.2f\n",counter_he);
printf("Number of 'in' bigram: %.2f\n",counter_in);
printf("Number of 'er' bigram: %.2f\n",counter_er);
printf("Number of 'an' bigram: %.2f\n",counter_an);     //We decided to print all bigrams individually.
printf("Number of 'en' bigram: %.2f\n",counter_en);
printf("Number of 'ch' bigram: %.2f\n",counter_ch);
printf("Number of 'de' bigram: %.2f\n",counter_de);
printf("Number of 'ei' bigram: %.2f\n",counter_ei);
printf("Number of 'te' bigram: %.2f\n",counter_te);





    //When we tried to make assignment the array like this,we got an error below.

    /*for(int i=0;i<10;i++)
        {
            float calculated_frequencies[i] = bigram_array[i];    //'variable sized object may not be initialized' error due to this loop//

        }
    */

   //So we decided make assignment to array like this.


calculated_frequencies[0]= counter_th;
calculated_frequencies[1]= counter_he;
calculated_frequencies[2]= counter_in;
calculated_frequencies[3]= counter_er;
calculated_frequencies[4]= counter_an;
calculated_frequencies[5]= counter_en;
calculated_frequencies[6]= counter_ch;
calculated_frequencies[7]= counter_de;
calculated_frequencies[8]= counter_ei;
calculated_frequencies[9]= counter_te;

   printf("\nTotal Bigram Number: %d\n",total_bigram_counter); //Total Bigram Number in text according our bigram list.

   printf("\nBigram Frequency Matrix:");

    for(int i=0;i<10;i++)
        {
          printf("%.2f\t",calculated_frequencies[i]);       //We print bigram frequency matrix.

        }
      printf("\n");
    }

void calculate_frequencies_tri(char m[])
{


    int total_trigram_counter=0;
    float counter_the=0;
    float counter_and=0;
    float counter_ing=0;
    float counter_ent=0;
    float counter_ion=0;
    float counter_der=0;
    float counter_sch=0;
    float counter_ich=0;
    float counter_nde=0;
    float counter_die=0;

    for(int i=0;m[i];i++)
    {
            for(int a=0;a<10;a++)
            {
                if(matrix_trigram_strings[a][0]==m[i])
                     {  if(matrix_trigram_strings[a][1]==m[i+1])
                            { if(matrix_trigram_strings[a][2]==m[i+2])
                                    {
                                        total_trigram_counter++;

                                        switch (a)                  //That switch-case structure computes every single trigram -according our trigram list- in text one-by-one
                                        {                           //and assign them all to individual variables.
                                            case 0:
                                                counter_the++;

                                            break;


                                            case 1:

                                                counter_and++;

                                            break;

                                            case 2:
                                                counter_ing++;

                                            break;

                                            case 3:
                                                counter_ent++;

                                            break;

                                            case 4:
                                                counter_ion++;

                                            break;

                                            case 5:
                                                counter_der++;

                                            break;

                                            case 6:
                                                counter_sch++;

                                            break;

                                            case 7:
                                                counter_ich++;

                                            break;

                                            case 8:
                                                counter_nde++;

                                            break;

                                            case 9:
                                                counter_die++;

                                            break;
                                        }

                                    }
                            }
                     }

            }
    }

printf("\n\n\n");

printf("Number of 'the' trigram: %.2f\n",counter_the);
printf("Number of 'and' trigram: %.2f\n",counter_and);
printf("Number of 'ing' trigram: %.2f\n",counter_ing);
printf("Number of 'ent' trigram: %.2f\n",counter_ent);
printf("Number of 'ion' trigram: %.2f\n",counter_ion);
printf("Number of 'der' trigram: %.2f\n",counter_der);            //We decided to print all trigrams individually.
printf("Number of 'sch' trigram: %.2f\n",counter_sch);
printf("Number of 'ich' trigram: %.2f\n",counter_ich);
printf("Number of 'nde' trigram: %.2f\n",counter_nde);
printf("Number of 'die' trigram: %.2f\n",counter_die);



printf("\nTotal Trigram Number: %d\n",total_trigram_counter);  //Total Trigram Number in text according our trigram list.



//Because of the same reason as bigram arrays...

calculated_frequencies[10]= counter_the;
calculated_frequencies[11]= counter_and;
calculated_frequencies[12]= counter_ing;
calculated_frequencies[13]= counter_ent;
calculated_frequencies[14]= counter_ion;
calculated_frequencies[15]= counter_der;
calculated_frequencies[16]= counter_sch;
calculated_frequencies[17]= counter_ich;
calculated_frequencies[18]= counter_nde;
calculated_frequencies[19]= counter_die;

  printf("\nTrigram Frequency Matrix:");
    for(int i=10;i<20;i++)
        {
            printf("%.2f\t",calculated_frequencies[i]);       //We print trigram frequency matrix.

        }
    printf("\n");
}

void calculate_distances()
    {

   /*
        printf("Calculated Frequencies:\n");
        for(int i=0;i<20;i++)
        {
           printf("%.2f \t",calculated_frequencies[i]);

        }

        printf("\n\n");


        printf("\nCalculated Distances-Eng:\n");
  */
        for(int i=0;i<20;i++)
            {
                float x=pow((calculated_frequencies[i]-frequency_eng[i]),2);   //Calculating distance between our frequency matrix and English frequency matrix.
  //              printf("%.2f\t",x);
                e = e + x;

            }
        distances[0]=e;
  //      printf("\n");

  //      printf("\nCalculated Distances-Germ:\n");
        for(int i=0;i<20;i++)
            {
                float x=pow((calculated_frequencies[i]-frequency_germ[i]),2);  //Calculating distance between our frequency matrix and German frequency matrix.
  //              printf("%.2f\t",x);
      //          printf("%.2f\t",x);
                g = g + x;
            }
        distances[1]=g;
    }

void detect_lang(int m,int n)
{
    if (sqrt(m)>sqrt(n))
            {
                printf("\nText you entered is German. ");
            }
    if (sqrt(m)<sqrt(n))
            {
                printf("\nText you entered is English. ");
            }

}

int main()
{
    printf("After writing text, press enter, write EOF character via CTRL+Z combination and press enter again.\n\n");
    printf("Enter a text: ");
    char str[10000];
    get_string(str);
    filter_str(str);
    calculate_frequencies_bi(str);
    calculate_frequencies_tri(str);
    calculate_distances();
    detect_lang(e,g);
    return 0;
}
