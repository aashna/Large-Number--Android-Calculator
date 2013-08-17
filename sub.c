#include<stdio.h>
#include<string.h>
#define N 10000

#include"com_example_calculator_Example.h"
#include "C:\Program Files\Java\jdk1.7.0_21\include\jni.h"

JNIEXPORT jcharArray JNICALL Java_com_example_calculator_Example_subtract
  (JNIEnv * env, jobject thisobj, jcharArray j3, jcharArray j4){  	

   jint i,j,m,k,n,sm,diff[N],check=0;   
   jchar res[N],temp[N];   
   	
  	 jchar *reverse1 = (*env)->GetCharArrayElements(env,j3, NULL);
  	 jchar *reverse2 = (*env)->GetCharArrayElements(env,j4, NULL);
    jsize len1=(*env)->GetArrayLength(env,j3);
    jsize len2=(*env)->GetArrayLength(env,j4);  
         
	// printf("reverse1:%s\n",reverse1); 
	  // printf("reverse2:%s\n",reverse2);	
	   
	   //printf("len1=%d\t",len1);    
	    //printf("len2=%d\n",len2);  
	    
     jint cmp=0;
     if(len1<len2)
         cmp=-1;         
         else if(len1>len2)
         cmp=1;        
         else if(len1==len2)                              
        {    
        jint inj,intab,intcd,eq=0;
          for(inj=0;inj<len1;inj++)
          {
                   intab=reverse1[inj]-48;intcd=reverse2[inj]-48;
                    if(intab<intcd)
                    {
                    cmp=-1;
                    break;
                    }
                    else if(intab>intcd)
                    {
                    cmp=1;
                    break;
                    }
                    else if(intab==intcd)
                    eq++;                
          }         eq=eq+50;
          if(eq==(len1+50))
          cmp=eq;                  
      }
	  
//	  printf("reverse1:%s\n",reverse1); 
//	    printf("reverse2:%s\n",reverse2); 
  //printf("compare=%d\n",cmp);
   if(cmp==-1)
   {
   	
   	for(i=0;i<len1;i++)
   	temp[i]=reverse1[i];
                                                       //strcpy(temp,reverse1);
                                                       
    for(i=0;i<len2;i++)
   	reverse1[i]=reverse2[i];                                                   
                                               //  strcpy(reverse1,reverse2);
    
	 for(i=0;i<len1;i++)
   	reverse2[i]=temp[i]; 
	
	                                          //strcpy(reverse2,temp);
   check=len1;                               //swap len1 and len2
   len1=len2;
   len2=check; 
   }
   
   
   
  jchar a[N];
  jchar b[N];
  jint bb1=0,bb2=0;
   for(i=len1-1;i>=0;i--)
   {a[bb1]=reverse1[i];                       //reversing the nos. n1 and n2
   bb1++;}

   for(i=len2-1;i>=0;i--)
   {
    b[bb2]=reverse2[i];
    bb2++;
	}
   
     //  printf("a:%s\n",a); 
	  // printf("b:%s\n",b);
	    
	    
   jint sub_arr1[N],sub_arr2[N];
   for(sm=0;sm<len1;sm++)                  
   {
   sub_arr1[sm]=a[sm]-48;
  // printf("sub_arr1[%d]=%d\t",sm,sub_arr1[sm]);
  }
    
   for(m=0;m<len2;m++)  
   {
   sub_arr2[m]=b[m]-48;
    //printf("sub_arr2[%d]=%d\t",m,sub_arr2[m]);
	}    
    //printf("\n");
   n=len1;                           //loop works for longer length
  
  
  // printf("len1=%d\t",len1);    
	//    printf("len2=%d\n",len2); 
  
  
   for(k=0;k<n;k++)
   {
   if((len1==len2)||(k<len1 && k<len2))  
   {
   if(sub_arr1[k]<sub_arr2[k])
   {diff[k]=(10+sub_arr1[k])-sub_arr2[k];
   sub_arr1[k+1]=sub_arr1[k+1]-1;
   //printf("diff[%d]=%d\n",k,diff[k]);
   }
   else
   {
   diff[k]=sub_arr1[k]-sub_arr2[k];
   // printf("diff[%d]=%d\n",k,diff[k]);
}
   }
   else if(k>=len2)
  {
   diff[k]=sub_arr1[k]; 
   // printf("diff[%d]=%d\n",k,diff[k]);
    }             //if n2 gets finished, difference=rest of n1
   }   
  
    for(j=0;j<k;j++)
   {
   res[j]=diff[k-j-1]+48;}
    res[k]='\0';
   //printf("answer: %s\n",res);
    if(res[0]==48)  
                 {
                 for(j=0;j<k;j++) 
                 res[j]=res[j+1];
                 res[k-1]='\0';}
                 
                if(check!=0)  
                    
                {
                 for(j=0;j<k;j++) 
                 res[j+1]=res[j];
                 res[0]=45;
                 res[k]='\0';
                }    

  /*bb1=0,bb2=0;
 for(i=len1-1;i>=0;i--)
   {reverse1[bb1]=a[i];                       //reversing the nos. n1 and n2
   bb1++;}
   
   for(i=len2-1;i>=0;i--)
   {reverse2[bb2]=a[i];                       //reversing the nos. n1 and n2
   bb2++;}*/

   //printf("answer: %s\n",res);
	jcharArray outj=(*env)->NewCharArray(env,N);
	(*env)->SetCharArrayRegion(env,outj,0,N,res);	                  
  return outj;

   
}

