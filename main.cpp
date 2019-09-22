#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <windows.h>
#include <string>


using namespace std;

fstream file;
char HD[100];

void criaHD(char str[100] ,int i){
	int j=0;
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
	file.open(HD, std::fstream::in | std::fstream::out | std::fstream::app);
	
	
	for(int l = 1; l < 40; l++){
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
		
	
}

void criaArquivo(char str[100]){
	cout<<"CHAMA";
	int i=0;
	int j=0;
	char matriz[40][33];

	while (!file.eof()){
          for (i = 0; i < 40; i++)
          {
              for (j = 0; j < 33; j++)
              {
          file >> matriz[i][j];
            cout << matriz[i][j] << "";
            }
            
            
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
		i++;
	}
	
	
	if(i==8){
		i++;
		criaHD(str, i);

	}else{
		cout<< "Não foi possivel criar o HD";
	}
	
	
	gets(arquivo);
	
	while(arquivo[j] == create[j] && arquivo[j] !='\0'){
		j++;
	}
	
	if(j==6 && file.is_open()){
		j++;
		criaArquivo(arquivo);
	}
	
	
		file.close();

	

	system("pause");
	return 0;
}
