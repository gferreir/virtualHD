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
char arquivo[100];// nome arquivo
int posicao=0; // posição disponivel para escreve conteudo do arquivo
char matriz[1024][32]; // HD
char conteudo[100];// conteudo arquivo
char comandoHd[100];
char createHd[9] = "createhd";
char comandoArq[100];//comando cria arquivo
char create[7] = "create";
char proximo[200];
string nome;

//Declaração funções
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
	while(comandoHd[i] !='\0'){
		HD[j]=comandoHd[i];

		if(comandoHd[i + 1] == '\0'){
			HD[j+1] = comandoHd[i+1];
		}
		i++;
		j++;

	}
	
	
	
}

void nomeArq(int i){
	int j=0;
	while(comandoArq[i] !='\0'){
		arquivo[j]=comandoArq[i];

		if(comandoArq[i + 1] == '\0'){
			arquivo[j+1] = comandoArq[i+1];
		}
		i++;
		j++;

	}
	
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
	cout << "# " << HD << "> ";
	nome = formataTxT(HD);
	filew.open(nome.c_str());
	criaMatriz();
	filew.close();


}

int confirmaDisponibilidadeA(){
    for (int i = 20; i<1024; i++){
        if(matriz[i][0] == '0'){
            return i;
        }
    }
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

void incrementaProximo(){
    int k = 3;
    int valor;
    int estourou = 0;
    valor = proximo[k] - '0';
    if (valor >=0 && valor <= 8){
        proximo[k] = proximo[k] + 1;
    }
    else{
        proximo[k] = '0';
        estourou = 1;
    }
    k = 2;
    if (estourou == 1){
        while(estourou == 1 || k == 0){
            valor = proximo[k] - '0';
            if (valor >=0 && valor <= 7){
                proximo[k] = proximo[k] + 1;
                estourou = 0;
            }
            else if(valor == 8){
                proximo[k] = '0';
            }
            else{
                proximo[k] = '1';
            }
        }
    }
}

void criaArquivo(int i, char conteudo[200]){
    int tamanho = strlen(conteudo);
    int nLinhas = tamanho/24;
    int a = confirmaDisponibilidadeA();
    criaProximo(a+1);
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
            //if(pasta){
            //teste[i][k] = pasta[k-4];
            //}
            //else{
            matriz[i][k] = '0';
            //}
        }
        else if ( k >= 8 & k <= 11){
            //if(pasta){
            //teste[i][k] = "0";
            //}
            //else{
            matriz[i][k] = proximo[k-8];
            //}
        }
        else if ( k >= 12 & k <= 15){
            matriz[i][k] = tamanhoConteudo[k-12];
        }
        else if ( k >= 16 & k <= 31){
            matriz[i][k] = arquivo[k-16];
        }
    }
    if ((a + nLinhas) <= 1024){
        for (int j = a; j <= a + nLinhas;j++){
            for (int k = 0; k < 32; k++){
                if ( k == 0){
                    matriz[j][k] = '1';
                }
                else if ( k >= 4 & k <= 7){
                    if(nLinhas > 0 && j != (a +nLinhas)){
                        matriz[j][k] = proximo[k-4];
                    }
                    else{
                        matriz[j][k] = '0';
                    }
                }
                else if ( k >= 8 & k <= 31){
                    if (conteudo[atual] != 0){
                        matriz[j][k] = conteudo[atual];
                        atual++;
                    }
                }
            }
            incrementaProximo();
        }
    }
    else{
        cout << "overflow de memoria";
    }
}





void confirmaDisponibilidadeD(char conteudo[200]){
    for (int i = 0; i<20; i++){
        if(matriz[i][0] == '0'){
            criaArquivo(i, conteudo);
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
	leituraHD();

	cout<<"Digite o conteudo do arquivo:"<<endl;
	gets(conteudo);
	fflush(stdin);
	confirmaDisponibilidadeD(conteudo);
	memset(arquivo,'\0', 16);

}


int main(int argc, char *argv[])
{
	
	cout << "# ";
	cin.getline(comandoHd, sizeof(comandoHd));
	fflush(stdin);

	int i =0, j = 0;


	while(comandoHd[i] == createHd[i] && comandoHd[i] !='\0'){
		i++;
	}

	if(i==8){
		i++;
		criaHD(i);
		criaMatriz();
		filew.close();

	}else{
		cout<< "Não foi possivel criar o HD";
	}


	cin.getline(comandoArq, sizeof(comandoArq));
	fflush(stdin);

	while(comandoArq[j] == create[j] && comandoArq[j] !='\0'){
		j++;
	}

	if(j==6){
		j++;
		filer.open(HD);
		criaArquivo(j);
	}

	system("pause");
	return 0;
}
