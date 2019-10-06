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
#include <sstream>


using namespace std;


//Declaração variaveis
ifstream filer; // abre arquivo em modo de leitura
ofstream filew; // abre aquivo em modo de escrita
char HD[100];  // nome do HD
char arquivo[16];// nome arquivo
int posicao=0; // posição disponivel para escreve conteudo do arquivo
char matriz[1024][32]; // HD
char conteudo[100];// conteudo arquivo
char comando[100];
char createHd[9] = "createhd";
char comandoArq[100];//comando cria arquivo
char create[7] = "create";
char excluir[7] = "remove";
char proximo[200];
char comandoDelete[100];
string nome;


//Declaração funções
int iguais(char v[], char d[]);
void verificaDisponibilidade();
void criaMatriz();
void criaHD(int i);
void criaArquivo(int j);
void leituraHD();
void nomeArquivo();
void nomeHD(int i);
string formataTxT(char* txt);

void nomeHD(int i){
	int j=0;
	while(comando[i] !='\0'){
		HD[j]=comando[i];

		if(comando[i + 1] == '\0'){
			HD[j+1] = comando[i+1];
		}
		i++;
		j++;

	}
	
	
	
}

void nomeArq(int i){
	int j=0;
	while(comando[i] !='\0'){
		arquivo[j]=comando[i];

		if(comando[i + 1] == '\0'){
			arquivo[j+1] = comando[i+1];
		}
		i++;
		j++;

	}
	
}

void nomeArqDel(int i){
	int j=0;
	while(comando[i] !='\0'){
		arquivo[j]=comando[i];

		if(comando[i + 1] == '\0'){
			arquivo[j+1] = comando[i+1];
		}
		i++;
		j++;

	}
	cout<<arquivo;
	
}

void leituraHD(){
	int i=0;
	int j=0;
	filer.open(nome.c_str());

    for (i = 0; i < 1024; i++){
        for (j = 0; j < 32; j++){
	        filer >> matriz[i][j];

        }

    }
    
    filer.close();
}

void verificaDisponibilidade(){
    int i=0;
     for(i=21;i<40;i++){
	        if(matriz[i][0] =='0'){
				posicao = i;


		}

	}

}

int iguais(char v[], char d[]){
    int c = 0;
    while(v[c] != 0 ){
        if(v[c] != d[c]){
            return 0;
        }
        c++;
    }
    return 1;
}
void criaMatriz(){
    for (int i = 0; i<1024; i++){
        for (int j = 0; j< 33 ;j++){
            if (j == 0 || (j == 1 && i>=0 && i<=19)){
                filew << "0";
            }
            else if(j == 1 && i>=20){
                filew << "1";
            }
            else if(j == 32){
                filew << endl;
            }
            else{
                filew << "-";
            }
        }
    }
}

string formataTxT(char* txt){
	string nomeHD = txt;
	nomeHD += ".txt";
	return nomeHD;
	
}

void criaHD(int i){
	nomeHD(i);
	nome = formataTxT(HD);
	filew.open(nome.c_str());
	criaMatriz();
	filew.close();


}

int * confirmaDisponibilidadeA(int n){
	int *disponiveis = new int[n];
	int m;
	int i;
	for(m = 0; m < n;m++){
	    for (i= 20; i<1024; i++){
            if(matriz[i][0] == '0'){
				disponiveis[m] = i;
				matriz[i][0] = '1';
            	break;
        	}
		}
    }
    return disponiveis;
}

void criaProximo(int i){
    stringstream strs;
    strs  << i;
    string temp_str = strs.str();
    if(strlen(temp_str.c_str()) == 1){
        proximo[0] = '0';
        proximo[1] = '0';
        proximo[2] = '0';
        proximo[3] = (char) temp_str.c_str()[0];
    }
    if(strlen(temp_str.c_str()) == 2){
        proximo[0] = '0';
        proximo[1] = '0';
        proximo[2] = (char) temp_str.c_str()[0];
        proximo[3] = (char) temp_str.c_str()[1];
    }
    if(strlen(temp_str.c_str()) == 3){
        proximo[0] = '0';
        proximo[1] = (char) temp_str.c_str()[0];
        proximo[2] = (char) temp_str.c_str()[1];
        proximo[3] = (char) temp_str.c_str()[2];
    }
    if(strlen(temp_str.c_str()) == 4){
        proximo[0] = (char) temp_str.c_str()[0];
        proximo[1] = (char) temp_str.c_str()[1];
        proximo[2] = (char) temp_str.c_str()[2];
        proximo[3] = (char) temp_str.c_str()[3];
    }
    return;
}

void deleteArquivo(){
    leituraHD();
    cout << "# " << HD << "> ";
    char tempNomeArquivo[16];
    char tempPosConteudo[4];
    int posicaoConteudo = 0;
    for(int i = 0; i < 20; i++){
        for(int j = 16; j < 32; j++){
            if(matriz[i][j] != 0) {
                tempNomeArquivo[j - 16] = matriz[i][j];
            }
        }
        if(iguais(arquivo, tempNomeArquivo)){
            matriz[i][0] = '0';
            for(int k = 8; k < 12; k++){
                tempPosConteudo[k - 8] = matriz[i][k];
            }
            posicaoConteudo = atoi(tempPosConteudo);
        }
    }
    matriz[posicaoConteudo][0] = '0';
    while ( posicaoConteudo != 0){
        matriz[posicaoConteudo][0] = '0';
	    for(int k = 4; k < 8; k++){
	        tempPosConteudo[k - 4] = matriz[posicaoConteudo][k];
	    }
	    posicaoConteudo = atoi(tempPosConteudo);
	}
   filew.open(nome.c_str());
    for (int i = 0; i<1024; i++){
        for (int j = 0; j< 33 ;j++){
            if(j == 32){
                filew << endl;
            }
            else{
                filew << matriz[i][j];
            }
        }
    }
    filew.close();
}

void escreveArquivo(int i){
    int tamanho = strlen(conteudo);
    int nLinhas = (tamanho/24) + 1;
    int *a;
    a = confirmaDisponibilidadeA(nLinhas);
    criaProximo(a[0]);
    stringstream strs;
    strs  << tamanho;
    string temp_str = strs.str();
    char tamanhoConteudo[4];
    if(strlen(temp_str.c_str()) == 1){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = '0';
        tamanhoConteudo[2] = '0';
        tamanhoConteudo[3] = (char) temp_str.c_str()[0];
    }
    if(strlen(temp_str.c_str()) == 2){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = '0';
        tamanhoConteudo[2] = (char) temp_str.c_str()[0];
        tamanhoConteudo[3] = (char) temp_str.c_str()[1];
    }
    if(strlen(temp_str.c_str()) == 3){
        tamanhoConteudo[0] = '0';
        tamanhoConteudo[1] = (char) temp_str.c_str()[0];
        tamanhoConteudo[2] = (char) temp_str.c_str()[1];
        tamanhoConteudo[3] = (char) temp_str.c_str()[2];
    }
    if(strlen(temp_str.c_str()) == 4){
        tamanhoConteudo[0] = (char) temp_str.c_str()[0];
        tamanhoConteudo[1] = (char) temp_str.c_str()[1];
        tamanhoConteudo[2] = (char) temp_str.c_str()[2];
        tamanhoConteudo[3] = (char) temp_str.c_str()[3];
    }

    int atual = 0;

    for (int k = 0; k < 32; k++){
        if ( k == 0){
            matriz[i][k] = '1';
        }
        else if ( k == 2){
            matriz[i][k] = '0';
        }
        else if ( k >= 4 & k <= 7){
            matriz[i][k] = '0';

        }
        else if ( k >= 8 & k <= 11){

            matriz[i][k] = proximo[k-8];
    
        }
        else if ( k >= 12 & k <= 15){
            matriz[i][k] = tamanhoConteudo[k-12];
        }
        else if ( k >= 16 & k <= 31){
            matriz[i][k] = arquivo[k-16];
        }
    }
      for (int j = 0; j <= (nLinhas - 1);j++){
		if(j != (nLinhas - 1)){
            criaProximo(a[(j+1)]);
		}
        for (int k = 0; k < 32; k++){
            if ( k >= 4 & k <= 7){
                if(j == (nLinhas-1) && j==0){
                    matriz[(a[j])][k] = proximo[k-4];
                }else if(j == (nLinhas-1) && j!=0){
                    matriz[(a[j])][k] = '0';
                }else if(j != (nLinhas-1) && j!=0){
                    matriz[(a[j])][k] = '0';
                }
                else{
                    matriz[(a[j])][k] = proximo[k-4];
                }
            }
           else if ( k >= 8 & k <= 31){
				if (conteudo[atual] != 0){
                	matriz[a[j]][k] = conteudo[atual];
                	atual++;
				}
            }
    	}
	}
}





void confirmaDisponibilidadeD(){
    for (int i = 0; i<=20; i++){
        if(matriz[i][0] == '0'){
            escreveArquivo(i);
            filew.open(nome.c_str());
		    for (int i = 0; i<1024; i++){
		        for (int j = 0; j< 33 ;j++){
		            if(j == 32){
		                filew << endl;
		            }
		            else{
		                filew << matriz[i][j];
		            }
		        }
		    }
		    filew.close();
            return;
        }
    }
}

void criaArquivo(int j){
	
	nomeArq(j);
	cout << "# " << HD << "> ";
	leituraHD();
	cout<<"Digite o conteudo do arquivo:"<<endl;
	gets(conteudo);
	fflush(stdin);
	confirmaDisponibilidadeD();
	memset(arquivo,'\0', 16);
	

}


int main(int argc, char *argv[])
{
	
	cout << "# ";
	int i =0, j = 0;
	char fim[5] = "exit";

	while(true){
        int i;
	    int k = 0;
	    if(HD[0]!= '\0'){
	    	cout << "# " << HD << "> ";
		}
	    cin.getline(comando, sizeof(comando));
	    fflush(stdin);

	    if (iguais(createHd, comando)){
			int i=9;
			criaHD(i);
		    criaMatriz();
	    }
	    else if (iguais(create, comando)){
	        int j=7;
		    criaArquivo(j);
	    }
	    else if(iguais(excluir, comando)){
	        int j=7;
	        nomeArq(j);
	        deleteArquivo();
	    }
	    else if(iguais("exit",comando)){
	        return 0;
	    }
	    

	}
	



	
	
	

	system("pause");
	return 0;
}
