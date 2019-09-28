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

ifstream filer;
ofstream filew;
char HD[100];

void criaMatriz(){
    for(int l = 1; l < 40; l++){
		for(int c = 1; c < 33; c++){
  			if(c == 1)
				filew << "0";

			else if(c == 32)
			    filew << "\n";

			else if(c == 2 && l < 21)
				filew << "0";

			else if(c == 2 && l > 20)
			   	 filew << "1";
			else
			    filew <<" ";


		}
	}
}

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
	filew.open(HD);


}
void criaArquivo(char str[100]){
	int i=0;
	int j=0;
	char matriz[40][33];
	filer.open(HD);
	char conteudo[100];

    for (i = 0; i < 40; i++){
        for (j = 0; j < 33; j++){
	        filer >> matriz[i][j];

        }

    }

    filer.close();

    filew.open(HD);
    i=0;
	int posicao=0;

	for(i=21;i<40;i++){
	        if(matriz[i][0] =='0'){
				posicao = i;


		}

	}
	printf("%i", posicao);
	gets(conteudo);
	fflush(stdin);






	filew.close();




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
	cin.getline(str, sizeof(str));
	fflush(stdin);

	int i =0, j = 0;


	while(str[i] == createHd[i] && str[i] !='\0'){
		i++;
	}


	if(i==8){
		i++;
		criaHD(str, i);
		criaMatriz();
		filew.close();

	}else{
		cout<< "Não foi possivel criar o HD";
	}


	cin.getline(arquivo, sizeof(arquivo));
	fflush(stdin);

	while(arquivo[j] == create[j] && arquivo[j] !='\0'){
		j++;
	}

	if(j==6){
		j++;
		criaArquivo(arquivo);
	}





	system("pause");
	return 0;
}
