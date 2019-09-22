#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;

void criaHD(char str[100] ,int i){
	int j=0;
	char HD[100];
	while(str[i] !='\0'){
		HD[j]=str[i];
		
		if(str[i + 1] == '\0'){
			HD[j+1] = str[i+1];
		}
		i++;
		j++;
			
	}
	
	cout << "# " << HD << "> ";
	
	strcat(HD, ".txt");
	ofstream file;
	file.open(HD);
	
	
	for(int l = 1; l < 1025; l++){
		for(int c = 1; c < 33; c++){
			if(c == 1)
			file << "0";

			if(c == 32)
			    file << "\n";

			if(c == 2 && l < 21)
				file << "0";
				
			else if(c == 2 && l > 20)
			   	 file << "1";
			
			
		}
	}
		
		file.close();
	
}




int main(int argc, char *argv[])
{
	char str[100];
	char HD[100];
	char createHd[9] = "createhd";
	
	
	char arquivo[100];
	char nome[100];
	char create[7] = "create";
	cout << "# ";
	gets(str);
	
	int i =0, j = 0;

	while(str[i] == createHd[i] && str[i] !='\0'){
		if(str[i] != createHd[i]){
			printf("Errado");
			return 0;
			
		}
		i++;
	}
	
	
	
	if(i==8){
		i++;
		criaHD(str, i);
	
	}else{
		cout<< "Não foi possivel criar o HD";
	}
	

	

	system("pause");
	return 0;
}
