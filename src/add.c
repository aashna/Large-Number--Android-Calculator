#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10000
#include <android/log.h>
#include <jni.h>




JNIEXPORT jcharArray JNICALL Java_com_example_calculator_MainActivity_add
  (JNIEnv * env, jobject thisobj, jcharArray j1, jcharArray j2){
  	
 
  	
  	 jchar *a = (*env)->GetCharArrayElements(env, j1, NULL);
  	 jchar *b = (*env)->GetCharArrayElements(env, j2, NULL);	 
  	 
  	 
   
  	jint i,j,carry,n,sum,rs[80],float1=0,float2=0;
    jchar result[80];
   jint res[80];
   jsize len1=(*env)->GetArrayLength(env,j1);
    jsize len2=(*env)->GetArrayLength(env,j2);
    
  
    
  // printf("\nadd1=%s\t,add2=%s\n",a,b);
  jchar reverse1[SIZE];
  jchar reverse2[SIZE];
  jint bb1=0,bb2=0;
   for(i=len1-1;i>=0;i--)
   {
  
   reverse1[bb1]=a[i];                       //reversing the nos. n1 and n2
   bb1++;}
   
    for(i=len2-1;i>=0;i--)
   {
  
   reverse2[bb2]=b[i];
   bb2++;}

   n=len1;                           //loop works for longer length
   if(len1<len2){n=len2;}
  
  for(i=0;i<len1;i++)
    {reverse1[i]=reverse1[i]-48;}               // Converting char to int 
  
   for(i=0;i<len2;i++)
  {reverse2[i]=reverse2[i]-48;
  }
   
   carry=0;
   for(i=0;i<n;i++)
   {
   if((len1==len2)||(i<len1 && i<len2))  
   {sum=carry+reverse1[i]+reverse2[i];
  // printf("sum=%d\n",sum);
  }
   else if(i>=len1)                   //if n1 gets finished, sum=rest of n2
   {sum=carry+reverse2[i];
   // printf("sum=%d\n",sum);
  }
   else if(i>=len2)
   {sum=carry+reverse1[i];
  // printf("sum=%d\n",sum);
 
   }                //if n2 gets finished, sum=rest of n1

    rs[i]=sum%10;
    carry=sum/10;
    res[i]=0;
 
   }
   
  jint kk=i;  
  bb1=0,bb2=0; 
 for(i=len1-1;i>=0;i--)
   {a[bb1]=reverse1[i]; 
   bb1++;}
   for(i=len2-1;i>=0;i--)
   {                      //reversing the nos. n1 and n2
   b[bb2]=reverse2[i];
   bb2++;}
      
   for(i=0;i<len1;i++)
   a[i]=a[i]+48;             // Converting int to char
  
   for(i=0;i<len2;i++)
   b[i]=b[i]+48;
  
  jint gh=0;
  if(carry)                          //if carry is left, add to end of result
  { 
  rs[i]=carry;
  i++;
  gh=1;
  } 
  
    for(j=0;j<kk;j++)
  { 
  result[j]=rs[kk-j-1]+48  ;
  } result[kk]='\0';
   
   jint var;
   if((result[0]==48))
                {
                 for(var=0;var<j;var++) 
                 result[var]=result[var+1];
                 result[j]='\0';
                }   	
				kk=j;
//  printf("result=%s\n",result);
	jcharArray outj=(*env)->NewCharArray(env,SIZE);
	(*env)->SetCharArrayRegion(env,outj,0,kk,result);
  return outj;
   
  /*jcharArray out1,out2;
   out1=(*env)->NewCharArray(env,SIZE);
   out2=(*env)->NewCharArray(env,SIZE);


   jint c=a[0] -48;
   jint d=a[1]-48;
  // out1[0]=c;
  // jint e=c+d;
jchar n=c;
jchar m=c+d;
jchar l=m+48;
jchar outCArray []={'6',n,'8',m,'9',l,'7'};
 
//  (*env)->SetCharArrayRegion(env,out1,0,0,e);	
  (*env)->SetCharArrayRegion(env,out2,0,SIZE,outCArray);	
   
   //jint e=c+d;
   //e+=48;
   //out1[0]=e;
  return out2;*/
  		
  }

	
     


