
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define SIZE 10000
#include"com_example_calculator_Example.h"
#include "C:\Program Files\Java\jdk1.7.0_21\include\jni.h"

JNIEXPORT jcharArray JNICALL Java_com_example_calculator_Example_multiply
  (JNIEnv * env, jobject thisobj, jcharArray j1, jcharArray j2){
  	
 
  	
  	 jchar *a = (*env)->GetCharArrayElements(env, j1, NULL);
  	 jchar *b = (*env)->GetCharArrayElements(env, j2, NULL);	   	 

    //printf("mul1=%s\t,mul2=%s\n",a,b);
    jchar mul[SIZE];
    jchar c[SIZE];
    jchar mul_temp[SIZE];
    
    jint i,j,k=0,x=0,y;
    jint r=0;
    jint sum=0;
    
    jsize lena=(*env)->GetArrayLength(env,j1)-1;
    jsize lenb=(*env)->GetArrayLength(env,j2)-1;

   
    for(i=0;i<=lena;i++)          //char to int..
    a[i]=a[i]-48;
    for(i=0;i<=lenb;i++)
    b[i]=b[i]-48;
        
    for(i=lenb;i>=0;i--)           
    {
         r=0;
         for(j=lena;j>=0;j--)
         {
             mul_temp[k++]=(b[i]*a[j]+r)%10;        //multiplying and adding carry
             r=(b[i]*a[j]+r)/10;
         }
         mul_temp[k++]=r;
         x++;
         for(y=0;y<x;y++)
         {mul_temp[k++]=0;}
    }   
    k=0;r=0;
    
     for(i=0;i<=lena;i++)          //int to char..
     a[i]=a[i]+48;
     for(i=0;i<=lenb;i++)          //int to char
     b[i]=b[i]+48;        
    
    for(i=0;i<lena+lenb+2;i++)
    {
         sum=0;
         y=0;
         for(j=1;j<=lenb+1;j++)
         {
             if(i<=lena+j)
             sum=sum+mul_temp[y+i];             
             y+=j+lena+1;
         }
         c[k++]=(sum+r)%10;           
         r=(sum+r)/10;                 //storing carry of sum
    }
    c[k]=r;
    j=0;
    for(i=k-1;i>=0;i--)
    {mul[j++]=c[i]+48;}            //converting back to char..
    mul[j]='\0';
    if(mul[0]==48) 
    {
      for(i=0;i<j-1;i++) 
      mul[i]=mul[i+1];
      mul[j-1]='\0';                 
    } 
    jcharArray outj=(*env)->NewCharArray(env,SIZE);
	(*env)->SetCharArrayRegion(env,outj,0,SIZE,mul);	                  
  return outj;
   

}
