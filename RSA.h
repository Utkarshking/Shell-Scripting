#include<bits/stdc++.h>
#include<fstream>
using namespace std;
// global variables for rsa algorithm
long int p,q,n,phi,flag,e[100],d[100],temp[100],j,m[100],en[100],i; 
char msg[500]; 
// for operation on prime numbers
int prime(long int pr) { 
	int i; 
	j=sqrt(pr); 
	for (i=2;i<=j;i++) { 
		if(pr%i==0) 
		    return 0; 
	} 
	return 1;
}
long int cd(long int x) { 
	long int k=1; 
	while(1) { 
		k=k+phi; 
		if(k%x==0) 
		    return(k/x); 
	} 
}
 // encryption
void encrypt() { 
	long int pt,ct,key=e[0],k,len; 
	i=0; 
	len=strlen(msg); 
	while(i!=len) { 
		pt=m[i]; 
		pt=pt-96;
		k=1; 
		for (j=0;j<key;j++) { 
			k=k*pt; 
			k=k%n; 
		}
		temp[i]=k; 
		ct=k; 
		en[i]=ct; 
		i++; 
	} 
	en[i]=-1; 
	printf("\nTHE ENCRYPTED MESSAGE IS\n"); 
	for (i=0;en[i]!=-1;i++) 
	{
		printf("%c",en[i]);
	}
	
}
// decryption 
void decrypt() { 
	long int pt,ct,key=d[0],k;
	i=0; 
	while(en[i]!=-1) { 
		ct=temp[i]; 
		k=1; 
		for (j=0;j<key;j++) { 
			k=k*ct; 
			k=k%n; 
		} 
		pt=k+96; 
		m[i]=pt; 
		i++; 
	} 
	m[i]=-1; 
	printf("\nTHE DECRYPTED MESSAGE IS\n"); 
	for (i=0;m[i]!=-1;i++) 
	{
		printf("%c",m[i]);
    }
}
void ce() { 
	int k=0;  
	for (i=2;i<phi;i++) { 
		if(phi%i==0) 
		    continue; 
		flag=prime(i); 
		if(flag==1 && i!=p && i!=q) { 
			e[k]=i; 
			flag=cd(e[k]); 
			if(flag>0) { 
				d[k]=flag;
				k++; 
			} 
			if(k==99) 
			        break; 
		}
	} 
}
void launchrsa(){	
	// ifstream fp("rsadataset.txt");
	printf("\nENTER FIRST PRIME NUMBER\n"); 
	scanf("%d",&p);
    printf("%d",p); 
	flag=prime(p); 
	if(flag==0) { 
		printf("\nWRONG INPUT\n");  
		exit(1); 
	} 
	printf("\nENTER ANOTHER PRIME NUMBER\n");
 	scanf("%d",&q);
     printf("%d",q);
    //  cin>>q;
 	flag=prime(q);
 	if(flag==0||p==q) {
 		printf("\nWRONG INPUT\n");
  		exit(1);
 	}
 	printf("\nENTER MESSAGE\n"); 
	scanf(" %[^\n]%*c", &msg);
    // printf("%[^\n]%*c",msg);
    // printf("%c",msg);
    for (i=0;msg[i]!=NULL;i++) 
	{
		m[i]=msg[i]; 
	}
	n=p*q; 
	phi=(p-1)*(q-1);
	ce();
	printf("\nPOSSIBLE VALUES OF e AND d ARE\n"); 
	for (i=0;i<j-1;i++)
 	{
		printf("\n%ld\t%ld",e[i],d[i]); 
	} 
	encrypt(); 
	decrypt(); 
}